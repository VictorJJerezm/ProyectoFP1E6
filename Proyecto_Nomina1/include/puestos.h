#include <iostream>
#ifndef PUESTOS_H
#define PUESTOS_H
using namespace std;

class Puestos
{
    public:
        Puestos();
        virtual ~Puestos();
        void menu();
        void insertar();
        void desplegar();
        void buscar();
        void modificar();
        void borrar();

    protected:
        private:
};

#endif
