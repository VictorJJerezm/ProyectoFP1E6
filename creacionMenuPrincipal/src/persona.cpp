#include <iostream>
#include "persona.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
/*
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
        cout << "\t\t\t\t  2. Generaci�n de Nomina"<<endl;
        cout << "\t\t\t\t  3. Informes de Nomina"<<endl;
        cout << "\t\t\t\t  4. Transferencia bancaria"<<endl;
        cout << "\t\t\t\t  5. Generaci�n de Poliza"<<endl;
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
    		cout << "\t\t\t\t �Quieres seguir en el apartado de Mantenimientos? (S/N)";
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
}*/
///Menu de generaci�n de Poliza
void persona::generacionP()
{
    int choice;
    char v;
    do
    {
        system("cls");
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t    | Generacion de Poliza de la empresa |"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t  1. Ingreso de informaci�n"<<endl;
        cout << "\t\t\t\t  2. Desplegar informaci�n"<<endl;
        cout << "\t\t\t\t  3. Salir"<<endl;

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t  Opcion a escoger: [1/2/3]"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Selecciona tu opcion: "<<endl;
        cin >> choice;

        switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Ingresar mas informacion(S,N): ";
    		cin>>v;
		}while(v=='s'||v=='S');
		break;
	case 2:
		desplegarI();
		break;
	case 3:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 3);
}
