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
    gotoxy(35,2);
    cout<<"PRECIO UNITARIO";
    gotoxy(60,2);
    cout<<"STOCK";
    gotoxy(75,2);
    cout<<"ESTADO";
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
