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


struct tulip{
  //we could potentially have a bound for this
multimap<int,pair<int,int>> jyon; 
multimap<int,pair<int,int>> jcut;
multimap<int,pair<int,int>> part;
multimap<int,pair<int,int>> pcut;
int drac = 0; 
int bo = 0;
int up = 0; 
};

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

  cout << "The node: "<< it->first <<"----"<<  wt << "--->connected node:  " <<node<< "\n";
  it++; 
}}

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


// what do we do after the join, because it will now be a combined variable 


bool checkcut(multimap<int,pair<int,int>> cut,int a, int b){

 multimap<int, pair<int, int>>::iterator it = cut.find(a);
 multimap<int, pair<int, int>>::iterator update_one = cut.find(b);

 bool value = false;

if(cut.size() == 0){
  return true;
}

if(it->first == 0) // means it does not exist 
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
     value = true ;  // we could potentially do the join here.
    break; 
  }}
  return value;}



// we could just use the join method it could potentially work. 

// if it's true then we could combine the variables and add the data strucutre at the end. 
// It could be refrence of we could completely replace the  element we combined it, meaning 
// the data struture will not have duplicates now 


   
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


tulip jjl(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
  cout<<"--------------------------------------------------------"<<endl;
  cout<<"The found node is : "<<node<<endl;
  printGraph(adj);
  cout<<"The value of count(adj) is "<<count(adj)<<endl;
  if(count(adj) == 0) // means we have gone through all the joins
{ // this works because it's the final condition/
 // one.jyon = adj;
  return one;
}
multimap<int, pair<int, int>>::iterator it = adj.find(node);
if(it->second.second == 0){ // this will never be 0 because we are putting the joined elements in
  while(it != adj.end()){
    cout<<"The while loop value is: "<<it->second.second<<endl;
    if(it->second.second != 0){
      break;
    }
    it++;}}
// now  the itterator will be set to the number we want to itterate
for(int x = 0; x < adj.size(); x++){
//it = adj.find(node);
cout<<"The value of it is " <<it->first<<endl;
cout<<"The value of second  is " <<it->second.second<<endl;
if(it->second.second == 0){
  // even after the itteration if we get a 0 this means it's all been joined
  return one;
  break;}
int ct = 100 + node + it->second.second;
one.jyon = join(adj,node,it->second.second); // this also works 
one = jjl(join(adj,node,it->second.second),one,ct,0);

break;  // we don't need to itterate after the recursion 
}
  cout<<"Out of the loop"<<endl;
 // one.jyon = adj; // it won't work here because it's being updated 
  printGraph(one.jyon);
  return one;} 
    
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


// only adds postive number and also only if they can be joined meaning not the cut ones.
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
    
    cout<<"VALue of zone after adding: "<<zone<<endl;
}}
adj = remove_edge_2(adj, it->first,it->second.second); 
 }return zone;}



// still need to check where to put the lower bound. 
tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound, int lower){
cout<<"--------------------------------------------------------"<<endl;
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
cout<<"The size of the graphs part:"<<one.part.size()<<endl;
cout<<"  join: "<<one.jyon.size()<<endl;
printGraph(one.jyon);

//cut 
//ken.bo = one.bo; // pass in the bound. 
ken.pcut = addEdge(ken.pcut,node,0,tep.second);
ken = depth_search(remove_edge_2(adj,node,tep.second),ken,tep.second,bound,lower);
cout<<"It's returned here in the cut from first where everything is about to be returned. "<<endl;
if(ken.bo >= one.bo){ // has to change 
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
  return one;} // it's not going to the first recrusive call

multimap<int, pair<int, int>>::iterator it = adj.find(node); // this becomes the adj 

 if ( it->first == adj.size()  ){ 
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{ one.jcut = adj;
  return one; }} // meaning the weight is empty


while(it != adj.end() ) 
{
  if(it->first != 0){
    if(it->second.second != 0){
      break;
    }}
  it++;}

cout<<"Value of it after while loop: " <<it->first<<endl;
cout<<"Value of second after while loop: " <<it->second.second<<endl;



int rl = it->second.second; 
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
    one.bo = bounder(adj,one.pcut);
    return one;
    break;
    // calculate the bound and return.
  }
}

