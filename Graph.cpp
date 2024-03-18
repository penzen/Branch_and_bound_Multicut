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



multimap<int,pair<int,int>> v2(multimap<int,pair<int,int>> adj,int one, int two) {
  multimap<int, pair<int, int>>::iterator it = adj.find(one);
  pair<int, int> n1 = it->second;
  int combined = 100 + one + two;
cout<<"It first = "<<it->first<<endl;


  while(it != adj.end()){
    cout<<"It first = "<<it->first<<endl;
    if(n1.second == two){
    adj = addEdge(adj,combined,n1.second,0);}
multimap<int, pair<int, int>>::iterator sit = adj.find(two);
pair<int, int> snd = sit->second;
cout<<"SIt first = "<<sit->first<<endl;
while(sit != adj.end() ){
  if(snd.second == one){
    continue;}
cout<<"SIt first = "<<sit->first<<endl;
   if(n1.second == snd.second){ // they have the same end node 
   adj =  addEdge(adj,combined,n1.first+snd.first,n1.first);
   adj = remove_edge_2(adj,one,n1.second);
   adj = remove_edge_2(adj,two,snd.second);
   break;
   } 
sit++;
if(sit->first != two){
  break;
}

}
it++;
if(it->first != one){
  break;
}}  
return adj;}


multimap<int,pair<int,int>> cut_update(multimap<int,pair<int,int>> adj,int one, int two){

//adj =join(adj,one,two);
//can be called after the join method 
  /*
 it = adj.find(one);
 sit = adj.find(two);
cout<<"The value of it before the loop is: "<<it->first;
 //if(it->first == )


cout<<"The value of it is: "<<it->first<<endl;
cout<<"The value of sit is: "<<sit->first<<endl;

// kind of works like stacks where everything is reset as in the it and sit; 

 while(it != adj.end() ){
   it = adj.find(one);
   cout<<"The value of it is: "<<it->first<<endl;
   if(it->first == one){
        cout<<"it second : "<<it->second.second<<endl; 
        int rewe = it->second.second;
     adj = addEdge(adj,combined,it->second.first,it->second.second);
     adj = remove_edge_2(adj,one,rewe); 
  }else{
    cout<<"We are in the break condition " <<it->first<<endl;
    break;}}

while(sit != adj.end() ){
   sit = adj.find(two);
   cout<<"The value of sit is: "<<sit->first<<endl;
   if(sit->first == two){
        cout<<"sit second : "<<sit->second.second<<endl; 
        int rewe = sit->second.second;
     adj = addEdge(adj,combined,sit->second.first,sit->second.second);
    // cout<<"sit second : "<<sit->second.second<<endl; 
     adj = remove_edge_2(adj,two,rewe);
  }else{
    cout<<"We are in the break condition " <<sit->first<<endl;
    break;}} 
printGraph(adj);
 */
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
        cout<<"The removed value of one is: " <<beta[y].second<<endl;
        adj = remove_edge_2(adj,two,beta[y].second);
        break;
        }}}}

 
 // this for the cut edges could be put into a new method 
 
multimap<int, pair<int, int>>::iterator rerun = adj.find(one);
multimap<int, pair<int, int>>::iterator tst = adj.find(two);

 //if(it->first == )


// kind of works like stacks where everything is reset as in the it and sit; 
/*
*/
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


/*
*/
multimap<int,pair<int,int>> depth_search(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut,int node,int bound){

  multimap<int,pair<int,int>> anone; // for the refrence and comparision of the data structure 
  multimap<int,pair<int,int>> antwo;

cout<<"-----------------start of recursion--------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
multimap<int, pair<int, int>>::iterator it = adj.find(node);
//base case 
if(cut.size() == 0){ 
pair<int,int> tep = it->second;
cout<<"It's  in the cut size 0 if condition"<<endl;
// need to add another base case here because this will recursivly go on for the join part where there is no cut. 
cut = addEdge(cut,node,tep.first,tep.second);
adj = remove_edge_2(adj,node,tep.second);
anone = depth_search(adj,cut,tep.second,bound); //need a proper data structure to handale that 
// then call the recursion for the cut; 
cut = remove_edge_2(adj,node,tep.second); 
int combo = 100 + node + tep.second;
multimap<int, pair<int, int>>::iterator jn = adj.find(node);
// the first node is always going to be  0 so we will have to move to the next node. 

while(jn != adj.end()){
  if(jn->second.second != 0){
    cout<<"The value of Jn is: "<<jn->second.second<<endl;
    break;
  }else {
    jn++;
  }
}
//now that the itterator is updated 
adj = join(adj,node,tep.second );
antwo = depth_search(adj,cut,jn->second.second,bound); 
}
for(int x =0; x < adj.size(); x++){
  // check which branch increases the node most or the one with the higest value.  
  // the problem with this is their will be nodes that have a 

pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;
bool bs = checkcut(cut,it->first,ref.second); // before join 
if(bs == true ){ // if true then we can triverse through  it 

cout<<"Before going into the recurstion djjsdncordcwskdfpowesdolwksdcmlkm"<<endl;
// cutting
cut = addEdge(cut,node,ref.first,ref.second);
adj = remove_edge_2(adj,node,ref.second);
anone = depth_search(adj,cut,ref.second,bound); //need a proper data structure to handale that 
//joing
cut = remove_edge_2(adj,node,ref.second); 
int combo = 100 + node + ref.second;
multimap<int, pair<int, int>>::iterator jn = adj.find(node);

while(jn != adj.end()){
  if(jn->second.second != 0){
    break;
  }else {
    jn++;}}}
else{ 
it++;
}
if(it->first != node ){ // the condition alredy checks the size.
//return cut;
cout<<"It's in the break condition"<<endl;
  break;}}

// this is wrong why would we need two data structure. 
// and I think there might be a problem with the pointer.
multimap<int, pair<int, int>>::iterator oe = anone.find(node);
multimap<int, pair<int, int>>::iterator tw = antwo.find(node);
if(oe->second.second > tw->second.second){
  cout<<"Anone is bigger "<<endl;
  cout<<"anone value: "<<oe->second.second<<endl;
  cout<<"antwo value: "<<tw->second.second<<endl;
  return anone;
}
else{
   cout<<"Anone is bigger "<<endl;
   cout<<"antwo value: "<<tw->second.second<<endl;
   cout<<"anone value: "<<oe->second.second<<endl;
    return antwo;}
cout<<"-------------------end of recursion ------------------------------------"<<endl;
}

void  doo(multimap<int,pair<int,int>> adj,int node){

}


int main(){
multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> test;
multimap<int,pair<int,int>> result;
 
 /*
 adj = addEdge(adj,1,-1,2);
 adj = addEdge(adj,1,2,3);
 adj = addEdge(adj,1,-3,4);
 adj = addEdge(adj,1,3,5);
 adj = addEdge(adj,2,3,3);
 adj = addEdge(adj,2,4,4);
 adj = addEdge(adj,2,1,5);
 adj = addEdge(adj,3,1,4);
 adj = addEdge(adj,3,2,5);
 adj = addEdge(adj,4,1,5);
 
 */
 
 
adj = addEdge(adj,1,1,2);
adj = addEdge(adj,1,1,3);
adj = addEdge(adj,2,1,3);
 

//add method might be messing things 
 
 // also look into the pointer so it->second.second 
// that might be causing problems. 


// the problem seems to be when we start from 1 
// it just skips over 2 
// every other itteration works except for 1
depth_search(adj,test,2,0);
//result = depth_search(adj,result,1,2)
//cout<<"This is after the recursion";

return 0;
}