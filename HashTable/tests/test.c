#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition)                                                                           \
    do {                                                                                           \
        if (!condition) {                                                                          \
            fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition);                        \
            exit(EXIT_FAILURE);                                                                    \
        }                                                                                          \
    } while (0)

int main(int argc, char *argv[]) {

    HashMap *map = malloc(sizeof(HashMap));
    init(map);
    add(map, "word");
    CHECK((get(map, "word") == 1));
    add(map, "word");
    CHECK((get(map, "word") == 2));
    CHECK((get(map, "hello") == 0));

    char w[3];

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            w[0] = 'a' + i;
            w[1] = 'a' + j;
            add(map, w);
        }
    }

    CHECK((get(map, "aa") == 1));
    CHECK((get(map, "bb") == 1));

    return EXIT_SUCCESS;
}