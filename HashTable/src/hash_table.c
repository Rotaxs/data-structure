#include "hash_table.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        map->buckets[i] = NULL;
    }
}

unsigned hash(const char *s) {
    unsigned int h = 0;
    while (*s) {
        h = h * 31u + *s;
        ++s;
    }
    return h % TABLE_SIZE;
}

void add(HashMap *map, const char *word) {
    unsigned index = hash(word);
    Node *p = map->buckets[index];
    while (p != NULL) {
        if (strcmp(p->word, word) == 0) {
            ++p->count;
            return;
        }
        p = p->next;
    }

    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->word = malloc(strlen(word) + 1);
    if (node->word == NULL) {
        free(node);
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(node->word, word);
    node->count = 1;

    node->next = map->buckets[index];
    map->buckets[index] = node;
}

int get(const HashMap *map, const char *word) {
    unsigned index = hash(word);
    Node *p = map->buckets[index];
    while (p != NULL) {
        if (strcmp(p->word, word) == 0) {
            return p->count;
        }
        p = p->next;
    }
    return 0;
}

void destroy(HashMap *map) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node *p = map->buckets[i];
        while (p != NULL) {
            Node *next = p->next;
            free(p->word);
            free(p);
            p = next;
        }
        map->buckets[i] = NULL;
    }
}
