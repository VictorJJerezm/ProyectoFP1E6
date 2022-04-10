#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "usuario.h"
#include "empleados.h"


using namespace std;

usuario::usuario()
{
    //ctor
}

usuario::~usuario()
{
    //dtor
}
void usuario::menu()
{
    int choice;
    char s;
    do

    {
    system("cls");
    cout << "*********************************************"<<endl;
    cout << "   | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
    cout << "*********************************************"<<endl;
    cout << " 1. Ingresar"<<endl;
    cout << " 2. Salir"<<endl;

    cout << "*********************************************"<<endl;
    cout << "Opcion a escoger : [1/2]"<<endl;
    cout << "*********************************************"<<endl;
    cout << "Selecciona tu opcion: "<<endl;
    cin>>choice;

    switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        exit(0);
                        break;
                default:

                        cout<<"Hiciste algo mal, prueba otra vez"<<endl;

        }
        getch();
    }while(choice!= 2);
}

void usuario::login()
{
    int count;
    string nombre, contra, n, c;
    system("cls");
    cout << "*********************************************"<<endl;
    cout << "          | Ingresar al Sistema |"<<endl;
    cout << "*********************************************"<<endl;
    cout << " Nombre de Usuario:"<<endl;
    cin >>nombre;
    cout << " Contraseña:"<<endl;
    cin >>contra;

    ifstream input("RegistroUP.txt");
        while(input>>n>>c)
        {
                if(n==nombre && c==contra)

                {
                        count=0;
                        system("cls");
                }
        }
        input.close();
        if(count==0)
        {
                cout<<"\nHola "<< nombre<<"\nTu Ingreso ha sido Exitoso!";
                cin.get();
                cin.get();
                usuario::menu1();


        }
        else
        {
                cout<<"\nError en el accesos\nEl usuario o contraseña son invalidos\n";
        }
}

void usuario::menu1()
{
    int choice;
    char s;
    do
    {
        system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t    | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Manteniminetos"<<endl;
        cout << "\t\t\t  2. Generacion de Nomina"<<endl;
        cout << "\t\t\t  3. Informes de Nomina"<<endl;
        cout << "\t\t\t  4. Transferencia bancaria"<<endl;
        cout << "\t\t\t  5. Generación de Poliza"<<endl;
        cout << "\t\t\t  6. Impuestos"<<endl;
        cout << "\t\t\t  7. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		mantenimientos();
    		cout << "\t\t\t\t ¿Quieres seguir en el apartado de Mantenimientos? (S/N)";
    		cin>>s;
		}while(s=='s'||s=='S');
		break;
	/*case 2:
		generacionN();
		break;
	case 3:
		informesN();
		break;
	case 4:
		transferenciaB();
		break;
	case 5:
		generacionP();
		break;
    case 6:
        impuestos();
        break;*/
	case 7:
		exit(0);
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 7);
}

void usuario::mantenimientos()
{
    int choice;
    char s;
    do
    {


    system ("cls");

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t      | Menu Mantenimientos - Grupo 6 |"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t  1. Mantenimiento de Empleados"<<endl;
        cout << "\t\t\t  2. Mantenimiento de Puestos"<<endl;
        cout << "\t\t\t  3. Mantenimiento de Departamentos"<<endl;
        cout << "\t\t\t  4. Mantenimiento de Impuestos"<<endl;
        cout << "\t\t\t  5. Mantenimiento de Bancos"<<endl;
        cout << "\t\t\t  6. Mantenimiento de Empresas"<<endl;
        cout << "\t\t\t  7. Salir"<<endl;

        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
        cout << "\t\t\t *********************************************"<<endl;
        cout << "\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;

        switch(choice)
        {
    case 1:
    	do
    	{
    		escribirOpcion();
    		cout << "\t\t\t ¿Quieres seguir en el apartado de empleados? (S/N)";
    		cin>>s;
		}while(s=='s'||s=='S');
		break;
		 /*case 2:
		generacionN();
		break;
	case 3:
		informesN();
		break;
	case 4:
		transferenciaB();
		break;
	case 5:
		generacionP();
		break;
    case 6:
        impuestos();
        break;*/
	case 7:
		exit(0);
	default:
		cout << "\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 7);

}

int usuario::escribirOpcion()
{

    system("cls");
    int choice();

   cout << "\t\t\t *********************************************" << endl
        << "\t\t\t           | Menu de Empleados |" << endl
        << "\t\t\t *********************************************" << endl
        << "\t\t\t 1 - Ingresar empleados" << endl
        << "\t\t\t 2 - Desplegar empleados" << endl
        << "\t\t\t 3 - Buscar empleados" << endl
        << "\t\t\t 4 - Borrar empleados "<< endl
        << "\t\t\t 5 - Salir "<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\t\t\t Ingresa tu opcion [1/2/3/4/5]"<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\n\t\t\t Opcion: ";


}


