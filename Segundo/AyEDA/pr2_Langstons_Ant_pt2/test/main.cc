#include<bits/stdc++.h>
using namespace std;


int size = 5;
int * arr = new int[size];

void resize() {
    int newSize = size * 2;
    int* newArr = new int[newSize];

    memcpy( newArr, arr, size * sizeof(int) );
     
        
    for ( int i = 0; i < newSize; i++) {
      arr[i] = newArr[i];
    }
    
    size = newSize;
    //delete [] newArr;
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
    for(int i = -10 ; i < 5; i++) {
        arr[i] = 1;
    }*/ 

    cout << size << endl;
    
    arr[-10] = arr[4];
    for(int i = -10 ; i < 5; i++) {
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
