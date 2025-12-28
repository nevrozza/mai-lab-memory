//
// Created by nevrozq on 28.12.2025.
//

#ifndef SOLUTION_H
#define SOLUTION_H
#include <stdio.h>

#include "../vector/vector.h"

vector *read_clients_from_file(FILE *file);

vector *get_solution_clients(vector *clients, char start[15], char end[15]);


#endif //SOLUTION_H
