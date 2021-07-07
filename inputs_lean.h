//#include "fecha.h"
#ifndef INPUTS_LEAN_H_INCLUDED
#define INPUTS_LEAN_H_INCLUDED

#endif // INPUTS_LEAN_H_INCLUDED

/** \brief pide un numero entero al usuario y lo valida, dandole x cantidad de intetos
 *
 * \param pResultado int* puntero a la variable donde vamos a devolver el numero ingresado por el usuario
 * \param minimo int numero minimo que puede ingresar el usuario
 * \param maximo int numero maximo que puede ingresar el usuario
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getInt(int *pResultado, int minimo, int maximo, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide un numero flotante(con coma) al usuario y lo valida, dandole x cantidad de intetos
 *
 * \param pResultado float* puntero a la variable donde vamos a devolver el numero ingresado por el usuario
 * \param minimo float numero minimo que puede ingresar el usuario
 * \param maximo float numero maximo que puede ingresar el usuario
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getFloat(float *pResultado, float minimo, float maximo, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide un string, corroborando que no sea mayor al largo de la variable, dandole x cantidad de intetos
 *
 * \param cadena[] char variable donde vamos a devolver la cadena ingresada por el usuario
 * \param len int tamanio de la variable cadena[]
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getString(char cadena[], int len, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide un nombre, corroborando que no sea mayor al largo de la variable y qeu sean todas letras, dandole x cantidad de intetos
 *
 * \param nombre[] char variable donde vamos a devolver la cadena ingresada por el usuario
 * \param len int tamanio de la variable cadena[]
 * \param intentos int intentos totales que puede realizar el usuario para que el numero sea valido
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int retorna 1 si salio todo bien, 0 si hubo un problema
 *
 */
int getNombre(char nombre[], int len, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide una letra y la valida, dandole x cantidad de intentos
 *
 * \param letra char* puntero a la variable donde vamos a escribir la letra
 * \param intentos int intentos totales que puede realizar el usuario
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int devuelve 1 si esta todo ok, o 0 si hay algun error
 *
 */
int getLetra(char *letra, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide una fecha, validando que tenga el formato(DD/MM/AAAA) y que este dentro de la fecha maxima y minima, dandole x cantidad de intentos
 *
 * \param fecha eFecha* puntero a la variable que se va a escribir la fecha validada
 * \param fechaHoy eFecha fecha actual o maxima fecha que puede ingresar
 * \param fechaMin eFecha fecha minima que puede ingresar
 * \param intentos int intentos totales que puede realizar el usuario
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int devuelve 1 si esta todo ok, o 0 si hay algun error
 *
 */
//int getFecha(eFecha* fecha, eFecha fechaHoy, eFecha fechaMin, int intentos, char mensaje[], char mensajeError[]);

/** \brief pide el sexo, validando que sea f o m, dandole x cantidad de intentos
 *
 * \param sexo char* variable en la que se va a escribir el sexo valido
 * \param intentos int intentos totales que puede realizar el usuario
 * \param mensaje[] char mensaje que pide el numero al usuario
 * \param mensajeError[] char mensaje que avisa al usuario si el numero no es valido.
 * \return int devuelve 1 si esta todo ok, o 0 si hay algun error
 *
 */
int getSexo(char *sexo, int intentos, char mensaje[], char mensajeError[]);

int getTelefono(char telefono[], int len, int intentos);
