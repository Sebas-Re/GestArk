#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
///PEDIDO
void imprimiPedido(){
    Pedido obj;
    int pos=0;

    while(obj.leerDeDisco(pos++)){
        obj.mostrar();
    }
}

int buscarPedido(int id){
    Pedido reg;
    int pos=0;
    while((reg.leerDeDisco(pos))){
        if(reg.getnPedido()==id){
            return pos;
        }
        pos++;
        }
    return -1;
}

bool modificarMailPedido(Pedido &aux, int pos){
    char mailPedido[25];
    cout<<"INGRESE NUEVO MAIL DE PORVEEDOR: ";
    cargarCadena(mailPedido,29);
    aux.setEnvioMail(mailPedido);
    bool modifico=aux.modificarEnDisco(aux,pos);
    return modifico;
}

bool modificarCantPedida(Pedido &aux, int pos){
    int cantaPedir;
    cout<<"INGRESE NUEVA CANTIDAD A PEDIR: ";
    cin>>cantaPedir;
    aux.setCantSolicitada(cantaPedir);
    bool modifico=aux.modificarEnDisco(aux,pos);
    return modifico;
}

void modificarPedido(){
    Pedido reg;
    int id,opc;
    cout<<"INGRESE EL CODIGO DEl PEDIDO: ";
    cin>>id;
    int pos=buscarPedido(id);
    if(pos<0){cout<<"NO EXISTE PEDIDO PARA EL NUMERO INGRESADO"<<endl;}
    reg.leerDeDisco(pos);
    reg.mostrar();
    opc=menumodificarPedido();
    switch(opc){
    case 8:
        system("cls");
        if(modificarMailPedido(reg,pos)){cout<<"SE MODIFICO MAIL PROVEEDOR DE MANERA EXISOTA"<<endl;}
        else{cout<<"NO SE PUDO MODIFICAR MAIL"<<endl;}
        system("pause");
        break;
    case 9:
        system("cls");
        if(modificarCantPedida(reg,pos)){cout<<"SE MODIFICO LA CANTIDAD A PEDIR DE MANERA EXITOSA"<<endl;}
        else {cout<<"NO SE PUDO MODIFICAR CANTIDAD A PEDIR"<<endl;}
        system("pause");
        break;
    }
}
///REPORTES ARTICULO
///-------------------------------------------------------///

