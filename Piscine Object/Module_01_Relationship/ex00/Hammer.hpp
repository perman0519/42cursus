#pragma once
#include <iostream>
#include "Tool.hpp"
using namespace std;

class Hammer : public Tool {

public:
    Hammer(int numberOfUses = 0) : Tool(numberOfUses) {
        cout << "Hammer Constructor called." << endl;
    }

    ~Hammer() {
        cout << "Hammer Destructor called." << endl;
    }

    void use() {
        cout << "Hammer used." << endl;
        this->numberOfUses++;
    }
};