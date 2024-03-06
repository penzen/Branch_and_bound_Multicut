#include <iostream>
#include<stdio.h>
#include <vector>
#include<list>
#include <algorithm>
#include <map>
#include <string>
#include<queue>
#include <set>
using namespace std;


struct tulip{
  //we could potentially have a bound for this
multimap<int,pair<int,int>> gph; 
multimap<int,pair<int,int>> cut; 
};


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
        adj = addEdge(adj,combined,alpha[x].first + beta[x].first,beta[y].second); 
        adj = remove_edge_2(adj,one,beta[y].second);
        cout<<"The removed value of one is: " <<beta[y].second<<endl;
        adj = remove_edge_2(adj,two,beta[y].second);
        break;
        }}}}

 
 // this for the cut edges could be put into a new method 
 
multimap<int, pair<int, int>>::iterator rerun = adj.find(one);
multimap<int, pair<int, int>>::iterator tst = adj.find(two);

 //if(it->first == )

cout<<"The value of it is: "<<rerun->first<<endl;
cout<<"The value of sit is: "<<tst->first<<endl;

// kind of works like stacks where everything is reset as in the it and sit; 

 while(rerun != adj.end() ){
   rerun = adj.find(one);
   cout<<"The value of rerun is: "<<rerun->first<<endl;
   if(rerun->first == one){
        cout<<"rerun second : "<<rerun->second.second<<endl; 
        int rewe = rerun->second.second;
     adj = addEdge(adj,combined,rerun->second.first,rerun->second.second);
     adj = remove_edge_2(adj,one,rewe); 
  }else{
    cout<<"We are in the break condition " <<rerun->first<<endl;
    break;}}

while(tst != adj.end() ){
   tst = adj.find(two);
   cout<<"The value of sit is: "<<tst->first<<endl;
   if(tst->first == two){
        cout<<"sit second : "<<tst->second.second<<endl; 
        int rewe = tst->second.second;
     adj = addEdge(adj,combined,tst->second.first,tst->second.second);
    // cout<<"sit second : "<<sit->second.second<<endl; 
     adj = remove_edge_2(adj,two,rewe);
  }else{
    cout<<"We are in the break condition " <<tst->first<<endl;
    break;}} 

 
return adj;
}


// what do we do after the join, because it will now be a combined variable 


bool checkcut(multimap<int,pair<int,int>> cut,int a, int b){

 multimap<int, pair<int, int>>::iterator it = cut.find(a);
 multimap<int, pair<int, int>>::iterator update_one = cut.find(b);

 bool value = false;
 
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

// the recusion is repeting because the cut is not being updated properly

// first we could try the cut part and then the join 
tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){

cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
multimap<int, pair<int, int>>::iterator it = adj.find(node);



 if ( it->first == adj.size()  ){
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{
  return one; // return empty
  }}

  


if(one.cut.size() == 0){ 
pair<int,int> tep = it->second;
one.cut = addEdge(one.cut,node,tep.first,tep.second);
one.gph = addEdge(one.gph ,node,tep.first,tep.second);
adj = remove_edge_2(adj,node,tep.second);
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
one = depth_search(adj,one,tep.second,bound);
}

for(int x =0; x < adj.size(); x++){

  // check which branch increases the node most or the one with the higest value.  
  // the problem with this is their will be nodes that have a 

it = adj.find(node); // extra 
pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;

bool bs = checkcut(one.cut,it->first,ref.second);

prtspecifc(adj,node);

if(ref.first != 0){
if(bs == true ){ 
one.cut = addEdge(one.cut,node,ref.first,ref.second);
one.gph = addEdge(one.gph,node,ref.first,ref.second);
adj = remove_edge_2(adj,node,ref.second);

cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"Before going into the recurstion djjsdncordcwskdfpowesdolwksdcmlkm"<<endl;

cout<<"Value of x: "<<x<<endl;
cout<<"Value of it: "<<it->first<<endl;
multimap<int, pair<int, int>>::iterator detern = adj.find(ref.second);


cout<<"the second first is: "<<detern->second.first<<endl;
cout<<"the second second is: "<<detern->second.second<<endl;
if(detern->second.first == 0) //means it's been cut from everything 
{
  cout<<"It's in the condition where everything is cut"<<endl;
  continue;
}else{
one = depth_search(adj,one,ref.second,bound); //returns here 
}
cout<<"Value of it after recursion: "<<it->first<<endl;}

}



else{ 
it++;}

// potentially another statement 

if(it->first != node){
//return cut;
cout<<"It's in the break condition"<<endl;
  break;
}} 
cout<<"The end print graph"<<endl;
cout<<"The size of the cut: "<<one.cut.size()<<endl;
printGraph(one.cut);
cout<<"--------------------------------------------------------"<<endl;
return one;}


// basically if we do return cut it should work 


int main(){

// could potentially use name typedef for multimap it will be cleaner;

multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> test;
multimap<int,pair<int,int>> result;
tulip graph;

 
 adj = addEdge(adj,1,-1,2);
 adj = addEdge(adj,1,2,3);
 adj = addEdge(adj,1,-3,4);
 adj = addEdge(adj,2,3,3);
 adj = addEdge(adj,2,4,4);
 adj = addEdge(adj,3,1,4); 
/*
adj = addEdge(adj,2,1,5);
adj = addEdge(adj,1,3,5);
adj = addEdge(adj,3,2,5);
adj = addEdge(adj,4,1,5);

*/

 

graph = depth_search(adj,graph,3,0);
cout<<"GHP value is: "<<graph.gph.size()<<endl;
cout<<"adj size is: "<<adj.size()<<endl;
 
 printGraph(graph.gph);

/*
adj = remove_edge_2(adj,1,2);
adj = remove_edge_2(adj,1,3);
adj = remove_edge_2(adj,1,4);
prtspecifc(adj,1);
multimap<int, pair<int, int>>::iterator it = adj.find(1);
cout<<"it first is: "<<it->first ;
cout<<"it first is: "<<it->second.second ;*/

//test = depth_search(adj,result,test,2,0);
//cout<<"after recursion"<<endl;
// /printGraph(test);
 


return 0;
}



