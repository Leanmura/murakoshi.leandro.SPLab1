#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    int id;
    char pais[20];
    int unaDosis;
    int dosDosis;
    int sinVacunar;
} ePais;

#endif // PAIS_H_INCLUDED

ePais *pais_new();
ePais *pais_newParametros(char *idStr, char *paisStr, char *dosDosisStr, char *unaDosisStr, char *sinVacunarStr);
void pais_delete(ePais *this);
int pais_setId(ePais *this, int id);
int pais_getId(ePais *this, int *id);
int pais_setPais(ePais *this, char *pais);
int pais_getPais(ePais *this, char *pais);
int pais_setUnaDosis(ePais *this, int dosDosis);
int pais_getUnaDosis(ePais *this, int *dosDosis);
int pais_setDosDosis(ePais *this, int unaDosis);
int pais_getDosDosis(ePais *this, int *unaDosis);
int pais_setSinVacunar(ePais *this, int sinVacunar);
int pais_getSinVacunar(ePais *this, int *sinVacunar);
