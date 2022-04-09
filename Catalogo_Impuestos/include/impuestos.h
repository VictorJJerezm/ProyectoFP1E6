#include <iostream>
#ifndef IMPUESTOS_H
#define IMPUESTOS_H

using namespace std;


class impuestos
{
    public:
        impuestos();
        virtual ~impuestos();
        void menu();
        void insert();
        void desplegar();
        void calcular();
        void modificar();
        void buscar();
        void borrar();


    protected:

    private:
        string id, nombre;
        int sueldo;
};

#endif // IMPUESTOS_H
