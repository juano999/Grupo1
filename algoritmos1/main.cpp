#include <iostream>
using namespace std;

#include <iomanip>
#include <string>
#include <stdlib.h>
#include<fstream>
#include "ingresar.h"
#include "ordenar.h"
#include "busqueda.h"
#include "archivo.h"

int main()
{
    tLista lista;
    lista.contador = 0;
    int aux[5] = { 0 };//Este auxiiar sirve para comprobar que el usuario llene otros campos necesariamente
    cout << setw(30) << "Colegio Mejia" << endl;
    cout << setw(37) << "Sistema de Calificaciones " << endl;
    cout << endl;
    cout << "Bienvenido!" << endl;
    cout << endl << endl;
    int op = menu();
    while (op != 0)
    {
        switch (op)
        {
        case 1:
        {
            fflush(stdin);
            nombre_profesor(lista);
            aux[0] = 1;
        }
        break;
        case 2:
        {
            if (aux[0] == 1)
            {
                fflush(stdin);
                materia(lista);
                aux[1] = 1;
            }
            else
            {
                cout << "No ha ingresado el nombre del profesor. Intentelo de nuevo" << endl;
            }
        }
        break;
        case 3:
        {
            if (aux[0] == 1 && aux[1] == 1)
            {
                cin.ignore();
                Ingresar_nombres(lista);
                cout << endl;
                aux[2] = 1;
            }
            else
            {
                cout << "No ha ingresado algunos campos. Intentelo de nuevo" << endl;
            }
        }
        break;
        case 4:
        {
            if (aux[0] == 1 && aux[1] == 1 && aux[2] == 1)
            {
                cout << "Ingrese la nota de cada Estudiante: " << endl;
                Ingresar_notas(lista);
                cout << endl;
                ordenar(lista);
                //falta almacenar la ordenacion
                busqueda(lista);
                //se guarda automaticamente despues de cada selección tomando solo la ULTIMA
                aux[3] = 1;
            }
            else
            {
                cout << "No ha ingresado algunos campos. Intentelo de nuevo" << endl;
            }
        }
        break;
        case 5:
        {
            if (aux[0] == 1 && aux[1] == 1 && aux[2] == 1 && aux[3] == 1)
            {
                archcali(lista);
                aux[4] = 1;
            }
            else
            {
                cout << "No ha ingresado algunos campos. Intentelo de nuevo" << endl;
            }
        }
        }
        system("cls");
        cout << endl;
        cout << "Profesor: " << setw(25) << left << lista.profesor << "Materia: " << setw(25) << left << lista.materia << endl << endl;
        op = menu();
    }
}
