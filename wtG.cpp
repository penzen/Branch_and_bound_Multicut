#include <iostream>
#include<stdio.h>
#include <vector>
#include<list>
using namespace std;



void add_edge( int store[], int start, int end,int wth){

// need a way to store it, 

}

int main(){


list<int> num[10];
num[0].push_front(10);

list<pair<int,int>> number[10]; 
number[0].push_front(make_pair(22,33));
int d = 10;
// cout << "Trail: "<< num[0] << endl;

    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int source;
  int destination;
  int weight;
};

class Graph {
private:
       vector<vector<Edge>> adjacencyList;

public:
  Graph(int numVertices) {
    this->adjacencyList.resize(numVertices);
  }

  void addEdge(int source, int destination, int weight) {
    if (source < 0 || source >= adjacencyList.size() ||
        destination < 0 || destination >= adjacencyList.size()) {
      return;
    }

    adjacencyList[source].push_back({source, destination, weight});
  }

  void removeEdge(int source, int destination) {
    if (source < 0 || source >= adjacencyList.size() ||
        destination < 0 || destination >= adjacencyList.size()) {
      return;
    }

    auto edgeIterator = adjacencyList[source].begin();
    while (edgeIterator != adjacencyList[source].end()) {
      if (edgeIterator->destination == destination) {
        adjacencyList[source].erase(edgeIterator);
        break;
      }
      edgeIterator++;
    }
  }

  bool existsEdge(int source, int destination) {
    if (source < 0 || source >= adjacencyList.size() ||
        destination < 0 || destination >= adjacencyList.size()) {
      return false;
    }

    for (auto edge : adjacencyList[source]) {
      if (edge.destination == destination) {
        return true;
      }
    }

    return false;
  }

  void printGraph() {
    for (int source = 0; source < adjacencyList.size(); source++) {
       cout << "Vertex " << source << ":";
      for (auto edge : adjacencyList[source]) {
         cout << " -> " << edge.destination << "(" << edge.weight << ")";
      }
       cout << ::endl;
    }
  }
};

int main() {
  Graph graph(5);
  graph.addEdge(0, 1, 10);
  graph.addEdge(0, 4, 15);
  graph.addEdge(1, 2, 20);
  graph.addEdge(2, 3, 30);
  graph.addEdge(4, 3, 25);

  cout << "Graph:" << endl;
  graph.printGraph();

  cout << "Edge exists (0, 1): " << graph.existsEdge(0, 1) << endl;
  cout << "Edge exists (3, 4): " << graph.existsEdge(3, 4) << endl;

  graph.removeEdge(1, 2);

  cout << "Graph after removing edge (1, 2)" << endl;
  graph.printGraph();

  return 0;
}*/

