#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "usuario.h"
#include "empleado.h"



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

    		menu2();
    		cout << "\t\t\t ¿Quieres seguir en el apartado de empleados? (S/N)";
    		cin>>s;
		}while(s=='s'||s=='S');
		break;
    case 2:
		menuprincipal();
		break;
	case 3:
		menu3();
		break;
	case 4:
		menu4();
		break;
	/*case 5:
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

void usuario::menu2()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION EMPLEADOS  |"<<endl;
	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso empleados"<<endl;
	cout<<"\t\t\t 2. Despliegue empleados"<<endl;
	cout<<"\t\t\t 3. Modificar empleados"<<endl;
	cout<<"\t\t\t 4. Buscar empleados"<<endl;
	cout<<"\t\t\t 5. Borrar empleados"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 6);
}
void usuario::insert()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar informacion del empleado ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id del empleado         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre del empleado     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono del empleado   : ";
	cin>>telefono;
    file.open("registroDeEmpleados.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
	file.close();
}
void usuario::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Informacion de los empleados -------------------------"<<endl;
	file.open("registroDeEmpleados.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Empleado: "<<id<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombre<<endl;
			cout<<"\t\t\t Telefono Empleado: "<<telefono<<endl;
			file >> id >> nombre >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

void usuario::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de Empleados-------------------------"<<endl;
	file.open("registroDeEmpleados.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del empleado que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id del Empleado: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono del Empleado: ";
				cin>>telefono;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
				found++;
			}
			file >> id >> nombre >> telefono;

		}
		file1.close();
		file.close();
		remove("registroDeEmpleados.dat");
		rename("registro.dat","registroDeEmpleados.dat");
	}
}

void usuario::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("registroDeEmpleados.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del empleado buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del empleado buscado------------------------"<<endl;
		cout<<"\nIngrese Id del empleado que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id del empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre del empleado: "<<nombre<<endl;
				cout<<"\t\t\t Telefono del empleado: "<<telefono<<endl;
				found++;
			}
			file >> id >> nombre >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}


void usuario::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Informacion del Empleado a Borrar-------------------------"<<endl;
	file.open("registroDeEmpleados.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del empleado que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del Empleado no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeEmpleados.dat");
		rename("registro.dat","registroDeEmpleados.dat");
	}
}

void usuario::menuprincipal()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"----------------------------------------"<<endl;
	cout<<"\t\t |   GDUR DE PUESTOS DE TRABAJO  |"<<endl;
	cout<<"----------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nuevos puestos de trabajo"<<endl;
	cout<<"\t 2. Ver puestos de trabajo actuales"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		nuevopuesto();
    		cout<<"\n\t ¿Agregar un nuevo puesto?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		verpuestos();
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 3 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void usuario::nuevopuesto()
{
	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	cout<<"\tIngresa nombre del puesto de trabajo: ";
	cin>>nombrepuesto;

	cout<<"\tIngresa el area de trabajo de dicho puesto: ";
	cin>>area;

	cout<<"\tIngresa el segmento de dicho puesto: ";
	cin>>segmento;

	cout<<"\tIngresa el salario minimo de dicho puesto: ";
	cin>>salario;

	cout<<"\t¿Hay vacantes disponibles? ¿Cuantas? ";
	cin>>vacantes;

    archivo.open("puestosdetrabajo.dat", ios::binary | ios::app | ios::out);
    archivo2.open("puestosdetrabajo2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombrepuesto),
         sizeof( nombrepuesto ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&area),
         sizeof( area ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&segmento),
         sizeof( segmento ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&salario),
         sizeof( salario ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&vacantes),
        sizeof( vacantes ) );
    }
}

void usuario::verpuestos()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE PUESTOS ACTUALES --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has añadido ninguna informacion al sistema";
		archivo.close();
	}

	else
	{
		archivo >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			total++;
			cout<<"\n\n\t Puesto de trabajo: "<< nombrepuesto <<endl;
			cout<<"\t Area: "<< area <<endl;
			cout<<"\t Segmento: "<< segmento <<endl;
			cout<<"\t Salario minimo: "<< salario <<endl;
			cout<<"\t Vacantes: "<< vacantes <<endl;
			archivo >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}
		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
	}

	cout<<"Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion;

    if(opcion = 1){
        menuprincipal();
    }
}

void usuario::menu3()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA DE GESTION DEPARTAMENTOS  |"<<endl;
	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Departamnetos"<<endl;
	cout<<"\t\t\t 2. Despliegue Departamnetos"<<endl;
	cout<<"\t\t\t 3. Modificar Departamentos"<<endl;
	cout<<"\t\t\t 4. Buscar Departamentos"<<endl;
	cout<<"\t\t\t 5. Borrar Departamentos"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4/5/6]|"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

switch(choice)
    {
    case 1:
    	do
    	{
    		insert2();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display2();
		break;
	case 3:
		modify2();
		break;
	case 4:
		search2();
		break;
	case 5:
		delet2();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 6);
}

void usuario::insert2()
{
	system("cls");
	fstream file;
	cout<<"\n                      -----------------------------------------";
	cout<<"\n                      |AGREGAR LA INFORMACION DEL DEPARTAMNETO|"<<endl;
	cout<<"\t\t\tIngresa codigo del Departamento        : ";
	cin>>codigo;
	cout<<"\t\t\tIngresa Nombre del Departamento    : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Nombre del Empleado   : ";
	cin>>nombreem;
	file.open("registrodedepartamentos.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem<< "\n";
	file.close();
}
void usuario::display2()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Informacion de los Departamentos -------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t codigo Departamento: "<<codigo<<endl;
			cout<<"\t\t\t Nombre Departamento: "<<nombre<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombreem<<endl;
			file >> codigo >> nombre >> nombreem;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void usuario::modify2()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de Departamnetos-------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese codigo del Departamento que quiere modificar: ";
		cin>>participant_codigo;
		file1.open("registros.txt",ios::app | ios::out);
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo!=codigo)
			{
			 file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese codigo del Departamneto: ";
				cin>>codigo;
				cout<<"\t\t\tIngrese Nombre del Departamento: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>nombreem;
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem<< "\n";
				found++;
			}
			file >> codigo >> nombre >> nombreem;

		}
		file1.close();
		file.close();
		remove("registrodedepartamentos.txt");
		rename("registros.txt","registrodedepartamentos.txt");
	}
}
void usuario::search2()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Departamento buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_codigo;
		cout<<"\n-------------------------Datos del Departamento buscado------------------------"<<endl;
		cout<<"\nIngrese codigo del Departamento que quiere buscar: ";
		cin>>participant_codigo;
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo==codigo)
			{
				cout<<"\n\n\t\t\t codigo del Departamento: "<<codigo<<endl;
				cout<<"\t\t\t Nombre del Departamento: "<<nombre<<endl;
				cout<<"\t\t\t Nombre del empleado: "<<nombreem<<endl;
				found++;
			}
			file >> codigo >> nombre >> nombreem;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}
void usuario::delet2()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Informacion del Departamento a Borrar-------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el codigo del Departamento que quiere borrar: ";
		cin>>participant_codigo;
		file1.open("registros.txt",ios::app | ios::out);
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo!= codigo)
			{
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> codigo >> nombre  >> nombreem;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t codigo del Departamento no encontrado...";
		}
		file1.close();
		file.close();
		remove("registrodedepartamentos.txt");
		rename("registros.txt","registrodedepartamentos.txt");
		}
}

void usuario::menu4()
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

void usuario::insert3()
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

void usuario::desplegar()
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

void usuario::calcular()
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

void usuario::modificar()
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
void usuario::buscar()
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

void usuario::borrar()
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
