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

long long timestamp(const int day, const int month, const int year, const int hour, const int minute,
                    const int second) {
    return
            year * 10000000000LL +
            month * 100000000LL +
            day * 1000000LL +
            hour * 10000LL +
            minute * 100LL +
            second;
}
