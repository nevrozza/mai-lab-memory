//
// Created by nevrozq on 28.12.2025.
//
#include <stdlib.h>

#include "../vector/vector.h"

void free_client(Client *c) {
    if (!c) return;
    free(c->surname);
    free(c->name);
    free(c->patronymic);
    if (c->transactions) {
        for (int i = 0; i < c->transaction_count; i++) {
            free(c->transactions[i]);
        }
        free(c->transactions);
    }
    free(c);
}
