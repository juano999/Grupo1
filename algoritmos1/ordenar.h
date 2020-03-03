
int menu_Ordenacion();
void burbuja(tLista &lista);
void seleccion(tLista&lista);
void merge_sort(tLista& lista, int inicial, int final);
void fusionar(tLista lista, int pos_inicial, int pos_final, int medio);
int dividir2(tLista lista, int inicio, int fin);
void quicksort(tLista& lista, int pinicial, int pfinal);
void HeapSort(tLista& lista);
void mostrar(tLista lista);
void guardar_ordenamiento (string nombre_o, tLista& lista);


void ordenar(tLista& lista)
{
    string nombre_o = "ALGORITMO: ";
    cout << "Algoritmo con el que desea ordenar las notas: " << endl;
    int opcion = menu_Ordenacion();
    switch (opcion)
    {
    case 1:
    {
        nombre_o += "Burbuja";
        //burbuja
        burbuja(lista);
    }
    break;
    case 2:
    {
        nombre_o += "Selección";
        //seleccion
        seleccion(lista);

    }
    break;
    case 3:
    {
        nombre_o += "Merge Sort";
        merge_sort(lista, 0, lista.contador - 1);

    }
    break;
    case 4:
    {
        nombre_o += "Quick Sort";
        quicksort(lista, 0, lista.contador - 1);
    }
    break;
    case 5:
    {
        nombre_o += "Heap Sort";
        HeapSort(lista);
    }
    }

    cout << "\nOrdenado\n";
    mostrar(lista);
    guardar_ordenamiento(nombre_o, lista);
    cout << endl;
}
void mostrar(tLista lista) {

    for (int i = 0; i < lista.contador; i++)

    {

        cout << "| " << lista.estudiante[i].nombre << " : " << lista.estudiante[i].calificacion << " |";

    }
}
void burbuja(tLista& lista) {
    tEstudiantes aux;
    for (int i = 0; i < lista.contador; i++)
    {
        for (int j = i + 1; j <= lista.contador - 1; j++)
        {
            if (lista.estudiante[i].calificacion > lista.estudiante[j].calificacion)
            {
                aux = lista.estudiante[i];
                lista.estudiante[i] = lista.estudiante[j];
                lista.estudiante[j] = aux;
            }
        }
    }
}
void seleccion(tLista& lista) {
    tEstudiantes aux;
    int min;
    for (int i = 0; i < lista.contador; i++)
    {
        min = i;
        for (int j = i + 1; j < lista.contador; j++)
        {
            if (lista.estudiante[min].calificacion > lista.estudiante[j].calificacion)
            {
                min = j;
            }
        }
        aux = lista.estudiante[i];
        lista.estudiante[i] = lista.estudiante[min];
        lista.estudiante[min] = aux;
    }
}
int menu_Ordenacion()

{
    int op = -1;
    while (op < 0 || op > 6)
    {
        cout << "1.- Algoritmo Burbuja " << endl;
        cout << "2.- Algoritmo Seleccion " << endl;
        cout << "3.- Algoritmo Merge Sort" << endl;
        cout << "4.- Algoritmo Quick Sort" << endl;
        cout << "5.- Algoritmo Heap Sort" << endl;
        cout << "0.- Salir " << endl;
        cout << "Opcion: ";
        cin >> op;
        cout << endl;
    }
    return op;
}

void merge_sort(tLista& lista, int inicial, int final)
{
    int mitad;
    if (inicial < final)
    {
        mitad = (inicial + final) / 2;
        merge_sort(lista, inicial, mitad);
        merge_sort(lista, mitad + 1, final);
        fusionar(lista, inicial, final, mitad);
    }
}

void fusionar(tLista lista, int pos_inicial, int pos_final, int medio)
{
    int i, j, k;
    tLista temp;
    temp.estudiante[pos_final - pos_inicial + 1];
    i = pos_inicial;
    k = 0;
    j = medio + 1;
    while (i <= medio && j <= pos_final)
    {
        if (lista.estudiante[i].calificacion < lista.estudiante[j].calificacion)
        {
            temp.estudiante[k] = lista.estudiante[i];
            k++;
            i++;
        }
        else
        {
            temp.estudiante[k] = lista.estudiante[j];
            k++;
            j++;
        }
    }

    while (i <= medio)
    {
        temp.estudiante[k] = lista.estudiante[i];
        k++;
        i++;
    }
    while (j <= pos_final)
    {
        temp.estudiante[k] = lista.estudiante[j];
        k++;
        j++;
    }
    for (i = pos_inicial; i <= pos_final; i++)
    {
        lista.estudiante[i] = temp.estudiante[i - pos_inicial];
    }
}

void quicksort(tLista& lista, int inicio, int fin)
{
    int pivote;
    if (inicio < fin)
    {
        pivote = dividir2(lista, inicio, fin);
        quicksort(lista, inicio, pivote - 1);
        quicksort(lista, pivote + 1, fin);
    }
}

int dividir2(tLista lista, int inicio, int fin)
{
    int izquierda, derecha;
    double pivote;
    tEstudiantes temp;
    pivote = lista.estudiante[inicio].calificacion;
    izquierda = inicio;
    derecha = fin;
    // Mientras no se cruzen los índices
    while (izquierda < derecha)
    {
        while (lista.estudiante[derecha].calificacion > pivote)
        {
            derecha--;
        }
        while (izquierda < derecha && (lista.estudiante[izquierda].calificacion <= pivote))
        {
            izquierda++;
        }
        // Si todavía no se cruzan los indices se sigue intercambiando
        if (izquierda < derecha)
        {
            temp = lista.estudiante[izquierda];
            lista.estudiante[izquierda] = lista.estudiante[derecha];
            lista.estudiante[derecha] = temp;
        }
        // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    }
    temp = lista.estudiante[derecha];
    lista.estudiante[derecha] = lista.estudiante[inicio];
    lista.estudiante[inicio] = temp;
    return derecha;
}

void HeapSort(tLista& lista)//por comprobar
{
    int a;
    tEstudiantes temp, valor;
    for (int i = lista.contador; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            valor = lista.estudiante[j];
            a = j / 2;
            while (a > 0 && lista.estudiante[a].calificacion < valor.calificacion)
            {
                lista.estudiante[j] = lista.estudiante[a];
                j = a;
                a = a / 2;
            }
            lista.estudiante[j] = valor;
        }
        temp = lista.estudiante[1];
        lista.estudiante[1] = lista.estudiante[i];
        lista.estudiante[i] = temp;
    }
}

void guardar_ordenamiento(string nombre_o, tLista& lista)
{
    ofstream archivo;
    archivo.open("C:/colegio/ordenamiento.txt");
    archivo << setw(30) << right << "COLEGIO MEJIA" << endl;
    archivo << "Calificaciones Ordenadas" << endl;
    archivo << nombre_o << endl;
    archivo << "N°- ";
    for (int i = 0; i < lista.contador; i++)

    {
        archivo << "| " << lista.estudiante[i].calificacion << " |";
    }
    archivo << endl;
    archivo << endl;
    archivo << setw(30) << right << " " << "-------------------" << endl;
    archivo << setw(35) << right << " " << lista.profesor << endl;
    archivo << setw(35) << right << " " << "1717653222" << endl;
    archivo.close();
}

