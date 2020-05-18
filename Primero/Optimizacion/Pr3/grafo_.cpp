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
    for (int i = 0; i < n; i++)
    {
        LS[i].clear();
        LP[i].clear();
    }
    LS.clear();
    LP.clear();
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)  
{
    LS.clear();  // al ser una actualización, hay que limpiar ambas listas antes de proceder a la actualización
    LP.clear();

    unsigned i, j;
    ElementoLista aux;  //creacion del nodo contenedor de tipo elemento lista para crear las listas pertinentes

    cout << "Introduzca el nombre del nuevo fichero: " << endl;
    cin >> nombrefichero;

    ifstream textfile;
    textfile.open(nombrefichero);

    if (textfile.is_open())  // si el fichero esta abierto, entonces
    {
        textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;  //cargamos los valores del fichero en las variables
        
        LS.resize(n);
        LP.resize(n);
        
        for (int l = 0; l < m; l++)
        {
            if(dirigido == 1){
            textfile >> (unsigned &) i >> (unsigned &) j; 
            aux.j = j-1; //Lo que hacemos en estas lineas: Accedemos al valor en aux (de tipo ElementoLista), y asignamos el valor del nodo - 1
            LS [i-1].push_back(aux); //Montamos la lista, colocando uno a uno detras del otro

            aux.j = i-1;
            LP [j-1].push_back(aux);
            }
            else{  //No es dirigido, montamos lista de adyacencia
            textfile >> (unsigned &) i >> (unsigned &) j;    
                if (i != j)
                { 
                    aux.j = j-1;
                    LS [i-1].push_back(aux);

                    aux.j = i-1;
                    LS [j-1].push_back(aux);
                    
                }
                else{
                    //No hacemos nada, i=j 1-1 sería un bucle
                    aux.j = j-1;
                    LS [i-1].push_back(aux);
                }
            }
        }
        textfile.close();
    }
    else
    {
        errorapertura = 1;  //para poder controlar si escribimos mal el documento
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
       // Metodo opcional
};
void GRAFO :: Mostrar_Listas (int l)
{   
    if (l == 2)
    {
        cout << "Ha selecionado lista de adyacencias.";
        for (int i = 0; i < n; i++)
        {
            cout << "\nLos adyacentes del nodo " << i+1 << " son:";
            for (int j = 0; j < LS[i].size(); j++)
            {   
                cout << " " << (LS[i][j].j) + 1; // +1 para obtener el valor del nodo correcto
            }
            
        }
        cout << endl;
    }
    
    if (l == 1)
    {
        cout << "Ha seleccionado lista de sucesores." ;
        for (int i = 0; i < n; i++){
            cout << "\nEl nodo " << i+1 << " tiene como sucesores a: " ;
            for (int j = 0; j < LS[i].size(); j++)
            {
                cout << " " << LS[i][j].j + 1 ;
            }
            
        }
        cout << endl;
    }
    if (l == 0){
    cout << "Ha seleccionado lista de predecesores." ;
    for (int i = 0; i < n; i++){
        cout << "\nEl nodo" << i+1 << " tiene como predecesores a: " ;
        for (int j = 0; j < LP[i].size(); j++)
        {
            cout << " " << LP[i][j].j + 1 ;
        }
    }
    cout << endl;
    }
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
    int cconex = 0;
    vector<bool> visit;
    visit.resize(n,false);

    for (unsigned i = 0; i < visit.size(); i++){
         if (visit[i] == false){   //si aun así, hay algún nodo que esta en "false"
            cconex++; // indicamos que ya no es conexo
            cout << "Componente conexa " << cconex << ": ";
            dfs (i, visit); //dfs de este subgrafo
            cout << endl;
        }
    }
    if (cconex == 1)
    {
        cout << "\n El grafo es conexo " << endl;
    }
    else
    {
        cout << "\n El grafo no es conexo " << endl;
    }
    
 
}

void GRAFO::ListaPredecesores() 
{
    // Metodo opcional
}


GRAFO::GRAFO(char nombrefichero[85], int &errorapertura) // en actualizar tengo los comentarios explicando como funcionan los metodos de actualizar y de este constructor
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
            textfile >> (unsigned &) i >> (unsigned &) j;    
                if (i != j)
                {   aux.j = j-1;
                    LS [i-1].push_back(aux);

                    aux.j = i-1;
                    LS [j-1].push_back(aux);
                                        
                }
                else{
                    //No hacemos nada, i=j 1-1 sería un bucle
                    aux.j = j-1;
                    LS [i-1].push_back(aux);
                }
            }
        }
        textfile.close();
    }
    if (dirigido !=0 && dirigido !=1)
    {
        errorapertura = 1;
    }
    
}




