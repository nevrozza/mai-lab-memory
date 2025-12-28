//
// Created by nevrozq on 28.12.2025.
//
#include <stdio.h>
#include <stdlib.h>

#include "../utils/utils.h"
#include "../vector/vector.h"

Transaction *create_transaction(int day, int month, int year, int hour, int minute, int second, bool is_profit,
                                double amount) {
    Transaction *transaction = malloc(sizeof(Transaction));
    if (transaction == NULL) {
        memory_error();
        return NULL;
    }
    transaction->timestamp=timestamp(day, month, year, hour, minute, second);

    transaction->is_profit = is_profit;
    transaction->amount = amount;
    return transaction;
}

Client *create_client(const int pid, char *surname, char *name, char *middle_name, int transaction_count,
                      Transaction **transactions) {
    Client *client = malloc(sizeof(Client));
    if (client == NULL) {
        memory_error();
        return NULL;
    }
    client->pid = pid;
    client->surname = surname;
    client->name = name;
    client->middle_name = middle_name;
    client->transaction_count = transaction_count;
    client->transactions = transactions;
    return client;
}

void free_client(Client *c) {
    if (!c) return;
    free(c->surname);
    free(c->name);
    free(c->middle_name);
    if (c->transactions) {
        for (int i = 0; i < c->transaction_count; i++) {
            free(c->transactions[i]);
        }
        free(c->transactions);
    }
    free(c);
}
