#include<bits/stdc++.h>
using namespace std;


int size = 5;
int * arr = new int[size];

void resize() {
    size_t newSize = size * 2;
    int* newArr = new int[newSize];

    memcpy( newArr, arr, size * sizeof(int) );

    size = newSize;
    //delete [] arr;
    arr = newArr;   
}
int main() {

    cout << "El primero vale: " << endl;
    for(int i = -5 ; i < size; i++) {
        arr[i] = i + 10;
    } 
    for(int i = -5 ; i < size; i++) {
        cout<< "index: " << i << " vale " << arr[i] << endl;
    } 
    cout << "El segundo vale vale: " << endl;
    resize();
    
    /*
    for(int i = -5 ; i < size; i++) {
        arr[i] = i + 10;
    }*/ 
    for(int i = -5 ; i < size; i++) {
        cout<< "index: " << i << " vale " << arr[i] << endl;
    } 
  /*
  struct main {
    int hola;
    // int p;
  }myvalues;
       cout << "el struct vale" << sizeof(myvalues);
  */     
  return 0;
}
