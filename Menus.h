#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#define ENTER 13
#define ARRIBA 72
#define ABAJO 80
#define ESC 27
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
 //  FILE *pProv;
   int x=74,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU PRINCIPAL"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
/*
   pProv=fopen(ARCHIVOPROVEEDOR, "rb");
    if(!pProv==NULL){
    rlutil::locate(50,12);   cout<<"MENU ARTICULO"<<endl;
    rlutil::locate(50,14);   cout<<"MENU VENTAS"<<endl;
    }
    fclose(pProv);
*/

    rlutil::locate(75,12);   cout<<"MENU ARTICULO"<<endl;
    rlutil::locate(75,14);   cout<<"MENU VENTAS"<<endl;
   rlutil::locate(75,13);   cout<<"MENU CLIENTES"<<endl;
   rlutil::locate(75,15);   cout<<"MENU VENDEDORES"<<endl;
   rlutil::locate(75,16);   cout<<"MENU PROVEEDORES"<<endl;
   rlutil::locate(75,17);   cout<<"REPORTES"<<endl;
   rlutil::locate(75,18);   cout<<"CONFIGURACION"<<endl;
   rlutil::locate(75,19);   cout<<"SALIR"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU ARTICULOS
///-------------------------------------------------------///
int Menuarticulos(){
   int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU ARTICULO"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"AGREGAR ARTICULO"<<endl;
   rlutil::locate(73,13);   cout<<"LISTAR ARTICULO POR ID"<<endl;
   rlutil::locate(73,14);   cout<<"LISTAR TODOS LOS ARTICULOS"<<endl;
   rlutil::locate(73,15);   cout<<"MODIFICAR PRECIO ARTICULO"<<endl;
   rlutil::locate(73,16);   cout<<"MODIFICAR STOCK ARTICULO"<<endl;
   rlutil::locate(73,17);   cout<<"ELIMINAR ARTICULO"<<endl;
   rlutil::locate(73,18);   cout<<"ALTA ARTICULO"<<endl;
   rlutil::locate(73,19);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarArticulos(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR ARTICULOS"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR DEFECTO"<<endl;
   rlutil::locate(73,13);   cout<<"ORDEN ALFABETICO"<<endl;
   rlutil::locate(73,14);   cout<<"POR ID"<<endl;
   rlutil::locate(73,15);   cout<<"POR PRECIO UNITARIO"<<endl;
   rlutil::locate(73,16);   cout<<"POR STOCK"<<endl;
   rlutil::locate(73,17);   cout<<"DISPONIBLES"<<endl;
   rlutil::locate(73,18);   cout<<"NO DISPONIBLES"<<endl;
   rlutil::locate(73,19);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU CLIENTES
///-------------------------------------------------------///
int Menucliente(){
   int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU CLIENTES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"AGREGAR CLIENTE"<<endl;
   rlutil::locate(73,13);   cout<<"LISTAR CLIENTE POR DNI"<<endl;
   rlutil::locate(73,14);   cout<<"LISTAR CLIENTES"<<endl;
   rlutil::locate(73,15);   cout<<"MODIFICAR EMAIL"<<endl;
   rlutil::locate(73,16);   cout<<"BAJA CLIENTE"<<endl;
   rlutil::locate(73,17);   cout<<"RECUPERAR CLIENTE"<<endl;
   rlutil::locate(73,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 18;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarClientes(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR CLIENTES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR DEFECTO (SOLO DISPONIBLES)"<<endl;
   rlutil::locate(73,13);   cout<<"POR APELLIDO"<<endl;
   rlutil::locate(73,14);   cout<<">> ASCENDENTE(AZ-TODOS)"<<endl;
   rlutil::locate(73,15);   cout<<">> DESENDENTE(ZA-TODOS)"<<endl;
   rlutil::locate(73,16);   cout<<"POR FECHA DE INGRESO"<<endl;
   rlutil::locate(73,17);   cout<<">> ASCENDENTE"<<endl;
   rlutil::locate(73,18);   cout<<">> DESCENDENTE"<<endl;
   rlutil::locate(73,19);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

///-------------------------------------------------------///
///MENU VENTAS
///-------------------------------------------------------///
int Menuventas(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU VENTAS"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"AGREGAR VENTA"<<endl;
   rlutil::locate(73,13);   cout<<"LISTAR VENTA POR ID"<<endl;
   rlutil::locate(73,14);   cout<<"LISTAR TODAS LAS VENTAS"<<endl;
   rlutil::locate(73,15);   cout<<"ELIMINAR VENTA"<<endl;
   rlutil::locate(73,16);   cout<<"ALTA DE VENTA"<<endl;
   rlutil::locate(73,17);   cout<<"DEVOLVER VENTA"<<endl;
   rlutil::locate(73,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 18;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarVentas(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR VENTAS"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR DEFECTO"<<endl;
   rlutil::locate(73,13);   cout<<"POR ID"<<endl;
   rlutil::locate(73,14);   cout<<"POR IMPORTE"<<endl;
   rlutil::locate(73,15);   cout<<"POR CANTIDAD VENDIDA"<<endl;
   rlutil::locate(73,16);   cout<<"DISPONIBLES"<<endl;
   rlutil::locate(73,17);   cout<<"NO DISPONIBLES"<<endl;
   rlutil::locate(73,18);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 18;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU CONFIGURACION
///-------------------------------------------------------///
int Menuconfiguracion(){
   int x=64,y=12;
   system("cls");
   recuadro(60,9,57,12);
   rlutil::locate(83,10);
   cout <<"CONFIGURACION"<<endl;
   rlutil::locate(75,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(65,12);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO ARTICULOS"<<endl;
   rlutil::locate(65,13);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO CLIENTES"<<endl;
   rlutil::locate(65,14);   cout<<"HACER COPIA DE SEGURIDAD DEL ARCHIVO VENTAS"<<endl;
   rlutil::locate(65,15);   cout<<"RESTAURAR ARCHIVO ARTICULOS"<<endl;
   rlutil::locate(65,16);   cout<<"RESTAURAR ARCHIVO CLIENTES"<<endl;
   rlutil::locate(65,17);   cout<<"RESTAURAR ARCHIVO VENTAS"<<endl;
   rlutil::locate(65,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(75,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}
///-------------------------------------------------------///
///MENU PROVEEDORES
///-------------------------------------------------------///
int MenuProveedores(){
   int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU PROVEEDOR"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"ALTA PROVEEDOR"<<endl;
   rlutil::locate(73,13);   cout<<"LISTAR PROVEEDOR POR CODIGO"<<endl;
   rlutil::locate(73,14);   cout<<"LISTAR PROVEEDORES"<<endl;
   rlutil::locate(73,15);   cout<<"MODIFICAR DATOS PROVEDOR"<<endl;
   rlutil::locate(73,16);   cout<<"ELIMINAR PROVEEDOR"<<endl;
   rlutil::locate(73,17);   cout<<"RECUPERAR PROVEEDOR"<<endl;
   rlutil::locate(73,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 18;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarProveedores(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR PROVEEDORES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR DEFECTO"<<endl;
   rlutil::locate(73,13);   cout<<"ORDEN ALFABETICO"<<endl;
   rlutil::locate(73,14);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 14;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 14) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuModificarProveedores(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR PROVEEDORES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"MAIL"<<endl;
   rlutil::locate(73,13);   cout<<"DIRECCION"<<endl;
   rlutil::locate(73,14);   cout<<"TELEFONO"<<endl;
   rlutil::locate(73,15);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,20);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 15;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 15) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

///-------------------------------------------------------///
///MENU VENDEDOR
///-------------------------------------------------------///
int menuVendedor(){
   int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU VENDEDORES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"AGREGAR VENDEDOR"<<endl;
   rlutil::locate(73,13);   cout<<"LISTAR VENDEDOR POR DNI"<<endl;
   rlutil::locate(73,14);   cout<<"LISTAR VENDEDORES"<<endl;
   rlutil::locate(73,15);   cout<<"MODIFICAR CATEGORIA"<<endl;
   rlutil::locate(73,16);   cout<<"BAJA DE VENDEDOR"<<endl;
   rlutil::locate(73,17);   cout<<"RECUPERAR DE VENDEDOR"<<endl;
   rlutil::locate(73,18);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 18;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 18) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int MenuListarVendedores(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"LISTAR VENDEDORES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR ID (SOLO DISPONIBLES)"<<endl;
   rlutil::locate(73,13);   cout<<"POR APELLIDO"<<endl;
   rlutil::locate(73,14);   cout<<">> ASCENDENTE(AZ-TODOS)"<<endl;
   rlutil::locate(73,15);   cout<<">> DESENDENTE(ZA-TODOS)"<<endl;
   rlutil::locate(73,16);   cout<<"POR FECHA DE INGRESO"<<endl;
   rlutil::locate(73,17);   cout<<">> ASCENDENTE"<<endl;
   rlutil::locate(73,18);   cout<<">> DESCENDENTE"<<endl;
   rlutil::locate(73,19);   cout<<"VOLVER"<<endl;
   rlutil::locate(70,25);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 19;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 19) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

///-------------------------------------------------------///
///MENU REPORTES
///-------------------------------------------------------///
int menuReportes(){
   int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"MENU REPORTES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"IMPRIMIR PEDIDO"<<endl;
   rlutil::locate(73,13);   cout<<"MODIFICAR PEDIDO AUTOMATICO"<<endl;
   rlutil::locate(73,14);   cout<<"REPORTE ARTICULOS"<<endl;
   rlutil::locate(73,15);   cout<<"REPORTE VENDEDORES"<<endl;
   rlutil::locate(73,16);   cout<<"REPORTE CLIENTES"<<endl;
   rlutil::locate(73,17);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 17;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 17) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int menuReporteArticulos(){
    int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"REPORTE ARTICULOS"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"ID ARTICULO"<<endl;
   rlutil::locate(73,13);   cout<<"POR FECHA"<<endl;
   rlutil::locate(73,14);   cout<<"MAS VENDIDO"<<endl;
   rlutil::locate(73,15);   cout<<"MAS VENDIDO POR FECHA"<<endl;
   rlutil::locate(73,16);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,17);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 16;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 16) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int menumodificarPedido(){
    int x=1,y=8;
       rlutil::locate(2,8);   cout<<"MODIFICAR MAIL"<<endl;
       rlutil::locate(2,9);   cout<<"MODIFICAR CANTIDAD A PEDIR"<<endl;
       rlutil::locate(x,y);printf("*");
       bool elegir=false;
       while(!elegir){
        if(_kbhit()){
            rlutil::locate(x,y);printf(" ");
           char tecla = _getch();
            if (tecla==ENTER){elegir= true; return y;}
            if (tecla==ARRIBA&& y >8) rlutil::locate (x,y--);
            if(tecla==ABAJO && y <9) rlutil::locate(x,y++);
            rlutil::locate(x,y);printf("*");}
       }
}

int menuReportesVendedores(){
int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"REPORTE VENDEDORES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR VENDEDOR"<<endl;
   rlutil::locate(73,13);   cout<<"MEJORES VENDEDORES/AS"<<endl;
   rlutil::locate(73,14);   cout<<"POR FECHA O RANGO"<<endl;
   rlutil::locate(73,17);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 17;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 17) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int menuMejorVendedor(){
    int x=1,y=8;
       rlutil::locate(2,8);   cout<<"MAYOR CANTIDAD VENDIDA"<<endl;
       rlutil::locate(2,9);   cout<<"MAYOR IMPORTE RECAUDADO"<<endl;
       rlutil::locate(x,y);printf("*");
       bool elegir=false;
       while(!elegir){
        if(_kbhit()){
            rlutil::locate(x,y);printf(" ");
           char tecla = _getch();
            if (tecla==ENTER){elegir= true; return y;}
            if (tecla==ARRIBA&& y >8) rlutil::locate (x,y--);
            if(tecla==ABAJO && y <9) rlutil::locate(x,y++);
            rlutil::locate(x,y);printf("*");}
       }
}

int menuReportesClientes(){
int x=72,y=12;
   system("cls");
   recuadro(63,9,40,14);
   rlutil::locate(75,10);
   cout <<"REPORTE CLIENTES"<<endl;
   rlutil::locate(70,11);
   cout <<"---------------------------"<<endl;
   rlutil::locate(73,12);   cout<<"POR CLIENTE"<<endl;
   rlutil::locate(73,13);   cout<<"MEJORES CLIENTES/AS"<<endl;
   rlutil::locate(73,14);   cout<<"POR FECHA O RANGO"<<endl;
   rlutil::locate(73,17);   cout<<"VOLVER AL MENU PRINCIPAL"<<endl;
   rlutil::locate(70,19);
   cout <<"---------------------------"<<endl;
   rlutil::locate(x,y);printf("*");
   bool elegir=false;
   while(!elegir){
    if(_kbhit()){
        rlutil::locate(x,y);printf(" ");
       char tecla = _getch();
        if (tecla==ENTER){elegir= true; return y;}
        if (tecla==ESC){elegir= true; return 17;}
        if (tecla==ARRIBA&& y >12) rlutil::locate (x,y--);
        if(tecla==ABAJO && y < 17) rlutil::locate(x,y++);
        rlutil::locate(x,y);printf("*");}
   }
}

int menuMejorCliente(){
    int x=1,y=8;
       rlutil::locate(2,8);   cout<<"MAYOR CANTIDAD VENDIDA"<<endl;
       rlutil::locate(2,9);   cout<<"MAYOR IMPORTE RECAUDADO"<<endl;
       rlutil::locate(x,y);printf("*");
       bool elegir=false;
       while(!elegir){
        if(_kbhit()){
            rlutil::locate(x,y);printf(" ");
           char tecla = _getch();
            if (tecla==ENTER){elegir= true; return y;}
            if (tecla==ARRIBA&& y >8) rlutil::locate (x,y--);
            if(tecla==ABAJO && y <9) rlutil::locate(x,y++);
            rlutil::locate(x,y);printf("*");}
       }
}



#endif // MENUS_H_INCLUDED
