#include <iostream>
#include<stdio.h>
#include <vector>
#include<list>
#include <algorithm>
#include <map>
#include <string>
#include<queue>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

/*
Solution Tracking: The tulip struct is used to keep track of:
jyon: Stores the edges representing nodes that have been joined together.
jcut: Stores the edges that have been cut.
part: Stores partially constructed partitions.
pcut: Stores temporarily added cut edges during exploration.
bd_ref: Gives the outcome and is used for refrence after recursion
bo, drac: Aid in the bounding process and algorithm flow.
*/

struct tulip{
multimap<int,pair<int,int>> jyon; 
multimap<int,pair<int,int>> jcut;
multimap<int,pair<int,int>> part;
multimap<int,pair<int,int>> pcut;
multimap<int,pair<int,int>> bd_ref;
int drac = 0; 
int bo = 0;};

vector<std::vector<int>> readGraphData(const string& filename) {
     ifstream file(filename);
     vector<std::vector<int>> graphData; 
    if (file.is_open()) {
         string line;

        // Get the total number of vertices (nodes)
         getline(file, line);  
        // Ignore this for now, unless needed for other processing

        // Read and store each line of numbers
        while (getline(file, line)) {
             vector<int> lineData; 
             istringstream iss(line);
            int number;

            while (iss >> number) {
                lineData.push_back(number);
            }

            graphData.push_back(lineData); 
        }
        file.close();
    } else {
        cout << "Error opening file." <<endl;
    }

    return graphData;
}


multimap<int,pair<int,int>> addEdge(multimap<int,pair<int,int>> adj,int u,int wt,int v )
{
	  adj.insert(make_pair(u ,make_pair(wt,v))); 
    adj.insert(make_pair(v,make_pair(wt,u)));
    return adj;

}
void printGraph(multimap<int, pair<int, int>> adj)
{
multimap<int, pair<int, int>>::iterator it = adj.begin();
while (it != adj.end()) { 
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;

  cout << "The node: "<< it->first <<"--- "<<  wt <<  "--->connected node:  " <<node<< "\n";
  it++; 
}}




// prints specific index in the graph 
void prtspecifc(multimap<int, pair<int, int>> adj, int rm){
multimap<int, pair<int, int>>::iterator it = adj.find(rm);
while (it != adj.end()) { 
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;
  cout << "The node: "<< it->first << "----"<< wt << " --->connected node:  " <<node<< "\n";
  it++; 
  if(it->first != rm){
    break; 
  }}}


multimap<int, pair<int, int>> remove_edge_2(multimap<int, pair<int, int>> adj, int a, int b){
  multimap<int, pair<int, int>>::iterator it = adj.find(a);
  multimap<int, pair<int, int>>::iterator sit = adj.find(b);
  pair<int, int> value = it->second;
  pair<int, int> snd = sit->second;
  int node_one = value.second;
  int node_two = snd.second;
  bool fst = false; 
  bool nd = false; 

  for (int x = 0; x < adj.size(); ++x) {

     value = it->second;
     node_one = value.second;
    if(node_one == b){ 
      fst = true;}
   if (fst == false){  
    ++it;}

    snd = sit->second;
    node_two = snd.second;
   if(node_two == a){ 
      nd = true;}
   if (nd == false){  
    ++sit;}

   if(fst == true && nd == true){
    adj.erase(sit);
    adj.erase(it);
    break;
   }
}
 return adj;
}


