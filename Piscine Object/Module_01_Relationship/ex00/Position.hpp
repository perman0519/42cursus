#pragma once
#include <iostream>
using namespace std;
typedef struct Position_s {
    int x;
    int y;
    int z;

    Position_s(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {
        cout << "Position Constructor called." << endl;
    }
    ~Position_s() {
        cout << "Position Destructor called." << endl;
    }
} Position_t;

