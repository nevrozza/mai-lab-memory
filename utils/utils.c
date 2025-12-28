//
// Created by nevrozq on 25.12.2025.
//

#include <stdio.h>
#include <stdlib.h>

void error(char msg[]) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void memory_error() {
    error("MemoryError");
}
