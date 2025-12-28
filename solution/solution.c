//
// Created by nevrozq on 28.12.2025.
//

#include "solution.h"

#include <stdio.h>
#include <string.h>

Transaction *parse_transaction_line(char line[256]) {
    int day, month, year;
    int hour, minute, second;
    char transaction_type[7];
    double amount;
    sscanf(line, "%d.%d.%d\t%d:%d:%d\t%6s\t%lf", &day, &month, &year, &hour, &minute, &second, transaction_type,
           &amount);

    bool is_profit = strcmp(transaction_type, "Приход");

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
        char surname[50], name[50], middle_name[50];
        sscanf(line, "%s %s %s", surname, name, middle_name);
        fgets(line, sizeof(line), file);
        int transaction_count;
        sscanf(line, "%d", &transaction_count);

        Transaction *transactions[transaction_count];

        for (int i = 0; i < transaction_count; i++) {
            fgets(line, sizeof(line), file);
            transactions[i] = parse_transaction_line(line);
        }
        Client *client = create_client(pid, surname, name, middle_name, transaction_count, transactions);
        push(clients, client);
    }

    return clients;
}
