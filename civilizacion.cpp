#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){};

Civilizacion::Civilizacion(const Civilizacion& c):nombre(c.nombre),x(c.x),y(c.y), puntuacion(c.puntuacion){}

Civilizacion& Civilizacion::operator=(const Civilizacion &c){
    nombre = c.nombre;
    x = c.x;
    y = c.y;
    puntuacion = c.puntuacion;
    return *this;
}

void Civilizacion::setNombre(const string& _nombre){
    nombre = _nombre;
}

void Civilizacion::setX(const int& _x){
    x = _x;
}

void Civilizacion::setY(const int& _y){
    y = _y;
}

void Civilizacion::setPuntuacion(const int& _puntuacion){
    puntuacion = _puntuacion;
}

string Civilizacion::getNombre() const{
    return nombre;
}

int Civilizacion::getX() const{
    return x;
}

int Civilizacion::getY() const{
    return y;
}

int Civilizacion::getPuntuacion() const{
    return puntuacion;
}

string Civilizacion::toString(){
   return "Civilizacion: " + nombre +" | "+
           "Coordenadas en x: "+ to_string(x) + " | "+
           "Coordenadas en y: "+ to_string(y) + " | "+
           "Puntuacion: "+ to_string(puntuacion) + " | ";
}

bool Civilizacion::operator== (const Civilizacion& c){
    return nombre == c.nombre;
}

ostream& operator << (ostream &out, const Civilizacion& c){
    out << left;
    out << setw(15) << c.nombre;
    out << setw(20) << c.x;
    out << setw(20) << c.y;
    out << setw(10) << c.puntuacion;
    out << endl;
    return out;
}

istream& operator >> (istream &in, Civilizacion& c){

    cout<<"Nueva civilizacion"<<endl;
    cout<<"Ingrese el nombre: ";
    getline(cin, c.nombre);
    cout<<"Ingrese las coordenadas en x: ";
    cin>>c.x;
    cout<<"Ingrese las coordenadas en y: ";
    cin>>c.y;
    cout<<"Ingrese la puntuacion: ";
    cin>>c.puntuacion;
    cin.ignore();

    return in;
}

