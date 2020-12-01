#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>

class Aldeano{
    private:
        std::string nombre;
        int edad;
        std::string genero;
        int salud;
    public:
        Aldeano();

        void setNombre(std::string&);
        void setEdad(int&);
        void setGenero(std::string&);
        void setSalud(int&);

        std::string getNombre() const;
        int getEdad() const;
        std::string getGenero() const;
        int getSalud() const;

        std::string toString();

        bool operator == (const Aldeano&);

        friend std::ostream& operator <<(std::ostream&, const Aldeano&);
        friend std::istream& operator >>(std::istream&, Aldeano&);

};

#endif //ALDEANO_H_INCLUDED