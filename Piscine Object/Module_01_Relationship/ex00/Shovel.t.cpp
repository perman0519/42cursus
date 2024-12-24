#include "Shovel_t.hpp"
#include "Worker.hpp"

Shovel_s::Shovel_s(int numberOfUses) : numberOfUses(numberOfUses), worker(NULL) {
    cout << "Shovel Constructor called." << endl;
}

Shovel_s::~Shovel_s() {
    cout << "Shovel Destructor called." << endl;
}

void Shovel_s::setWorker(Worker *worker) {
    cout << "Shovel: Worker " << worker->getName() << " is set." << endl;
    this->worker = worker;
}

void Shovel_s::removeWorker() {
    if (this->worker == NULL) {
        cout << "Shovel: Worker is null." << endl;
        return;
    }
    Worker *worker = this->worker;
    this->worker = NULL;
    worker->unequip_shovel();
    cout << "Shovel: Worker " << worker->getName() << " is removed." << endl;
}