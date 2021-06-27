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
    cout<<"INVETARIO: ";
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
    gotoxy(66,y);
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
    gotoxy(44,y);
    cout<<"APELLIDO";
    gotoxy(69,y);
    cout<<"FECHA NAC.";
    gotoxy(92,y);
    cout<<"EMAIL";
    gotoxy(116,y);
    cout<<"TELEFONO";
    gotoxy(140,y);
    cout<<"DOMICILIO";
    gotoxy(172,y);
    cout<<"ESTADO";
}

void fullScreen(int ancho, int alto){
    HWND hwnd = GetForegroundWindow();
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, ancho, alto, 0);
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