if(ref.first != 0){ // don't need this check it's already been done above 
if(checkcut(one.pcut,it->first,ref.second) == true ){ 
printGraph(adj);

cout<<"The size of one.part after cut: "<<adj.size()<<endl;
cout<<"====================Before going into the recurstion ==========================="<<endl;

cout<<"Value of x: "<<x<<endl;
cout<<"Value of it: "<<it->first<<endl;
multimap<int, pair<int, int>>::iterator detern = adj.find(ref.second);

cout<<"the detern first is: "<<detern->second.first<<endl;
cout<<"the detern second is: "<<detern->second.second<<endl;

if(detern->second.first == 0) //means it's been cut from everything 
{
  cout<<"It's in the condition where everything is cut"<<endl;
  continue;
}
else{ 

tulip ken = one;
// join
one.jcut = one.pcut;// keep a refrecne that way we don't have to deal with the other one.
one.pcut = join(one.pcut,node,ref.second);
int j = 100 + node + ref.second;
// check the valie of bolder berfore recrusing 
cout<<"The value of cut one.bo updating "<<one.bo<<endl;
one.bo = bounder(adj,one.pcut); //calculate the bound  

if(lower > one.bo && lower > 0){
  cout<<"Condition where the lower bound is greater then upper "<<one.bo <<endl; 
  cout<<"Lower: "<<lower<<endl;
  one.bo = lower; // we are stiking with the better bound
  one = ken; // we update it back to the previous setting.
  return one; 
  break;
}

cout<<"Value of bounder before going into the recursion join: "<<one.bo<<endl;
one = depth_search(join(adj,node,ref.second),one,j,bound,lower);
lower = one.bo;
cout<<"It's returns here, the bound is also updated: "<<one.bo<<endl;






//bound = one.bo; don't need that because the bound are alredy calculated.
printGraph(one.jyon);
cout<<"=========================================Cut================================"<<endl;
printGraph(adj);


//cut 
ken.pcut = addEdge(one.pcut,node,ref.first,ref.second);
ken.part = remove_edge_2(adj,node,ref.second); // another way would be to return at the end condition, it's more efficent.

cout<<"Value of one.bo before going into the recursion Cut: "<<one.bo<<endl;
ken.bo = bounder(adj,ken.pcut);
//ken.bo = frcut(adj,ken.pcut); //calculate the bound 
cout<<"Value of ken.bobefore going into the recursion Cut: "<<ken.bo<<endl;
//check the 105 problem next. 

if(lower > ken.bo) // means even the lower bound of the one is better that means there is no use going in here 
{
  cout<<"This is for the cut. "<<endl;
  cout<< "Values lower: "<<lower<<endl;
  cout<< "Values ken.bo: "<<ken.bo<<endl;

  return one; 
 // return ken;  // this is causeing the problem because we are returning the one with the lower bound
  break;
}

ken = depth_search(remove_edge_2(adj,node,ref.second),ken,ref.second,bound,lower); //returns here 
cout<<"The original bound is : "<<bound<<endl;
cout<<"The  bound after remove : "<<ken.bo<<endl;
printGraph(ken.jyon);
cout<<"Value of ken jyon"<<endl;
cout<<"Value of it after recursion: "<<it->first<<endl;

// this is after the recrusion, so this will make sense 
if(ken.bo>= one.bo){ 
  return ken;
}else{return one; }
}}}  

else{ 
it++;}

if(it->first != node){ // if it's been cut they cannot join
//return cut;
cout<<"It's in the break condition"<<endl;
  break;
}} 

cout<<"The end print graph"<<endl;
cout<<"The size of the adj: "<<adj.size()<<endl;
printGraph(adj);
cout<<"--------------------------------------------------------"<<endl;
return one;}






int main(){

multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> test;
tulip graph;
tulip one;

  



// data being inputed
vector<vector<int>> myGraphData = readGraphData("graph_test.txt");
for (int x = 0; x < myGraphData.size(); x++) { // Iterate over lines
    for (int y = 0; y < myGraphData[x].size(); y++) { // Iterate over weights in a line
        int weight = myGraphData[x][y];
        int node1 = x + 1; // Adjust for 1-based indexing of your graph structure
        int node2 = node1+ y + 1; // Adjust for 1-based indexing

        adj = addEdge(adj, node1 , weight, node2); 
    }
}





graph = depth_search(adj,graph,15,0,0); 


//checkcut(test,1,2)

 /*
cout<<"===============Cut================"<<endl;
printGraph(graph.part);
cout<<"===============Join================"<<endl;
printGraph(graph.jyon);
 */
return 0;
}







/*
  void ConstraintPropagation(multimap<int,pair<int,int>> adj) {
    queue<pair<int,int>> selectedEdges;
    queue<pair<int,int> deselectedEdges;

    // Initialize queues based on initial edge values
    multimap<int, pair<int, int>>::iterator it = adj.begin();
    
      for (int j = 0; j < adj.size(); ++j) {
        if (it->first == 0) { //fixed edges check if cut or joined
          //selectedEdges.push({it->first}); // for the joined 
         // check the cut to see what's been cut 
        } else {  
        //  deselectedEdges.push(it->first);
        }
        it++;
      }
    

    // Process selected edges
    while (!selectedEdges.empty()) {
      pair<int,int> edge = selectedEdges.front();
      selectedEdges.pop();

      for (int k = 0; k < adj.size(); ++k) {
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

*/