int maximoVector(int *v, int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

void reportePorArticulo(){
    Venta reg;
    int id,pos=0,canttotal=0,linea=0;
    rlutil::locate(1,30);
    cout << "ARTICULOS DISPONIBLES: ";
    listarArticulosDisponibles(31);
    rlutil::locate(1,4);
    cout<<"INGRESE ID DE ARTICULO: ";
    cin>>id;
    BorrarArea(1,29);
    system("cls");
    cartelListarVentas(1);
    while(reg.leerDeDisco(pos++)){
        if(reg.getIDarticulo()==id){reg.mostrar(linea+3);
           canttotal+=reg.getCantidadVendida();
           linea++;
        }

    }
    if(linea==0){
        rlutil::locate(1,3);
        cout<<"NO HAY REGISTROS PARA ESTE ARTICULO"<<endl;}
    else{
    cout<<"-----------------------"<<endl;
    cout<<"CANTIDAD TOTAL VENDIDA: "<<canttotal<<endl;
    cout<<"-----------------------"<<endl;}
    system("pause");
}

void reportePorFechaArticulo(){
    Venta reg;
    Fecha fecha1,fecha2;
    int id,pos=0,canttotal=0,linea=0;
    rlutil::locate(1,30);
    cout << "ARTICULOS DISPONIBLES: ";
    listarArticulosDisponibles(31);
    rlutil::locate(1,4);
    cout<<"INGRESE ID DE ARTICULO: ";
    cin>>id;
    system("cls");
    cout<<"INGRESE RANGO O FECHA DE CONSULTA: "<<endl;
    cout<<"PRIMER PARAMETRO: "<<endl;
    fecha1.cargar();
    cout<<"SEGUNDO PARAMETRO: "<<endl;
    fecha2.cargar();
    system("cls");
    cartelListarVentas(1);
    while(reg.leerDeDisco(pos++)){
        if(reg.getIDarticulo()==id && (reg.getFe()>fecha1) && (!(reg.getFe()>fecha2))){reg.mostrar(linea+3);
        linea++;
        }
    }
    system("pause");
}

void articuloMasVendido(){
    Venta regv;
    int cantArticulos=contarRegistros();
    int *cantvendida,pos=0;
    cantvendida= new int[cantArticulos];
    for(int i=0;i<cantArticulos;i++){
        cantvendida[i]=0;
    }
    while(regv.leerDeDisco(pos++)){
            cantvendida[regv.getIDarticulo()-1]+=regv.getCantidadVendida();
        }
    cout<<"CODIGO ARTICULO MAS VENDIDO :"<<maximoVector(cantvendida,cantArticulos)+1<<endl;
    BuscarArticuloporId(maximoVector(cantvendida,cantArticulos)+1);
    cout<<"CANTIDAD VENDIDA: "<<cantvendida[maximoVector(cantvendida,cantArticulos)]<<endl;
    cout<<"------------------------"<<endl;

    system("pause");
}

void articuloMasVendidoxFecha(){
    Venta reg;
    Fecha fecha1,fecha2;
    int cantArticulos=contarRegistros();
    int *cantvendida,pos=0;
    cantvendida= new int[cantArticulos];
    for(int i=0;i<cantArticulos;i++){
        cantvendida[i]=0;
    }
    cout<<"INGRESE RANGO O FECHA DE CONSULTA: "<<endl;
    cout<<"PRIMER PARAMETRO: "<<endl;
    fecha1.cargar();
    cout<<"SEGUNDO PARAMETRO: "<<endl;
    fecha2.cargar();
    system("cls");
    while(reg.leerDeDisco(pos++)){
            if((reg.getFe()>fecha1) && (!(reg.getFe()>fecha2)))
            cantvendida[reg.getIDarticulo()-1]+=reg.getCantidadVendida();
        }
//    for(int i=0;i<cantArticulos;i++){ dejo esto para ver como se carga el vector (sacar antes de entregar)
//        cout<<cantvendida[i]<<endl;
//    }
    cout<<"CODIGO ARTICULO MAS VENDIDO :"<<maximoVector(cantvendida,cantArticulos)+1<<endl;
    BuscarArticuloporId(maximoVector(cantvendida,cantArticulos)+1);
    cout<<"CANTIDAD VENDIDA: "<<cantvendida[maximoVector(cantvendida,cantArticulos)]<<endl;
    cout<<"------------------------"<<endl;
    system("pause");
}

void reportesArticulos(){
    int opc;
    do{
        opc=menuReporteArticulos();
            switch(opc){
                case 12:
                    system("cls");
                    reportePorArticulo();
                    break;
                case 13:
                    system("cls");
                    reportePorFechaArticulo();
                    break;
                case 14:
                    system("cls");
                    articuloMasVendido();
                    break;
                case 15:
                    system("cls");
                    articuloMasVendidoxFecha();
                    break;
            }
        }while(opc!=16);
}
///-------------------------------------------------------///
///REPORTES VENDEDOR
///-------------------------------------------------------///

void reportePorVendedor(){
    Venta reg;
    int id,pos=0,canttotal=0,linea=0;
    rlutil::locate(1,30);
    cout << "VENDEDORES DISPONIBLES: ";
    listarVendedores(31);
    rlutil::locate(1,1);
    cout << "INGRESE ID DEL VENDEDOR: ";
    cin >> id;
    BorrarArea(1,29);
    system("cls");
    cartelListarVentas(linea);
    while(reg.leerDeDisco(pos++)){
        if(reg.getIDvendedor()==id){reg.mostrar(linea+3);
           canttotal+=reg.getCantidadVendida();
           linea++;
        }

    }
    if(linea==0){
        rlutil::locate(1,3);
        cout<<"NO HAY REGISTROS PARA ESTE VENDEDOR"<<endl;}
    else{
    cout<<"-----------------------"<<endl;
    cout<<endl;
    cout<<"CANTIDAD TOTAL VENDIDA: "<<canttotal<<endl;
    cout<<"-----------------------"<<endl;
    }
    system("pause");
}

void mejorEnCantidad(){
    Venta reg;
    Fecha fecha1,fecha2;
    int contarVendedores=contarRegistrosVendedores();
    int *cantVendedores,pos=0;
    cantVendedores= new int[contarVendedores];
    for(int i=0;i<contarVendedores;i++){
        cantVendedores[i]=0;
    }
    cout<<"INGRESE RANGO O FECHA DE CONSULTA: "<<endl;
    cout<<"PRIMER PARAMETRO: "<<endl;
    fecha1.cargar();
    cout<<"SEGUNDO PARAMETRO: "<<endl;
    fecha2.cargar();
    system("cls");
    while(reg.leerDeDisco(pos++)){
            if((reg.getFe()>fecha1) && (!(reg.getFe()>fecha2)))
            cantVendedores[reg.getIDvendedor()-1]+=reg.getCantidadVendida();
        }
   for(int i=0;i<contarVendedores;i++){ //dejo esto para ver como se carga el vector (sacar antes de entregar)
        cout<<cantVendedores[i]<<endl;
    }
    cout<<"NUMERO DE  VENDEDOR CON MAYOR CANTIDAD DE VENTAS :"<<maximoVector(cantVendedores,contarVendedores)+1<<endl;
    cout<<"CANTIDAD VENDIDA: "<<cantVendedores[maximoVector(cantVendedores,contarVendedores)]<<endl;
    cout<<"------------------------"<<endl;
    system("pause");
}

void mejorEnImporte(){
    Venta reg;
    Fecha fecha1,fecha2;
    int contarVendedores=contarRegistrosVendedores();
    int *cantVendedores,pos=0;
    cantVendedores= new int[contarVendedores];
    for(int i=0;i<contarVendedores;i++){
        cantVendedores[i]=0;
    }
    cout<<"INGRESE RANGO O FECHA DE CONSULTA: "<<endl;
    cout<<"PRIMER PARAMETRO: "<<endl;
    fecha1.cargar();
    cout<<"SEGUNDO PARAMETRO: "<<endl;
    fecha2.cargar();
    system("cls");
    while(reg.leerDeDisco(pos++)){
            if((reg.getFe()>fecha1) && (!(reg.getFe()>fecha2)))
            cantVendedores[reg.getIDvendedor()-1]+=reg.getImporte();
        }
    for(int i=0;i<contarVendedores;i++){// dejo esto para ver como se carga el vector (sacar antes de entregar)
        cout<<cantVendedores[i]<<endl;
    }
    cout<<"NUMERO DE  VENDEDOR CON MAYOR RECAUDACION  :"<<maximoVector(cantVendedores,contarVendedores)+1<<endl;
    BuscarVendedorNumero(maximoVector(cantVendedores,contarVendedores));
    cout<<"RECAUDADO: "<<cantVendedores[maximoVector(cantVendedores,contarVendedores)]<<endl;
    cout<<"------------------------"<<endl;
    system("pause");
}

void mejorVendedor(){
    int opc;
    cout<<"FILTRAR POR: "<<endl;
    opc=menuMejorVendedor();
    switch(opc){
    case 8:
        system("cls");
        mejorEnCantidad();
        break;
    case 9:
        system("cls");
        mejorEnImporte();
        break;
    }
}


void reporteVendedores(){
    int opc;
    do{
        opc=menuReportesVendedores();
        switch(opc){
        case 12:
            system("cls");
            reportePorVendedor();
            break;
        case 13:
            system("cls");
            mejorVendedor();
            break;
        }
    }while(opc!=17);
}
///-------------------------------------------------------///
void seccionReportes(){

    int opc;
    do{
        opc=menuReportes();
        switch(opc){
            case 12:
                system("cls");
                imprimiPedido();
                system("pause");
                break;
            case 13:
                system("cls");
                modificarPedido();
                break;
            case 14:
                system("cls");
                reportesArticulos();
                break;
            case 15:
                system("cls");
                reporteVendedores();
                break;
            case 16:
                system("cls");

                break;
        }
    }while(opc!=16);
}

#endif // MENUREPORTES_H_INCLUDED
