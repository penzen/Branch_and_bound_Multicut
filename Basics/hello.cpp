#include <iostream>
#include<vector>

typedef std::string john_t; // type def for less typoes
typedef int number_t; 
//using number_t = int; same as typedef  

// comment 
namespace example{
// in this scope of the program simp will be 32 if we want to use the others then 
// we simple have to use it by writting example"simp""
    int simp = 32; 
}


void John(){ //funtion

    std:: cout << "Sup bro"; 
}

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