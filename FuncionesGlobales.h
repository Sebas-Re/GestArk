#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
#include "rlutil.h"
///FUNCIONES GLOBALES
bool verificarCliente(int );
bool verificarVendedor(int );
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
void cartelListarArticulos(int y){
    gotoxy(1,y);
    cout<<"INVENTARIO: ";
    y++;
    gotoxy(4,y);
    cout<<"ID";
    gotoxy(8,y);
    cout<<"DESCRIPCION";
    gotoxy(28,y);
    cout<<"PRECIO UNITARIO";
    gotoxy(46,y);
    cout<<"STOCK";
    gotoxy(54,y);
    cout<<"ESTADO";
    gotoxy(74,y);
    cout<<"PROVEEDOR";
}

void BorrarArea(int x, int y){
int i,j;

    for (j=x; j < x+200; j++)
    {
        for (i=y; i<y+30; i++)
        {
            rlutil::locate(j,i);
            cout <<" ";
        }
    }




}

void cartelListarProveedores(int y){
    gotoxy(1,y);
    cout<<"PROVEEDORES: ";
    y++;
    gotoxy(4,y);
    cout<<"CODIGO";
    gotoxy(24,y);
    cout<<"PROVEEDOR";
    gotoxy(60,y);
    cout<<"TELEFONO";
    gotoxy(80,y);
    cout<<"MAIL";
    gotoxy(118,y);
    cout<<"DIRECCION";
}

void cartelListarVendedores(int y){
    gotoxy(4,y);
    cout<<"ID";
    gotoxy(8,y);
    cout<<"CATEGORIA";
    gotoxy(22,y);
    cout<<"DNI";
    gotoxy(34,y);
    cout<<"NOMBRE";
    gotoxy(59,y);
    cout<<"APELLIDO";
    gotoxy(84,y);
    cout<<"FECHA ING.";
    gotoxy(100,y);
    cout<<"EMAIL";
    gotoxy(140,y);
    cout<<"TELEFONO";
    gotoxy(160,y);
    cout<<"ESTADO";
}

void cartelListarClientes(int y){
    gotoxy(4,y);
    cout<<"DNI";
    gotoxy(19,y);
    cout<<"NOMBRE";
    gotoxy(40,y);
    cout<<"APELLIDO";
    gotoxy(58,y);
    cout<<"FECHA NAC.";
    gotoxy(80,y);
    cout<<"EMAIL";
    gotoxy(106,y);
    cout<<"TELEFONO";
    gotoxy(126,y);
    cout<<"DOMICILIO";
    gotoxy(165,y);
    cout<<"ESTADO";
}

#endif // FUNCIONESGLOBALES_H_INCLUDED
