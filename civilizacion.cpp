#include "civilizacion.h"

using namespace std;

Civilizacion::Civilizacion(){};

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

void Civilizacion::agregarFinal(const Aldeano& a){
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a){
    aldeanos.push_front(a);
}

void Civilizacion::imprimirAldeanos(){
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(10) << "Edad";
    cout << setw(15) << "Genero";
    cout << setw(10) << "Salud";
    cout<<endl;

    for(auto it = aldeanos.begin(); it!= aldeanos.end(); it++){
            cout<< *it;
    }
}

void Civilizacion::eliminarNombre(const string& nombre){
    for(auto it = aldeanos.begin(); it!= aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            aldeanos.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarSalud(const int& salud){
    aldeanos.remove_if([salud](const Aldeano& a){ return a.getSalud()< salud;});
}

void Civilizacion::eliminarEdad(){
    aldeanos.remove_if([](const Aldeano& a){ return a.getEdad()>= 60;});
}

void Civilizacion::ordenarNombre(){
    aldeanos.sort([](const Aldeano& a1, const Aldeano& a2){return a1.getNombre() <a2.getNombre(); });
}

void Civilizacion::ordenarEdad(){
    aldeanos.sort([](const Aldeano& a1, const Aldeano& a2){return a1.getEdad() > a2.getEdad(); });
}

void Civilizacion::ordenarSalud(){
    aldeanos.sort([](const Aldeano& a1, const Aldeano& a2){return a1.getSalud() > a2.getSalud(); });
}

Aldeano* Civilizacion::buscar(const Aldeano& a){
    auto it = find(aldeanos.begin(), aldeanos.end(), a);

    if(it == aldeanos.end())
        return nullptr;
    else
        return &(*it);
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

void Civilizacion::respaldar_aldeanos(){
    ofstream aldeanos_archivo(getNombre() + ".txt", ios::out);
    
    for (auto it = aldeanos.begin(); it != aldeanos.end(); ++it) {
        Aldeano &aldeano = *it; 
        aldeanos_archivo << aldeano.getNombre() << endl;
        aldeanos_archivo << aldeano.getEdad()   << endl;
        aldeanos_archivo << aldeano.getGenero() << endl;
        aldeanos_archivo << aldeano.getSalud()  << endl;
    }
    aldeanos_archivo.close();
}

void Civilizacion::recuperar_aldeanos() {
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open()) {
        string temp;
        int aux;
        Aldeano a;

        while(true) {
            getline(archivo, temp);
            if(archivo.eof()) {
                break;
            }
            a.setNombre(temp);

            getline(archivo, temp);
            aux = stoi(temp);
            a.setEdad(aux);

            getline(archivo, temp);
            a.setGenero(temp);

            getline(archivo, temp);
            aux = stoi(temp);
            a.setSalud(aux);

            agregarFinal(a);
        }
    }
    archivo.close();
}

void Civilizacion::anular_aldeanos(){
    aldeanos.clear();
}
