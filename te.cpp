#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
  vector<bool> cut;
  int numCuts;
  int weight;

  Node(const vector<bool>& cut, int numCuts, int weight) {
    this->cut = cut;
    this->numCuts = numCuts;
    this->weight = weight;
  }

  bool isLeaf() {
    return numCuts == INT_MAX;
  }
};

class MultiCut {
public:
  int n;
  vector<vector<int>> adj;
  vector<Edge> edges;
  int numVertices;
  int numCuts;
  int weight;

  MultiCut(int n) {
    this->n = n;
    adj.resize(n);
  }

  void addEdge(int u, int v, int weight) {
    edges.push_back({u, v, weight});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void solve() {
    Node root(vector<bool>(n), 0, 0);
    numVertices = n;

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(root);

    while (!pq.empty()) {
      Node node = pq.top();
      pq.pop();

      if (node.isLeaf()) {
        if (node.weight < weight) {
          weight = node.weight;
        }
      } else {
        for (int i = 0; i < numVertices; i++) {
          if (!node.cut[i]) {
            vector<bool> newCut = node.cut;
            newCut[i] = true;
            int newNumCuts = node.numCuts + 1;
            int newWeight = node.weight + getWeight(i);

            Node newNode(newCut, newNumCuts, newWeight);
            pq.push(newNode);
          }
        }
      }
    }

    cout << "Found a minimum-weight multicut with " << numCuts << " cuts and total weight " << weight << endl;
  }

private:
  int getWeight(int u) {
    int weight = 0;
    for (int v : adj[u]) {
      if (!cutContainsVertex(u, v)) {
        weight += edges[findEdge(u, v)].weight;
      }
    }
    return weight;
  }

  bool cutContainsVertex(int u, int v) {
    if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) {
      return false;
    }

    return cut[u] && cut[v];
  }

  int findEdge(int u, int v) {
    for (int i = 0; i < edges.size(); i++) {
      if (edges[i].u == u && edges[i].v == v) {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  int n = 5;
  MultiCut mc(n);

  mc.addEdge(0, 1, 1);
  mc.addEdge(1, 2, 2);
  mc.addEdge(2, 3, 3);
  mc.addEdge(0, 3, 4);

  mc.solve();

  return 0;
}