// C++ program to represent undirected and weighted graph
// using STL. The program basically prints adjacency list
// representation of graph
#include <bits/stdc++.h>
using namespace std;

// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
									int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int,int> > adj[], int V)
{
	int v, w;
	for (int u = 0; u < V; u++)
	{
		cout << "Node " << u << " makes an edge with \n";
		for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
		{
			v = it->first;
			w = it->second;
			cout << "\tNode " << v << " with edge weight ="
				<< w << "\n";
		}
		cout << "\n";
	}
}

void prtspecifc(vector<pair<int,int>> adj[], int index){

int x; 
int y;
cout<<"\nPrininting spefic index of "<< index; 
for(auto id = adj[index].begin();id != adj[index].end();id++)
{
	x = id->first;
	y = id->second;
	cout<<"\n" <<"The node is: " << x <<"\nThe weights are: " << y;
}}
// how to return an array 
//return the updated graph
void remove_edge(vector<pair<int,int>> adj[],int n1,int n2){
/*
 remove the edge between them
 have to be done on both the vertexes 
 also have to find a specifc value 
 we need both indexes as it's stored in  both sides of the variables. 
 can possible be done in one loop 
*/
for(auto it = adj[n1].begin(); it != adj[n1].end();it++){
/*
we need to find the node that we need to delete so, the itteration should stop at the node we want to delete.
remember the node B has a variiety of the nodes, so we need to find the specific node that need to be deleted
let's see if we can delete one edge first. 
*/
int x = it->first;

if(x == n2){ 
cout<<"\nNow about the delete the data: "<< x;
adj[n1].erase(it);
prtspecifc(adj,n1); 
break; 
}}}



void remove_edge2(vector<pair<int,int>> adj[],int A,int B)
{
	int one = 0;
	int two = 0;
	int x = 0;
    int y = 0; //not nesseary 
	if(adj[A].size() > adj[B].size())
	{
		one = A; 
		two = B; 
		int x = B; // the number we want to remove
        int y = A; 
	}
	else{
		one = B; 
		two = A; 
		int x = A; // the number we want to remove
        int y = B; 
	}
    auto itwo = adj[two].begin();

	for(auto id = adj[one].begin();id != adj[one].end();id++){ // we have the size that we need now 
     // now we have the size 
	 // two second one is the smaller one 	 
	 // 
	 if( itwo != adj[two].end()){
		 int p = itwo->first; // now converted to an int   
		 if( p == y){ //y is associated with two
		 adj->erase(itwo);}
		itwo++; // keeps going unitl the target is found
		 }
	int fone = id->first;

	if(fone = x){
		adj->erase(id);
		// have to find a good place to break
	}	
}}
	
int main()
{
  
	int V = 6;
	vector<pair<int, int> > adj[V];
	addEdge(adj, 1, 2, 10); 
	addEdge(adj, 1, 5, 20);
	addEdge(adj, 2, 3, 30);
	addEdge(adj, 2, 4, 40);
	addEdge(adj, 2, 5, 50);
	addEdge(adj, 3, 4, 60);
	addEdge(adj, 4, 5, 70);
	addEdge(adj, 4, 1, 30);
	addEdge(adj, 5, 3,-20);
	
	cout<< "\n" <<"The size of the vertex 2 is : "<<adj[2].size() <<"\n";
	remove_edge(adj,2,4);
	cout<< "\n" <<"After the removeal of the edges the size now is  : "<<adj[2].size() <<"\n";
	//printGraph( adj,  V);

	for(int x = 0; x < V; x++)
	{
		adj[x].clear();
		//delete adj[x];
	}
	
	
	
	return 0;
}


//version control 
void multicut(){




}
