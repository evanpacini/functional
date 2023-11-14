#include <functional.h>
#include <stdio.h>
#include <math.h>
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

void assertStringEqual(const char* a, const char* b, const char *message) {
    if (strcmp(a, b) != 0) {
        printf("Assertion failed: %s\n", message);
        printf("Expected: %s\n", a);
        printf("Actual: %s\n", b);
        exit(1);
    }
}

void testInitializeListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    assert(ld->head == 1., "testInitializeListDouble: head == 1.");
    assert(ld->tail->head == 2., "testInitializeListDouble: tail->head == 2.");
    assert(ld->tail->tail->head == 3., "testInitializeListDouble: tail->tail->head == 3.");
    assert(ld->tail->tail->tail->head == 4., "testInitializeListDouble: tail->tail->tail->head == 4.");

    assert(ld->size == 4, "testInitializeListDouble: size == 4.");
    assert(ld->tail->size = 3, "testInitializeListDouble: tail->size == 3.");
    assert(ld->tail->tail->size = 2, "testInitializeListDouble: tail->tail->size == 2.");
    assert(ld->tail->tail->tail->size = 1, "testInitializeListDouble: tail->tail->tail->size == 1.");

    assert(ld->tail->tail->tail->tail->headBits == nilBits, "testInitializeListDouble: tail->tail->tail->tail->headBits == nilBits.");
    assert(ld->tail->tail->tail->tail->tail == NULL, "testInitializeListDouble: tail->tail->tail->tail->tail == NULL.");
    assert(ld->tail->tail->tail->tail->size == 0, "testInitializeListDouble: tail->tail->tail->tail->size == 0.");
}

void testGetListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    assert($ld(ld).get(0) $_ == 1., "get(0) == 1.");
    assert($ld(ld).get(1) $_ == 2., "testGetListDouble: get(1) == 2.");
    assert($ld(ld).get(2) $_ == 3., "testGetListDouble: get(2) == 3.");
    assert($ld(ld).get(3) $_ == 4., "testGetListDouble: get(3) == 4.");
}

void testToStringListDouble() {
    const ListDouble ld = ListDouble(1., 2., 3., 4.);
    //printf("number of characters: %llu, list->size * 18 + 13 = %d\n", strlen(toStringListDouble(ld)), ld->size * 18 + 13);
    assertStringEqual(toStringListDouble(ld), "ListDouble(1.0000000000e+00, 2.0000000000e+00, 3.0000000000e+00, 4.0000000000e+00, )", "testToStringListDouble: toStringListDouble(ld) == \"ListDouble(1.0000000000e+00, 2.0000000000e+00, 3.0000000000e+00, 4.0000000000e+00, )\".");
}

void runTests() {
    printf("\nTesting testInitializeListDouble...");
    testInitializeListDouble();
    printf("\rTesting testInitializeListDouble DONE");
    printf("\nTesting testGetListDouble...");
    testGetListDouble();
    printf("\rTesting testGetListDouble DONE");
    printf("\nTesting testToStringListDouble...");
    testToStringListDouble();
    printf("\rTesting testToStringListDouble DONE");
}

int main() {
    runTests();
    exit(0);
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
