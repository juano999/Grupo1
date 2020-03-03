
typedef struct
{
    double a_buscar;
    string buscado;
    string encontrado;
    string nombre_opcion;
} tBusqueda;

void guardar_busqueda (tBusqueda busca, tLista& lista);
int interpolacion(tLista lista, int num);

int menu_busqueda()
{
    int sal;
    cout << "----MENU BUSQUEDA------";
    cout << "\n0.-Salir \n";
    cout << "1.-Busqueda lineal \n";
    cout << "2.-Busqueda binaria\n";
    cout << "3.-Busqueda por interpolacion\n ";
    cin >> sal;
    if (sal > 3 || sal < 0)
    {
        menu_busqueda();
    }
    return sal;
}

void busqueda_lineal(tLista lista, tBusqueda& busca)
{
    busca.nombre_opcion += " Lineal";
    bool c = false;
    for (int i = 0; i <= lista.contador; i++)
    {
        if (busca.a_buscar == lista.estudiante[i].calificacion)
        {
            busca.encontrado += lista.estudiante[i].nombre;
            c = true;
        }
    }
    if (!c)
    {
        busca.encontrado = " ELEMENTO NO ENCONTRADO \n ";
    }
}

void busqueda_binaria(tLista lista, tBusqueda& busca)
{
    busca.nombre_opcion += " Binaria";
    int pfinal = lista.contador;
    int pini = 0;
    int k;
    do
    {
        k = (pini + pfinal) / 2;
        if (lista.estudiante[k].calificacion <= busca.a_buscar)
        {
            pini = k + 1;
        }
        if (lista.estudiante[k].calificacion >= busca.a_buscar)
        {
            pfinal = k - 1;
        }
    } while (pini <= pfinal);
    if (lista.estudiante[k].calificacion == busca.a_buscar)
    {
        busca.encontrado += lista.estudiante[k].nombre;
    }
    else
    {
        busca.encontrado = " ELEMENTO NO ENCONTRADO \n ";
    }
}

void busqueda_interpolacion(tLista lista, tBusqueda& buscar)
{
    buscar.nombre_opcion += " Interpolacion";
    int inter;
    inter = interpolacion(lista, buscar.a_buscar);
    if (inter > -1)
    {
        buscar.encontrado += lista.estudiante[inter].nombre;
    }
    else
    {
        buscar.encontrado = " ELEMENTO NO ENCONTRADO \n ";
    }
}
int interpolacion(tLista lista, int num)
{
    int sal;
    int primero = 0;
    int ultimo = lista.contador - 1;
    int medio;
    int cont = 0;
    while ((lista.estudiante[primero].calificacion != num) && (cont <= lista.contador))
    {
        medio = primero + ((num - lista.estudiante[primero].calificacion) * (ultimo - primero)) / (lista.estudiante[ultimo].calificacion - lista.estudiante[primero].calificacion);
        if (lista.estudiante[medio].calificacion < num)
        {
            primero = medio + 1;
        }
        else if (lista.estudiante[medio].calificacion > num)
        {
            ultimo = medio - 1;
        }
        else
        {
            primero = medio;
        }
        cont++;
        if (primero < 0)
        {
            primero = -(primero);
        }
        if (primero > lista.contador)
        {
            primero -= lista.contador;
        }
    }
    if (lista.estudiante[primero].calificacion == num)
    {
        sal = primero;
    }
    else
    {
        sal = -1;
    }
    return sal;
}

void busqueda(tLista lista)
{
    tBusqueda buscar;
    string bus;
    buscar.nombre_opcion = "ALGORITMO: ";
    buscar.buscado = "La calificacion a buscar es: ";
    buscar.encontrado = "Corresponde al estudiante:";
    int op, l;
    op = menu_busqueda();
    if (op > 0)
    {
        cout << "\nIngrese la calificacion a buscar: ";
        cin >> buscar.a_buscar;
        switch (op)
        {
        case 1:
            busqueda_lineal(lista, buscar);
            break;
        case 2:
            busqueda_binaria(lista, buscar);
            break;
        case 3:
            busqueda_interpolacion(lista, buscar);//falta corregir
            break;
        }
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%g", buscar.a_buscar);
        buscar.buscado += buffer;
        cout << setw(30) << right << "COLEGIO MEJIA" << endl;
        cout << "Busqueda de Calificaciones" << endl;
        cout << buscar.nombre_opcion << endl;
        cout << buscar.buscado << endl;
        cout << buscar.encontrado << endl;
        guardar_busqueda(buscar, lista);
        if (op < 4 && op>0)
        {
            busqueda(lista);
        }
    }
}

void guardar_busqueda(tBusqueda busca, tLista& lista)
{
    ofstream archivo;
    archivo.open("C:/colegio/busqueda.txt");
    archivo << setw(30) << right << "COLEGIO MEJIA" << endl;
    archivo << "Busqueda de Calificaciones" << endl;
    archivo << endl << busca.nombre_opcion;
    archivo << endl << busca.buscado;
    archivo << endl << busca.encontrado << endl;
    archivo << endl;
    archivo << endl;
    archivo << setw(30) << right << " " << "-------------------" << endl;
    archivo << setw(35) << right << " " << lista.profesor << endl;
    archivo << setw(35) << right << " " << "1717653222" << endl;
    archivo.close();
}
