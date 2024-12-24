#pragma once

class Worker;
typedef struct Shovel_s {
    int numberOfUses;
    Worker *worker;

    Shovel_s(int numberOfUses = 0);
    ~Shovel_s();
    void setWorker(Worker *worker);
    void removeWorker();
} Shovel_t;