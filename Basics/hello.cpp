#include <iostream>
#include<vector>

struct tulip{
  //we could potentially have a bound for this
multimap<int,pair<int,int>> jyon; 
multimap<int,pair<int,int>> cut;
multimap<int,pair<int,int>> part;
int drac; // will count the itterations 
};
//could potentially have a size variable here 
// it help with less looping 
// for the testing phase we could also potentially add a adj multimap that wat we have multiple ones
// but as we only need one we don't really need that 

int main() {

const double PI = 10.20 ; //constant cannot be changed. 
 int simp = 20; 
 int i = 43;
 std:: string name = "Penzen"; 
// std:: cout << "Your father's age is "<< i << " good"<< std::endl; 
 std:: cout << example::simp;  
 std::cout<<" \n"<< simp;

/*std::cout << "What is your name ? ";
std::cin >> name; 
std::cout <<"Your name is" <<name <<" Lama"; */

int z = 0; 
/*while(z < 10){
    std::cout<<'\n' <<" The count is at "<<z;
    z++; 
}*/

// std::cout << simp * 10; 

/*for(int r = 0; r < 10; r++)
{

}
*/

John();

std::cout <<"\n" << "Hello monkeys it's been a while"; 

    return 0; 
}


multimap<int,pair<int,int>> v1(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut,multimap<int,pair<int,int>> anone,int node,int bound){

  
cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
multimap<int, pair<int, int>>::iterator it = adj.find(node);

//another case where 



if(cut.size() == 0){ 
pair<int,int> tep = it->second;
cut = addEdge(cut,node,tep.first,tep.second);
anone = addEdge(anone,node,tep.first,tep.second);
adj = remove_edge_2(adj,node,tep.second);
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
anone = v1(adj,cut,anone,tep.second,bound);
}
for(int x =0; x < adj.size(); x++){

  // check which branch increases the node most or the one with the higest value.  
  // the problem with this is their will be nodes that have a 

pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;

bool bs = checkcut(cut,it->first,ref.second);

if(bs == true ){ // if true then we can triverse through  it 
// recurse here because we can triverse it 
cut = addEdge(cut,node,ref.first,ref.second);
anone = addEdge(anone,node,ref.first,ref.second);
adj = remove_edge_2(adj,node,ref.second);
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"Before going into the recurstion djjsdncordcwskdfpowesdolwksdcmlkm"<<endl;
//join(adj,node,ref.second); // then for this section we could add another statement for the recusion 
// also need to join the cut parts here.

//actually why not check the second before recursion 

cout<<"Value of x: "<<x<<endl;
cout<<"Value of it: "<<it->first<<endl;
multimap<int, pair<int, int>>::iterator detern = adj.find(ref.second);
anone = v1(adj,cut,anone,ref.second,bound); //returns here 
cout<<"Value of it after recursion: "<<it->first<<endl;
}
// if it returns empty 
else{ 
it++;
}

if(it->first != node){
//return cut;
cout<<"It's in the break condition"<<endl;
  break;
}} 

cout<<"The end print graph"<<endl;
cout<<"The size of the cut: "<<cut.size()<<endl;
printGraph(cut);
cout<<"--------------------------------------------------------"<<endl;
return anone;

}
tulip v2(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
multimap<int, pair<int, int>>::iterator it = adj.find(node);
 if ( it->first == adj.size()  ){
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{return one; }}

if(one.cut.size() == 0){ 
pair<int,int> tep = it->second;
one.cut = addEdge(one.cut,node,tep.first,tep.second);
one.gph = addEdge(one.gph ,node,tep.first,tep.second);
adj = remove_edge_2(adj,node,tep.second);
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
one = v2(adj,one,tep.second,bound);}

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
one = v2(adj,one,ref.second,bound); //returns here 
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




// now make sure we join everything so, we will need three data structure in the struct now 


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
    continue;
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
    zion = one.part.size() 
}else{zion = one.jyon.size()}


