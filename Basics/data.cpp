#include<iostream>

void swap(std::string &p, std::string &x);

const std:: string na = "John";//const cannot be changed 

int main(){

int *pointer = nullptr; // this is how to assign pointers


std::string name = "Penzen";
std::cout << &name; //get memory address 
std::string p = "Passing by refrence";
std::string x = "Passing by name";

 //swap(p,x); does not work because they are just making copies that's why we pass my refrence
 swap(p,x);

std::cout <<'\n'<< p;
std::cout <<'\n'<< x;

int test = 10; 
pointer = &test;
std::cout<<'\n'<<*pointer<<" This is the value of the pointer" ;  // this way we can get the value of the pointer 

    return 0; 
}

void swap(std::string &p, std::string &x)
{
  std::string temp = p;
  p = x;
  x = temp;
}
