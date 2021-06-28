#ifndef MENUVENTA_H_INCLUDED
#define MENUVENTA_H_INCLUDED
///MENU VENTAS
///-------------------------------------------------------///
bool verificarstock(int cantidad, int idarticulo){
    Articulo art;
    int pos;
    pos=buscarArticulo(idarticulo);
    if(pos<0){return false;}
    art.leerDeDisco(pos);
    if(cantidad<1 || cantidad>art.getStock()){
        cout<<"SIN STOCK.LA CANTIDAD VENDIDA DEBE SER MAYOR A CERO Y MENOR  A: "<<art.getStock()<<endl;
        return false;
    }
    else{return true;}
}

bool controlstock(int cantidad, int idarticulo, bool mod){
     Articulo art;
     int pos=0,stockoriginal=0;
     pos=buscarArticulo(idarticulo);
     art.leerDeDisco(pos);
     stockoriginal=art.getStock();
     if(mod==true){
     art.setStock(stockoriginal-cantidad);}
     else{art.setStock(stockoriginal+cantidad);}
     bool modifico=art.modificarEnDisco(art,pos);

     return modifico;
}

float calcularimporte(int cantidad,int idarticulo){
     Articulo art;
     int pos=0;
     float pu=0;
     int importe=0;
     pos=buscarArticulo(idarticulo);
     art.leerDeDisco(pos);
     pu=art.getPu();
     importe=cantidad*pu;
     return importe;
}

int buscarVenta(int Nventa){//recibe "id" del registro y devuelve la posicion donde se encuentra el registro
    Venta ven;
    int pos=0;
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb");
    if(pVenta==NULL){return -1;}
    while((ven.leerDeDisco(pos))==1){
        if(ven.getNventa()==Nventa){
            fclose(pVenta);
            return pos;
        }
        pos++;
    }
    fclose(pVenta);
    return -2;
}

void AsignacionNumeroVenta (Venta &ven){

    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb");
    fseek(pVenta,-sizeof (Venta),2);
    fread(&ven,sizeof ven,1,pVenta);
    ven.setNventa(ven.getNventa()+1);
    fclose(pVenta);

}

bool agregarVenta(){
    int r,contador=0;
    do{
    Venta ven;
    cout<<"REGISTAR VENTA"<<endl;

            AsignacionNumeroVenta(ven);
            cout<<"ESTE ES SU NUMERO DE VENTA: "<<ven.getNventa()<<endl;
            cout<<"COMPLETE LOS SIGUIENTES CAMPOS: "<<endl;

            ven.cargar();
            if(!ven.grabarEnDisco()){
            cout << "Error al guardar el archivo.";
            system("pause");
            return contador;
        }
        contador++;
        cout<<"DESEA AGREGAR OTRO ARTICULO (y/n)?"<<endl;
        r=getch();
        system("cls");
    }while(r==121||r==89);
    return contador;
}

int BuscarVentaporNumero(int venta){//busca articulo por id y lo muestra si "estado" esta en true
    Venta ven;
    int pos=0;
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb");
    if(pVenta==NULL){return -1;}
    pos=buscarVenta(venta);
    if(pos<0){return -2;}
    ven.leerDeDisco(pos);
    if(ven.getEstado()==true){ven.mostrar();}
    else{return -2;}
    fclose(pVenta);


}

int contarRegistrosVentas(){//Devuelve la cantidad de registros
    int c=0, tam;
    FILE *pVentas;
    pVentas=fopen(ARCHIVOVENTAS, "rb");
    if(pVentas==NULL){return -1;}
    fseek(pVentas, 0, 2);
    tam=ftell(pVentas);
    fclose(pVentas);
    c=tam/sizeof(Venta);
    return c;
}

bool listarVentas(){//lista todo el registro siempre y cuando "estado" este en true
       int cantReg,i;
       Venta ven;
       cantReg=contarRegistrosVentas();
       for(i=0;i<cantReg;i++){
        ven.leerDeDisco(i);
        if(ven.getEstado()){
        ven.mostrar();
        cout<<endl;}
       }
       return cantReg;
}

