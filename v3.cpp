#include <iostream>
#include<stdio.h>
#include <vector>
#include<list>
#include <algorithm>
#include <map>
#include <string>
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

multimap<int, pair<int, int>> remove_edge(multimap<int, pair<int, int>> adj, int a, int b){
  multimap<int, pair<int, int>>::iterator it = adj.find(a); 
  pair<int, int> value = it->second;
  int node = value.second;
  while (it != adj.end() ) {
     value = it->second;
     node = value.second;
    if(node == b){ 
      adj.erase(it);
     
      break; 
    }
  ++it;  
}
 return adj;
 }

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
bool visitednodes(multimap<int,pair<int,int>> adj, int fst, int branch){ 
multimap<int, pair<int, int>>::iterator it = adj.find(fst);
while (it != adj.end()) { 
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;
  if(node == branch){
    return true;
    break;
  }
  it++; 
  if(it->first != fst){ 
    return false;
    break; 
  }}}


multimap<int,pair<int,int>> tracker;
bool saver(vector<int> numbers,int node){

    if (find(numbers.begin(), numbers.end(), node) != numbers.end()) { 
        return true;
    } else {
        return false; 
    }}

// we could do the check after the itteration, meaning if it has gone through and the index is still in the 
// list that means we are at the end of the recusion

/*
multimap<int, pair<int, int>>::iterator brancher(multimap<int, pair<int, int>> adj ,vector<int> numbers, int tar){

multimap<int, pair<int, int>>::iterator it = adj.find(tar); 

 pair<int, int> value = it->second; 
 int fs = it->first; 
 int nd = value.second;

 cout<<"It's in the brancher"<<"\n";

 while (saver(numbers,nd) ==true) 
  {   
    //cout <<"The first number is: "<<fs <<'\n';
    if(fs == it->first) // meaning if it's in the same start node 
    { 
     // cout <<"The itterator is outputting the following: "<< nd <<'\n';
      ++it; 
      value = it->second; 
      nd = value.second;
      cout <<" It's going to be incremented"<<'\n'; 
      // need to know how I have reached the end 
      
      }
    else{
        break; 
    }
     
    }
    return it;
    }

*/



multimap<int, pair<int, int>>::iterator brancher(multimap<int, pair<int, int>>::iterator it,vector<int> numbers){

 pair<int, int> value = it->second; 
 int fs = it->first; 
 int nd = value.second;
// int refrencce = value.first  


 cout<<"It's in the brancher"<<"\n";
 cout<<"The node passed in is : "<<it->first<<"\n";


 while (saver(numbers,nd) ==true) 
  {   
    //cout <<"The first number is: "<<fs <<'\n';
    if(fs == it->first) // meaning if it's in the same start node 
    { 
      ++it; 
/* 
pair<int,int> checker = it->second;
 if(refrence > checker.first ){
  continue; 
 }
 else{
  refrence = checker.first; 
 }

*/
      value = it->second; 
      nd = value.second;
      cout <<" It's going to be incremented"<<'\n'; 
      // need to know how I have reached the end 
      
      }
    else{
        break; 
    }
     
    }
    return it;
    }




