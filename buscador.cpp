    #include <stdio.h>
    #include "conio.h"
    #include <iostream>
    #include <string.h>
    #include <stdlib.h>
    #include <iomanip>
    #include <windows.h>
    #include "Lista.h"
    #include "Vehiculo.h"
    
    
	#ifndef NULL
	#define NULL      0
	#endif
    
    #define		FALSE 0
    #define		TRUE  1
    
    #define 	MAXLINEA 	2000
	#define 	MAXCAMPO	50
    #define 	TOPEVECTOR 	79
    
  
    using namespace std;
     
   // typedef int 	bool;
    typedef char 	str40[MAXCAMPO];
    typedef char 	str_linea[MAXLINEA];
    /*REGISTRO	FECHA	HORA	DESCRIPCION (Vehiculo / Moto)	DOMINIO	MARCA	MODELO	MOTIVO	 LEVANTADO EN:	ACTA DE COMPROBACION 	ACTA CONTRAVENCIONAL	BOLETA DE CITACION	AGENTE LABRANTE	INFRACTOR/ CONTRAVENTOR	AGENTE DE PLAYA QUE RECIBIO	GRUA / CHOFER	INVENTARIO SI/NO	Nº CHASIS Y MOTOR	FECHA	HORA	PERSONA QUE RETIRÓ (indicar si es Titular o Conductor Autorizado y DNI).	ENTREGA AGENTE	NOTAS	CONTROL DE LEGALES																																																																																																																																																																																														
TRO*/     
    typedef struct ty_libro
    {
    	str40	registo;
    	str40   fecha;
    	str40	hora;
    	str40	descripcion;
    	str40   dominio;
    	str40 	marca;
    	str40 	modelo;
    };
     
/******************************************************************************/
   
    void mostrarEncabezadoMenu(void);
    void MenuPrincipal(void);
    void MenuFIN(void);
    void color(int X);
    char numeroAcaracter(int n);
    void cargarVector(void);
    
    void cargarLista(Lista &listaVehiculo);
    void cargarLista2(Lista &listaVehiculo);
    void cargarLista3(Lista &listaVehiculo);
    void recorrerLista(Lista &listaVehiculo);
	ResultadoComparacion comparaVehiculos(PtrDato dato1,PtrDato dato2);
	
	PtrNodoLista localizarDominio(Lista &vehiculos, string dominio);
	
	void mensajeDeErrorMenuPrincipal(void);
    void mostrarEncabezadoMenu(void);
/******************************************************************************/
/******************************************************************************/
     
    int main()
    {
				
			color(47);
		//	cargarVector();
			int option=0;
			
			Lista vehiculos;

			Lista vehiculosR;
			Lista vehiculosC;
			Lista vehiculosA;

			crearLista(vehiculos,comparaVehiculos);
			crearLista(vehiculosR,comparaVehiculos);
			crearLista(vehiculosC,comparaVehiculos);
			crearLista(vehiculosA,comparaVehiculos);
			
			cargarLista(vehiculos);
			cargarLista(vehiculosR);
			cargarLista3(vehiculos);
			cargarLista3(vehiculosA);
			cargarLista2(vehiculos);
			cargarLista2(vehiculosC);
			
			
			
			string dominio="BSS698";
			
			do
			{
			   MenuPrincipal();
			   fflush(stdin);
			   cin>>option;
			   
			   system("cls");
			   switch (option)
			
			  {   case 1 :{ 
							/*a. Buscar vehiculos */
							mostrarEncabezadoMenu();
							cout<<"\nIngrese dominio del vehiculo [EN MAYUSCULA] : ";
							cin>>dominio;
							//for (i<0;i<sizeof(domi);i++) {domi = toupper(domi(i))};
							
							PtrNodoLista ptrAux = fin();
							ptrAux=localizarDominio(vehiculos,dominio);
							if(ptrAux==fin()){
								cout<<"\nNo se encontro el vehiculo\n"<<endl;
							}else
							{ cout<<toString(*(Vehiculo*)ptrAux->ptrDato);
							}
							system("pause");
							
			         		break;}
			
			      case 2 :{/*b. Listar Vehiculos abandonados*/
			      			mostrarEncabezadoMenu();
							recorrerLista(vehiculosR);
							system("pause");
							break;
			      					      			
				  		   }

			      case 3 :{/*b. Listar Vehiculos california*/
			      			mostrarEncabezadoMenu();
							recorrerLista(vehiculosC);
							system("pause");
							break;
			      					      			
				  		   }

			      case 4 :{/*b. Listar Vehiculos rio cuarto*/
			      			mostrarEncabezadoMenu();
							recorrerLista(vehiculosA);
							system("pause");
							break;
			      					      			
				  		   }
				  case 5:{ MenuFIN();
				  	
					break;
				  }
				  	   			
			             
			      default:{mensajeDeErrorMenuPrincipal(); fflush(stdin); break;}
			    }
			}while(option != 5);
			
				 
			return 0;
			cout<<"\n\n";
			
			
	}


