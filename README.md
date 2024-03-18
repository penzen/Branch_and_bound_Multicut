# Branch_and_bound_Multicut
The multicut problem is a fundamental combinatorial optimization problem with applications in areas such as computer vision and machine learning.  Given an undirected graph with weighted edges, the goal is to partition the graph into components by removing edges, while minimising the total cost of the removed edges or maximising the sum of the edges in the partition. The project follows the description of the latter. 
In the project, we are working with complete graphs, meaning each node is connected to its subsequent node. 
This project aims to explore a purely combinatorial branch-and-bound algorithm for solving the multicut problem. In contrast to ILP-based methods, this algorithm will not rely on linear programming, offering potential advantages:
Faster Exploration: The search tree can be traversed more quickly without the overhead of solving linear programs at each node.
Structural Exploitation: The algorithm can directly leverage the specific properties of the multicut problem, such as edge contractions.
Persistence Integration: Techniques to detect persistences (edges that must be included or excluded in any optimal solution) can be easily incorporated.
The primary tradeoff of a combinatorial approach is potentially weaker lower bounds compared to those obtained through linear programming relaxations. To further explore the bounds, we have calculated the bounds in three  different ways as it will be seen in the testing. 

