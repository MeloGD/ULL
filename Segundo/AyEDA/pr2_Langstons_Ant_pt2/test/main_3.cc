#include "vector_t.h"

int main() {
    Vector_T<Vector_T<int>>** array;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j].set_value();
            
    } 
    return 0;
}

