#include "parser.h"

int parser_PaisFromText(FILE *pFile, LinkedList *pListaPaises)
{
    int todoOk = 0;
    int cant;
    char buffer[5][50];
    ePais *nuevoPais;
    if (pFile != NULL && pListaPaises != NULL)
    {
        while (!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]); // guardarlo en una matriz
            if (cant == 5)
            {
                nuevoPais = pais_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

                if (nuevoPais != NULL)
                {
                    ll_add(pListaPaises, nuevoPais);
                    todoOk = 1;
                }
                else
                {
                    pais_delete(nuevoPais);
                }
            }
        }
    }
    return todoOk;
}
