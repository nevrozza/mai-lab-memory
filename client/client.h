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

typedef struct {
    int id;
    char *surname;
    char *name;
    char *patronymic;
    int transaction_count;
    Transaction **transactions;
} Client;

#endif //CLIENT_H
