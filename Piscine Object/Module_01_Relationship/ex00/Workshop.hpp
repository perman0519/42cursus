#pragma once
#include <iostream>
#include <vector>
#include "Worker.hpp"
using namespace std;

class Workshop {
    vector<Worker *> workers;

public:
    Workshop() {
        cout << "Workshop Constructor called." << endl;
    }
    ~Workshop() {
        cout << "Workshop Destructor called." << endl;
    }

    void addWorker(Worker *worker) {
        workers.push_back(worker);
        worker->addWorkshop(this);
    }

    void removeWorker(Worker *worker) {
        for (size_t i = 0; i < workers.size(); i++) {
            if (workers[i] == worker) {
                workers.erase(workers.begin() + i);
                worker->removeWorkshop(this);
                break;
            }
        }
    }

    void excuteWorkDay() {
        for (size_t i = 0; i < workers.size(); i++) {
            cout << "Workshop: Worker " << workers[i]->getName() << " is working." << endl;
            workers[i]->work();
        }
    }
};