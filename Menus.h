#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#define ENTER 13
#define ARRIBA 72
#define ABAJO 80
#include "rlutil.h"

///-------------------------------------------------------///
///MENU
///-------------------------------------------------------///
///RECUADRO
void recuadro(int x, int y, int ancho, int alto){
const char *UI_BOTTOM_RIGHT = "\xD9"; // 217 - ┘
const char *UI_BOTTOM_LEFT = "\xC0"; // 192 - └
const char *UI_TOP_LEFT = "\xDA"; // 218 - ┌
const char *UI_TOP_RIGHT = "\xBF"; // 191 - ┐
const char *UI_CROSS = "\xC5"; // 197 - ┼
const char *UI_HORIZONTAL_LINE = "\xC4"; // 196 - ─
const char *UI_HORIZONTAL_LINE_TOP = "\xC1"; // 193 - ┴
const char *UI_HORIZONTAL_LINE_BOTTOM = "\xC2"; // 194 - ┬";
const char *UI_VERTICAL_LINE = "\xB3"; // 179 - │
const char *UI_VERTICAL_LINE_LEFT = "\xC3"; // 195 - ├
const char *UI_VERTICAL_LINE_RIGHT = "\xB4"; // 180 - ┤
const char *DOT="\x167";
    int i,j;
    ///Borrar antes de reimprimir nuevos dados
    for(i=x;i<=x+ancho;i++){
        for(j=y;j<=y+alto;j++){
            rlutil::locate(i,j);
            cout<<" ";
        }
    }
   ///linea horizontal
    for(i=x;i<=x+ancho;i++){
        rlutil::locate(i,y);
        cout<<UI_HORIZONTAL_LINE,
        rlutil::locate(i,y+alto);
        cout<<UI_HORIZONTAL_LINE;
    }
    ///linea vertical
    for(i=y;i<=y+alto;i++){
        rlutil::locate(x,i);
        cout<<UI_VERTICAL_LINE,
        rlutil::locate(x+ancho,i);
        cout<<UI_VERTICAL_LINE;
    }

    ///vertices
    rlutil::locate(x,y);
    cout<<UI_TOP_LEFT;
    rlutil::locate(x+ancho,y);
    cout<<UI_TOP_RIGHT ;
    rlutil::locate(x,y+alto);
    cout<<UI_BOTTOM_LEFT;
    rlutil::locate(x+ancho,y+alto);
    cout<<UI_BOTTOM_RIGHT ;
 }
///-------------------------------------------------------///
///MENU PRINCIPAL
int Menuprincipal(){
   int x=49,y=12;
   system("cls");
   recuadro(40,9,40,11);
   rlutil::locate(53,10);
   cout <<"MENU PRINCIPAL"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(50,12);   cout<<"MENU ARTICULO"<<endl;
   rlutil::locate(50,13);   cout<<"MENU CLIENTES"<<endl;
   rlutil::locate(50,14);   cout<<"MENU VENTAS"<<endl;
   rlutil::locate(50,15);   cout<<"REPORTES"<<endl;
   rlutil::locate(50,16);   cout<<"CONFIGURACION"<<endl;
   rlutil::locate(50,17);   cout<<"SALIR"<<endl;
   rlutil::locate(47,18);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 17) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU ARTICULOS
