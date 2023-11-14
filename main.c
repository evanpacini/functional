#include <functional.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

double square(double a) {
    return a * a;
}

void assert(bool condition, const char *message) {
    if (!condition) {
        printf("Assertion failed: %s\n", message);
        exit(1);
    }
}

void assertStringEqual(const char *a, const char *b, const char *message) {
    if (strcmp(a, b) != 0) {
        printf("Assertion failed: %s\n", message);
        printf("Expected: %s\n", a);
        printf("Actual: %s\n", b);
        exit(1);
    }
}

void assertDoubleEqual(const double a, const double b, const char *message) {
    if (a != b) {
        printf("Assertion failed: %s\n", message);
        printf("Expected: %f\n", a);
        printf("Actual: %f\n", b);
        exit(1);
    }
}

bool helper_assertListDoubleEqual(const ListDouble a, const ListDouble b) {
    if (a->headBits != b->headBits) return false;
    if (a->headBits == nilBits) return true;
    return helper_assertListDoubleEqual(a->tail, b->tail);
}

void assertListDoubleEqual(const ListDouble a, const ListDouble b, const char *message) {
    if (!helper_assertListDoubleEqual(a, b)) {
        printf("Assertion failed: %s\n", message);
        printf("Expected: %s\n", toStringListDouble(a));
        printf("Actual: %s\n", toStringListDouble(b));
    }
}

void testInitializeListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    assert(ld->head == 1., "head == 1.");
    assert(ld->tail->head == 2., "tail->head == 2.");
    assert(ld->tail->tail->head == 3., "tail->tail->head == 3.");
    assert(ld->tail->tail->tail->head == 4., "tail->tail->tail->head == 4.");

    assert(ld->size == 4, "size == 4.");
    assert(ld->tail->size = 3, "tail->size == 3.");
    assert(ld->tail->tail->size = 2, "tail->tail->size == 2.");
    assert(ld->tail->tail->tail->size = 1, "tail->tail->tail->size == 1.");

    assert(ld->tail->tail->tail->tail->headBits == nilBits, "tail->tail->tail->tail->headBits == nilBits.");
    assert(ld->tail->tail->tail->tail->tail == NULL, "tail->tail->tail->tail->tail == NULL.");
    assert(ld->tail->tail->tail->tail->size == 0, "tail->tail->tail->tail->size == 0.");
}

void testGetListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    assert($ld(ld).get(0) $_ == 1., "get(0) == 1.");
    assert($ld(ld).get(1) $_ == 2., "get(1) == 2.");
    assert($ld(ld).get(2) $_ == 3., "get(2) == 3.");
    assert($ld(ld).get(3) $_ == 4., "get(3) == 4.");
}

void testToStringListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    assertStringEqual(toStringListDouble(ld), "ListDouble(1.0000000000e+00, 2.0000000000e+00, 3.0000000000e+00, 4.0000000000e+00, )", "testToStringListDouble: toStringListDouble(ld) == \"ListDouble(1.0000000000e+00, 2.0000000000e+00, 3.0000000000e+00, 4.0000000000e+00, )\".");
}

void testInsertListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    const ListDouble ld2 = $ld(ld).insert(5.) $;
    assertDoubleEqual(ld2->head, 5., "5 should be inserted to [1, 2, 3, 4]");
    assertListDoubleEqual(ld2->tail, ld, "The original list should not change.");
}

void testConcatListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    const ListDouble ld2 = ListDouble(5., 6., 7., 8.);
    const ListDouble ld3 = $ld(ld).concat(ld2) $;
    const ListDouble ld4 = ListDouble(1., 2., 3., 4., 5., 6., 7., 8.);
    assertListDoubleEqual(ld3, ld4, "The concatenation should work.");
    assertListDoubleEqual(ld, ListDouble(1., 2., 3., 4.), "The original list should not change.");
    assertListDoubleEqual(ld2, ListDouble(5., 6., 7., 8.), "The concatenated list should not change.");
}

void testMapToDoubleListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    const ListDouble ld2 = $ld(ld).mapToDouble(square) $;
    const ListDouble ld3 = ListDouble(1., 4., 9., 16.);
    assertListDoubleEqual(ld2, ld3, "[1, 2, 3, 4] should be mapped to [1, 4, 9, 16].");
    assertListDoubleEqual(ld, ListDouble(1., 2., 3., 4.), "The original list should not change.");
}

void runTests() {
    printf("Testing testInitializeListDouble...");
    testInitializeListDouble();
    printf("\rTesting testInitializeListDouble DONE\n");
    printf("Testing testGetListDouble...");
    testGetListDouble();
    printf("\rTesting testGetListDouble DONE\n");
    printf("Testing testToStringListDouble...");
    testToStringListDouble();
    printf("\rTesting testToStringListDouble DONE\n");
    printf("Testing testInsertListDouble...");
    testInsertListDouble();
    printf("\rTesting testInsertListDouble DONE\n");
    printf("Testing testConcatListDouble...");
    testConcatListDouble();
    printf("\rTesting testConcatListDouble DONE\n");
    printf("Testing testMapToDoubleListDouble...");
    testMapToDoubleListDouble();
    printf("\rTesting testMapToDoubleListDouble DONE\n");
}

int main() {
    runTests();
    OptionalInt test = $i(someInt(4)).add(someInt(2)).mul(someInt(5)).xor (someInt(3)) $;
    printf("val: %d\n", $i(test) $_);

    OptionalFloat test2 = $f(someFloat(3.14f)).add(someFloat(2.71f)).mul(someFloat(5.f)).div(someFloat(3.f)) $;
    printf("val: %f\n", $f(test2) $_);

    // Equivalent statements:
    float pi = $f(someFloat(6.28f)).div(someFloat(2.f)).endPipe().value;
    float pi2 = $f(someFloat(6.28f)).div(someFloat(2.f)) $.value;
    float pi3 = $f(someFloat(3.14f)).pow(someFloat(2.f)).pow(someFloat(.5f)).getValue();
    float pi4 = $f(someFloat(3.14f)).pow(someFloat(2.f)).pow(someFloat(.5f)) $_;
    printf("pi: %f\n", pi);
    printf("pi2: %f\n", pi2);
    printf("pi3: %f\n", pi3);
    printf("pi4: %f\n", pi4);

    // Combining Int and Float pipes:
    float x = $f(someFloat(.5f)).pow(someFloat(.5f)).round().toInt().add(someInt(1)).toFloat() $_;
    printf("x: %f\n", x);

    printf("NilDouble: %f 0x%016llx\n", NilDouble->head, *((uint64_t *) &NilDouble->head));

    ListDouble list = ListDouble(1.123456789e-5, 2., 3., 4.);
    printf("list: %s\n", toStringListDouble(list));
    printf("\nlist->head: %f\nlist->tail: %s\n", list->head, toStringListDouble(list->tail));
    printf("list(3): %f\n", $ld(list).get(3) $_);
    printf("list size: %d\n", list->size);

    ListDouble list2 = ListDouble(1.);
    printf("list2: %s\n", toStringListDouble(list2));
    printf("list2 with 3 inserted: %s\n", toStringListDouble($ld(list2).insert(3.) $));
    printf("list2 after insertion in the pipe: %s\n", toStringListDouble(list2));
    printf("list and list2: %s\n", toStringListDouble($ld(list).concat(list2) $));
    printf("list after concat: %s\n", toStringListDouble(list));
    printf("list mapped to square: %s\n", toStringListDouble($ld(list).mapToDouble(square) $));
    printf("list mapped to square, then concatenated with list2, 9 inserted and then mapped to sqrt: %s\n", toStringListDouble($ld(list).mapToDouble(square).concat(list2).insert(9.).mapToDouble(sqrt) $));
    printf("NilDouble: %s\n", toStringListDouble(NilDouble));

    return 0;
}
