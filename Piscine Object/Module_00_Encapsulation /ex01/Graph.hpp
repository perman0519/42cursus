#pragma once

#include "Vector2.hpp"
#include <vector>
using namespace std;
class Graph {
    int _size;
    vector<Vector2> _vertices;

public:
    Graph(int size = 0);
    ~Graph();

    void add(int x, int y);
    void remove(int x, int y);
    void show() const;
};