///-------------------------------------------------------///
int Menuarticulos(){
   int x=49,y=12;
   system("cls");
   recuadro(40,9,40,11);
   rlutil::locate(53,10);
   cout <<"MENU ARTICULO"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(50,12);   cout<<"AGREGAR ARTICULO"<<endl;
   rlutil::locate(50,13);   cout<<"LISTAR ARTICULO POR ID"<<endl;
   rlutil::locate(50,14);   cout<<"LISTAR TODOS LOS ARTICULOS"<<endl;
   rlutil::locate(50,15);   cout<<"MODIFICAR PRECIO ARTICULO"<<endl;
   rlutil::locate(50,16);   cout<<"ELIMINAR ARTICULO"<<endl;
   rlutil::locate(50,17);   cout<<"ALTA ARTICULO"<<endl;
   rlutil::locate(50,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(47,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarArticulos(){
    int x=49,y=12;
   system("cls");
   recuadro(40,9,40,11);
   rlutil::locate(53,10);
   cout <<"LISTAR ARTICULOS"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(50,12);   cout<<"POR DEFECTO"<<endl;
   rlutil::locate(50,13);   cout<<"ORDEN ALFABETICO"<<endl;
   rlutil::locate(50,14);   cout<<"POR ID"<<endl;
   rlutil::locate(50,15);   cout<<"POR PRECIO UNITARIO"<<endl;
   rlutil::locate(50,16);   cout<<"POR STOCK"<<endl;
   rlutil::locate(50,17);   cout<<"DISPONIBLES"<<endl;
   rlutil::locate(50,18);   cout<<"NO DISPONIBLES"<<endl;
   rlutil::locate(50,19);   cout<<"VOLVER"<<endl;
   rlutil::locate(47,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

///-------------------------------------------------------///
///MENU CLIENTES
///-------------------------------------------------------///
int Menucliente(){
   int x=49,y=12;
   system("cls");
   recuadro(40,9,40,11);
   rlutil::locate(53,10);
   cout <<"MENU CLIENTES"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(50,12);   cout<<"AGREGAR CLIENTE"<<endl;
   rlutil::locate(50,13);   cout<<"LISTAR CLIENTE POR DNI"<<endl;
   rlutil::locate(50,14);   cout<<"LISTAR TODOS LOS CLIENTES"<<endl;
   rlutil::locate(50,15);   cout<<"MODIFICAR EMAIL"<<endl;
   rlutil::locate(50,16);   cout<<"ELIMINAR CLIENTE"<<endl;
   rlutil::locate(50,17);   cout<<"ALTA CLIENTE"<<endl;
   rlutil::locate(50,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(47,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU VENTAS
///-------------------------------------------------------///
int Menuventas(){
    int x=47,y=12;
   system("cls");
   recuadro(40,9,41,12);
   rlutil::locate(53,10);
   cout <<"MENU VENTAS"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(48,12);   cout<<"AGREGAR VENTA"<<endl;
   rlutil::locate(48,13);   cout<<"LISTAR VENTA POR NUMERO DE VENTA"<<endl;
   rlutil::locate(48,14);   cout<<"LISTAR TODAS LAS VENTAS"<<endl;
   rlutil::locate(48,15);   cout<<"ELIMINAR VENTA"<<endl;
   rlutil::locate(48,16);   cout<<"ALTA DE VENTA"<<endl;
   rlutil::locate(48,17);   cout<<"DEVOLVER VENTA"<<endl;
   rlutil::locate(48,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(47,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU CONFIGURACION
///-------------------------------------------------------///
int Menuconfiguracion(){
   int x=49,y=12;
   system("cls");
   recuadro(40,9,57,12);
   rlutil::locate(53,10);
   cout <<"CONFIGURACION"<<endl;
   rlutil::locate(47,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(50,12);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO ARTICULOS"<<endl;
   rlutil::locate(50,13);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO CLIENTES"<<endl;
   rlutil::locate(50,14);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO VENTAS"<<endl;
   rlutil::locate(50,15);   cout<<"RESTAURAR ARCHIVO ARTICULOS"<<endl;
   rlutil::locate(50,16);   cout<<"RESTAURAR ARCHIVO CLIENTES"<<endl;
   rlutil::locate(50,17);   cout<<"RESTAURAR ARCHIVO VENTAS"<<endl;
   rlutil::locate(50,18);   cout<<"RESTABLECER DATOS DE INICIO"<<endl;
   rlutil::locate(50,19);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(47,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
/*
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}*/
#endif // MENUS_H_INCLUDED
