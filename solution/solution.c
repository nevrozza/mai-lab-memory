//
// Created by nevrozq on 28.12.2025.
//

#include "solution.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/utils.h"

Transaction *parse_transaction_line(char line[256]) {
    int day, month, year;
    int hour, minute, second;
    char transaction_type[7];
    double amount;
    sscanf(line, "%d.%d.%d\t%d:%d:%d\t%6s\t%lf", &day, &month, &year, &hour, &minute, &second, transaction_type,
           &amount);

    bool is_profit = strcmp(transaction_type, "Приход") == 0;

    return create_transaction(
        day, month, year,
        hour, minute, second,
        is_profit, amount
    );
}

vector *read_clients_from_file(FILE *file) {
    vector *clients = init();
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        int pid;
        sscanf(line, "%d", &pid);

        fgets(line, sizeof(line), file);
        char *surname = malloc(50 * sizeof(char)), *name = malloc(50 * sizeof(char)), *middle_name = malloc(
            50 * sizeof(char));
        sscanf(line, "%s %s %s", surname, name, middle_name);

        fgets(line, sizeof(line), file);
        int transaction_count;
        sscanf(line, "%d", &transaction_count);
        Transaction **transactions = malloc(transaction_count * sizeof(Transaction));
        for (int i = 0; i < transaction_count; i++) {
            fgets(line, sizeof(line), file);
            Transaction *transaction = parse_transaction_line(line);
            transactions[i] = transaction;
        }
        Client *client = create_client(pid, surname, name, middle_name, transaction_count, transactions);
        push(clients, client);
    }

    return clients;
}

long long get_timestamp_from_date_str(char date_str[15]) {
    int day, month, year;
    int hour, minute, second;
    sscanf(date_str, "%d.%d.%d\t%d:%d:%d\t", &day, &month, &year, &hour, &minute, &second);
    return timestamp(day, month, year, hour, minute, second);
}

vector *get_solution_clients(
    vector *clients,
    char start[15], // 28.12.25 05:00:00
    char end[15]
) {
    vector *ans = init();
    long long minimal_spent = INT64_MAX;

    long long start_timestamp = get_timestamp_from_date_str(start);
    long long end_timestamp = get_timestamp_from_date_str(end);

    // Найти ФИО и ID клиентов с минимальным количеством расходных транзакций в заданный период времени (время с .. по..)
    for (int i = 0; i < size(clients); i++) {
        Client *client = get(clients, i);
        long long spent = 0;

        for (int j = 0; j < client->transaction_count; j++) {
            const Transaction *transaction = client->transactions[j];
            if (!(transaction->is_profit) && start_timestamp <= transaction->timestamp && transaction->timestamp <=
                end_timestamp) {
                spent += 1;
            }
        }

        if (minimal_spent > spent) {
            not_deep_clear(ans);
            minimal_spent = spent;
            push(ans, client);
        } else if (minimal_spent == spent) {
            push(ans, client);
        }
    }
    printf("Минимальное количество расходных транзакций: %lld\n", minimal_spent);
    return ans;
}
