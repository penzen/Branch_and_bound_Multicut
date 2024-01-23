#include<iostream>
template <typename T>

T max(T x, T y){ // funtion templete will work with many data types
 return (x > y) ? x:y; 
}
struct student{ 
    std:: string name;
    int age;
    bool enrooled;
    std::string school;
    };

void school(student one);

int main(){

 student one; 
 one.name = "John";
 one.age = 16;
 one.enrooled = true;


    return 0;
}

void school(student one) //passed by value and not refrence to work with original add &one
{
      one.school = "TU Dresden";
     
}