// we could potentially split the for into two diffrent parts
// it could work

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
//////////////////////////////////////////////////////////////////////
tulip depth_search(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;

// cut 
if(one.pcut.size() == 0){ 
multimap<int, pair<int, int>>::iterator mit = adj.find(node);
pair<int,int> tep = mit->second;
//for cut 
one.pcut = addEdge(one.pcut,node,tep.first,tep.second);
one.part = remove_edge_2(adj,node,tep.second);// this just to make sure the recursion works
 // the above statement is equvalent to doing this = adj = remove_edge_2(adj,node,tep.second);
// for join 
/*
adj = addEdge(adj,node,tep.first,tep.second);
one.jlo = join(adj,1,2); // try this to see what happens. */
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
one = depth_search(adj,one,tep.second,bound);}

multimap<int, pair<int, int>>::iterator it = one.part.find(node); // this becomes the adj 

 if ( it->first == one.part.size()  ){ // change this for the itterator 
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{return one; }}



for(int x =0; x < one.part.size(); x++){ // this can be fixed just add the bigger size.
  // check which branch increases the node most or the one with the higest value.  
  // the problem with this is their will be nodes that have a 
it = one.part.find(node); // extra 
pair<int, int> ref = it->second;
int alpha = it->first;
cout<<"It value: "<<it->first<<endl;
cout<<"ref value: "<<ref.first<<" node: "<<ref.second<<endl;

bool bs = checkcut(one.pcut,it->first,ref.second);

if(ref.first != 0){
if(bs == true ){ 
printGraph(one.part);
one.pcut = addEdge(one.pcut,node,ref.first,ref.second);
one.part = remove_edge_2(one.part,node,ref.second);
//adj = remove_edge_2(adj,node,ref.second);

cout<<"The size of one.part after cut: "<<one.part.size()<<endl;
cout<<"Before going into the recurstion djjsdncordcwskdfpowesdolwksdcmlkm"<<endl;

cout<<"Value of x: "<<x<<endl;
cout<<"Value of it: "<<it->first<<endl;
multimap<int, pair<int, int>>::iterator detern = one.part.find(ref.second);


cout<<"the second first is: "<<detern->second.first<<endl;
cout<<"the second second is: "<<detern->second.second<<endl;
if(detern->second.first == 0) //means it's been cut from everything 
{
  cout<<"It's in the condition where everything is cut"<<endl;
  continue;
}else{
one = depth_search(adj,one,ref.second,bound); //returns here 
}
cout<<"Value of it after recursion: "<<it->first<<endl;}}
else{ 
it++;}

// potentially another statement 
if(it->first != node){
//return cut;
cout<<"It's in the break condition"<<endl;
  break;
}} 
cout<<"The end print graph"<<endl;
cout<<"The size of the cut: "<<one.pcut.size()<<endl;
printGraph(one.pcut);
cout<<"--------------------------------------------------------"<<endl;
return one;}


tulip final(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){



cout<<"--------------------------------------------------------"<<endl;
cout<<"The found node is : "<<node<<endl;
multimap<int, pair<int, int>>::iterator it = adj.find(node);
 if ( it->first == adj.size()  ){
cout<< "It's in the other case"<<endl;
  if(it->second.first == 0) // means that this has all been cut 
{return one; }}

if(one.cut.size() == 0){ 
pair<int,int> tep = it->second;
one.cut = addEdge(one.cut,node,tep.first,tep.second);
one.gph = addEdge(one.gph ,node,tep.first,tep.second);
adj = remove_edge_2(adj,node,tep.second);
cout<<"The size of adj after cut: "<<adj.size()<<endl;
cout<<"It's  in the cut size 0 if condition"<<endl;
one = v2(adj,one,tep.second,bound);}


one.part = adj; 
one.jyon = adj; 
// actually we could do the above in the loop

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



// if we do the join first we don't have to worry about the cut 
// cut first if we are are use adj 
one.cut = addEdge(one.cut,node,ref.first,ref.second);
adj = remove_edge_2(adj,node,ref.second);
one.part = adj;
// recurse 


int j = 100 + node + ref.second;
one.jyon = adj;



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
one = v2(adj,one,ref.second,bound); //returns here 
}
cout<<"Value of it after recursion: "<<it->first<<endl;}}

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


tulip jjl(multimap<int,pair<int,int>> adj,tulip one,int node,int bound){
  cout<<"--------------------------------------------------------"<<endl;
  cout<<"The found node is : "<<node<<endl;
  printGraph(adj);
  cout<<"The value of count(adj) is "<<count(adj)<<endl;
  if(count(adj) == 0) // means we have gone through all the joins
{ return one;}
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
one = jjl(join(adj,node,it->second.second),one,ct,0);
break;  // we don't need to itterate after the recursion 
}
  cout<<"Out of the loop"<<endl;
  printGraph(one.jyon);
  return one;} 