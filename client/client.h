//
// Created by nevrozq on 28.12.2025.
//

#ifndef CLIENT_H
#define CLIENT_H
#include <stdbool.h>

typedef struct {
    int day, month, year;
    int hour, minute, second;
    bool is_profit;
    double amount;
} Transaction;

Transaction *create_transaction(int day, int month, int year, int hour, int minute, int second,
                                bool is_profit, double amount);

typedef struct {
    int pid;
    char *surname;
    char *name;
    char *middle_name;
    int transaction_count;
    Transaction **transactions;
} Client;

Client *create_client(int pid, char *surname, char *name, char *middle_name,
                      int transaction_count, Transaction **transactions);

void free_client(Client *c);

#endif //CLIENT_H
