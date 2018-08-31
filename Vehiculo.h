#include "Lista.h"
#include <iostream>

#include "string.h"
#include <string>

#ifndef __VEHICULO_H__
#define __VEHICULO_H__

using namespace std;

// Definición de la estructura jugador.

typedef struct Vehiculo
{
    	string	idRegistro;
    	string  fecha;
    	string	hora;
    	string	descripcion;
    	string  dominio;
    	string 	marca;
    	string 	modelo;
    	string	motivo;
};

/*------------------------------------------------------------------*/
/*
PRE: El TDA no debe haber sido creado.
POST: Crea el TDA con los siguientes valores por defecto:
	idJugador = 0, nombreJugador = " ", fechaNacimiento = "00/00/0000",
	goles = 0, idEquipoPertenece = 0.
*/

PtrDato crearVehiculo(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado.
POST: Destruye el TDA.
*/

void destruirVehiculo(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idJugador".
*/

void setIdVehiculo(Vehiculo &vehiculo, string idRegistro);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idJugador".
*/

string getIdVehiculo(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "nombreJugador".
*/

void setFecha(Vehiculo &vehiculo, string fecha);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "nombreJugador".
*/

string getFecha(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setHora(Vehiculo &vehiculo, string hora);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getHora(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setDescripcion(Vehiculo &vehiculo, string descripcion);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getDescripcion(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setDominio(Vehiculo &vehiculo, string dominio);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getDominio(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setMarca(Vehiculo &vehiculo, string marca);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getMarca(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setModelo(Vehiculo &vehiculo, string modelo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getModelo(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setMotivo(Vehiculo &vehiculo, string motivo);

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getMotivo(Vehiculo &vehiculo);

/*------------------------------------------------------------------*/

string toString(Vehiculo &vehiculo);


#endif

