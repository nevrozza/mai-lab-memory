//
// Created by nevrozq on 28.12.2025.
//

#include "vector.h"
#include "../utils/utils.h"
#define INITIAL_CAPACITY  4

#include <stdlib.h>

struct vector {
    int size;
    int capacity;
    Client *items;
};

vector init() {
    vector v;
    v.size = 0;
    v.capacity = INITIAL_CAPACITY;
    v.items = malloc(v.capacity * sizeof(Client));
    if (v.items == NULL) {
        memory_error();
    }
    return v;
}

int size(const vector *v) {
    return v->size;
}

void resize(vector *v, const int new_size) {
    if (new_size < v->capacity) {
        return;
    }
    Client *new_items = realloc(v->items, new_size);
    if (new_items == NULL) {
        memory_error();
        free(new_items);
        return;
    }
    v->items = new_items;
    v->capacity = new_size;
}

Client get(const vector *v, const int index) {
    return v->items[index];
}

void set(const vector *v, const int index, const Client client) {
    v->items[index] = client;
}

void push(vector *v, const Client client) {
    if (v->size >= v->capacity) {
        resize(v, v->capacity * 2);
    }
    v->items[v->size++] = client;
}

Client pop(vector *v) {
    return v->items[--v->size];
}
