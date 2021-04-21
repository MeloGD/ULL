#include <random>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
std::string random_string()
{
     std::string str("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

     std::random_device rd;
     std::mt19937 generator(rd());

     shuffle(str.begin(), str.end(), generator);
     
     return str.substr(0, 3);    // assumes 32 < number of characters in str         
}

int main()
{
    std::string rstr = random_string();

    //some_func_that_needs_const_char_pointer(rstr.c_str());
    std::cout << rstr << "\n";
}