bool eliminarVenta(){//cambia el estado de true a false
    bool nodisponible=false;
    char r;
    int Nventa;
    Venta ven;
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb+");
    if(pVenta==NULL){return false;}
    cout<<"INGRESE ID DE VENTA: ";
    cin>>Nventa;
    int pos=buscarVenta(Nventa);
    if(pos<0){
            fclose(pVenta);
            return false;}
    ven.leerDeDisco(pos);
    ven.mostrar();
    cout<<"ELIMINAR VENTA (Y/N)?";
    cin>>r;
    if(r=='y'||r=='Y'){
            ven.leerDeDisco(pos);
            ven.setestado(nodisponible);
            bool modifico=ven.modificarEnDisco(ven,pos);
            fclose(pVenta);
            return modifico;
    }
    else{return false;}
}

bool altaVenta(){// cambia el estado de false a true
    bool disponible=true;
    char r;
    int Nventa;
    Venta ven;
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb+");
    if(pVenta==NULL){return false;}
    cout<<"INGRESE ID DE VENTA: ";
    cin>>Nventa;
    int pos=buscarVenta(Nventa);
    if(pos<0){
            fclose(pVenta);
            return false;}
            ven.leerDeDisco(pos);
            ven.mostrar();
            cout<<"DAR EL ALTA LA VENTA (Y/N)?";
            cin>>r;
    if(r=='y'||r=='Y'){
            ven.leerDeDisco(pos);
            ven.setestado(disponible);
            bool modifico=ven.modificarEnDisco(ven,pos);
            fclose(pVenta);
            return modifico;
    }
    else{return false;}
}

bool devolverVenta(){//pone en false el estado de la venta y repone la cantidad de articulos vendida
    bool nodisponible=false;
    char r;
    int Nventa;
    Venta ven;
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb+");
    if(pVenta==NULL){return false;}
    cout<<"INGRESE ID DE VENTA: ";
    cin>>Nventa;
    int pos=buscarVenta(Nventa);
    if(pos<0){
            fclose(pVenta);
            return false;}
    ven.leerDeDisco(pos);
    ven.mostrar();
    cout<<"DEVOLVER VENTA (Y/N)?";
    cin>>r;
    if(r=='y'||r=='Y'){
            ven.leerDeDisco(pos);
            ven.setestado(nodisponible);
            if((controlstock(ven.getCantidadVendida(),ven.getIDarticulo(),false))==0){cout<<"NO SE PUDO MODIFICAR STOCK"<<endl;}
            bool modifico=ven.modificarEnDisco(ven,pos);
            fclose(pVenta);
            return modifico;
    }
    else{return false;}
}

void seccionVenta(){
    int opc;
    do{
        opc=Menuventas();
        switch(opc){
        case 12:
            {
                int agregados=0;
                system("cls");
                agregados = agregarVenta();
                cout << agregados <<"VENTA/s CARGADA/s CON EXITO!"<<endl;
                break;
            }
            break;
        case 13:
                system("cls");
                int nventa;
                cout<<"INGRESE NUMERO DE VENTA: "<<endl;
                cin>>nventa;
                if (BuscarVentaporNumero(nventa)==-2){cout<<"VENTA INEXISTENTE O ELIMINADA"<<endl;}
                system("pause");
            break;
        case 14:
                system("cls");
                if((listarVentas())==0){cout<<"ERROR AL LISTAR VENTAS"<<endl;}
                system("pause");
            break;
        case 15:
                system("cls");
                if(eliminarVenta()==false){cout<<"ERROR AL ELIMNIAR VENTA"<<endl;}
                system("pause");
            break;
        case 16:
                system("cls");
                if(altaVenta()==false){cout<<"ERROR ALTA DE VENTA"<<endl;}
                system("pause");
            break;
        case 17:
                system("cls");
                if(devolverVenta()==false){cout<<"ERROR ALTA DE VENTA"<<endl;}
                system("pause");
            break;
        }
    }while(opc!=18);
}
///-------------------------------------------------------///


#endif // MENUVENTA_H_INCLUDED
