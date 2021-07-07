#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"

ePais *pais_new()
{
    ePais *newPais = (ePais *)malloc(sizeof(ePais));
    if (newPais != NULL)
    {
        newPais->id = 0;
        strcpy(newPais->pais, "");
        newPais->unaDosis = 0;
        newPais->dosDosis = 0;
        newPais->sinVacunar = 0;
    }
    return newPais;
}

ePais *pais_newParametros(char *idStr, char *paisStr, char *unaDosisStr, char *dosDosisStr, char *sinVacunarStr)
{
    ePais *newPais = pais_new();

    if (newPais != NULL)
    {
        if (!(pais_setId(newPais, atoi(idStr)) &&
              pais_setPais(newPais, paisStr) &&
              pais_setUnaDosis(newPais, atoi(unaDosisStr)) &&
              pais_setDosDosis(newPais, atoi(dosDosisStr)) &&
              pais_setSinVacunar(newPais, atoi(sinVacunarStr))))
        {
            pais_delete(newPais);
            newPais = NULL;
        }
    }
    return newPais;
}

void pais_delete(ePais *this)
{
    free(this);
}

int pais_setId(ePais *this, int id)
{
    int todoOk = 0;
    if (this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getId(ePais *this, int *id)
{
    int todoOk = 0;
    if (this != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setPais(ePais *this, char *pais)
{
    int todoOk = 0;
    if (this != NULL && pais != NULL && strlen(pais) < 30 && strlen(pais) > 1)
    {
        strcpy(this->pais, pais);
        todoOk = 1;
    }
    return todoOk;
}

int pais_getPais(ePais *this, char *pais)
{
    int todoOk = 0;
    if (this != NULL)
    {
        strcpy(pais, this->pais);
        todoOk = 1;
    }
    return todoOk;
}

int pais_setUnaDosis(ePais *this, int unaDosis)
{
    int todoOk = 0;
    if (this != NULL && unaDosis >= 0)
    {
        this->unaDosis = unaDosis;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getUnaDosis(ePais *this, int *unaDosis)
{
    int todoOk = 0;
    if (this != NULL)
    {
        *unaDosis = this->unaDosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setDosDosis(ePais *this, int dosDosis)
{
    int todoOk = 0;
    if (this != NULL && dosDosis >= 0)
    {
        this->dosDosis = dosDosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_getDosDosis(ePais *this, int *dosDosis)
{
    int todoOk = 0;
    if (this != NULL)
    {
        *dosDosis = this->dosDosis;
        todoOk = 1;
    }
    return todoOk;
}

int pais_setSinVacunar(ePais *this, int sinVacunar)
{
    int todoOk = 0;
    if (this != NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}
int pais_getSinVacunar(ePais *this, int *sinVacunar)
{
    int todoOk = 0;
    if (this != NULL)
    {
        *sinVacunar = this->sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}
