#include "set_calculator.h"

#include "iostream"
#include "vector"

using namespace std;

// int argc, char const *argv[]
int main()
{
    
    //0 0 0 0 0 0 1 0 --> Pertenece al conjunto {2}
    Set A;
    A.Print();
    string test = "00000111";
    long intest = stoi(test);
    cout << test << endl;
    return 0;
}