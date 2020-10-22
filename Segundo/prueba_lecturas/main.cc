
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int op1,op2,result;
char sign1, sign2;

int CheckandRead(int);


// Leemos de un fichero valores y comprobamos si son primos con un vector predefinido
int main() {
    vector<int> nums;

    int product = 11;
    if (product == CheckandRead(11))
    {
        cout << op1 << sign1 << op2 << sign2 << result << endl;
    }
    

    /*
    while (file >> op1 >> sign1 >> op2 >> sign2 >> result)
    {
        // cout << result << endl;
        // nums.push_back(result);
        if (result == 3)
        {
            cout << op1 << sign1 << op2 << sign2 << endl;
        }
    } */
    
    /*Ejemplo de organización si hiciera falta --> sort(nums.begin(), nums.end());*/
    /*
    vector<int> nprimes = {2,3,5,7,11};
    
    for (int i = 0; i < nprimes.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (nprimes[i] == nums[j])
            {
                cout << nums[j] << endl;
            }  
        }
    }*/
    return 0;
}

int CheckandRead(int n) {
    ifstream file;
    file.open("output.txt");
    while (file >> op1 >> sign1 >> op2 >> sign2 >> result)
    {
        if (result == n)
        {
            return n;
        }
    }
}
