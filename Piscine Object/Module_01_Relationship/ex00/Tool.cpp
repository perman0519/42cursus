#include "Tool.hpp"
#include "Worker.hpp"
#include <iostream>
using namespace std;

Tool::Tool (int numberOfUses) : numberOfUses(numberOfUses), worker(NULL) {
    cout << "Tool Constructor called." << endl;
}

Tool::~Tool() {
    cout << "Tool Destructor called." << endl;
}

void Tool::setWorker(Worker *worker) {
    cout << "Tool: Worker " << worker->getName() << " is set." << endl;
    this->worker = worker;
}

void Tool::removeWorker() {
    if (this->worker == NULL) {
        cout << "Tool: Worker is null." << endl;
        return;
    }
    Worker *worker = this->worker;
    this->worker = NULL;
    worker->unequip_tool();
    cout << "Tool: Worker " << worker->getName() << " is removed." << endl;
}

bool Tool::isWorker() {
    return this->worker != NULL;
}