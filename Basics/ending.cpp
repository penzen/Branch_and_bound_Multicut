#include<iostream>
//when we pass an array to a funtion it decays into a pointer.

// dynamic memory allocts to the heap not the stack, used when we don't know how much memory we need.


int main(){

/*
int *pNUM = Null; 
pNUM = new int; // this is how we use heap with the help of the new key word. 
*pNUM = 10; 
delete pNUM; "deletes the dynamicly stored memeory"*/

std::string pizzas[5] = {"Opa","poili","jkoe","dss","yum"};
std::string *point = pizzas; // arrays store in pointers so we don't need to worry about it later

std::cout<< (point + 1) <<'\n'; // can iternate through the array using that
return 0;
}

