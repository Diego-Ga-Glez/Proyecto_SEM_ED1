#include "aldeano.h"

using namespace std;

Aldeano::Aldeano(){}

void Aldeano::setNombre(string& _nombre){
    nombre = _nombre;
}

void Aldeano::setEdad(int& _edad){
    edad = _edad;
}

void Aldeano::setGenero(string& _genero){
    genero = _genero;
}

void Aldeano::setSalud(int& _salud){
    salud = _salud;
}

string Aldeano::getNombre() const{
    return nombre;
}

int Aldeano::getEdad() const{
    return edad;
}

string Aldeano::getGenero() const{
    return genero;
}

int Aldeano::getSalud() const{
    return salud;
}

string Aldeano::toString(){
    return "Nombre Aldeano: " + nombre + " | " +
           "Edad: " + to_string(edad) + " | " +
           "Genero: " + genero + " | " +
           "Salud: " + to_string(salud) + " | ";
}

bool Aldeano::operator== (const Aldeano &a){
    return nombre == a.nombre;
}


ostream& operator <<(ostream& out, const Aldeano& a){
    out << left;
    out << setw(15) << a.nombre;
    out << setw(10) << a.edad;
    out << setw(15) << a.genero;
    out << setw(10) << a.salud;
    out << endl;
    return out;
}

istream& operator >> (istream &in, Aldeano& a){
    cout<<"Nuevo aldeano"<<endl;
    cout<<"Ingrese el nombre: ";
    getline(cin,a.nombre);
    cout<<"Ingrese edad: ";
    cin>>a.edad;cin.ignore();
    cout<<"Ingrese genero: ";
    getline(cin,a.genero);
    cout<<"Ingrese salud: ";
    cin>>a.salud;cin.ignore();

    return in;
}