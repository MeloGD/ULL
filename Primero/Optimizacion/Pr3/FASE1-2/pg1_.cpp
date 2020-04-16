 /*
 *  PG1.CPP - Actividad I de Optimiza!cion.
 *
 *
 *               Autores : Antonio Sedeno Noda, Sergio Alonso.
 *               Fecha : Marzo-2020
 */

#include <string.h>
#include "grafo.h"


void clrscr() //No funciona en todos los sistemas: opcional
{
	// system("cls"); descomentar y comentar el clear si es para windows
    system("clear");
}



void menu (unsigned dirigido, char &opcion)
//Expresion del menu de opciones segun sea un grafo dirigido o no dirigido
{

       if(dirigido == 1){
           cout << "\nActividad 1, Optimización: Carga del grafo y conectividad" << endl;
           cout << "a. Cargar el grafo desde fichero" << endl;
           cout << "b. Mostrar informacion basica del grafo" << endl;
           cout << "c. Mostrar la lista de sucesores del grafo" << endl;
           cout << "d. Mostrar la lista de predecesores del grafo" << endl;
           cout << "e. Finalizar el programa" << endl;
           cout << "Introduzca la letra de la opcion a escoger:" << endl;
           cin >> opcion;   
       }
       else
       {
           cout << "\nActividad 1, Optimización: Carga del grafo y conectividad" << endl;
           cout << "a. Cargar el grafo desde fichero" << endl;
           cout << "b. Mostrar informacion basica del grafo" << endl;
           cout << "c. Mostrar la lista de adyacencia del grafo" << endl;
           cout << "d. Mostrar las componentes conexas del grafo" << endl;
           cout << "e. Finalizar el programa" << endl;
           cout << "Introduzca la letra de la opcion a escoger:" << endl;
           cin >> opcion;   
       }
       

   
       //Cumplimentar por alumnado según pantallas de opciones en el guión u otras equivalentes
        
};


// El principal es simplemente un gestor de menu, diferenciando acciones para grafo dirigido y para no dirigido
int main(int argc, char *argv[])
{
    int error_apertura;
    char nombrefichero[85], opcion;

	clrscr();
    //Cargamos por defecto el fichero que se pasa como argumento del ejecutable
	if (argc > 1)
    {
		cout << "Cargando datos desde el fichero dado como argumento..." << endl;
        strcpy(nombrefichero, argv[1]);
    }
    else
    {
        cout << "Introduce el nombre completo del fichero de datos con el que quiere empezar a trabajar:" << endl;
        cin >> nombrefichero;
        cout<< "\nHa seleccionado: " << nombrefichero << endl;
		clrscr();
    }
    GRAFO G(nombrefichero, error_apertura);
    if (error_apertura == 1)
    {
        cout << "Error en la apertura del fichero: revisa nombre y formato." << endl;
    }
    else
    {
        do
        {
            menu(G.Es_dirigido(), opcion);
                if (G.Es_dirigido() == 1){
                    switch (opcion){   
                        case 'a': G.actualizar(nombrefichero, error_apertura);
                            while (error_apertura == 1)
                            {
                                G.actualizar(nombrefichero, error_apertura);
                            }
                            clrscr();
                            cout<< "\nHa pasado a trabajar con: " << nombrefichero << endl;
                            break;
                        case 'b':
                            clrscr();
                            cout << "La informacion del grafo " << nombrefichero << " es:" << endl;
                            G.Info_Grafo();
                            break;
                        case 'c': G.Mostrar_Listas(1);
                            break;
                        case 'd': G.Mostrar_Listas(0);
                            break;
                        case 'e': cout << "Ha escogido finalizar el programam, saludos." << endl;
                            return (0);
                    }
                }    
                else
                {
                    switch (opcion){
                        case 'a': G.actualizar(nombrefichero, error_apertura);
                            while (error_apertura == 1)
                            {
                                G.actualizar(nombrefichero, error_apertura);
                            }
                            clrscr();
                            cout<< "\nHa pasado a trabajar con: " << nombrefichero << endl;
                            break;
                        case 'b':
                            clrscr();
                            cout << "La informacion del grafo " << nombrefichero << " es:" << endl;
                            G.Info_Grafo();
                            break;
                        case 'c': G.Mostrar_Listas(1);
                            break;
                        case 'd': G.Mostrar_Listas(0);
                            break;
                        case 'e': cout << "\nHa escogido finalizar el programam saludos." << endl;
                            return (0);
                    }
                }
        }while (opcion != 'e');
    };
    cout << "Fin del programa";
	return(0);
};

