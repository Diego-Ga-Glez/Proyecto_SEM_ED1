#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>

class Civilizacion{
    private:
        std::string nombre;
        int x;
        int y;
        int puntuacion;

    public:
        Civilizacion();
        Civilizacion(const Civilizacion&);
        Civilizacion& operator = (const Civilizacion&);

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

        friend std::ostream& operator <<(std::ostream&, const Civilizacion&);
        friend std::istream& operator >>(std::istream&, Civilizacion&);


};

#endif // CIVILIZACION_H_INCLUDED
