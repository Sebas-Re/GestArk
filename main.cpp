#include <iostream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;
///Nueva prueba de GitKraken
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

#include "FuncionesGlobales.h"
#include "clsarticulo.h"
#include "herramientas.h"
#include "Menus.h"
#include "clscadena.h"
#include "clsdirrecion.h"
#include "clsfecha.h"
#include "clspersona.h"
#include "clscliente.h"
#include "clsventa.h"
#include "clsvendedor.h"
#include "MenuArticulos.h"
#include "MenuClientes.h"
#include "Menuventa.h"
#include "MenuConfiguracion.h"

int main(){

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
        case 16:
            seccionConfiguracion();
        case 17:
            rlutil::locate(1,25);
            return 0;
            break;
        }
    }
    return 0;
}
