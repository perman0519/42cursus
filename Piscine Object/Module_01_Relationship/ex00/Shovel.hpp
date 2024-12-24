#pragma once
#include <iostream>
#include "Tool.hpp"
using namespace std;

class Worker;

class Shovel : public Tool {

public:
    Shovel(int numberOfUses = 0) : Tool(numberOfUses) {
        cout << "Shovel Constructor called." << endl;
    }

    ~Shovel() {
        cout << "Shovel Destructor called." << endl;
    }

    void use() {
        cout << "Shovel used." << endl;
        this->numberOfUses++;
    }
};