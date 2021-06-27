#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <windows.h>
using namespace std;



///-------------------------------------------------------///
///ARCHVOS ARTICULO///
const char ARCHIVOARTICULO[]="ArchivoArticulo.dat";
const char ARCHIVOARTICULO_BKP[]="Archivoarticulo_bkp.dat";
const char ARCHIVOINICIAL[]="Archivoinicial.dat";
///-------------------------------------------------------///
///ARCHIVOS CLIENTE
const char ARCHIVOCLIENTE[]="ArchivoCliente.dat";
const char ARCHIVOCLIENTE_BKP[]="Archivocliente_bkp.dat";
const char ARCHIVOINICIALCLIENTE[]="Archivoclienteinicial.dat";
///-------------------------------------------------------///
///ARCHVOS VENDEDOR///
const char ARCHIVOVENDEDOR[] = "ArchivoVendedor.dat";
const char ARCHIVOVENDEDOR_BKP[] = "ArchivoVendedor_bkp.dat";
const char ARCHIVOINICIALVENDEDOR[] = "ArchivoVendedorinicial.dat";
///-------------------------------------------------------///
///ARCHIVOS VENTA///
const char ARCHIVOVENTAS[]="Archivoventa.dat";
const char ARCHIVOVENTAS_BKP[]="Archivoventa_bkp.dat";
const char ARCHIVOVENTASINICIAL[]="Archivoventainicial.dat";
///-------------------------------------------------------///
///ARCHIVOS PROVEEDOR///
const char ARCHIVOPROVEEDOR[]="ArchivoProveedor.dat";
const char ARCHIVOPROVEEDOR_BKP[]="ArchivoProveedor_bkp.dat";
const char ARCHIVOPROVEEDORINICIAL[]="ArchivoProveedorinicial.dat";
///-------------------------------------------------------///
///ARCHIVOS PEDIDO///
const char ARCHIVOPEDIDO[]="ArchivoPedido.dat";
///-------------------------------------------------------///

#include "rlutil.h"
#include "FuncionesGlobales.h"
#include "clsarticulo.h"
#include "clsdirrecion.h"
#include "clsproveedor.h"
#include "clsfecha.h"
#include "clspersona.h"
#include "clsvendedor.h"
#include "herramientas.h"
#include "Menus.h"
#include "clscadena.h"
#include "clscliente.h"
#include "clsventa.h"
#include "MenuArticulos.h"
#include "MenuClientes.h"
#include "Menuventa.h"
#include "MenuProveedores.h"
#include "MenuConfiguracion.h"
#include "menuVendedor.h"




int main(){
    full_screen(1500, 1000);

    /*char tecla = _getch();
    int otraTecla = _getch();
    cout << tecla << "        " << otraTecla << endl;
    system("pause");
    return 0;*/
    system("TITLE GestArk - gestion empresarial");
    int opc;
    while(true){
        opc=Menuprincipal();
        switch(opc){
        case 12:
            seccionArticulos();
            break;
        case 13:
            seccionClientes();
            break;
        case 14:
            seccionVenta();
            break;
        case 15:
            seccionVendedor();
            break;
        case 16:
            seccionProveedores();
            break;
        case 17:
            seccionConfiguracion();
            break;
        case 18:
            seccionConfiguracion();
            break;
        case 19:
            rlutil::locate(1,25);
            return 0;
            break;
        }
    }
    return 0;
}
