 /*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *
 *  Autor : Antonio Sedeno Noda, Sergio Alonso
 *  Fecha : 2013-2020
 */

#include "grafo.h"

GRAFO::~GRAFO()
{
    LS.clear();
    LP.clear();
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    LS.clear();
    LP.clear();

    unsigned i, j;
    ElementoLista aux;

    cout << "Introduzca el nombre del nuevo fichero: " << endl;
    cin >> nombrefichero;

    ifstream textfile;
    textfile.open(nombrefichero);

    if (textfile.is_open())
    {
        textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
        
        LS.resize(n);
        LP.resize(n);
        
        for (int l = 0; l < m; l++)
        {
            if(dirigido == 1){
            textfile >> (unsigned &) i >> (unsigned &) j; 
            aux.j = j-1; //en ElementoLista, colocamos el valor del nodo-1
            LS [i-1].push_back(aux);

            aux.j = i-1;
            LP [j-1].push_back(aux);
            }
            else{
                if (i != j){ 
                    aux.j = i-1;
                    LS [j-1].push_back(aux);
                }
                else{// i=j 1-1 sería un bucle
                }
            }
        }
        textfile.close();
        ListaPredecesores();

    }
    if (dirigido !=0 && dirigido !=1)
    {
        cout << "El fichero no especifica bien si es dirigido o no (0 o 1)" << endl;
    }
}

void GRAFO::Info_Grafo()
{
    if (dirigido == 1)
    {
        cout << "Grafo dirigido ";
    }
    else
    {
        cout << "Grafo no dirigido ";
    };
    cout << " | nodos " << n << " | ";
    if (dirigido == 1)
    {
        cout << " arcos ";
    }
    else
    {
        cout << "aristas ";
    };
    cout << m << " " << endl;
}

unsigned GRAFO::Es_dirigido()
{
	return dirigido;
}

void Mostrar_Lista(vector<LA_nodo> L)
{
};

void GRAFO :: Mostrar_Listas (int l)
{
};

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
	visitado[i] = true;
    cout << i+1 << ", ";
	for (unsigned j=0;j<LS[i].size();j++)
             if (visitado[LS[i][j].j] == false)
                 dfs(LS[i][j].j, visitado);
}

void GRAFO::ComponentesConexas()
{
}

void GRAFO::ListaPredecesores() 
{
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
    unsigned i, j;
    ElementoLista aux;

    ifstream textfile;
    textfile.open(nombrefichero);

    if (textfile.is_open())
    {
        textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
        
        LS.resize(n);
        LP.resize(n);
        
        for (int l = 0; l < m; l++)
        {
            if(dirigido == 1){
            textfile >> (unsigned &) i >> (unsigned &) j; 
            aux.j = j-1; //en ElementoLista, colocamos el valor del nodo-1
            LS [i-1].push_back(aux);

            aux.j = i-1;
            LP [j-1].push_back(aux);
            }
            else{
                if (i != j){ 
                    aux.j = i-1;
                    LS [j-1].push_back(aux);
                }
                else{// i=j 1-1 sería un bucle
                }
            }
        }
        textfile.close();
        ListaPredecesores();

    }
    if (dirigido !=0 && dirigido !=1)
    {
        cout << "El fichero no especifica bien si es dirigido o no (0 o 1)" << endl;
    }
    
}




