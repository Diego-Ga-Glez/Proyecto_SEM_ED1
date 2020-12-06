#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include <fstream>
#include "aldeano.h"

class Civilizacion{
    private:
        std::string nombre;
        int x;
        int y;
        int puntuacion;
        std::list<Aldeano> aldeanos;

    public:
        Civilizacion();

        void setNombre(const std::string&);
        void setX(const int&);
        void setY(const int&);
        void setPuntuacion(const int&);

        std::string getNombre() const;
        int getX() const;
        int getY() const;
        int getPuntuacion() const;

        std::string toString();
        bool operator == (const Civilizacion&);

        void agregarFinal(const Aldeano&);
        void agregarInicio(const Aldeano&);
        void imprimirAldeanos();
        void eliminarNombre(const std::string&);
        void eliminarSalud(const int&);
        void eliminarEdad();
        void ordenarNombre();
        void ordenarEdad();
        void ordenarSalud();
        Aldeano* buscar(const Aldeano&);

        void respaldar_aldeanos();
        void recuperar_aldeanos();
         void anular_aldeanos();


        friend std::ostream& operator <<(std::ostream&, const Civilizacion&);
        friend std::istream& operator >>(std::istream&, Civilizacion&);


};

#endif // CIVILIZACION_H_INCLUDED
