#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

typedef struct {
        unsigned extremo1, extremo2;
        int peso;
} AristaPesada;



int main()
{
    
    vector<AristaPesada> Aristas;
    vector<int> T;

    unsigned head =0;
    AristaPesada AristaDummy;
    Aristas.resize(4);
    


    Aristas[0].extremo1 = 1; Aristas[0].extremo2 = 3; Aristas[0].peso = 8;
    Aristas[1].extremo1 = 1; Aristas[1].extremo2 = 4; Aristas[1].peso = 2;
    Aristas[2].extremo1 = 3; Aristas[2].extremo2 = 4; Aristas[2].peso = 1;
    Aristas[3].extremo1 = 4; Aristas[3].extremo2 = 2; Aristas[3].peso = 10;
    
    
    
    for (int i = 0; i < 4; i++)  //cuantas veces quiero recorrer la lista
    {
        for (int j = 0; j < 4; j++)
        {
            if (Aristas[j].peso > Aristas[j+1].peso) //el bucle que recorre la lista
            {
                AristaDummy = Aristas[j];
                Aristas[j] = Aristas[j+1];
                Aristas[j+1] = AristaDummy;
                head++; //aumentamos head cuando se produce un cambio en el orden
            }
        }
    }

   

    for (int i = 0; i < 4; i++)
    {
        cout << Aristas[i].extremo1 << " " <<Aristas[i].extremo2 << " " << Aristas[i].peso << " "<< head << endl;
    }
    
    
    for (int i = 0; i < 4; i++)
    {
        T.push_back(i);
        cout << T[i] << endl;
    }
    

    return 0;
}



