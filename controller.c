#include "controller.h"

/** \brief
 *
 * \param pElement void*
 * \return void*
 *
 */
void *map(void *pElement);

int controller_loadFromText(char *path, LinkedList *pListaPaises)
{
    int todoOk = 0;
    FILE *f = NULL;

    if (path != NULL && pListaPaises != NULL)
    {
        f = fopen(path, "r");
        if (f == NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if (parser_PaisFromText(f, pListaPaises))
            {
                todoOk = 1;
            }
        }
        fclose(f);
    }
    return todoOk;
}

/** \brief Listar paises
 *
 * \param path char*
 * \param pListaPaises LinkedList*
 * \return int
 *
 */
int controller_ListPaises(LinkedList *pListaPaises)
{
    ePais *pais;
    int auxId;
    char auxPais[20];
    int unaDosis;
    int dosDosis;
    int sinVacunar;
    int cantPais = 0;
    int todoOk = 0;

    if (pListaPaises != NULL)
    {
        printf("----------------- LISTADO DE PAISES -----------------\n");
        printf(" ID     PAIS              1 Dosis  2 Dosis  Sin vacunar\n");

        int len = ll_len(pListaPaises);

        for (int i = 0; i < len; i++)
        {
            pais = (ePais *)ll_get(pListaPaises, i);
            if ((pais_getId(pais, &auxId) &&
                 pais_getPais(pais, auxPais) &&
                 pais_getUnaDosis(pais, &unaDosis) &&
                 pais_getDosDosis(pais, &dosDosis) &&
                 pais_getSinVacunar(pais, &sinVacunar)))
            {
                printf(" %03d    %-20s%2d%%      %2d%%       %2d%%\n", auxId, auxPais, unaDosis, dosDosis, sinVacunar);
                cantPais++;
            }
        }
        if (cantPais == len)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

LinkedList *controller_assing(LinkedList *pListaPaises)
{
    LinkedList *listaMap = NULL;
    if (pListaPaises != NULL)
    {
        listaMap = ll_map(pListaPaises, map);
    }
    return listaMap;
}

/** \brief Guarda los datos de los empleados en un archivo .csv (modo texto).
 *
 * \param path char*
 * \param pListaPaises LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pListaPaises)
{
    int todoOk = 0;
    char respuesta = 's';
    int auxId;
    char auxPais[20];
    int unaDosis;
    int dosDosis;
    int sinVacunar;
    ePais *pais;
    FILE *f = NULL;
    int cantCargados = 0;

    if (path != NULL && pListaPaises != NULL)
    {
        f = fopen(path, "r");
        if (f != NULL)
        {
            if (!getLetra(&respuesta, 3, "Este archivo ya existe. Desea sobreescribirlo? ", "Error. "))
            {
                printf("Ha exedido el limite de intentos.\n");
                respuesta = 'n';
            }
            fclose(f);
        }

        if (respuesta != 'n')
        {
            f = fopen(path, "w");
            if (f == NULL)
            {
                printf("No se pudo abrir el archivo.\n");
            }
            else
            {
                fprintf(f, "ID,Pais,1 Dosis,2 Dosis,Sin vacunar\n");
                for (int i = 0; i < ll_len(pListaPaises); i++)
                {
                    pais = (ePais *)ll_get(pListaPaises, i);
                    if (pais != NULL)
                    {
                        if ((pais_getId(pais, &auxId) &&
                             pais_getPais(pais, auxPais) &&
                             pais_getUnaDosis(pais, &unaDosis) &&
                             pais_getDosDosis(pais, &dosDosis) &&
                             pais_getSinVacunar(pais, &sinVacunar)))
                        {
                            fprintf(f, "%d,%s,%d,%d,%d\n", auxId, auxPais, unaDosis, dosDosis, sinVacunar);
                            cantCargados++;
                        }
                    }
                }
                if (cantCargados == ll_len(pListaPaises))
                {
                    todoOk = 1;
                }
            }
        }
        fclose(f);
    }
    return todoOk;
}

void *map(void *pElement)
{
    int unaDosis;
    int dosDosis;
    int sinVacunar;
    int maxUnaDosis = 60;
    int minUnaDosis = 1;
    int maxDosDosis = 40;
    int minDosDosis = 1;
    void *newElement = NULL;
    if (pElement != NULL)
    {
        newElement = pais_new();
        if (newElement != NULL)
        {
            pais_getId(pElement, &((ePais *)newElement)->id);
            pais_getPais(pElement, ((ePais *)newElement)->pais);
            unaDosis = rand() % (maxUnaDosis - minUnaDosis + 1) + minUnaDosis;
            dosDosis = rand() % (maxDosDosis - minDosDosis + 1) + minDosDosis;
            sinVacunar = 100 - unaDosis - dosDosis;

            if (!(pais_setUnaDosis(((ePais *)newElement), unaDosis) &&
                  pais_setDosDosis(((ePais *)newElement), dosDosis) &&
                  pais_setSinVacunar(((ePais *)newElement), sinVacunar)))
            {
                pais_delete(newElement);
                newElement = NULL;
            }
        }
    }
    return newElement;
}
