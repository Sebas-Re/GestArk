#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include "rlutil.h"
///FUNCIONES GLOBALES

void cargarCadena(char *pal, int tam){//recibe un char y un int y ajusta la variable con memoria dinamica
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}
///CARTELES
void cartelListarArticulos(){
    gotoxy(1,1);
    cout<<"INVETARIO: ";
    gotoxy(4,2);
    cout<<"ID";
    gotoxy(8,2);
    cout<<"DESCRIPCION";
    gotoxy(28,2);
    cout<<"PRECIO UNITARIO";
    gotoxy(46,2);
    cout<<"STOCK";
    gotoxy(54,2);
    cout<<"ESTADO";
    gotoxy(66,2);
    cout<<"PROVEEDOR";
}

void cartelListarProveedores(){
    gotoxy(1,1);
    cout<<"PROVEEDORES: ";
    gotoxy(4,2);
    cout<<"CODIGO";
    gotoxy(8,2);
    cout<<"PROVEEDOR";
    gotoxy(35,2);
    cout<<"TELEFONO";
    gotoxy(60,2);
    cout<<"MAIL";
    gotoxy(75,2);
    cout<<"DIRECCION";
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