//join: Implements the core logic of merging two nodes, updating the graph, and tracking joined information.
multimap<int,pair<int,int>> join(multimap<int,pair<int,int>> adj,int one, int two) {

// we can use 0 as the index to keep the refrence
//find the nodes and then combine them 
// remember this is a completed graph so each node has to be combined and also it's 
//can be done in the same itteration. 
//directly add the node to adj. 
//we can have a refrence to 0

  multimap<int, pair<int, int>>::iterator it = adj.find(one);
  multimap<int, pair<int, int>>::iterator sit = adj.find(two);
  vector<pair<int, int>> alpha;
  vector<pair<int, int>> beta;
  pair<int, int> n1 = it->second;
  pair<int, int> snd = sit->second;
  int combined = 100 + one + two;
  int ref = 0;

while (it != adj.end()) { 
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;
  alpha.push_back({wt,node});
  it++; 
  if(it->first != one){
    break; 
  }}

while (sit != adj.end()) { 
 pair<int, int> value = sit->second;
  int wt = value.first;
  int node = value.second;
  beta.push_back({wt,node});
  sit++; 
  if(sit->first != two){
    break; 
  }}
 
 // this only works if are connected to the same component 
 // now that they are no connected to the same component it will not be joined

for(int x = 0; x < alpha.size(); x++){
if(alpha[x].second == two){
  adj = addEdge(adj,combined,alpha[x].first,0);
  adj = remove_edge_2(adj,one,two);
}
for(int y = 0; y < beta.size(); y++){
  if(alpha[x].second == beta[y].second){// it's not talking into account that it it's cut there could be edges that are not in one 
    if(beta[y].second == one){
      continue;
    }else{
        adj = addEdge(adj,combined,alpha[x].first + beta[y].first,beta[y].second); 
        adj = remove_edge_2(adj,one,beta[y].second);
        adj = remove_edge_2(adj,two,beta[y].second);
        break;
        }}}}

 
 // this for the cut edges could be put into a new method 
 
multimap<int, pair<int, int>>::iterator rerun = adj.find(one);
multimap<int, pair<int, int>>::iterator tst = adj.find(two);

 //if(it->first == )



// kind of works like stacks where everything is reset as in the it and sit; 

 while(rerun != adj.end() ){
   rerun = adj.find(one);
   if(rerun->first == one){
        int rewe = rerun->second.second;
     adj = addEdge(adj,combined,rerun->second.first,rerun->second.second);
     adj = remove_edge_2(adj,one,rewe); 
  }else{
    break;}}

while(tst != adj.end() ){
   tst = adj.find(two);
   if(tst->first == two){
        int rewe = tst->second.second;
     adj = addEdge(adj,combined,tst->second.first,tst->second.second);
    // cout<<"sit second : "<<sit->second.second<<endl; 
     adj = remove_edge_2(adj,two,rewe);
  }else{
    break;}} 

 
return adj;
}


//checkcut: Determines if an edge can be joined by ensuring it hasn't previously been cut.
bool checkcut(multimap<int,pair<int,int>> cut,int a, int b){

 multimap<int, pair<int, int>>::iterator it = cut.find(a);
 multimap<int, pair<int, int>>::iterator update_one = cut.find(b);

 bool value = false;

if(cut.size() == 0){
  return true;
}

if(it->first == 0) 
 {
   cout<<"Cannot join with 0 "<<endl; 
  return false;
 }

 
 if(it->first == cut.size()) // means it does not exist 
 { 
  if(it->second.second > 5000){
  cout<<"Node: "<<a<<"---- join ---- "<<b<<endl; 
  cout<<"It does not exist condition: "<<it->first<<endl;
  return true;}} 


 // now we make sure that it is not in the cut 
while (it != cut.end()) { 
  pair<int, int> alpha = it->second;
  int node = alpha.second;
if(node == b){
  cout<<"It's been cut already so cannot join"<<endl;
  return value; 
  break;}
  it++; 
  if(it->first != a){ // if we reached here that would mean we did not find the value 
    cout<<"Node: "<<a<<"---- join ---- "<<b<<endl; 
     value = true ;  
    break; 
  }}
  return value;}



// count: A helper function to count the number of remaining edges in a graph excluding 0.
int count(multimap<int, pair<int, int>> adj){
int counter = 0;
multimap<int, pair<int, int>>::iterator it = adj.begin();
while (it != adj.end()) { 
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;

 if (it->first != 0 ) {
    if( node != 0){
    ++counter; }}
       it++;
  }
return counter; }


//inital_bounde:Adds all postive edges.
int inital_bounder(multimap<int,pair<int,int>> adj){
int cal = 0;
multimap<int, pair<int, int>>::iterator it = adj.begin();
for(int x = adj.size(); x > 0; x-=2){
  it = adj.begin();
  if(it->second.first >= 0 ){
  cal += it->second.first;
  adj = remove_edge_2(adj, it->first,it->second.second); 
 }}
  return cal;
}

//bounder: Adds all edges if they can be joined or are joined 
int bounder(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut){
int zone = 0;
multimap<int, pair<int, int>>::iterator it = adj.begin();
for(int y = adj.size(); y > 0; y-=2){
  it = adj.begin();
if(it->first == 0){
  zone+= it->second.first;
}else{
    if(checkcut(cut, it->first,it->second.second)  == true){
    zone+= it->second.first;
    cout<<"VALue of zone after adding: "<<zone<<endl;
}}
adj = remove_edge_2(adj, it->first,it->second.second); 
 }return zone;}


