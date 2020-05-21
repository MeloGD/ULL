 /*
 *  GRAFO.CPP - Implementaci�n de la clase GRAFOS
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
    int k;
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
            textfile >> (unsigned &) i >> (unsigned &) j >> (int &) k; 
            aux.j = j-1; //Lo que hacemos en estas lineas: Accedemos al valor en aux (de tipo ElementoLista), y asignamos el valor del nodo - 1
            aux.c = k;
            LS [i-1].push_back(aux); //Montamos la lista, colocando uno a uno detras del otro

            aux.j = i-1;
            aux.c = k;
            LP [j-1].push_back(aux);
            }
            else{  //No es dirigido, montamos lista de adyacencia
            textfile >> (unsigned &) i >> (unsigned &) j >> (int &) k;    
                if (i != j)
                { 
                    aux.j = j-1;
                    aux.c = k;
                    LS [i-1].push_back(aux);

                    aux.j = i-1;
                    aux.c= k;
                    LS [j-1].push_back(aux);
                    
                }
                else{
                    //No hacemos nada, i=j 1-1 sería un bucle
                    aux.j = j-1;
                    aux.c = k;
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

unsigned GRAFO::Es_dirigido()
{
    return dirigido;
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
                cout << " (" << (LS[i][j].j) + 1; // +1 para obtener el valor del nodo correcto
                cout << ":" << LS[i][j].c << ")";
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
                cout << " (" << (LS[i][j].j) + 1; // +1 para obtener el valor del nodo correcto
                cout << ":" << LS[i][j].c << ")";
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
            cout << " " << LP[i][j].c;
        }
    }
    cout << endl;
    }
};

void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
    visitado[i] = true;
    cout << " (" << i+1 << ") ";
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

void GRAFO::Kruskal()
{
    vector <AristaPesada> Aristas;

    /*Usaremos la busqueda del menor en cada momento, pues es el mejor para Kruskal que no exige tener todas las aristas ordenadas*/
    /*Cargamos todas las aristas de la lista de adyacencia*/

    Aristas.resize(m);
    
    unsigned k = 0;
    for (unsigned i = 0; i<n; i++){
        for (unsigned j=0; j<LS[i].size();j++){
            if (i < LS[i][j].j) {
                Aristas[k].extremo1 = i;
                Aristas[k].extremo2 = LS[i][j].j;
                Aristas[k++].peso = LS[i][j].c;
                }
        }
    };
    /*Inicializamos el indice a la cabeza del vector*/
    unsigned head = 0;
    AristaPesada AristaDummy; //Para los intercambios en la ordenacion parcial
    
    //Ordenacion usando el metodo burbuja
    for (int i = 0; i < m-1; i++)
    {
        for (int j = 0; j < m-1; j++)
        {
            if (Aristas[j].peso > Aristas[j+1].peso)
            {
                AristaDummy = Aristas[j];
                Aristas[j] = Aristas[j+1];
                Aristas[j+1] = AristaDummy;
            } 
        }
    } 

    
    /*Inicializamos el contador de aristas en la soluci�n*/
    unsigned a = 0;
       

    /*Inicializamos el peso de la solucion*/
    unsigned pesoMST = 0;

    /*Inicializamos el registro de componentes conexas: cada nodo est� en su compomente conexa*/
    vector <unsigned> Raiz;
    Raiz.resize(n);
    for (unsigned q = 0;q < n; q++){
        Raiz[q]=q;
    };

    
    /*Comenzamos Kruskal*/
    int aux, peso_aris;
    unsigned l,j = 0;
    for (int i = 0; i < m; i++)
    {
        j = Aristas[i].extremo1;
        l = Aristas[i].extremo2;
            if (Raiz[j] != Raiz[l])
            {
                aux = Raiz[j];
                for (int k = 0; k < n; k++)
                {
                    if (aux == Raiz[k])
                    {
                        Raiz[k] = Raiz[l];
                    }
                }
                peso_aris = Aristas[i].peso;
                cout << "Arista " << i+1 << " (" << Aristas[i].extremo1 + 1 << "," << Aristas[i].extremo2 + 1 << ") incoporada con peso " << peso_aris << endl;
                pesoMST += Aristas[i].peso;
                a++;
            }
    }

    if (a == (n - 1)){
        cout << "El peso del arbol generador de minimo coste es " << pesoMST << endl;
    }
    else {
        cout << "El grafo no es conexo y el bosque generador de minimo coste tiene peso " << pesoMST  << endl;
    }; 
}


GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
    unsigned i, j;
    int k;
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
            textfile >> (unsigned &) i >> (unsigned &) j >> (int &) k; 
            aux.j = j-1; //en ElementoLista, colocamos el valor del nodo-1
            aux.c = k;
            LS [i-1].push_back(aux);

            aux.j = i-1;
            aux.c = k;
            LP [j-1].push_back(aux);
            }
            else{
            textfile >> (unsigned &) i >> (unsigned &) j >> (int &) k;    
                if (i != j)
                {   aux.j = j-1;
                    aux.c = k;
                    LS [i-1].push_back(aux);

                    aux.j = i-1;
                    aux.c = k;
                    LS [j-1].push_back(aux);
                                        
                }
                else{
                    aux.j = j-1;
                    aux.c = k;
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

//Metodo para recorrer el vector pred y mostrar los caminos mininos que almacena
void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred){
    if (i != s)
    {
        MostrarCamino(s, pred[i], pred);
        cout << pred[i]+1 << " -> ";
    }  
}

void GRAFO::Dijkstra(){
    vector<bool> PermaEtiquetado;
    vector<int> d;
    vector<unsigned> pred;
    int min;
    unsigned s, candidato;

    //Resizes de los vectores e inicializacion de valores
    PermaEtiquetado.resize(n,false);
    d.resize(n,maxint);
    pred.resize(n, UERROR);

    //Solicitamos el nodo origien al usuario
    cout << endl;
    cout << "Caminos minimos: Dijkstra" << endl;
    cout << "¿Nodo de partida?  [1-" << n << "]: ";
    cin >> (unsigned&) s;
    d[--s]=0; //distancia del nodo origen es 0
    pred[s]=s; //el predecesor es él mismo --> pred de 1, es 1, por ejemplo

    do
    {
        min = maxint; //asignamos a min el coste mayor posible
        for (int i = 0; i < n; i++)
        {
            if ((PermaEtiquetado[i] == false) && (d[i] < min)) //si no se ha etiquetado y el coste es menor
            {
                candidato = i;
                min = d[i];
            }
        }
        if (candidato != UERROR) //si existe un candidato
        {
            PermaEtiquetado[candidato] = true; //etiquetamos
            for (unsigned j = 0; j < LS[candidato].size(); j++)
            {
                if (PermaEtiquetado[LS[candidato][j].j] == false) //si el nodo esta en el almacen
                {
                    if ((d[LS[candidato][j].j]) > (d[candidato] + LS[candidato][j].c)) //a partir de aqui, implementamos las operaciones de las diapositivas, actualizando d y pred
                    {
                        d[LS[candidato][j].j] = (d[candidato] + LS[candidato][j].c);
                        pred[LS[candidato][j].j] = candidato;
                    }
                }
            }
        } 
    } while (min < maxint);  

    cout << "\nSoluciones: " << endl;
    for (unsigned i = 0; i < n; i++)
    {
        if (i != s)
        {
            if (PermaEtiquetado[i] == true)
            {
                cout << "El camino desde " << s+1 << " al nodo  " << i+1 << " es: ";
                MostrarCamino(s,i,pred); //llamamos a mostrar camino para que monte la solucion en pantalla
                cout << i+1 << " de longitud " << d[i] << endl;
            }
            else
            {
                cout << "No hay camino desde " << s+1 << " al nodo " << i+1 << endl;
            }
            
            
        }
        
    }
    
    
}




