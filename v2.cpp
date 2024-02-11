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
	  adj.insert(make_pair(u ,make_pair(wt,v))); // Vertex --> pair(weight, vertex)
    adj.insert(make_pair(v,make_pair(wt,u)));
    return adj;

}

void remove(multimap<int,pair<int,int>> trl,int a, int b ){  // removing node b 


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
   //refrence to the node we want to delete 
  pair<int, int> value = it->second;
  int node = value.second;
  while (it != adj.end() ) {
     value = it->second;
     node = value.second;
    if(node == b){ // if we find the node we want to delete
      adj.erase(it);
     
      break; 
    }
  ++it;  
}
 return adj;
 }

////////////////////////////////////////////////////////////////

multimap<int, pair<int, int>> remove_edge_2(multimap<int, pair<int, int>> adj, int a, int b){
  multimap<int, pair<int, int>>::iterator it = adj.find(a);
  multimap<int, pair<int, int>>::iterator sit = adj.find(b);
   //refrence to the node we want to delete 
  pair<int, int> value = it->second;
  pair<int, int> snd = sit->second;
  int node_one = value.second;
  int node_two = snd.second;
  bool fst = false; 
  bool nd = false; 

  for (int x = 0; x < adj.size(); ++x) {

     value = it->second;
     node_one = value.second;
    if(node_one == b){ // if we find the node we want to delete
      fst = true;}
   if (fst == false){  // could potentially use a thread 
    ++it;}

    snd = sit->second;
    node_two = snd.second;
   if(node_two == a){ // if we find the node we want to delete
      nd = true;}
   if (nd == false){  // could potentially use a thread 
    ++sit;}

   if(fst == true && nd == true){
    adj.erase(sit);
    adj.erase(it);
    break;
   }
}
 return adj;
}
bool visitednodes(multimap<int,pair<int,int>> adj, int fst, int branch){ // this if for the branching
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
  if(it->first != fst){ // it;s at the end and has not found the node so it's not been visited
    return false;
    break; 
  }}}


multimap<int,pair<int,int>> tracker; // the tracker needs to go in the visited node 
bool saver(vector<int> numbers,int node){
// code snipit to save the index and this will be used for the branching and in the recursive call
// this can also be an array for the diffrent types of recusioon stroing the diffrent start index. 

// this part of the algorithm is not optimized as the 5 is not suppose to be there. 

    if (find(numbers.begin(), numbers.end(), node) != numbers.end()) { // we could potentially use the itteration here 
        return true;
    } else {
        return false; 
    }}


multimap<int, pair<int, int>>::iterator brancher(multimap<int, pair<int, int>>::iterator it,vector<int> numbers){
//find the node
 pair<int, int> value = it->second; //this is set at the first 
 int fs = it->first;// might need for the other check 
 int nd = value.second;

 while (saver(numbers,nd) ==true) // branching 
  {   
    /*
   We could potentially use saver for both the problems 
   basically creating the two method from one method thing 
   where one method could be used in multiple ways. 
    */
      ++it; 
      value = it->second; //this is set at the first 
      nd = value.second;
    

      cout <<" It's going to be incremented"<<'\n';
    }
    return it;}

int s = 0;  // to check the itterations 
multimap<int,pair<int,int>> trail(multimap<int,pair<int,int>> adj, int tar,vector<int> numbers){
++s;
int wt;
int node ;
// base case
// need to rethink the postion it is in the recursion will suffer if not changes, the node has been added may need to change it.
if(saver(numbers,node) == true ) //meaning if the all the ittrations to the node has been done we return. 
{
  tracker = addEdge(tracker,it->first,wt,node); //then the recurstion should work 
  return tracker; 
}
cout<< "Iteraation: " << s<< '\n';


// the placement for these are not correct the above one espesiialy 
multimap<int, pair<int, int>>::iterator it = adj.find(tar); // find the target we want to itterate throught 

while (it != adj.end()) { // goes through every itteration.
 pair<int, int> value = it->second; //this is the value we input. 
  int wt = value.first;
  int node = value.second;
  numbers.push_back(it->first); // the  number we start with 
  // the branching is not being checked and their is no counter increasing then branch 
  //another will loop to check the branching again   

  cout<<"The size of numbers is: "<<numbers.size()<<'\n';
  cout<<"In the while loop"<<'\n';

// adding it to the traker after it's been visited
  
  cout<<"The node we are looking at is : "<<it->first<< '\n';
  it = brancher(it,numbers);
  tracker = trail(adj,node,numbers); // we recurse on the second number
  
  if(it->first != tar){ // this could potentially be useful for the break condition. 
   cout<<"about to break"<<'\n';
  break;}
}

}


int main(){

/*
trail["one"].push_back(10);
trail["one"].push_back(20);
trail["one"].push_back(30);
trail["one"].push_back(40);
trail["one"].push_back(50);
cout<<"The first index is: "<< trail["one"][4];

cout<<" \nthe size of: "<< sizeof(trail["one"]); 

int x = 0;
for (auto& entry : trail) {
  if (entry.first == "one") {
    const int size = entry.second.size();
    std::cout << "The size of the vector associated with the key 'apple' is " << size << std::endl;
     cout<<"Iterration on: "<<x;
   ++x; 
  } 
}

vector<int> myVector = {1, 2, 3, 4, 5};

for (auto number : myVector) {
  cout << number << " ";
}

*/
multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> result;

 adj = addEdge(adj,1,30,2);
 adj = addEdge(adj,1,30,3);
 adj = addEdge(adj,1,30,4);
 adj = addEdge(adj,2,30,3);
 adj = addEdge(adj,2,30,4);
 adj = addEdge(adj,3,30,4);


 //cout<< " \n The answer is :"<< visitednodes(adj,1,6) <<'\n'; works

//adj = remove_edge(adj,1,4);
/*
cout << "the size of the graph is: "<<adj.size() << endl;
cout<<"before:" <<"\n";
adj = remove_edge_2(adj,1,2);
cout << "the size of the graph is: "<<adj.size() << endl; // could potentiall use this in the loop 
cout<<"after:"<< "\n";
printGraph(adj);
*/
vector<int> numbers;
//result = trail(adj,1,numbers);


/*
multimap<int, pair<int, int>>::iterator it = adj.find(1);
 pair<int, int> value = it->second;
  int wt = value.first;
  int node = value.second;
numbers.push_back(2);
numbers.push_back(3);
cout <<"The itterator is outputting the following: "<< node <<'\n'; 
it = brancher(it,numbers);
value = it->second;
 wt = value.first;
 node = value.second;
cout <<"The itterator is outputting the following: "<< node <<'\n';
cout<<"The size of the graph is: "<<adj.size() << endl;
*/

  
}