//frcut:Adds all postive edges if they can be joined or are joined 
int frcut(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut){
int zone = 0;
multimap<int, pair<int, int>>::iterator it = adj.begin();
for(int y = adj.size(); y > 0; y-=2){
  it = adj.begin();
if(it->first == 0){
  zone+= it->second.first;
}else{
    if(checkcut(cut, it->first,it->second.second)  == true){
      if(it->second.first > 0){
        zone+= it->second.first;}
    
    
}}
adj = remove_edge_2(adj, it->first,it->second.second); 
 }
 cout<<"VALue of bound after adding: "<<zone<<endl;
 return zone;}

//nd_bounder: Calculates the bound using the current node, can only if theybe joined or are joined 
int nd_bounder(multimap<int,pair<int,int>> adj,int node,multimap<int,pair<int,int>> cut){
int zone = 0;
multimap<int, pair<int, int>>::iterator it = adj.begin();
// add 0 then find the node we want;
for(int y = adj.size(); y > 0; y-=2){
  it = adj.begin();
if(it->first == 0){
  zone+= it->second.first;
}else{
    it = adj.find(node);
    if(it->first != node){
      break; 
    }
    if(checkcut(cut, it->first,it->second.second)  == true){
    zone+= it->second.first;
    cout<<"VALue of zone after adding: "<<zone<<endl;
}}
adj = remove_edge_2(adj, it->first,it->second.second);}
 
 return zone;}


/*
Base Case:If the graph is empty (all nodes joined or cut), or if a cut has removed all connections to the current node, 
it signals a terminaation for the recursion.

Branching: The algorithm branches into two possibilities for each edge connected to the current node:

Join: Join the current node with the node at the other end of the edge, effectively merging them into a cluster.

Cut: Cut the edge, separating the two nodes into (or maintaining them in) different clusters.

Bound: The code calculates bounds to estimate the best possible solution achievable in each branch.

Upper Bound (bo): Calculated using functions like inital_bounder and frcut. This estimates the maximum potential weight sum of a partition from the current state.

Lower Bound (lower): Represents the best solution found so far.
Pruning: If the upper bound of a particular branch is lower than the current best solution (lower bound)
that branch is pruned – it cannot lead to a better solution.

Recursion: The depth_search function calls itself recursively on both the "join" and "cut" branches
further exploring the solution space.

*/



tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound, int lower){
cout<<"-------------------------START-----------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;

if(one.drac == 0){ 
++one.drac; 
cout<<"It's in the first case"<<endl;
multimap<int, pair<int, int>>::iterator mit = adj.find(node);
pair<int,int> tep = mit->second; 
// join
tulip ken = one; 
int j = 100 + node + tep.second;
bound = inital_bounder(adj);
one = depth_search(join(adj,node,tep.second),one,j,bound,lower);
cout<<"After the join recrusion is fininshed in first "<<endl;
lower = one.bo;// this is lower bound before we go in the recrusion.
cout<<"  Bound: "<<one.bo<<endl;

//cut 
ken.pcut = addEdge(ken.pcut,node,0,tep.second);
ken = depth_search(remove_edge_2(adj,node,tep.second),ken,tep.second,bound,lower);
cout<<"It's returned here in the cut from first where everything is about to be returned. "<<endl;
if(ken.bo >= one.bo){ 
 cout<<"Returning from cut "<<endl;
 cout<< "Values ken.bo: "<<ken.bo<<endl;
  cout<< "Values one.bo: "<<one.bo<<endl;
  return ken;
}else{
  cout<<"Returning from join "<<endl;
  cout<< "Values ken.bo: "<<ken.bo<<endl;
  cout<< "Values one.bo: "<<one.bo<<endl;
  return one;}}


if(count(adj) == 0) // means we have gone through all the joins or cuts 
{ cout<<"Everrything is joined or cut"<<endl;
  one.jyon = adj;
  cout<<"Bound in the final one.bo: "<<one.bo<<endl;
  cout<<"Bound in the final lower: "<<lower<<endl;
  multimap<int, pair<int, int>>::iterator fd = adj.find(node);
  return one;} 

multimap<int, pair<int, int>>::iterator it = adj.find(node); 

 if ( it->first == adj.size()  ){ 
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{ one.jcut = adj;
  return one; }} // meaning the weight is empty


while(it != adj.end() ) // make sure the start node is not 0 and pointing to a valid node
{
  if(it->first != 0){
    if(it->second.second != 0){
      break;
    }}
  it++;}


int rl = it->second.second; //refrece for the case where there is only one connection left 
for(int x =0; x < adj.size(); x++){ 

pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;

if(x > 0){
  if (rl == ref.second){
 cout<<"It's in the condition where there is nothing else to itterate"<<endl;

  if (checkcut(one.pcut, it->first,it->second.second)){
    cout<<"The bool check is true "<<endl;
  } 
    one.bd_ref = adj;
    one.bo = bounder(adj,one.pcut);
    return one;
    break;
    // calculate the bound and return.
  }
}

if(ref.first != 0){ 
if(checkcut(one.pcut,it->first,ref.second) == true ){ 

cout<<"Value of it: "<<it->first<<endl;
multimap<int, pair<int, int>>::iterator detern = adj.find(ref.second);


if(detern->second.first == 0) //means it's been cut from everything 
{
  cout<<"It's in the condition where everything is cut"<<endl;
  continue;
}
else{ 

cout<<"==================== Join ==========================="<<endl;
tulip ken = one;
// join
one.jcut = one.pcut;// keep a refrecne that way we don't have to deal with the other one.
one.pcut = join(one.pcut,node,ref.second);
one.jyon = join(adj,node,ref.second);
one.bd_ref = one.jyon; /////////////////
int j = 100 + node + ref.second;

cout<<"The value of cut one.bo updating "<<one.bo<<endl;
 //one.bo = frcut(adj,one.pcut); //calculate the bound  
 one.bo = nd_bounder(one.jyon,j,one.pcut);
//one.bo = bounder(adj,one.pcut);

if(lower > one.bo && lower > 0){
  cout<<"Condition where the lower bound is greater then upper "<<one.bo <<endl; 
  cout<<"Lower: "<<lower<<endl;
  one = ken; // we update it back to the previous setting.
  return one; 
  break;
}

cout<<"Value of bounder before going into the recursion join: "<<one.bo<<endl;
one = depth_search(one.jyon,one,j,bound,lower);
lower = one.bo;
//lower = bounder(one.bd_ref,one.pcut);
cout<<"It's returns here, the bound is also updated: "<<one.bo<<endl;

cout<<"=========================================Cut================================"<<endl;

//cut 
ken.pcut = addEdge(one.pcut,node,ref.first,ref.second);
ken.part = remove_edge_2(adj,node,ref.second); // another way would be to return at the end condition, it's more efficent.
ken.bd_ref = ken.part;


cout<<"Value of one.bo before going into the recursion Cut: "<<one.bo<<endl;
//ken.bo = bounder(adj,ken.pcut);
ken.bo = nd_bounder(ken.part,ref.second,ken.pcut);


if(lower > ken.bo) // means even the lower bound of the one is better that means there is no use going in here 
{
  cout<<"This is from the cut. "<<endl;
  cout<< "Values lower: "<<lower<<endl;
  cout<< "Values ken.bo: "<<ken.bo<<endl;
  return one; 
  break;
}

ken = depth_search(ken.part,ken,ref.second,bound,lower); //returns here 
cout<<"The original bound is : "<<bound<<endl;
cout<<"The  bound after remove : "<<ken.bo<<endl;


if(ken.bo>= one.bo){ 
  return ken;
}else{return one; }
}}}  

else{ 
it++;}

if(it->first != node){ // if it's been cut they cannot join
cout<<"It's in the break condition"<<endl;
  break;
}} 


cout<<"-----------------------END-------------------------------"<<endl;
return one;}






int main(){

multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> test;
tulip graph;
tulip one;


vector<vector<int>> myGraphData = readGraphData("graph_cars.txt");
for (int x = 0; x < myGraphData.size(); x++) { // Iterate over lines
    for (int y = 0; y < myGraphData[x].size(); y++) { // Iterate over weights in a line
        int weight = myGraphData[x][y];
        int node1 = x + 1; // Adjust for 1-based indexing of your graph structure
        int node2 = node1+ y + 1; // Adjust for 1-based indexing

        adj = addEdge(adj, node1 , weight, node2); 
    }
}


graph = depth_search(adj,graph,20,0,0); 
cout<<"===============Result================"<<endl; 
 printGraph(graph.bd_ref);

 
return 0;
}