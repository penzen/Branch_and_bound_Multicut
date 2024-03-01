class ConstraintPropagation {

  void propagate(multimap<int,pair<int,int>> adj) {
    queue<pair<int,int>> selectedEdges;
    queue<pair<int,int> deselectedEdges;

    // Initialize queues based on initial edge values
    for (int i = 0; i < adj.size(); ++i) {
      for (int j = 0; j < edges[i].size(); ++j) {
        if (edges[i][j] == 1) { //fixed edges 
          selectedEdges.push({i, j});
        } else {
          deselectedEdges.push({i, j});
        }
      }
    }

    // Process selected edges
    while (!selectedEdges.empty()) {
      Edge edge = selectedEdges.front();
      selectedEdges.pop();

      for (int k = 0; k < edges.size(); ++k) {
        // Selection rule
        if (edges[edge.i][k] == 1 && edges[edge.j][k] != 1) {
          edges[edge.j][k] = 1;
          selectedEdges.push({edge.j, k});
        }

        // Deselection rule
        if (edges[edge.i][k] != 1 && edges[edge.j][k] != 1) {
          edges[edge.j][k] = 0;
          deselectedEdges.push({edge.j, k});
        }
      }
    }

    // Process deselected edges
    while (!deselectedEdges.empty()) {
      Edge edge = deselectedEdges.front();
      deselectedEdges.pop();

      for (int k = 0; k < edges.size(); ++k) {
        // Deselection rule
        if (edges[edge.i][k] != 1 && edges[edge.j][k] != 1) {
          edges[edge.j][k] = 0;
          deselectedEdges.push({edge.j, k});
        }
      }
    }
  }
};