#include "Graph.hpp"
using namespace std;

int main() {
    Graph graph(5);
    graph.add(0, 0);
    graph.add(2, 4);
    graph.add(4, 2);
    graph.add(2, 2);

    graph.show();

    graph.remove(2, 4);
    graph.remove(4, 2);
    graph.show();
}