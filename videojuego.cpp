#include "videojuego.h"

using namespace std;

Videojuego::Videojuego(){}

void Videojuego::setNombre(const std::string& _nombre){
    nombreUsuario = _nombre;
}

string Videojuego::getNombre() const{
    return nombreUsuario;
}

int Videojuego::tam(){
    return civilizaciones.size();
}

void Videojuego::agregar(const Civilizacion &c){
    civilizaciones.push_back(c);
}

void Videojuego::insertar(const Civilizacion &c, const int &n){
    if(n < 0 or n >= tam())
        cout<<"Posicion no valida :("<<endl;
    else
        civilizaciones.insert(civilizaciones.begin()+n,c);
}

void Videojuego::inicializar(const Civilizacion &c, const int &n){
    civilizaciones = vector<Civilizacion>(n,c);
}

Civilizacion Videojuego::primero(){
    return civilizaciones.front();
}

Civilizacion Videojuego::ultimo(){
    return civilizaciones.back();
}

void Videojuego::ordenarNombre(){
    sort(civilizaciones.begin(),civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}

void Videojuego::ordenarCoordenadaX(){
    sort(civilizaciones.begin(),civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}

void Videojuego::ordenarCoordenadaY(){
    sort(civilizaciones.begin(),civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getY() < c2.getY();});
}

void Videojuego::ordenarPuntuacion(){
    sort(civilizaciones.begin(),civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}

void Videojuego::eliminar(const string &nombre){
    int i = 0;

    while(i<= tam()){

        if(civilizaciones[i].getNombre() == nombre){
            civilizaciones.erase(civilizaciones.begin()+ i);
            cout<<"Se ha eliminado con exito la civilizacion "<< nombre<<"..."<<endl;
            break;
        }
        i++;
    }
}

Civilizacion* Videojuego::buscar(const Civilizacion& c){

    auto it = find(civilizaciones.begin(), civilizaciones.end(),c);

    if(it == civilizaciones.end())
        return nullptr;
    else
        return &(*it);
}

void Videojuego::toString(){
    cout<< left;
    cout<<setw(15)<<"CIVIlIZACION";
    cout<<setw(20)<<"COORDENADA EN X";
    cout<<setw(20)<<"CORRDENADA EN Y";
    cout<<setw(10)<<"PUNTUACION";
    cout<<endl;

    for(int i = 0; i<civilizaciones.size(); i++){
        cout << civilizaciones[i];
    }
}
