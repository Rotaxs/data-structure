#pragma once

#define TABLE_SIZE 301

typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

typedef struct {
    Node *buckets[TABLE_SIZE];
} HashMap;

void init(HashMap *map);
unsigned hash(const char *s);
void add(HashMap *map, const char *word);
int get(const HashMap *map, const char *word);
void destroy(HashMap *map);