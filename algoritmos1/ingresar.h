using namespace std;

const int maxi = 100;

typedef struct
{
    string nombre;
    double calificacion;
} tEstudiantes;

typedef tEstudiantes tArray[maxi];

typedef struct
{
    tArray estudiante;
    string profesor = " ";
    string materia = " ";
    int contador;
} tLista;

int menu()
{
    int op = -1;
    while (op < 0 || op > 6)
    {
        cout << "1.- Ingrese Su nombre " << endl;
        cout << "2.- Ingrese la materia" << endl;
        cout << "3.- Ingresar numero de estudiantes" << endl;
        cout << "4.- Ingresar notas de cada estudiante" << endl;
        cout << "5.- Almacenar las notas" << endl;
        cout << "0.- Salir " << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
    }
    return op;
}

void nombre_profesor(tLista& lista)
{
    cout << "Ingrese el nombre del Profesor: " << endl;
    cin.ignore();
    //fflush(stdin);
    getline(cin, lista.profesor);
}

void materia(tLista& lista)
{
    cout << "Ingrese el nombre de la materia: " << endl;
    cin.ignore();
    //fflush(stdin);
    getline(cin, lista.materia);
}

void Ingresar_nombres(tLista& lista)
{
    cout << "Ingrese el numero de estudiantes: ";
    cin >> lista.contador;
    cout << "Ingrese el nombre de cada Estudiante " << endl;
    cin.ignore();
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "Estudiante " << i + 1 << ":    ";
        getline(cin, lista.estudiante[i].nombre);
        fflush(stdin);
    }
}

void Ingresar_notas(tLista& lista)

{
    cout << endl;
    cout << "Solo se registrará notas entre 0-20!" << endl << endl;
    cout << "  " << setw(20) << left << "Nombre" << setw(8) << left << "Nota" << endl;
    for (int i = 0; i < lista.contador; i++)
    {
        cout << i + 1 << " " << setw(20) << left << lista.estudiante[i].nombre;
        cin >> lista.estudiante[i].calificacion;
        while (lista.estudiante[i].calificacion < 0 || lista.estudiante[i].calificacion >20) {
            cout << i + 1 << " " << setw(20) << left << lista.estudiante[i].nombre;
            cin >> lista.estudiante[i].calificacion;
        }
    }
}


