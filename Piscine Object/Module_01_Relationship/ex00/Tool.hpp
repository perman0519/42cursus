#pragma once

// #include "Worker.hpp"

class Worker;

class Tool {
protected:
    int numberOfUses;
    Worker *worker;
public:
    Tool (int numberOfUses = 0);
    virtual ~Tool();
    void setWorker(Worker *worker);
    void removeWorker();
    bool isWorker();
    virtual void use() = 0; // 순수 가상 함수
};