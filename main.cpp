#include <iostream>
#include "videojuego.h"

using namespace std;

void menuOrdenar(Videojuego&);
void menuModificar(Civilizacion*);
void menuAldeano(Civilizacion*);
void menuModificarAldeano(Aldeano*);

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
        cout<<"12.- Respaldar"<<endl;
        cout<<"13.- Recuperar"<<endl;
        cout<<"0.- Salir"<<endl;
        cout<<"Elije una opcion: ";

        switch(op){
            case 1:
                cout<<"Ingrese su nombre de usuario: ";
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
                menuOrdenar(newGame);
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
                    menuAldeano(ptr);
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
                    cout<< ptr->toString() <<endl;
                    menuModificar(ptr);
                }
                break;
            case 11:
                newGame.toString();
                break;
            case 12:
                newGame.respaldar_civilizaciones();
                break;
            case 13:
                newGame.recuperar_civilizaciones();
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

void menuOrdenar(Videojuego &newGame){
    int op;
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
}

void menuModificar(Civilizacion* ptr){
    string cadena;
    int temp,op;
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

void menuAldeano(Civilizacion* ptr){
    string cadena;
    int op,temp;
    Aldeano aux;
    Aldeano* ptrA;
    do{
        cout<<endl;
        cout<<"Menu aldeanos"<<endl;
        cout<<"1.- Agregar"<<endl;
        cout<<"2.- Eliminar"<<endl;
        cout<<"3.- Clasificar"<<endl;
        cout<<"4.- Buscar"<<endl;
        cout<<"5.- Modificar"<<endl;
        cout<<"6.- Mostrar aldeanos"<<endl;
        cout<<"0.- Salir"<<endl;
        cout<<"Elija una opcion: ";
        cin>>op; cin.ignore();
        cout<<endl;

        switch(op){
            case 1:
                cout<<endl<<"1.- Agregar al final"<<endl;
                cout<<"2.- Agregar al inicio"<<endl;
                cout<<"Elija una opcion: ";
                cin>>op;cin.ignore();

                switch(op){
                    case 1:
                        cin>>aux;
                        ptr->agregarFinal(aux);
                        temp = ptr->getPuntuacion() + 100;
                        ptr->setPuntuacion(temp);
                        break;
                    case 2:
                        cin>>aux;
                        ptr->agregarInicio(aux);
                        temp = ptr->getPuntuacion() + 100;
                        ptr->setPuntuacion(temp);
                        break;
                }
                break;
            case 2:
                cout<<endl<<"1.- Eliminar por nombre"<<endl;
                cout<<"2.- Eliminar aldeanos con salud menor a x"<<endl;
                cout<<"3.- Eliminar aldeanos con edad mayor o igual a 60"<<endl;
                cout<<"Elija una opcion: ";
                cin>>op;cin.ignore();
                switch(op){
                    case 1:
                        cout<<endl<<"Ingrese el nombre del aldeano: ";
                        getline(cin,cadena);
                        ptr->eliminarNombre(cadena);
                        break;
                    case 2:
                        cout<<"x: ";
                        cin>>temp; cin.ignore();
                        ptr->eliminarSalud(temp);
                        break;
                    case 3:
                        ptr->eliminarEdad();
                        break;
                }
                break;
            case 3:
                cout<<endl<<"1.- Clasificar por nombre (ascendente)"<<endl;
                cout<<"2.- Clasificar por edad (descendente)"<<endl;
                cout<<"3.- Ordenar por salud (descendente)"<<endl;
                cout<<"Elija una opcion: ";
                cin>>op; cin.ignore();

                switch(op){
                    case 1:ptr->ordenarNombre();break;
                    case 2:ptr->ordenarEdad();break;
                    case 3:ptr->ordenarSalud();break;
                }
                break;
            case 4:
                cout<<"Nombre del aldeano: ";
                getline(cin,cadena);
                aux.setNombre(cadena);
                ptrA = ptr->buscar(aux);
                if(ptrA == nullptr)
                    cout<<"No se ha encontrado el elemento"<<endl;
                else{
                    cout<<"Se ha encontrado el elemento a buscar:"<<endl;
                    cout<< ptrA->toString() <<endl; 
                }
                break;
            case 5:
                cout<<"Nombre del aldeano: ";
                getline(cin,cadena);
                aux.setNombre(cadena);
                ptrA = ptr->buscar(aux);
                if(ptrA == nullptr)
                    cout<<"No se ha encontrado el elemento"<<endl;
                else{
                    cout<<"Se ha encontrado el elemento a buscar:"<<endl;
                    cout<< ptrA->toString() <<endl; 
                    menuModificarAldeano(ptrA);
                }
                break;
            case 6:
                ptr->imprimirAldeanos();
                break;
        }
    }while(op != 0);
}

void menuModificarAldeano(Aldeano* ptr){
    int op,temp;
    string cadena;
    
    cout<<endl;
    cout<<"Modificar Aldeano"<<endl;
    cout<<"1.- Nombre"<<endl;
    cout<<"2.- Edad"<<endl;
    cout<<"3.- Genero"<<endl;
    cout<<"4.- Salud"<<endl;
    cout<<"Elija una opcion: ";
    cin>>op; cin.ignore();
    cout<<endl;

    switch (op)
    {
        case 1:
            cout<<"Ingrese el nuevo nombre";
            getline(cin, cadena);
            ptr->setNombre(cadena);
            break;
        case 2:
            cout<<"Ingrse la nueva edad: ";
            cin>>temp;cin.ignore();
            ptr->setEdad(temp); 
            break;
        case 3:
        cout<<"Ingrese el nuevo genero";
            getline(cin, cadena);
            ptr->setGenero(cadena); 
            break;
        case 4:
            cout<<"Ingrse la nueva salud: ";
            cin>>temp;cin.ignore();
            ptr->setSalud(temp); 
            break;
    
    
    }
}