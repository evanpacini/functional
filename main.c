#include <functional.h>
#include <stdio.h>

int main() {
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
    printf("list(2): %f\n", $ld(list).get(3) $_);
    printf("list size: %d\n", list->size);

    ListDouble list2 = ListDouble(1.);
    printf("list2: %s\n", toStringListDouble(list2));
    printf("list2 with 3 inserted: %s\n", toStringListDouble($ld(list2).insert(3.) $));
    printf("list2 after insertion in the pipe: %s\n", toStringListDouble(list2));
    printf("list and list2: %s\n", toStringListDouble($ld(list).concat(list2) $));
    printf("list after concat: %s", toStringListDouble(list));
    printf("NilDouble: %s\n", toStringListDouble(NilDouble));
    return 0;
}
