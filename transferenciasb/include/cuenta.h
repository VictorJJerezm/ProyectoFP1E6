#ifndef CUENTA_H
#define CUENTA_H

using namespace std;


class cuenta
{
    public:
        cuenta();
        virtual ~cuenta();
        void menu();
        void insert();
        void inserttrans();
        void search();

    protected:

    private:
        string ncuenta, dinero;
        string ncuentat, cantidad;
};

#endif // CUENTA_H