/******************************************************************************/

void cargarLista(Lista &listaVehiculo){
	
	FILE *pArchivo; //rioCuarto
    char 		*token;
    str_linea 	linea;
    str_linea	aux;
    int 		i=0;
    
    
    	//Abro el archivo en modo lectura
    	pArchivo=fopen("PlayaRioCuarto.csv","r");
    	
		
		if(pArchivo==NULL && pArchivo==NULL)
    	{
    		cout<<"No se pudo abrir el Archivo de Entrada.\n";
    	}else
    	{
    	//	cout<<"El archivo se abrio correctamente.\n";
    	}
    	
    	
    	while (!feof(pArchivo))
    	{
    	
			fgets(linea,MAXLINEA,pArchivo);
		
		    Vehiculo* ptrVehiculo = new Vehiculo;
		    crearVehiculo(*ptrVehiculo);
		    token=strtok(linea,";");
			setIdVehiculo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			if(token!=NULL){
    	//	cout<<"fin"<<endl;
		//	}else{
			
			setFecha(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setHora(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDescripcion(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDominio(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setMarca(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setModelo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			setMotivo(*ptrVehiculo,token);
			/*
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			*/
		if(i==0){
	    		adicionarPrincipio(listaVehiculo,ptrVehiculo);
			cout<<"entro";	
	        		
			}else{
			adicionarFinal(listaVehiculo, ptrVehiculo);
			}
			
	    	

			destruirVehiculo(*ptrVehiculo);
			}
			
			i++;
			
		}
	
		fclose(pArchivo);
	
}

/******************************************************************************/

void cargarLista2(Lista &listaVehiculo){
	
	FILE *pArchivo; //California
    char 		*token;
    str_linea 	linea;
 
 	int			i=0;
   	//Abro el archivo en modo lectura
    	pArchivo=fopen("PlayaCalifornia.csv","rt");
    	
		
		if(pArchivo==NULL && pArchivo==NULL)
    	{
    		cout<<"No se pudo abrir el Archivo de Entrada.\n";
    	}else
    	{
    //		cout<<"El archivo se abrio correctamente.\n";
    	}
    	
    	while (!feof(pArchivo))
		{
    			fgets(linea,MAXLINEA,pArchivo);
		
		    Vehiculo* ptrVehiculo = new Vehiculo;
		    crearVehiculo(*ptrVehiculo);
		    token=strtok(linea,";");
			setIdVehiculo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			if(token!=NULL){
    	//	cout<<"fin"<<endl;
		//	}else{
			
			setFecha(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setHora(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDescripcion(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDominio(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setMarca(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setModelo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			setMotivo(*ptrVehiculo,token);
			/*
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			*/
		if(i==0){
	    		adicionarPrincipio(listaVehiculo,ptrVehiculo);
			}else{
			adicionarFinal(listaVehiculo, ptrVehiculo);
			}
			
	    
			destruirVehiculo(*ptrVehiculo);
			}
			
			i++;
	}
	
		fclose(pArchivo);
	
}

/******************************************************************************/
void cargarLista3(Lista &listaVehiculo){
	
	FILE *pArchivo; //Abandonados
    char 		*token;
    str_linea 	linea;
    int 		i=0;
    
    
    	//Abro el archivo en modo lectura
    	pArchivo=fopen("PlayaAbandonados.csv","r");
    	
		
		if(pArchivo==NULL && pArchivo==NULL)
    	{
    		cout<<"No se pudo abrir el Archivo de Entrada.\n";
    	}else
    	{
    	//	cout<<"El archivo se abrio correctamente.\n";
    	}
    	
      	while (!feof(pArchivo))
    	{
    	
			fgets(linea,MAXLINEA,pArchivo);
		
		    Vehiculo* ptrVehiculo = new Vehiculo;
		    crearVehiculo(*ptrVehiculo);
		    token=strtok(linea,";");
			setIdVehiculo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			if(token!=NULL){
    	//	cout<<"fin"<<endl;
		//	}else{
			
			setFecha(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setHora(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDescripcion(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setDominio(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setMarca(*ptrVehiculo,token);

			token=strtok(NULL,";");
			setModelo(*ptrVehiculo,token);
			
			token=strtok(NULL,";");
			setMotivo(*ptrVehiculo,token);
			/*
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");token=strtok(NULL,";");
			*/
		if(i==0){
	    		adicionarPrincipio(listaVehiculo,ptrVehiculo);
   		
			}else{
			adicionarFinal(listaVehiculo, ptrVehiculo);
			}	    	

			destruirVehiculo(*ptrVehiculo);
			}
			
			i++;
			
		}
	
		fclose(pArchivo);	
}

/******************************************************************************/

void recorrerLista(Lista &listaVehiculo){
	
 PtrNodoLista cursor=primero(listaVehiculo);
 //cout<<"***Recorrer Lista***"<<endl;
 
 if(cursor==fin()){
 	cout<<"lista vacia";
 }else
 {while(cursor!=fin()){
 	cout<<"REG--> "<<getIdVehiculo(*(Vehiculo*)cursor->ptrDato);
	cout<<" DOM : "<<getDominio(*(Vehiculo*)cursor->ptrDato);
	cout<<" MAR : "<<getMarca(*(Vehiculo*)cursor->ptrDato);
	cout<<" MOD : "<<getModelo(*(Vehiculo*)cursor->ptrDato);
	cout<<" MOT : "<<getMotivo(*(Vehiculo*)cursor->ptrDato)<<endl;
 	
 	cursor=siguiente(listaVehiculo,cursor);
 }
 }
}

/******************************************************************************/

PtrNodoLista localizarDominio(Lista &vehiculos, string dominio)
{

     PtrNodoLista devuelve = fin();
     Vehiculo auxVehiculo;
     crearVehiculo(auxVehiculo);
     setDominio(auxVehiculo,dominio);
     PtrNodoLista cursor = primero(vehiculos);
     //bool encontrado = false;

     while (cursor != fin())
     {
         
         if (getDominio(*(Vehiculo*)cursor->ptrDato).compare(dominio)==0) //iguales
         {
            devuelve = cursor;
            //encontrado = true;
         }
         cursor = siguiente(vehiculos,cursor);
     }

  return devuelve;
}

/******************************************************************************/

ResultadoComparacion comparaVehiculos(PtrDato dato1,PtrDato dato2)
{
                     if(  ((Vehiculo*)dato1)->idRegistro >  ((Vehiculo*)dato2)->idRegistro)
                     {
                          return MAYOR;
                      }
                      else if(  ((Vehiculo*)dato1)->idRegistro<  ((Vehiculo*)dato2)->idRegistro )
                      {
                           return MENOR;

                       }
                       else
                       {
                           return IGUAL;
                       }
}

/******************************************************************************/

/***funciones de menu****/
void mostrarEncabezadoMenu(void)
{
system("cls");
printf("\n************************** PLAYA RIO CUARTO ");
cout<<"**********************************\n";
}

void MenuPrincipal(void)
    {
        mostrarEncabezadoMenu();
        printf("\nQue operacion desea realizar?\n\n");
        printf("1. Buscar Dominio\n");
        printf("2. Listar Vehiculos Rio Cuarto \n");
        printf("3. Listar Vehiculos California \n");
        printf("4. Listar Vehiculos Abandonados \n");
		printf("5. Salir\n\n");
        printf("Ingrese numero de operacion: ");

    }


void MenuFIN(void)
{
     mostrarEncabezadoMenu();
     cout<<"\nUsted salio del sistema\n";
}



/******************************************************************************/

/*Mensajes de error*/
void mensajeDeErrorMenuPrincipal(void)
{
 mostrarEncabezadoMenu();
 printf("\nError, las opciones validas son 1, 2 o 3. \n\n");
 system("PAUSE");
 MenuPrincipal();

}


/******************************************************************************/
char numeroAcaracter(int n)
{
     switch (n)
     {case 0:return 'A';
      case 1:return 'B';
      case 2:return 'C';
      case 3:return 'D';
      case 4:return 'E';
      case 5:return 'F';
      case 6:return 'G';
      case 7:return 'H';
      }
}


void color(int X)
{
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

/******************************************************************************/

void cargarVector(void){
	
	    FILE *pArchivo;
    	//FILE *pArchivo2;
    	
		ty_libro 	vLibro[TOPEVECTOR];
    	char 		*token;
    	str_linea 	linea;
    	int 		i=0;
    
    	//clrscr();
    	//Abro el archivo en modo lectura
    	pArchivo=fopen("PlayaRioCuar.csv","r");
		
		if(pArchivo==NULL)
    	{
    		cout<<"No se pudo abrir el Archivo de Entrada.\n";
    	}
    	else
    	{
    		cout<<"El archivo se abrio correctamente.\n";
    	}
    	
    	while (!feof(pArchivo) && i<80)
    	{
    		fgets(linea,MAXLINEA,pArchivo);
    		
    		token=strtok(linea,";");
			strcpy(vLibro[i].registo,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].fecha,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].hora,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].descripcion,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].dominio,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].marca,token);
			
			token=strtok(NULL,";");
			strcpy(vLibro[i].modelo,token);

			i++;
		}
	
			/*int tam = sizeof(vLibro); //tamañano
			int j=0;
			
			for(j=0;j<tam;j++){
				cout<<vLibro[j].registo<<"°°"<<vLibro[j].fecha<<"°°"<<vLibro[j].hora<<"°°"<<vLibro[j].dominio<<"\n";
			}*/
		fclose(pArchivo);
		cout<<"cargo";
		
};

/***********************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
************************************************************************************************************
*/
	
		 /*for(j=0;j<i;j++)
    	{
    		cout<<"Registro: "<<vLibro[j].registor<<endl;
    		cout<<"Nombre: "<<vLibro[j].dominio<<endl;
    		cout<<setw(8)<<setfill('-')<<"-"<<endl;
    	}*/
    	
    	//Parseo el archivo hasta la marca de fin de archivo
    	//y voy guardando los registros en el vector de registros
    	/*while (!feof(pArchivo))
    	{
    		fgets(linea,MAXLINEA,pArchivo);
     
    		token = strtok(linea,";");
    		vLibro[i].iCodigo = atoi(token);
     
    		token = strtok(NULL,";");
    		strcpy(vLibro[i].sAutor,token);
     
    		token = strtok(NULL,";");
    		strcpy(vLibro[i].sNombre,token);
     
    		token = strtok(NULL,";");
    		vLibro[i].fPrecio = atof(token);
     
    		token = strtok(NULL,";");
    		vLibro[i].iStock = atoi(token);
    		i++;
    	}*/
    	//Cierro el archivo
    	//Muestro parte del contenido para verificar el correcto parseo
    	/*for(i=0;i<2;i++)
    	{
    		cout<<"Codigo: "<<vLibro[i].iCodigo<<endl;
    		cout<<"Nombre: "<<vLibro[i].sNombre<<endl;
    		cout<<"Autor: "<<vLibro[i].sAutor<<endl;
    		cout<<"Precio: "<<vLibro[i].fPrecio<<endl;
    		cout<<"Stock: "<<vLibro[i].iStock<<endl;
    		cout<<setw(8)<<setfill('-')<<"-"<<endl;
    	}*/
   
    
    /*
	
	    		while(token !=NULL){
				vLibro[i].registor = atoi(token);
     			strcpy(vLibro[i].dominio,token);     
  			cout<<token;
			 	token = strtok(NULL,";");
    			}
			
				//cout<<linea<<"\t";
  			/*if (!strcmp(strtok(linea,";"),"FVX801")){
  				cout<<"encontrado";
			  }*/
			  

	/*int id = 1;
    char dato[50];

     if (!listaVacia(listaVehiculo))
     {
        id = (getIdVehiculo(*((Vehiculo*)(ultimo(listaVehiculo)->ptrDato))))+1;
     }
	*/

