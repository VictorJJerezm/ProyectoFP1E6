#include <iostream>
#ifndef IMPUESTOS_H
#define IMPUESTOS_H

using namespace std;

class impuestos
{
    public:
        impuestos(int = 0, string = "", double = 0);

    // funciones de acceso para numeroCuenta
   void establecerNumeroId( int );
   int obtenerNumeroId() const;

   // funciones de acceso para primerNombre
   void establecerUsuario( string );
   string obtenerUsuario() const;

   // funciones de acceso para el saldo
   void establecerSueldo( double );
   double obtenerSueldo() const;

    private:
        int numeroId;
        char usuario[ 10 ];
        double sueldo;

};

#endif // IMPUESTOS_H
