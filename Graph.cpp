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
multimap<int,pair<int,int>> jyon; 
multimap<int,pair<int,int>> jcut;
multimap<int,pair<int,int>> part;
multimap<int,pair<int,int>> pcut;
int drac = 0; 
int bo = 0;
int up = 0; 
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
 
 if(it->first == cut.size()) // means it does not exist 
 {
   cout<<"Node: "<<a<<"---- join ---- "<<b<<endl; 
  return true;
 }


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
/*
tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
//when count returns 2 that means there are only two things to join 
//when count is 0 that means everything has been joined 
// we could have a condition where the size is 1 
// another check we could fo is the start index being 0 
// then we will know it is joined 
// cut 
if(one.drac == 0){ //base case 
multimap<int, pair<int, int>>::iterator mit = adj.find(node);
pair<int,int> tep = mit->second;
++one.drac;
//join 
int data =  100 + node + tep.second;
one.jyon = join(adj,node,tep.second); // try this to see what happens. 
multimap<int, pair<int, int>>::iterator dt = one.jyon.find(data);

while(dt != one.jyon.end()) {
  ++dt;
  if(dt->second.second != 0 ){
    break;}}

printGraph(one.jyon);
cout<<"After the join nodes the index is at: "<<dt->second.second<<endl;

one = depth_search(adj,one,dt->second.second,bound); // join

//cut
one.pcut = addEdge(one.pcut,node,tep.first,tep.second);
one.part = remove_edge_2(adj,node,tep.second);// this just to make sure the recursion works
one = depth_search(adj,one,tep.second,bound);}//cut  

if(count(one.jyon) == 0 ) // means we have done all the possbile  joins 
{return one;}

//in each itteration we are only focusing on one element and then we will cut or join them.
multimap<int, pair<int, int>>::iterator it = one.part.find(node);  
multimap<int, pair<int, int>>::iterator bit = one.jyon.find(node); 


// this is valid because we need it for both the join and remove
// now the below case only works for cut 
// now because we are doing join and cut together, think about the condtions that could happen.


if(one.pcut.size() == 0){
 cout<<"one.pcut.size() is 0 there is nothing here "<<endl;
}else{
// might not need it for the join as it's already done in the begining
// the below works for the cut   
 if ( it->first == one.part.size()  ){ // change this for the itterator 
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{return one; }}
}

 
// we can use the above as the initial base 

int zion = 0;

if(one.part.size() > one.jyon.size()){
    zion = one.part.size();
}else{zion = one.jyon.size();}


// we could potentially split the for into two diffrent parts
// it could work


// the problem is here because it is currently empty
for(int x =0; x <zion; x++){ 
 it = one.part.find(node);  
 bit = one.jyon.find(node); 

pair<int, int> ref = it->second;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;


// the important thing is we check  if they havne't been cut before we join.
bool bs = checkcut(one.pcut,it->first,ref.second);
if(ref.first != 0){
if(bs == true ){ 
printGraph(one.part);
// if it can be cut it can also be joined 

one.jyon = join(one.jyon,node,ref.second);

one.pcut = addEdge(one.pcut,node,ref.first,ref.second);
one.part = remove_edge_2(one.part,node,ref.second);


// we don't actually need the cut for the join, because we will be working with  the same cut.
//adj = remove_edge_2(adj,node,ref.second);

cout<<"The size of one.part after cut: "<<one.part.size()<<endl;
cout<<"Before going into the recurstion djjsdncordcwskdfpowesdolwksdcmlkm"<<endl;

cout<<"Value of x: "<<x<<endl;
cout<<"Value of it: "<<it->first<<endl;

// the above codes should work we have to focus on below.
multimap<int, pair<int, int>>::iterator detern = one.part.find(ref.second);

int refrecne = 100 + node + ref.second;
multimap<int, pair<int, int>>::iterator rn = one.jyon.find(refrecne);


if( count(one.jyon) == 0 ){

    continue;
}else{
   // if it's not 0 then there are things we can join 
    one = depth_search(adj,one,rn->second.second,bound);
}


cout<<"the second first is: "<<detern->second.first<<endl;
cout<<"the second second is: "<<detern->second.second<<endl;
if(detern->second.first == 0) //means it's been cut from everything 
{
  cout<<"It's in the condition where everything is cut"<<endl;
  continue;
}else{
one = depth_search(adj,one,ref.second,bound);}
cout<<"Value of it after recursion: "<<it->first<<endl;}}
else{ 
it++;}

// potentially another statement 
if(it->first != node){ // probly need another statement. 
//return cut;
cout<<"It's in the break condition"<<endl;
  break;
}} 

cout<<"The end print graph"<<endl;
cout<<"The size of the cut: "<<one.pcut.size()<<endl;
printGraph(one.pcut);
cout<<"--------------------------------------------------------"<<endl;
return one;}


*/








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
    
    
tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;


