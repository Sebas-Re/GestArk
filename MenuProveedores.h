#ifndef MENUPROVEEDORES_H_INCLUDED
#define MENUPROVEEDORES_H_INCLUDED
///MENU PROVEEDOR
///-------------------------------------------------------///
bool agregarProveedor(){//agrega un registro articulo
    int r,contador=0;
    do{
    Proveedor reg;
    FILE *pProveedor;
    pProveedor=fopen(ARCHIVOPROVEEDOR,"rb");
    fseek(pProveedor,-sizeof (Proveedor),2);
    fread(&reg,sizeof reg,1,pProveedor);
    reg.setCodigoProv(reg.getCodigoProv()+1);
    fclose(pProveedor);
    cout<<"CODIGO AUTONUMERICO ASIGNADO: "<<reg.getCodigoProv()<<endl;
    reg.cargar();
    if(!reg.grabarEnDisco()){
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

int buscarProveedor(int codigo){//recibe "id" del registro y devuelve la posicion donde se encuentra el registro
    Proveedor reg;
    int pos=0;
    while((reg.leerDeDisco(pos))==1){
        if(reg.getCodigoProv()==codigo){
            return pos;
        }
        pos++;
        }
    return -1;
}

int BuscarProveedorCod(int id){//busca articulo por id y lo muestra si "estado" esta en true
    Proveedor reg;
    int pos=0;
    pos=buscarProveedor(id);
    if(pos<0){return -2;}
    reg.leerDeDisco(pos);
    if(reg.getEstado()==true){reg.mostrar();}
    else{return -2;}
}

int contarRegistrosProv(){//Devuelve la cantidad de registros
    int c=0, tam;
    FILE *pProveeedor;
    pProveeedor=fopen(ARCHIVOPROVEEDOR,"rb");
    if(pProveeedor==NULL){return -1;}
    fseek(pProveeedor, 0, 2);
    tam=ftell(pProveeedor);
    fclose(pProveeedor);
    c=tam/sizeof(Proveedor);
    return c;
}

void copiarArchivoProveedor(Proveedor *pProveeedor, int cantProveedor){
    int i;
    for(i=0;i<cantProveedor;i++){
        pProveeedor[i].leerDeDisco(i);
    }
}

void mostrarVectorProveedor(Proveedor *pProveedor, int cantProveedor){
    int i;
    cartelListarProveedores();
    for(i=0;i<cantProveedor;i++){
        pProveedor[i].mostrar(i+3);
        cout<<endl;
    }
}

void ordenarAZProveedor(Proveedor *pProveeedor, int cantProveedor){
    int i, j, posMin;
    Proveedor aux;
    for(i=0;i<cantProveedor-1;i++){
        posMin=i;
        for(j=i+1;j<cantProveedor;j++){
                if(strcmp(pProveeedor[j].getNombreProv(), pProveeedor[posMin].getNombreProv())<0){
                        posMin=j;
                }
        }
        aux=pProveeedor[i];
        pProveeedor[i]=pProveeedor[posMin];
        pProveeedor[posMin]=aux;
    }
}

bool listarProveedorPorDefecto(){//lista todo el registro como fue cargado siempre y cuando "estado" sea true
       int cantReg,i;
       Proveedor reg;
       cantReg=contarRegistrosProv();
       cartelListarProveedores();
       for(i=0;i<cantReg;i++){
        reg.leerDeDisco(i);
        reg.mostrar(i+3);
        cout<<endl;}
       return cantReg;
}

void listarProveedoresOrdenados(int orden){
    int cantProveedores=contarRegistrosProv();
    Proveedor *pProveedor;
    pProveedor=new Proveedor[cantProveedores];
    if(pProveedor==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }
    copiarArchivoProveedor(pProveedor,cantProveedores);
    switch(orden){
    case 1:
        listarProveedorPorDefecto();
        break;
    case 2:
        ordenarAZProveedor(pProveedor, cantProveedores);
        break;
    }
    mostrarVectorProveedor(pProveedor, cantProveedores);
    delete pProveedor;
}

void listarProveedores(){
    int opc;
    do{
        opc=MenuListarProveedores();
        switch(opc){
        case 12:
            system("cls;");
            listarProveedoresOrdenados(1);
            system("pause");
            break;
        case 13:
            system("cls;");
            listarProveedoresOrdenados(2);
            system("pause");
            break;
        }
    }while(opc!=14);
}

void seccionProveedores(){
    int opc;
    do{
        opc=MenuProveedores();
        switch(opc){
           case 12:
               {
                int agregados=0;
                system("cls");
                agregados = agregarProveedor();
                cout << agregados <<"ARTICULO/s CARGADO/s CON EXITO!"<<endl;
                break;
            }
            break;
           case 13:
               system("cls");
               int cod;
               cout<<"INGRESE CODIGO DE PROVEEDOR: "<<endl;
               cin>>cod;
               if(BuscarProveedorCod(cod)==-2){cout<<"PROVEEDOR INEXISTENTE O ELIMINADO"<<endl;}
               system("pause");
            break;
           case 14:
                system("cls");
                listarProveedores();
            break;
           case 15:
               system("cls");
               if(modificarPrecioU()==1){cout<<"MODIFICADO CON EXITO"<<endl;}
               else{cout<<"ERROR AL INTENTAR MODIFICAR.ARTICULO INEXISTENTE O ELIMINADO"<<endl;}
               system("pause");
            break;
           case 16:
               system("cls");
               if(elmininarArticulo()==1){cout<<"ARTICULO ELIMINADO"<<endl;}
               else{cout<<"NO SE PUDO ELIMINAR EL ARTICULO."<<endl;}
               system("pause");
            break;
           case 17:
                system("cls");
                if(altaArticulo()==1){cout<<"ALTA DE ARTICULO EXITOSA"<<endl;}
                else{cout<<"NO SE PUDO DAR DE ALTA EL ARTICULO."<<endl;}
                system("pause");
            break;
            }
    }while(opc!=18);
}
#endif // MENUPROVEEDORES_H_INCLUDED
