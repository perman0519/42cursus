#pragma once
#include "Position.hpp"
#include "Statistic.hpp"
#include "Shovel_t.hpp"
#include "Tool.hpp"
#include <string>
#include <vector>
// #include "Workshop.hpp"
class Workshop;

class Worker {
    string      name;
    Position_t  coordonnee; // coordonnee는 프랑스어로 좌표를 의미
    Statistic_t stat;
    Shovel_t    *shovel;
    Tool        *tool;
    vector<Workshop *> workshops;

public:
    Worker(string name = "", int x = 0, int y = 0, int z = 0, int level = 0, int exp = 0) : name(name), coordonnee(x, y, z), stat(level, exp), shovel(NULL), tool(NULL) {
        cout << this->name << ": Worker Constructor called." << endl;
    }
    ~Worker() {
        cout << this->name << ": Worker Destructor called." << endl;
    }

    bool equip_shovel(Shovel_t *shovel) {
        cout << this->name << ": Shovel equipped." << endl;
        this->shovel = shovel;
        shovel->setWorker(this);
        return true;
    }

    Shovel_t *unequip_shovel() {
        if (shovel == NULL) {
            cout << this->name << ": Shovel is null." << endl;
            return NULL;
        }
        Shovel_t *ret = shovel;
        shovel = NULL;
        ret->removeWorker();
        cout << this->name << ": Shovel unequipped." << endl;
        return ret;
    }

    bool equip_tool(Tool *tool) {
        cout << this->name << ": Tool equipped." << endl;
        if (this->tool != NULL) {
            this->tool->removeWorker();
        }
        tool->removeWorker();
        tool->setWorker(this);
        this->tool = tool;
        return true;
    }

    Tool *unequip_tool() {
        if (tool == NULL) {
            cout << this->name << ": Tool is null." << endl;
            return NULL;
        }
        Tool *ret = this->tool;
        tool = NULL;
        ret->removeWorker();
        cout << this->name << ": Tool unequipped." << endl;
        return ret;
    }

    void work() {
        if (workshops.empty()) {
            cout << this->name << ": Worker is not in any workshop." << endl;
            return;
        }
        if (tool == NULL) {
            cout << this->name << ": Worker has no tool." << endl;
            return;
        }
        cout << this->name << ": Worker is working." << endl;
        tool->use();
    }

    void addWorkshop(Workshop *workshop) {
        workshops.push_back(workshop);
    }

    void removeWorkshop(Workshop *workshop) {
        for (size_t i = 0; i < workshops.size(); i++) {
            if (workshops[i] == workshop) {
                workshops.erase(workshops.begin() + i);
                break;
            }
        }
    }

    string getName() {
        return this->name;
    }
};