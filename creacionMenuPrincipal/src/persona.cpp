#include <iostream>
#include "persona.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

persona::persona()
{
    //ctor
}

persona::~persona()
{
    //dtor
}
void persona::menu()
{
    int choice;
    char s;
    do
    {
        system ("cls");

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t    | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t  1. Manteniminetos"<<endl;
        cout << "\t\t\t\t  2. Generación de Nomina"<<endl;
        cout << "\t\t\t\t  3. Informes de Nomina"<<endl;
        cout << "\t\t\t\t  4. Transferencia bancaria"<<endl;
        cout << "\t\t\t\t  5. Generación de Poliza"<<endl;
        cout << "\t\t\t\t  6. Impuestos"<<endl;
        cout << "\t\t\t\t  7. Salir"<<endl;

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Selecciona tu opcion: "<<endl;
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
	case 2:
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
        break;
	case 7:
		exit(0);
	default:
		cout << "\t\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 7);
}

