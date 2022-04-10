#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
#include "impuestos.h"

int escribirOpcion();
void crearArchivoCredito();
void nuevoRegistro( fstream& );
void consultarRegistro( fstream& );
void buscarRegistro(fstream&);
int obtenerId( const char * const );
void mostrarLineaPantalla( const impuestos &);
void actualizarRegistro( fstream& );
void mostrarLinea( ostream&, const impuestos & );
void eliminarRegistro( fstream& );
void calcularSueldo(fstream&);
void obtenerSueldo( const char * const);

enum Opciones { Ingresar = 1, Consultar, Buscar, Borrar, FIN };

int main()
{
    fstream creditoEntradaSalida( "Informacion.dat", ios::in | ios::out | ios::binary);

    if ( !creditoEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      crearArchivoCredito();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    int opcion;

   // permitir al usuario que especifique la acción
   while ( ( opcion = escribirOpcion() ) != FIN ) {

      switch ( opcion ) {

         // crear el archivo de texto a partir del archivo de registros
         case Ingresar:
            nuevoRegistro( creditoEntradaSalida );
            break;

         // actualizar registro
         case Consultar:
            consultarRegistro( creditoEntradaSalida );
            break;

         case Buscar:
            buscarRegistro(creditoEntradaSalida);
            break;

         case Borrar:
            eliminarRegistro( creditoEntradaSalida );
            break;
         // consultar registros existentes por pantalla
         default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } // fin de instrucción switch

      creditoEntradaSalida.clear(); // reinicializar indicador de fin de archivo

   } // fin de instrucción while

   return 0;
}
int escribirOpcion()
{
   // mostrar opciones disponibles
   cout << "\t\t\t *********************************************" << endl
        << "\t\t\t           | Menu de Conceptos |" << endl
        << "\t\t\t *********************************************" << endl
        << "\t\t\t 1 - Ingresar informacion salarial" << endl
        << "\t\t\t 2 - Desplegar informacion salarial" << endl
        << "\t\t\t 3 - Buscar inforacion salarial" << endl
        << "\t\t\t 4 - Borrar informacion salarial "<< endl
        << "\t\t\t 5 - Salir "<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\t\t\t Ingresa tu opcion [1/2/3/4/5]"<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\n\t\t\t Opcion: ";

   int opcionMenu;
   cin >> opcionMenu; // recibir opción del usuario

   return opcionMenu;

} // fin de la función escribirOpcion

void nuevoRegistro( fstream &insertarEnArchivo )
{
    system("cls");
   // obtener el número de cuenta a crear
   int numeroId = obtenerId( "Escriba el ID que desea asignar: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   // leer el registro del archivo
   impuestos persona;
   insertarEnArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   // crear el registro, si éste no existe ya
   if ( persona.obtenerNumeroId() == 0 ) {

      char usuario[ 10 ];
      double sueldo;

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el nombre de usuario: " << endl;
      cin >> setw( 10 ) >> usuario;
      cout << "Escriba el sueldo: " << endl;
      cin >> sueldo;

      // usar valores para llenar los valores de la cuenta
      persona.establecerUsuario( usuario );
      persona.establecerSueldo( sueldo );
      persona.establecerNumeroId( numeroId );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &persona ),
         sizeof( impuestos ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta # " << numeroId
           << " ya contiene informacion." << endl;
    system("cls");

} // fin de la función nuevoRegistro

void consultarRegistro( fstream &leerDeArchivo )
{
    system("cls");
   cout << left << setw( 10 ) << "ID" << setw( 14 ) << "Usuario" << right<< setw( 10 ) << "Sueldo" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   impuestos persona;
   leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( persona.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(persona);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
         sizeof( impuestos ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

void buscarRegistro( fstream &buscarArchivo )
{
    system("cls");
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el Id de la persona a buscar: " );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    buscarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   // leer el primer registro del archivo
    impuestos persona;
   buscarArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   // actualizar el registro
   if ( persona.obtenerNumeroId() != 0 ) {
      mostrarLinea( cout, persona );
   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroId
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

void eliminarRegistro( fstream &eliminarDeArchivo )
{
    system("cls");
   // obtener número de cuenta a eliminar
   int numeroId = obtenerId( "Escriba el Id de la persona a eliminar: " );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   // leer el registro del archivo
   impuestos persona;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   // eliminar el registro, si es que existe en el archivo
   if ( persona.obtenerNumeroId() != 0 ) {
      impuestos clienteEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );

      cout << "Informacion #" << numeroId << " eliminada.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "La posicion #" << numeroId << " esta vacia.\n";

} // fin de eliminarRegistro

/*void calcularSueldo( fstream &buscarArchivo )
{
    system("cls");
   // obtener el número de cuenta a actualizar
   int numeroId = obtenerId( "Escriba el Id de la persona a buscar: " );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
    buscarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

    float sueldo = obtenerSueldo( sueldo );
    float sueldoCal = sueldo - sueldo*0.0483;
    float sueldoBon = sueldoCal + 250;

   // leer el primer registro del archivo
    impuestos persona;
   buscarArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   // actualizar el registro


   if ( persona.obtenerNumeroId() != 0 ) {
      mostrarLinea( cout, persona );

    cout << "El sueldo calculado es: "<<sueldoBon;
   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroId
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro*/

int obtenerId( const char * const indicador )
{
   int numeroId;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 100 );

   return numeroId;

} // fin de la función obtenerCuenta

/*int obtenerSueldo( const char * const indicador )
{
   int sueldo;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 100 );

   return sueldo;

} // fin de la función obtenerCuenta*/

void mostrarLinea( ostream &salida, const impuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

} // fin de la función mostrarLinea

void mostrarLineaPantalla( const impuestos &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

} // fin de la función mostrarLineaPantalla

void crearArchivoCredito()
{
    ofstream creditoSalida( "Informacion.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   impuestos clienteEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 100; i++ )
      creditoSalida.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );
}