if(one.drac == 0){ // initial one.pcut.size()
++one.drac;
cout<<"It's in the first case"<<endl;
multimap<int, pair<int, int>>::iterator mit = adj.find(node);
pair<int,int> tep = mit->second; 
// join
int j = 100 + node + tep.second;
bound = inital_bounder(adj);
one = depth_search(join(adj,node,tep.second),one,j,bound);
cout<<"After the join recrusion is fininshed"<<endl;
printGraph(one.part);

tulip ken = one;

cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
one.pcut = addEdge(one.pcut,node,0,tep.second);
one = depth_search(remove_edge_2(adj,node,tep.second),one,tep.second,bound);
cout<<"It's returned here"<<endl;
if(bound > one.bo){ // has to change 
  return ken;
}else{return one;}
}
one.part = adj; // this could potentially be a problem 
if(count(adj) == 0) // means we have gone through all the joins
{ cout<<"Everrything is joined"<<endl;
  one.jyon = adj;
  multimap<int, pair<int, int>>::iterator fd = adj.find(node);
  one.bo = fd->second.first; // it's 0 because it's disconnected from everything
  return one;} // it's not going to the first recrusive call
multimap<int, pair<int, int>>::iterator it = adj.find(node); // this becomes the adj 

 if ( it->first == adj.size()  ){ 
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{ one.jcut = adj;
  one.bo = 10;
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

for(int x =0; x < adj.size(); x++){ 
//it = adj.find(node); 
pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;

bool bs;
if(one.pcut.size() == 0 ){
 bs = true; // it's empty so it will return nothing
}else{bs = checkcut(one.pcut,it->first,ref.second);}


if(ref.first != 0){ // don't need this check it's already been done above 
if(bs == true ){ 
printGraph(adj);

cout<<"The size of one.part after cut: "<<adj.size()<<endl;
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


// maybe somewhere we need to add 
// one.jyon = 

// join
one.jcut = one.pcut;// keep a refrecne that way we don't have to deal with the other one.
one.pcut = join(one.pcut,node,ref.second);
int j = 100 + node + ref.second;
//one.jyon = join(adj,node,ref.second); this is causing the problems 
one = depth_search(join(adj,node,ref.second),one,j,bound);
cout<<"It's returns here "<<one.bo<<endl;

tulip ken = one;

bound = one.bo; // refrence 
printGraph(one.jyon);
cout<<"dsdsfvdosfjiesjdfilgjesvldifnhvliesnfhdliv"<<endl;
printGraph(adj);

// refrence has to be set here to compare with the cut. 

//cut 
one.pcut = one.jcut;
one.pcut = addEdge(one.pcut,node,ref.first,ref.second);
one.part = remove_edge_2(adj,node,ref.second); // another way would be to return at the end condition, it's more efficent.
one = depth_search(remove_edge_2(adj,node,ref.second),one,ref.second,bound); //returns here 
cout<<"The original bound is : "<<bound<<endl;
cout<<"The  bound after remove : "<<one.bo<<endl;
printGraph(one.pcut);/////////////////////////////////////////////////
cout<<"Value of ken"<<endl;


if(bound > one.bo){ // that has to chage we are using an initial bould 
  return ken;
}else{return one;}
break;
}
cout<<"Value of it after recursion: "<<it->first<<endl;}}
else{ 
it++;}

// potentially another statement 
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
  if(checkcut(cut, it->first,it->second.second) == true){
    cout<<"In: "<<y<<endl;
    cout<<"In the zone"<<endl;
    zone+= it->second.first;
  }
  adj = remove_edge_2(adj, it->first,it->second.second); 
 }
  return zone;
}



int main(){

// could potentially use name typedef for multimap it will be cleaner;

multimap<int,pair<int,int>> adj;
multimap<int,pair<int,int>> test;
multimap<int,pair<int,int>> result;
tulip graph;
tulip one;

 
 adj = addEdge(adj,1,4,2);
  adj = addEdge(adj,2,12,3);
 adj = addEdge(adj,1,-10,3);


/*
adj = addEdge(adj,1,-3,4);
 adj = addEdge(adj,2,3,3);
 adj = addEdge(adj,2,4,4);
 adj = addEdge(adj,3,1,4); 

*/
/*
adj = addEdge(adj,2,1,5);
adj = addEdge(adj,1,3,5);
adj = addEdge(adj,3,2,5);
adj = addEdge(adj,4,1,5);

*/

 
//graph = depth_search(adj,graph,1,0); // this is the key to makeing it work.

//int b = inital_bounder(adj);

//printGraph(adj);

// bounder works 
// added a few twiks to the check cut, now it works for node that are not there.

multimap<int,pair<int,int>> cut; 
cut = addEdge(cut,1,4,2);
int z = bounder(adj,cut);
cout<<"The value of b is :"<<z<<endl;

 

cout<<"===============Cut================"<<endl;
printGraph(graph.pcut);
cout<<"===============Join================"<<endl;
printGraph(graph.jyon);
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



