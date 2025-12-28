//
// Created by nevrozq on 28.12.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "solution/solution.h"
#include "utils/utils.h"
#include "vector/vector.h"


int main() {
    // Найти ФИО и ID клиентов с минимальным количеством расходных транзакций в заданный период времени (время с .. по..)

    // '../' т.к. запускается из cmake-build
    FILE *file = fopen("../client_log", "r");

    if (file == NULL) {
        error("Ошибка при открытии файла");
    }

    vector *clients = read_clients_from_file(file);
    printf("Всего клиентов: %d", size(clients));

    fclose(file);


    return 0;
}
