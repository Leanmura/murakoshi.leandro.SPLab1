#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs_lean.h"

int getInt(int *pResultado, int minimo, int maximo, int intentos, char mensaje[], char mensajeError[])
{
    int numero;
    int todoOk = 0;

    if (pResultado != NULL && mensajeError != NULL && minimo <= maximo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if (scanf("%d", &numero))
            {
                if (numero >= minimo && numero <= maximo)
                {
                    *pResultado = numero;
                    break;
                }
            }
            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getFloat(float *pResultado, float minimo, float maximo, int intentos, char mensaje[], char mensajeError[])
{
    float numero;
    int todoOk = 0;

    if (pResultado != NULL && mensajeError != NULL && minimo <= maximo && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if (scanf("%f", &numero))
            {
                if (numero >= minimo && numero <= maximo)
                {
                    *pResultado = numero;
                    break;
                }
            }
            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getString(char cadena[], int len, int intentos, char mensaje[], char mensajeError[])
{
    char auxCadena[100];
    int todoOk = 0;
    if (cadena != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(auxCadena);

            if (strlen(auxCadena) < len)
            {
                strncpy(cadena, auxCadena,len-1); // hay que tener en cuenta el '\0'
                break;
            }

            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getNombre(char nombre[], int len, int intentos, char mensaje[], char mensajeError[])
{
    int i;
    char auxNombre[100];
    int todoOk = 0;
    int flag = 0;
    if (nombre != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(auxNombre);

            i = 0;
            while (auxNombre[i] != '\0')
            {
                if ((auxNombre[i] < 'a' || auxNombre[i] > 'z') && (auxNombre[i] < 'A' || auxNombre[i] > 'Z'))
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                    i++;
                }
            }

            if (strlen(auxNombre) < len && !flag) // mirar esto para las otras funciones string
            {
                strncpy(nombre, auxNombre,len-1); // hay que tener en cuenta el '\0'
                break;
            }

            printf("%s", mensajeError);
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int getLetra(char *letra, int intentos, char mensaje[], char mensajeError[])
{
    int todoOk = 0;
    if (letra != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", letra);
            if (!isalpha(*letra))
            {
                printf("%s", mensajeError);
                intentos--;
            }
            else
            {
                break;
            }
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

/*int getFecha(eFecha *fecha, eFecha fechaHoy, eFecha fechaMin, int intentos, char mensaje[], char mensajeError[])
{
    //scanf("%d/%d/%d", &auxEmpleados.fIngreso.dia, &auxEmpleados.fIngreso.mes, &auxEmpleados.fIngreso.anio);
    eFecha auxFecha;
    int todoOk = 0;
    int validarF;
    if (fecha != NULL && mensajeError != NULL && intentos > 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            if (scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio))
            {
                validarF = validarFecha(auxFecha, fechaHoy, fechaMin);
                if (validarF == 1)
                {
                    *fecha = auxFecha;
                    break;
                }
            }
            else
            {
                printf("%s", mensajeError);
            }
            if (validarF == 0)
            {
                printf("%s", mensajeError);
            }
            intentos--;
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}*/

int getSexo(char *sexo, int intentos, char mensaje[], char mensajeError[])
{
    int todoOk = 0;
    if (sexo != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", sexo);
            *sexo = tolower(*sexo);
            if (*sexo != 'f' && *sexo != 'm')
            {
                printf("%s", mensajeError);
                intentos--;
            }
            else
            {
                break;
            }
        } while (intentos);

        if (intentos > 0)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int getTelefono(char telefono[], int len, int intentos)
{
    int todoOk = 0;
    int tipo;
    if (telefono != NULL && len > 9 && intentos >= 0)
    {
        if (getInt(&tipo, 1, 2, 3, "Ingrese tipo de numero de telefono: \n1. Numero de celular.\n2. Numero de linea. \n", "Error. "))
        {
            do
            {
                if (tipo == 1)
                {
                    printf("Ingrese su numero de celular (nn-nnnn-nnnn): ");
                    fflush(stdin);
                    gets(telefono);
                    for (int i = 0; i < 12; i++)
                    {
                        if ((isdigit(telefono[i]) || ((i == 2 || i == 7) && telefono[i] == '-')) && strlen(telefono) < 13)
                        {
                            todoOk = 1;
                        }
                        else
                        {
                            todoOk = 0;
                            printf("Error. ");
                            break;
                        }
                    }
                }
                else
                {
                    printf("Ingrese su numero de linea (nnnn-nnnn): ");
                    fflush(stdin);
                    gets(telefono);

                    for (int i = 0; i < 9; i++)
                    {
                        if ((isdigit(telefono[i]) || (i == 4 && telefono[i] == '-')) && strlen(telefono) < 10)
                        {
                            todoOk = 1;
                        }
                        else
                        {
                            todoOk = 0;
                            printf("Error. ");
                            break;
                        }
                    }
                }
                intentos--;
            } while (!todoOk && intentos != 0);
        }
    }
    return todoOk;
}
