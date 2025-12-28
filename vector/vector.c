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
    Client **items;
};

vector *init() {
    vector *v = malloc(sizeof(vector));
    Client **items = malloc(INITIAL_CAPACITY * sizeof(Client *));
    if (v == NULL || items == NULL) {
        memory_error();
        return NULL; // suppress IDE
    }
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
    v->items = items;
    return v;
}

void not_deep_clear(vector *v) {
    // for (int i = 0; i < v->size; i++) {
    //     free_client(v->items[i]);
    // }
    free(v->items);
    v->items = malloc(INITIAL_CAPACITY * sizeof(Client *));
    if (v->items == NULL) {
        memory_error();
    }
    v->size = 0;
    v->capacity = INITIAL_CAPACITY;
}

void destroy(vector *v) {
    if (!v || !v->items) return;
    for (int i = 0; i < v->size; i++) {
        free_client(v->items[i]);
    }
    free(v->items);
    v->items = NULL;
    v->size = 0;
    v->capacity = 0;
}

int size(const vector *v) {
    return v->size;
}

void resize(vector *v, const int new_capacity) {
    if (new_capacity < v->capacity) {
        return;
    }
    Client **new_items = realloc(v->items, new_capacity * sizeof(Client *));
    if (new_items == NULL) {
        memory_error();
        free(new_items);
        return;
    }
    v->items = new_items;
    v->capacity = new_capacity;
}

Client *get(const vector *v, const int index) {
    return v->items[index];
}

void set(const vector *v, const int index, Client *client) {
    v->items[index] = client;
}

void push(vector *v, Client *client) {
    if (v->size >= v->capacity) {
        resize(v, v->capacity * 2);
    }
    v->items[v->size++] = client;
}

Client *pop(vector *v) {
    return v->items[--v->size];
}
