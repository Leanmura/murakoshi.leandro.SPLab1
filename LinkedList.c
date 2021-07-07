#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node *getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList *ll_newLinkedList(void)
{
    LinkedList *this = (LinkedList *)malloc(sizeof(LinkedList));
    if (this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node *getNode(LinkedList *this, int nodeIndex)
{
    Node *pNode = NULL;
    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        // si entra al if, es xq hay una linked list
        pNode = this->pFirstNode;            // entonces guardamos la direccion del primer nodo (indice 0)
        for (int i = 1; i <= nodeIndex; i++) // se repite hasta llegar al indice buscado
        {
            pNode = pNode->pNextNode; // guardamos la direccion del siguiente nodo
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node *test_getNode(LinkedList *this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement)
{
    int returnAux = -1;
    Node *newNode = NULL;
    if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) //&& pElement != NULL  (se deberia poder que algun vagon apunte a NULL)
    {
        // si entra al if, es xq hay una linked list
        newNode = (Node *)malloc(sizeof(Node)); // creo el nuevo nodo
        if (newNode != NULL)                    // si lo pude crear
        {
            newNode->pElement = pElement;                  // guardo el elemento en el nodo
            newNode->pNextNode = getNode(this, nodeIndex); // uno mi nuevo nodo, con el nodo que esta en el indice donde lo quiero poner
            if (nodeIndex == 0)                            // si el indice donde lo quiero poner es en el 0
            {
                this->pFirstNode = newNode; // uno la linked list con el nuevo nodo
            }
            else
            {
                getNode(this, nodeIndex - 1)->pNextNode = newNode; // uno el nodo anterior a donde lo quiero poner, con el nuevo nodo
            }
            this->size++; // aumento el tamanio de l alinked list
            newNode = NULL;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement)
{
    return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement)
{
    int returnAux = -1;
    if (this != NULL)
    {
        if (addNode(this, ll_len(this), pElement) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief obtiene un elemento de la linked list que se encuentra en el �ndice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void *ll_get(LinkedList *this, int index)
{
    void *pElement = NULL;
    Node *auxNode = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        if (auxNode != NULL)
        {
            pElement = auxNode->pElement;
            auxNode = NULL;
        }
    }
    return pElement;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement)
{
    int returnAux = -1;
    Node *auxNode = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this, index);
        if (auxNode != NULL)
        {
            auxNode->pElement = pElement;
            auxNode = NULL;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index)
{
    int returnAux = -1;
    Node *remNode = NULL; // puntero al nodo que vamos a eliminar
    Node *auxNode = NULL; // puntero al nodo anterior al que vamos a eliminar
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        remNode = getNode(this, index);
        if (remNode != NULL)
        {
            if (index == 0) // si el que queremos eliminar es el primer vagon
            {
                this->pFirstNode = remNode->pNextNode; // copiamos el nodo que le sigue al que vamos a eliminar enn el primer nodo
            }
            else
            {
                auxNode = getNode(this, index - 1);
                if (auxNode != NULL)
                {
                    auxNode->pNextNode = remNode->pNextNode; // copiamos el nodo que le sigue al que vamos a eliminar en el nodo anterior
                }
            }
            auxNode = NULL;
            free(remNode); // liberamos el nodo que eliminamos
            this->size--;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = 0;
        while (ll_len(this) > 0) // se puede poner ll_isEmpty
        {
            if (ll_remove(this, 0) == -1)
            {
                returnAux = -1;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        if (ll_clear(this) == 0)
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement)
{
    int returnAux = -1;
    Node *pNode = NULL;
    int len;
    if (this != NULL)
    {
        len = ll_len(this);
        for (int i = 0; i < len; i++) // se repite hasta llegar al indice buscado
        {
            pNode = getNode(this, i);
            if (pNode != NULL)
            {
                if (pNode->pElement == pElement)
                {
                    returnAux = i;
                    break;
                }
            }
        }
        pNode = NULL;
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = 0;
        if (ll_len(this) == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement)
{
    int returnAux = addNode(this, index, pElement); // no hace falta validar, por que ya lo hace el add node
    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero (elimina el nodo, es decir elimina el elemento de la lista, no el elemento en si)
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void *ll_pop(LinkedList *this, int index)
{
    void *returnAux = NULL;
    if (this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);
        if (returnAux != NULL)
        {
            if (ll_remove(this, index) == -1)
            {
                returnAux = NULL;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList *this, void *pElement)
{
    int returnAux = -1;
    if (this != NULL)
    {
        returnAux = 0;
        if (ll_indexOf(this, pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList *this, LinkedList *this2)
{
    int returnAux = -1;
    void *pElement = NULL;
    int len2;
    if (this != NULL && this2 != NULL)
    {
        returnAux = 1;
        len2 = ll_len(this2);
        for (int i = 0; i < len2; i++)
        {
            pElement = ll_get(this2, i);
            if (ll_contains(this, pElement) != 1)
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList *ll_subList(LinkedList *this, int from, int to)
{
    LinkedList *subList = NULL;
    void *pElement = NULL;
    if (!(this == NULL || from < 0 || from >= ll_len(this) || to <= from || to > ll_len(this)))
    {
        subList = ll_newLinkedList();
        if (subList != NULL)
        {
            for (int i = from; i < to; i++)
            {
                pElement = ll_get(this, i);
                //if(pElement != NULL)
                //{
                if (ll_add(subList, pElement) == -1)
                {
                    ll_deleteLinkedList(subList);
                    break;
                }
                //}
            }
        }
    }
    return subList;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param cloneList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList *ll_clone(LinkedList *this)
{
    LinkedList *cloneList = NULL;
    cloneList = ll_subList(this, 0, ll_len(this));
    return cloneList;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void *, void *), int order)
{
    int returnAux = -1;
    int len;
    void *pAux1 = NULL;
    void *pAux2 = NULL;
    if (this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        len = ll_len(this);
        if (len != -1)
        {
            for (int i = 0; i < len - 1; i++)
            {
                for (int x = i + 1; x < len; x++)
                {
                    pAux1 = ll_get(this, i);
                    pAux2 = ll_get(this, x);
                    if ((pFunc(pAux1, pAux2) == 1 && order) || (pFunc(pAux1, pAux2) == 0 && !order))
                    {
                        if (!ll_set(this, x, pAux1) && !ll_set(this, i, pAux2))
                        {
                            returnAux = 0;
                        }
                    }
                }
            }
            pAux1 = NULL;
            pAux2 = NULL;
        }
    }
    return returnAux;
}
/** \brief Filtra elementos de la linked list que le pasemos y los copia a una linked list nueva
 *
 * \param this LinkedList* puntero a la lista
 * \param int(*pFunc)(void*) puntero a la funcion que sabe filtrar un empleado
 * \return LinkedList* retorna un puntero al nuevo linkedList con los elementos filtrados
 *
 */
LinkedList *ll_filter(LinkedList *this, int (*pFunc)(void *))
{
    LinkedList *listaFiltrada = NULL;
    int len;
    void *pAux = NULL;

    if (this != NULL && pFunc != NULL)
    {
        listaFiltrada = ll_newLinkedList();
        if (listaFiltrada != NULL)
        {
            len = ll_len(this);
            for (int i = 0; i < len; i++)
            {
                pAux = ll_get(this, i);
                if (pFunc(pAux))
                {
                    if (ll_add(listaFiltrada, pAux) == -1)
                    {
                        ll_deleteLinkedList(listaFiltrada);
                        listaFiltrada = NULL;
                        break;
                    }
                }
            }
            pAux = NULL;
        }
    }
    return listaFiltrada;
}

LinkedList *ll_map(LinkedList *this, void *(*pFunc)(void *))
{
    LinkedList *listaMap = NULL;
    int len;
    void *pAux = NULL;
    void *pElement = NULL;
    if (this != NULL && pFunc != NULL)
    {
        listaMap = ll_newLinkedList();
        if (listaMap != NULL)
        {
            len = ll_len(this);
            for (int i = 0; i < len; i++)
            {
                pAux = ll_get(this, i);

                pElement = pFunc(pAux);
                if (pElement != NULL)
                {
                    if (ll_add(listaMap, pElement) == -1)
                    {
                        ll_deleteLinkedList(listaMap);
                        listaMap = NULL;
                        break;
                    }
                }
            }
            pAux = NULL;
        }
    }
    return listaMap;
}
