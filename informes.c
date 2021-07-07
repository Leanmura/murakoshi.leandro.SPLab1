#include "informes.h"

int paisesExitosos(void *pPais)
{
    int retorno = 0;
    if (pPais != NULL && ((ePais *)pPais)->dosDosis > 30)
    {
        retorno = 1;
    }
    return retorno;
}

int paisesEnElHorno(void *pPais)
{
    int retorno = 0;
    if (pPais != NULL && ((ePais *)pPais)->sinVacunar > ((ePais *)pPais)->unaDosis + ((ePais *)pPais)->dosDosis)
    {
        retorno = 1;
    }
    return retorno;
}

int ordernarPorVacunacion(void *p1, void *p2)
{
    int retorno = -1;
    if (p1 != NULL && p2 != NULL)
    {
        if (((ePais *)p1)->unaDosis > ((ePais *)p2)->unaDosis)
        {
            retorno = 1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int paisMasCastigado(LinkedList *pListaPaises)
{
    int len;
    ePais *auxP = NULL;
    char auxPais[20];
    int masCastigado = -1;
    if (pListaPaises != NULL)
    {
        len = ll_len(pListaPaises);

        for (int i = 0; i < len; i++)
        {
            auxP = ll_get(pListaPaises, i);
            if (i == 0 || auxP->sinVacunar > masCastigado)
            {
                masCastigado = auxP->sinVacunar;
            }
        }

        printf("Pais/es mas castigado/s: \n");
        for (int i = 0; i < len; i++)
        {
            auxP = ll_get(pListaPaises, i);
            if (auxP->sinVacunar == masCastigado)
            {
                if (pais_getPais(auxP, auxPais))
                {
                    printf("%-25s\n", auxPais);
                }
            }
        }
        printf("Tuvieron: %d%% de personas sin vacunar\n", masCastigado);
    }
    return masCastigado;
}
