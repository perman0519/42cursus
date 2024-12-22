#include <iostream>
#include "Graph.hpp"
#include <algorithm>
using namespace std;

Graph::Graph(int size) : _size(size) {}
Graph::~Graph() {}

void Graph::add(int x, int y) {
    if (x < 0 || y < 0 || x >= _size || y >= _size) {
        cout << "Vertex (" << x << ", " << y << ") is out of bounds" << endl;
        return;
    }
    Vector2 v2(x, y);
    _vertices.push_back(v2);
}

void Graph::remove(int x, int y) {
    if (x < 0 || y < 0 || x >= _size || y >= _size) {
        cout << "Vector2 (" << x << ", " << y << ") is out of bounds" << endl;
        return;
    }
    Vector2 v2(x, y);
    for (vector<Vector2>::iterator it = _vertices.begin(); it != _vertices.end(); it++) {
        if (it->getX() == x && it->getY() == y) {
            _vertices.erase(it);
            return;
        }
    }
}

void Graph::show() const {
    for (int i = _size; i >= 0; i--) {
        cout << i << " ";
        for (int j = 0; j <= _size; j++) {
            if (find(_vertices.begin(), _vertices.end(), Vector2(j, i)) != _vertices.end()) {
                cout << "X";
            } else {
                cout << ".";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << "  ";
    for (int i = 0; i <= _size; i++) {
        cout << i << " ";
    }
    cout << endl;
}