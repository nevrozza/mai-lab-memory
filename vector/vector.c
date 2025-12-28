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
