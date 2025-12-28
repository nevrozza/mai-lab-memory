//
// Created by nevrozq on 28.12.2025.
//

#include <stdio.h>

#include "solution/solution.h"
#include "utils/utils.h"
#include "vector/vector.h"


int main() {
    char start_time[] = "01.12.20 05:00:00"; //"01.12.20 05:00:00"
    char end_time[] = "01.12.26 05:00:00"; //"01.12.26 05:00:00"
    // Найти ФИО и ID клиентов с минимальным количеством расходных транзакций в заданный период времени (время с .. по..)
    setbuf(stdout, NULL);
    // '../' т.к. запускается из cmake-build
    FILE *file = fopen("../client_log", "r");


    if (file == NULL) {
        error("Ошибка при открытии файла");
    }

    vector *clients = read_clients_from_file(file);

    printf("Всего клиентов: %d\n", size(clients));
    vector *ans = get_solution_clients(clients, start_time, end_time);
    printf("Подходящих клиентов: %d\n\n", size(ans));
    for (int i = 0; i < size(ans); i++) {
        Client* client = get(ans, i);
        printf("%s %s %s [pid: %d]\n", client->surname, client->name, client->middle_name, client->pid);
    }


    fclose(file);


    return 0;
}
