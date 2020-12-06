#ifndef VIDEOJUEGO_H_INCLUDED
#define VIDEOJUEGO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "civilizacion.h"

class Videojuego{
    private:
        std::string nombreUsuario;
        std::vector<Civilizacion> civilizaciones;

    public:
        Videojuego();

        void setNombre(const std::string&);
        std::string getNombre() const;


        int tam();
        void agregar(const Civilizacion&);
        void insertar(const Civilizacion&, const int&);     //No debe de hablar con el usuario
        void inicializar(const Civilizacion&, const int&);
        Civilizacion primero();             //No debe de hablar con el usuario
        Civilizacion ultimo();      //No debe de hablar con el usuario
        void ordenarNombre();
        void ordenarCoordenadaX();
        void ordenarCoordenadaY();
        void ordenarPuntuacion();
        void eliminar(const std::string&);
        Civilizacion* buscar(const Civilizacion&);
        void toString();

        void respaldar_civilizaciones();
        void recuperar_civilizaciones();
        



};

#endif // VIDEOJUEGO_H_INCLUDED
