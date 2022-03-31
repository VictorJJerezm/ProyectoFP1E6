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
}/*
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
		break;/*
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
///Se agrega Menu de impuestos
void persona::impuestos()
{
    int choice;
        char l;
        do
        {
            system ("cls");

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t            | Calculo de Impuestos |"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t  1. Ingreso de sueldos"<<endl;
        cout << "\t\t\t\t  2. Visualizar Impuestos"<<endl;
        cout << "\t\t\t\t  3. Visualizar sueldos"<<endl;
        cout << "\t\t\t\t  4. Calculo de sueldos"<<endl;
        cout << "\t\t\t\t  5. Visuzalizar retenciones"<<endl;
        cout << "\t\t\t\t  6. Salir"<<endl;

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Opcion a escoger: [1/2/3/4/5]"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Selecciona tu opcion: "<<endl;
        cin choice;

        switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agregar otro sueldo(S,N): ";
    		cin>>l;
		}while(l=='s'||l=='S');
		break;
	case 2:
		visualizarI();
		break;
	case 3:
		visualizarS();
		break;
	case 4:
		calculoS();
		break;
    case 5:
        visualizarR();
        break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
        }
=======
} */
void persona::informesN()
{
int id, phone, dia, salario;
	string name;


	system("cls");
	fstream file;
    cout << "\t\t\t\t *********************************************************************"<<endl;
    cout << "\t\t\t\t ****************|Generar Informes de nomina|************"<<endl;
    cout << "\t\t\t\t *********************************************************************"<<endl;

	cout<<"\n   Ingrese los datos del empleado"<<endl;
    cout<<"\t\t\tIngresar ID del empleado         : ";
	cin>>id;
	cout<<"\t\t\tIngresar Nombre del empleado     : ";
	cin>>name;
	cout<<"\t\t\tIngresar Celular del empleado  : ";
	cin>>phone;
	cout<<"\t\t\tIngresar dias laborados   : ";
	cin>>dia;
	cout<<"\t\t\tIngresar salario basico   : ";
	cin>>salario;
	file.open("informesNomina.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15) << dia <<std::left<<std::setw(15) << salario <<std::left<<std::setw(15) <<"\n";
	file.close();

}