multimap<int,pair<int,int>> trail(multimap<int,pair<int,int>> adj, int tar,vector<int> numbers,multimap<int,pair<int,int>> tracker){

multimap<int, pair<int, int>>::iterator it = adj.find(tar); 
pair<int,int> trk = it->second; // the distination node and weight

//base case 
if(saver(numbers,tar) == true ){

cout<<"It's in the base case"<<'\n';
cout<<"Before the brancher the first number is: "<<it->first<<'\n';
cout<<"The target  number is : "<<tar<<'\n';
 multimap<int, pair<int, int>>::iterator buf = brancher(it,numbers); //brancher 
 pair<int,int> re = buf->second;

 //checks to see if the number is there meaning it has gone through all the itterations. 
 if(saver(numbers,re.second)== true) // meaning we have gone throught all the itteration, then
 {
  cout<<"It's in the if statement of the base"<<'\n';
  tracker = addEdge(tracker,it->first,trk.first,trk.second); //don't think we need this 
  return tracker; }
 else{// move to the next itteration of the tree.
    it = buf;
    trk = it->second;

    cout<<"it's in the else statement of the while loop: "<<it->first<<endl;
    cout<<"The target node is : "<<trk.second<<endl;
    }

}

while (it != adj.end()) { // we have to look at specific index and not the whole thing so we can keep track of the first number

if(it->first == 4){
  break;
}

if(it->first == tar){
  pair<int, int> value = it->second;  
  int wt = value.first;
  int node = value.second;
  numbers.push_back(it->first); 
 // cout<<"The size of numbers is: "<<numbers.size()<<'\n';
  cout<<"In the while loop"<<'\n';
  
  cout<<"The node we are looking at is : "<<it->first<< '\n';
  it = brancher(it,numbers);                   //this is required 
  value = it->second;  
  wt = value.first;
  node = value.second;
  
  tracker = trail(adj,node,numbers,tracker); // this will be one 
}}}
// the answers are one because the first target node is always one.

int main(){
multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> result;

 adj = addEdge(adj,1,30,2);
 adj = addEdge(adj,1,30,3);
 adj = addEdge(adj,1,30,4);
 adj = addEdge(adj,2,30,3);
 adj = addEdge(adj,2,30,4);
 adj = addEdge(adj,3,30,4);

vector<int> numbers;


result = trail(adj,1,numbers,result);

/*
multimap<int, pair<int, int>>::iterator it = adj.find(1);

pair<int,int> trk = it->second; // the distination node and weight
//base case 
if(saver(numbers,2) == true ){
 multimap<int, pair<int, int>>::iterator buf = brancher(it,numbers); //brancher 
 
 pair<int,int> re = buf->second;

 // check if all the branches are in the list
 // return  true or false 
 // need a method for that, and it should solve the problem 

 if(re.second == trk.second) // meaning we have gone throught all the itteration, then
 {
cout<<"This is the break sentence"<< '\n';
  tracker = addEdge(tracker,it->first,trk.first,trk.second); 
 }
 else{// move to the next itteration of the tree.
    cout<<"the else statement "<< '\n';
    it = buf;}
}

pair<int,int> df = it->second;


 cout<<"After loop "<< '\n';
 cout<<"The first is: "<<it->first<< '\n';
 cout<<"The second is: "<<df.second<< '\n';



*/
  
}

/* 
This method is used to determine wether two nodes should join or not, the diffrence being 
that this method makes sure that if the node we want to join with is connected to one of the cut nodes then
the join will not be allowed, this method is impratical for a complete graph but can be used for 
non- complete graph
bool checkcut(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut,int a,int b){
 
 // a is the one we want to merge with 
 // b is the refrence to the cut nodes. 

  multimap<int, pair<int, int>>::iterator it = cut.find(a);
  multimap<int, pair<int, int>>::iterator sit = adj.find(b);
  pair<int, int> value = it->second;
  pair<int, int> snd = sit->second;
  int node_one = value.second;
  int node_two = snd.second;
  bool fst = false; 
  bool cutter = false;


//  if both return true that means that the node has alredy been cut from node a 
//  if one of them returns flase 
 
 for (int x = 0; x < adj.size(); ++x) {
  
  
   if(it->first == a){
    if(fst == true){
      break;
    }else{
      if(x != 0){
         ++it;}
      } 
     value = it->second;
     node_one = value.second;  
     for (int y = 0; y < adj.size(); ++y) {

     if(sit->first == b){
      snd = sit->second;
      node_two = snd.second;
      if(node_two == node_one) { // means it's been cut and it's on the list 
       cutter = true;
       fst = true; 
       break; 
      }else{
        ++sit;
      }}}}
      else{
        break;
      }}
   return cutter;}

*/
