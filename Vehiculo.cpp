#include "Vehiculo.h"
#include "string.h"

PtrDato crearVehiculo(Vehiculo &vehiculo)
{
	PtrDato puntero = new Vehiculo;
	vehiculo.idRegistro="";
	vehiculo.fecha="";
	vehiculo.hora="";
	vehiculo.descripcion="";
	vehiculo.dominio="";
	vehiculo.marca="";
	vehiculo.modelo="";
	vehiculo.motivo="";
	return puntero;
}

void destruirVehiculo(Vehiculo &vehiculo)
{	
}


/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "idJugador".
*/

void setIdVehiculo(Vehiculo &vehiculo, string idRegistro){
	vehiculo.idRegistro=idRegistro;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "idJugador".
*/

string getIdVehiculo(Vehiculo &vehiculo){
	return vehiculo.idRegistro;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "nombreJugador".
*/

void setFecha(Vehiculo &vehiculo, string fecha){
	vehiculo.fecha=fecha;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "nombreJugador".
*/

string getFecha(Vehiculo &vehiculo){
	return vehiculo.fecha;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setHora(Vehiculo &vehiculo, string hora){
	vehiculo.hora=hora;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getHora(Vehiculo &vehiculo){
	return vehiculo.hora;
}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setDescripcion(Vehiculo &vehiculo, string descripcion){
	vehiculo.descripcion=descripcion;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getDescripcion(Vehiculo &vehiculo){
	return vehiculo.descripcion;
}

/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setDominio(Vehiculo &vehiculo, string dominio){
	vehiculo.dominio=dominio;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getDominio(Vehiculo &vehiculo){
	return vehiculo.dominio;
}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setMarca(Vehiculo &vehiculo, string marca){
	vehiculo.marca=marca;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getMarca(Vehiculo &vehiculo){
	return vehiculo.marca;
}

/*------------------------------------------------------------------*/
/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setModelo(Vehiculo &vehiculo, string modelo){
	vehiculo.modelo=modelo;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getModelo(Vehiculo &vehiculo){
	return vehiculo.modelo;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Asigna el valor al campo "goles".
*/

void setMotivo(Vehiculo &vehiculo, string motivo){
	vehiculo.motivo=motivo;
}

/*------------------------------------------------------------------*/
/*
PRE: El TDA debe haber sido creado y no destruido.
POST: Devuelve el valor del campo "goles".
*/

string getMotivo(Vehiculo &vehiculo){
	return vehiculo.motivo;
}

/*------------------------------------------------------------------*/
string toString(Vehiculo &vehiculo){
	return "\nREG-->"+getIdVehiculo(vehiculo)+" DOM: "+getDominio(vehiculo)+" MAR: "+getMarca(vehiculo)+" MOD: "+getModelo(vehiculo)+" MOT:"+getMotivo(vehiculo)+"\n\n";
}

/*------------------------------------------------------------------*/
