#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void generarPedido(){
    Venta regVenta;
    int pos=0, tam;

    int *vecUnidades;
    tam=contarRegistros();  /// CONTAMOS LA CANTIDAD DE ARTICULOS QUE TENEMOS REGISTRADOS, Y CREAMOS UN VECTOR DEL MISMO TAMAÑO,
    vecUnidades=new int[tam]; /// DONDE CADA POSICION DEL VECTOR, SERA EL ID DEL ARTICULO-1
        if(vecUnidades==NULL){
            cout<<"ERROR DE ASIGNACION DE MEORIA";
            return;
        }
    while(regVenta.leerDeDisco(pos++)){
        vecUnidades[regVenta.getIDarticulo()-1]+=regVenta.getCantidadVendida(); ///LEEMOS EL ARCHIVO DE VENTAS, DONDE SACAMOS LAS UNIDADES VENDIDAS DE CADA ID DE ARTICULO.
                                                                                    ///Y LAS SUMAMOS EN EL VECTOR. POR AHORA LEVANTAMOS TODAS, PODRIAMOS PONERLE UN FILTRO POR FECHA.
    }

    Pedido regPedido;
    Articulo regArticulo;
    Proveedor regProveedor; ///EL ID DE PEDIDO ESTARIA BUENO QUE SEA AUTOMATICO Y QUE EL ARCHIVO SE BORRE CADA VEZ QUE GENERAMOS UN PEDIDO NUEVO
    for(int i=0; i<tam; i++){
        if(vecUnidades[i]>0){ ///SOLO SI HAY UNIDADES VENDIDAS, GENERA UN PEDIDO PARA ESE ARTICULO
            regArticulo.leerDeDisco(i); ///CON REGISTRO EN LA POS DE I, QUE LA MISMA QUE EL ID POR DEFECTO EN EL ARCHIVO.
            regPedido.setProducto(regArticulo.getDescripcion()); /// SETEAMOS LA DESCRIPCION DEL ARTICULO, DENTRO DEL REG PEDIDO.
            regPedido.setProvasolicitar(regArticulo.getProveedor()); ///LO MISMO CON EL NOMBRE DEL PROVEEDOR
            regPedido.setCantSolicitada(vecUnidades[i]); /// Y LAS UNIDADES VENDIDAS LAS SACAMOS DEL MISMO VECTOR.

            int pos=0;
            while(regProveedor.leerDeDisco(pos++)){ ///RECORREMOS EL ARCHIVO DE PROVEEDORES.
                if(strcmp(regProveedor.getNombreProv(),regArticulo.getProveedor())==0){ ///PARA COMPARAR EL NOMBRE CON EL QUE SACAMOS DEL ARCHIVO ARTICULOS.
                    regPedido.setEnvioMail(regProveedor.getMailProv()); ///Y PODER TRAERNOS EL MAIL DE CONTACTO.
                }

            }
        }
        regPedido.grabarEnDisco(); ///GUARDAMOS EL ARCHIVO PEDIDO
    }
    delete vecUnidades; ///DELETAMOS EL VECTOR QUE USAMOS PARA LAS UNIDADES.
}


void seccionReportes(){
    int opc;
    do{
        opc=menuReportes();
        switch(opc){
            case 12:
                system("cls");
                generarPedido();
                break;
            case 13:
                system("cls");

                break;
            case 14:
                system("cls");

                break;
            case 15:
                system("cls");

                break;
            case 16:
                system("cls");

                break;
            case 17:
                system("cls");

                break;
            case 18:
                system("cls");

                break;
            case 19:
                system("cls");

                break;
            case 20:
                system("cls");

                break;
        }
    }while(opc!=21);
}

#endif // MENUREPORTES_H_INCLUDED
