#pragma once
#include <iostream>
using namespace std;

typedef struct Statistic_s {
    int level;
    int exp;

    Statistic_s(int level = 0, int exp = 0) : level(level), exp(exp) {
        cout << "Statistic Constructor called." << endl;
    }
    ~Statistic_s() {
        cout << "Statistic Destructor called." << endl;
    }
} Statistic_t;

