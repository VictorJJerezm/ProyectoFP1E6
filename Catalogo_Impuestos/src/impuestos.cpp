#include <iostream>
#include "impuestos.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


impuestos::impuestos()
{
    //ctor
    string id, nombre, sueldo;
}

impuestos::~impuestos()
{
    //dtor
}
void impuestos::menu()
{
    int choice;
	char r;
	do
    {
	system("cls");

	cout<<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t         |   Menu de Conceptos  |"<<endl;
    cout<<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t 1. Ingresar informacion salarial"<<endl;
	cout<<"\t\t\t 2. Desplegar informacion salarial "<<endl;
	cout<<"\t\t\t 3. Calculo de sueldos "<<endl;
	cout<<"\t\t\t 4. Modificar informacion salarial"<<endl;
	cout<<"\t\t\t 5. Buscar informacion salarial"<<endl;
	cout<<"\t\t\t 6. Borrar informacion salarial"<<endl;
	cout<<"\t\t\t 7. Exit"<<endl;

	cout<<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t*********************************************"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\n\t\t\t Agregar informacion de otra persona(S,N): ";
    		cin>>r;
		}while(r=='s'||r=='S');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		calcular();
		break;
    case 4:
        modificar();
        break;
	case 5:
		buscar();
		break;
	case 6:
		borrar();
		break;
	case 7:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 7);
}

void impuestos::insert()
{
	system("cls");
	fstream file;
	cout <<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t     | Ingresar informacion del empleado | "<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t Ingresa Id del empleado: ";
	cin>>id;
	cout<<"\t\t\t Ingresa el nombre del empleado: ";
	cin>>nombre;
	cout<<"\t\t\t Ingresa el sueldo neto del empleado: ";
	cin>>sueldo;
	cout<<"\n\n\t\t\t ¡El ingreso fue exitoso! ";
	file.open("InformacionS.txt", ios::app | ios::out | ios::binary);
	file<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< sueldo<< "\n";
	file.close();
}

void impuestos::desplegar()
{
	system("cls");
	fstream file;
	int total=0;

	cout <<"\t\t\t*********************************************"<<endl;
	cout<<"\t\t\t         | Informacion de Empleados | "<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("InformacionS.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> sueldo;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Empleado: "<<id<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombre<<endl;
			cout<<"\t\t\t Sueldo Neto Empleado: "<<sueldo<<endl;
			file >> id >> nombre >> sueldo;
		}
		cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

void impuestos::calcular()
{
    system("cls");
	fstream file;
	int found=0;
	file.open("InformacionS.txt",ios::in);
	if(!file)
	{
		cout <<"\t\t\t*********************************************"<<endl;
		cout <<"\t\t\t              | Calculos |"<<endl;
		cout <<"\t\t\t*********************************************"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string id_persona;
		float sueldoCal;
		float sueldobon;
		cout <<"\t\t\t*********************************************"<<endl;
		cout <<"\t\t\t              | Calculos |"<<endl;
		cout <<"\t\t\t*********************************************"<<endl;
		cout<<"\nIngrese Id del empleado que quiere calcular el sueldo: ";
		cin>>id_persona;
		file >> id >> nombre >> sueldo;
		while(!file.eof())
		{
		    sueldoCal = sueldo - sueldo*0.0483;
		    sueldobon = sueldoCal + 250;
			if(id_persona==id)
			{
				cout<<"\n\n\t\t\t Id del empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre del empleado: "<<nombre<<endl;
				cout<<"\t\t\t Sueldo del empleado: "<<sueldobon<<endl;

				cout<<"\n\t\t\t Calculo: "<<endl;
				cout<<"\t\t\t Se descuenta la cuota laboral: -4.83% "<<endl;
				cout<<"\t\t\t Se suma bonificacion incentivo: +250Q "<<endl;

				cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
				found++;
			}
			file >> id >> nombre >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}

void impuestos::modificar()
{
	system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t   | Modificacion informacion Salarial | "<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("InformacionS.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del empleado que quiere modificar: ";
		cin>>id_persona;
		file1.open("registro.txt",ios::app | ios::out);
		file >> id >> nombre >> sueldo;
		while(!file.eof())
		{
			if(id_persona!=id)
			{
			 file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< sueldo << "\n";
			}
			else
			{
				cout<<"\t\t\t Ingrese Id del Empleado: ";
				cin>>id;
				cout<<"\t\t\t Ingrese Nombre del Empleado: ";
				cin>>nombre;
				cout<<"\t\t\t Ingrese Sueldo del Empleado: ";
				cin>>sueldo;
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< sueldo<< "\n";
				found++;
			}
			file >> id >> nombre >> sueldo;
		}
		file1.close();
		file.close();
		remove("InformacionS.txt");
		rename("registro.txt","InformacionS.txt");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}
void impuestos::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("InformacionS.txt",ios::in);
	if(!file)
	{
		cout <<"\t\t\t*********************************************"<<endl;
		cout <<"\t\t\t             | Buscar empleado | "<<endl;
		cout <<"\t\t\t*********************************************"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string id_persona;
		cout <<"\t\t\t*********************************************"<<endl;
		cout <<"\t\t\t             | Buscar empleado | "<<endl;
		cout <<"\t\t\t*********************************************"<<endl;
		cout<<"\n Ingrese Id del empleado que quiere buscar: ";
		cin>>id_persona;
		file >> id >> nombre >> sueldo;
		while(!file.eof())
		{
			if(id_persona==id)
			{
				cout<<"\n\n\t\t\t Id del empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre del empleado: "<<nombre<<endl;
				cout<<"\t\t\t Sueldo Neto del empleado: "<<sueldo<<endl;
				found++;
			}
			file >> id >> nombre >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}

void impuestos::borrar()
{
	system("cls");
	fstream file,file1;
	string id_persona;
	int found=0;
	cout <<"\t\t\t*********************************************"<<endl;
	cout <<"\t\t\t           | Borrar Informacion |"<<endl;
	cout <<"\t\t\t*********************************************"<<endl;
	file.open("InformacionS.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del empleado que quiere borrar: ";
		cin>>id_persona;
		file1.open("registro.txt",ios::app | ios::out);
		file >> id >> nombre >> sueldo;
		while(!file.eof())
		{
			if(id_persona!= id)
			{
				file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(10)<< nombre <<std::left<<std::setw(10)<< sueldo << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> sueldo;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("InformacionS.txt");
		rename("registro.txt","InformacionS.txt");
	}
	cout<<"\n\nPresione cualquier tecla para regresar al menu anterior "<<endl;
}
