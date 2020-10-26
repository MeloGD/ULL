#include "fib.h"

// int argc, char const *argv[]
int main()
{
    Fibonacci object(10);
    object.ReadFile("input.txt");
    object.BuildFibonacciSequence();
    object.WriteFile("output.txt"); // falta que comunique el indice

    return 0;
}
