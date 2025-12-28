//
// Created by nevrozq on 28.12.2025.
//

#ifndef VECTOR_H
#define VECTOR_H
#include "../client/client.h"

typedef struct vector vector;

vector* init();

void destroy(vector *v);

int size(const vector *v);

void resize(vector *v, int new_capacity);

Client* get(const vector *v, int index);

void set(const vector *v, int index, Client* client);

void push(vector *v, Client* client);

Client* pop(vector *v);

#endif //VECTOR_H
