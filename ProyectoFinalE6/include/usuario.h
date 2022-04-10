#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class usuario
{
    public:
        usuario();
        virtual ~usuario();
        void menu();
        void menu1();
        void menu2();
        void login();
        void mantenimientos();
        void insert();
		void display();
		void modify();
		void search();
		void delet();
		void menuprincipal();
		void nuevopuesto();
		void verpuestos();
		void menu3();
		void insert2();
		void display2();
		void modify2();
		void search2();
		void delet2();
		void menu4();
        void insert3();
        void desplegar();
        void calcular();
        void modificar();
        void buscar();
        void borrar();

    protected:

    private:
        string id,nombre,telefono;
        string nombrepuesto, area, segmento, salario, vacantes;
        string codigo,nombre1,nombreem;
        string id1, nombre2;
        int sueldo;
};

#endif // USUARIO_H
