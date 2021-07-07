#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "inputs_lean.h"
#include "parser.h"
#include "pais.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pListaPaises);

int controller_ListPaises(LinkedList *pListaPaises);

LinkedList* controller_assing(LinkedList* pListaPaises);

int controller_saveAsText(char *path, LinkedList *pListaPaises);
