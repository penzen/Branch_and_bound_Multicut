#include <iostream>
#include<stdio.h>
#include <vector>
#include<list>
#include <map>
#include <string>
using namespace std;



void add_edge( int store[], int start, int end,int wth){

// need a way to store it, 

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

adj.insert(make_pair(1 ,make_pair(30,2)));
adj.insert(make_pair(1,make_pair(40,3)));
adj.insert(make_pair(1,make_pair(20,4)));
adj.insert(make_pair(2 ,make_pair(40,3)));
adj.insert(make_pair(2 ,make_pair(30,1)));
adj.insert(make_pair(3 ,make_pair(40,3)));


//adj = remove_edge(adj,1,4);
cout << "the size of the graph is: "<<adj.size() << endl;
cout<<"before:" <<"\n";
printGraph(adj);
adj = remove_edge_2(adj,1,2);
cout << "the size of the graph is: "<<adj.size() << endl; // could potentiall use this in the loop 
cout<<"after:"<< "\n";
printGraph(adj);





  
}





