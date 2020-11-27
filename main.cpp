#include <iostream>
#include "videojuego.h"

using namespace std;

int main()
{
    Videojuego newGame;
    Civilizacion aux;
    Civilizacion* ptr;
    int op,temp;
    string cadena;

    do{
        cout<<endl;
        cout<<"1.- Nombre de usuario"<<endl;
        cout<<"2.- Agregar"<<endl;
        cout<<"3.- Insertar"<<endl;
        cout<<"4.- Inicializar "<<endl;
        cout<<"5.- Mostrar primero "<<endl;
        cout<<"6.- Mostrar ultimo"<<endl;
        cout<<"7.- Ordenar"<<endl;
        cout<<"8.- Eliminar"<<endl;
        cout<<"9.- Buscar "<<endl;
        cout<<"10.- Modificar "<<endl;
        cout<<"11.- Total"<<endl;
        cout<<"Elije una opcion: ";
        cin>>op;
        cin.ignore();
        cout<<endl;

        switch(op){
            case 1:
                cout<<"Ingrese el nombre del videojuego: ";
                getline(cin,cadena);
                newGame.setNombre(cadena);
                break;
            case 2:
                cin>>aux;
                newGame.agregar(aux);
                break;
            case 3:
                cout<<"Posicion: ";
                cin>>temp;
                cin.ignore();
                cin>>aux;
                newGame.insertar(aux,temp);
                break;
            case 4:
                cout<<"n: ";
                cin>>temp;
                cin.ignore();
                cin>>aux;
                newGame.inicializar(aux,temp);
                break;
            case 5:
                if(newGame.tam()<1)
                    cout<<"El arreglo esta vacio"<<endl;
                else{
                    aux = newGame.primero();
                    cout<< aux.toString()<<endl;
                }

                break;
            case 6:
                if(newGame.tam()<1)
                    cout<<"El arreglo esta vacio"<<endl;
                else{
                    aux = newGame.ultimo();
                    cout<< aux.toString()<<endl;
                }
                break;
            case 7:
                cout<<"Ordenas por"<<endl;
                cout<<"1.- Nombre"<<endl;
                cout<<"2.- Coordenada x"<<endl;
                cout<<"3.- Coordenada y"<<endl;
                cout<<"4.- Puntuacion"<<endl;
                cout<<"Elige una opcion: ";
                cin>>op;cin.ignore();

                switch(op){
                    case 1:newGame.ordenarNombre();break;
                    case 2:newGame.ordenarCoordenadaX();break;
                    case 3:newGame.ordenarCoordenadaY();break;
                    case 4:newGame.ordenarPuntuacion();break;
                }
                break;
            case 8:
                cout<<"Nombre de civilizacion: ";
                getline(cin,cadena);
                newGame.eliminar(cadena);
                break;
            case 9:
                cout<<"Nombre de civilizacion: ";
                getline(cin,cadena);
                aux.setNombre(cadena);
                ptr = newGame.buscar(aux);
                if(ptr == nullptr)
                    cout<<"No se ha encontrado el elemento"<<endl;
                else{
                    cout<<"Se ha encontrado el elemento a buscar:"<<endl;
                    cout<< ptr->toString() <<endl;
                }
                break;
            case 10:
                cout<<"Nombre de civilizacion: ";
                getline(cin,cadena);
                aux.setNombre(cadena);
                ptr = newGame.buscar(aux);
                if(ptr == nullptr)
                    cout<<"No se ha encontrado el elemento"<<endl;
                else{
                    cout<<"Se ha encontrado el elemento a buscar:"<<endl;
                    cout<< ptr->toString() <<endl<<endl;
                    cout<<"Modificar"<<endl;
                    cout<<"1.- Nombre"<<endl;
                    cout<<"2.- Ubicacion"<<endl;
                    cout<<"3.- Puntuacion"<<endl;
                    cout<<"Elija una opcion: ";
                    cin>>op; cin.ignore();

                    switch(op){
                        case 1:
                            cout<<"Ingrese el nuevo nombre: ";
                            getline(cin,cadena);
                            ptr->setNombre(cadena);
                            break;
                        case 2:
                            cout<<"Ingrese la nueva coordenada de x:";
                            cin>>temp;cin.ignore();
                            ptr->setX(temp);
                            cout<<"Ingrese la nueva coordenada de y:";
                            cin>>temp;cin.ignore();
                            ptr->setY(temp);
                            break;
                        case 3:
                            cout<<"Ingrese la nueva puntuacion:";
                            cin>>temp;cin.ignore();
                            ptr->setPuntuacion(temp);
                            break;
                    }

                }
                break;
            case 11:
                newGame.toString();
                break;
            case 0:
                cout<<endl<<"Hasta luego :3"<<endl;
                break;
            default:
                cout<<endl<<"No es una opcion valida"<<endl;
        }

    }while(op != 0);

    return 0;
}
