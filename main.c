#include <stdio.h>
#include <stdlib.h>
#include "inputs_lean.h"
#include "LinkedList.h"
#include "pais.h"
#include "controller.h"
#include "informes.h"

#define INTENTOS 3
void menu()
{
    system("cls");
    printf("   Menu\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Filtrar por paises en el horno\n");
    printf("6. Ordenar por nivel de vacunacion\n");
    printf("7. Mostrar mas catigado\n");
    printf("8. Salir\n\n");
}
int main()
{
    srand(time(NULL));
    int option = 0;
    char path[100];
    char respuesta = 's';
    char respuestaAsignacion = 's';
    char salir;
    LinkedList *listaPaises = ll_newLinkedList();
    LinkedList *auxListaPaises = NULL;
    int flag = 0;
    int flagAsignacion =0;
    int criterio;
    if (listaPaises == NULL)
    {
        printf("No se pudo crear la linkedList.\n");
        exit(1);
    }

    do
    {
        menu();
        printf("\n");
        if (!getInt(&option, 1, 8, INTENTOS, "Ingrese opcion: ", "Error. "))
        {
            printf("Ha excedido el limite de intentos...\nSe finalizara el programa.\n");
            exit(1);
        }
        switch (option)
        {
        case 1:
            system("cls");
            printf("CARGAR ARCHIVO\n");
            if (ll_len(listaPaises) > 0)
            {
                if (!getLetra(&respuesta, INTENTOS, "Tiene paises cargados en la lista y van a ser elminados.\nEsta seguro que quiere cargar otro archivo?", "Error. "))
                {
                    printf("Ha exedido el limite de intentos.\n");
                    respuesta = 'n';
                }
                if (respuesta == 's')
                {
                    ll_clear(listaPaises);
                    printf("Paises eliminados.\n");
                }
                else
                {
                    printf("Cargar archivo abortado.\n");
                }
            }
            if (respuesta == 's')
            {
                printf("Sugerencia: vacunas.csv\n");
                if (getString(path, 100, INTENTOS, "Ingrese path: ", "Error. "))
                {
                    if (controller_loadFromText(path, listaPaises))
                    {
                        printf("Archivo de texto (.csv) cargado con exito.\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("Hubo un error.\n");
                    }
                }
                else
                {
                    printf("Ha excedido el limite de intentos. \n");
                }
            }

            system("pause");

            break;

        case 2:
            system("cls");
            if (flag)
            {
                if (controller_ListPaises(listaPaises))
                {
                    printf("Se cargaron todos los paises con exito.\n");
                }
                else
                {
                    printf("No se pudieron cargar todos los paises.\n");
                }
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if (flag)
            {
                if(flagAsignacion == 1)
                {
                    if(!getLetra(&respuestaAsignacion, INTENTOS, "Ya hay estadisticas asignadas. Desea asignar nuevas estadisticas?(s/n) ", "Error. "))
                    {
                        printf("Ha exedido el limite de intentos.\n");
                        respuestaAsignacion = 'n';
                    }
                }
                if (respuestaAsignacion == 's')
                {
                    auxListaPaises = controller_assing(listaPaises);
                    if ( auxListaPaises != NULL)
                    {
                        ll_deleteLinkedList(listaPaises);
                        listaPaises = auxListaPaises;
                        flagAsignacion = 1;
                        printf("Se asigno correctamente.\n");
                    }
                    else
                    {
                        printf("No se pudieron asignar.\n");
                    }
                }
                else
                {
                    printf("Asignacion abortada.\n");
                }
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 4:
            system("cls");
            if (flag)
            {
                printf("FILTRAR POR PAISES EXITOSOS\n");
                LinkedList *listaExitosos = ll_filter(listaPaises, paisesExitosos);
                if (listaExitosos != NULL)
                {
                    if (getString(path, 100, INTENTOS, "Ingrese path: ", "Error. "))
                    {
                        if (controller_saveAsText(path, listaExitosos))
                        {
                            printf("Lista guardada correctamente.\n");
                        }
                    }
                }
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if (flag)
            {
                printf("FILTRAR POR PAISES EN EL HORNO\n");
                LinkedList *listaEnElHorno = ll_filter(listaPaises, paisesEnElHorno);
                if (listaEnElHorno != NULL)
                {
                    if (getString(path, 100, INTENTOS, "Ingrese path: ", "Error. "))
                    {
                        if (controller_saveAsText(path, listaEnElHorno))
                        {
                            printf("Lista guardada correctamente.\n");
                        }
                    }
                }
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 6:
            system("cls");
            if (flag)
            {
                if(getInt(&criterio, 0, 1, INTENTOS, "Ingrese criterio de ordenamiento(0 = descendente / 1 = ascendente): ", "Error. "))
                {
                    if (ll_sort(listaPaises, ordernarPorVacunacion, criterio) != -1)
                    {
                        printf("Ordenado correctamente.\n");
                    }
                    else
                    {
                        printf("Error. No se pudo ordenar.\n");
                    }
                }
                else
                {
                    printf("Ha excedido el limite de intentos.\n");
                }
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 7:
            system("cls");
            if (flag)
            {
                paisMasCastigado(listaPaises);
            }
            else
            {
                printf("Primero debe cargar un archivo.\n");
            }
            system("pause");
            break;

        case 8:
            system("cls");

            if (!getLetra(&salir, INTENTOS, "Esta seguro que quiere salir? ", "Error. "))
            {
                printf("Ha excedido el limite de intentos.\n");
            }
            system("pause");
        }
    }
    while (salir != 's');
    ll_deleteLinkedList(listaPaises);

    return 0;
}
