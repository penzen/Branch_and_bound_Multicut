#include <iostream>
#include<vector>

struct tulip{
  //we could potentially have a bound for this
multimap<int,pair<int,int>> gph; 
multimap<int,pair<int,int>> cut; 
};





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







multimap<int,pair<int,int>> depth_search(multimap<int,pair<int,int>> adj,multimap<int,pair<int,int>> cut,multimap<int,pair<int,int>> anone,int node,int bound){
  
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
anone = depth_search(adj,cut,anone,tep.second,bound);
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
anone = depth_search(adj,cut,anone,ref.second,bound); //returns here 
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