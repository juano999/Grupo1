
double promedio(tLista& lista) //Esta funcion determina el promedio de las calificaciones
{
    double sum = 0, pro;
    for (int i = 0; i < lista.contador; i++)
    {
        sum = sum + lista.estudiante[i].calificacion;
    }
    pro = sum / lista.contador;
    return pro;
}

int clasificacion(tLista& lista, int cla) //Esta funcion clasifica el numero de aprobados suspensos y reprobados
{
    int cont = 0;
    switch (cla)
    {
    case 1:
        for (int i = 0; i < lista.contador; i++)
        {
            if ((lista.estudiante[i].calificacion >= 14) && (lista.estudiante[i].calificacion <= 20))
            {
                cont = cont + 1;
            }
        }
        break;
    case 2:
        for (int i = 0; i < lista.contador; i++)
        {
            if ((lista.estudiante[i].calificacion >= 9) && (lista.estudiante[i].calificacion <= 13))
            {
                cont = cont + 1;
            }
        }
        break;
    case 3:
        for (int i = 0; i < lista.contador; i++)
        {
            if ((lista.estudiante[i].calificacion >= 1) && (lista.estudiante[i].calificacion <= 8))
            {
                cont = cont + 1;
            }
        }
        break;
    }
    return cont;
}

void archcali(tLista& lista) //Esta funcion guarda la informacion de las calificaciones en un solo archivo
{
    double promed = promedio(lista);
    int apro, sus, rep;
    ofstream archivo;
    archivo.open("C://colegio/calificaciones.txt");
    archivo << setw(35) << "COLEGIO MEJIA" << endl;
    archivo << setw(40) << "REPORTE DE CALIFICACIONES" << endl;
    archivo << endl;
    archivo << "Año lectivo: 2019 - 2020" << setw(5) << endl;
    archivo << "Materia: " << lista.materia << setw(5) << endl;
    archivo << setw(15) << left << "N°- " << setw(30) << left << "Estudiante" << "Calificación" << endl;
    for (int i = 0; i < lista.contador; i++)
    {
        archivo << setw(14) << left << i + 1 << setw(30) << left << lista.estudiante[i].nombre << lista.estudiante[i].calificacion << endl;
    }
    archivo << "RESUMEN" << endl;
    archivo << "Promedio del curso: " << setw(25) << setprecision(2) << fixed << right << promed << endl;
    apro = clasificacion(lista, 1);
    archivo << setw(19) << left << "Total" << setw(30) << left << "Aprobados (14 - 20)" << apro << endl;
    sus = clasificacion(lista, 2);
    archivo << setw(19) << right << " " << setw(30) << left << "Suspenso (09 - 13)" << sus << endl;
    rep = clasificacion(lista, 3);
    archivo << setw(19) << right << " " << setw(30) << left << "Reprobados (01 - 08)" << rep << endl;
    archivo << endl;
    archivo << endl;
    archivo << setw(30) << right << " " << "-------------------" << endl;
    archivo << setw(35) << right << " " << lista.profesor << endl;
    archivo << setw(35) << right << " " << "1717653222" << endl;
    archivo.close();
}

