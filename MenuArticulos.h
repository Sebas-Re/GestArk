#ifndef MENUARTICULOS_H_INCLUDED
#define MENUARTICULOS_H_INCLUDED
///MENU ARTICULO
///-------------------------------------------------------///
bool agregarArticulo(){//agrega un registro articulo
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb");
    fseek(pArticulo,-sizeof (Articulo),2);
    fread(&reg,sizeof reg,1,pArticulo);
    reg.setID(reg.getID()+1);
    fclose(pArticulo);
    cout<<"CODIGO AUTONUMERICO ASIGNADO: "<<reg.getID()<<endl;
    reg.cargar();
    bool grabo=reg.grabarEnDisco();
    return grabo;
}

int buscarArticulo(int codigo){//recibe "id" del registro y devuelve la posicion donde se encuentra el registro
    Articulo reg;
    int pos=0;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb");
    if(pArticulo==NULL){return -1;}
    while((reg.leerDeDisco(pos))==1){
        if(reg.getID()==codigo){
            fclose(pArticulo);
            return pos;
        }
        pos++;
    }
    fclose(pArticulo);
    return -2;
}

int BuscarArticuloporId(int id){//busca articulo por id y lo muestra si "estado" esta en true
    Articulo reg;
    int pos=0;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb");
    if(pArticulo==NULL){return -2;}
    pos=buscarArticulo(id);
    if(pos<0){return -2;}
    reg.leerDeDisco(pos);
    if(reg.getEstado()==true){reg.mostrar();}
    else{return -2;}
    fclose(pArticulo);

}

int contarRegistros(){//Devuelve la cantidad de registros
    int c=0, tam;
    FILE *pArticulo;

    pArticulo=fopen(ARCHIVOARTICULO, "rb");
    if(pArticulo==NULL){return -1;}

    fseek(pArticulo, 0, 2);
    tam=ftell(pArticulo);/// ftell() devuelve la cantidad de bytes que hay entre el principio del archivo y la posición actual del puntero FILE
    fclose(pArticulo);
    c=tam/sizeof(Articulo);
    return c;
}

void copiarArchivoArticulo(Articulo *pArticulos, int cantArticulos){
    int i;
    for(i=0;i<cantArticulos;i++){
        pArticulos[i].leerDeDisco(i);
    }
}

void ordenarAZArticulos(Articulo *pArticulos, int cantArticulos){
    int i, j, posMin;
    Articulo aux;
    for(i=0;i<cantArticulos-1;i++){
        posMin=i;
        for(j=i+1;j<cantArticulos;j++){

            if(strcmp(pArticulos[j].getDescripcion(), pArticulos[posMin].getDescripcion())<0){
                posMin=j;
            }
        }
        aux=pArticulos[i];
        pArticulos[i]=pArticulos[posMin];
        pArticulos[posMin]=aux;
    }
 }

void ordenarIDArticulos(Articulo *pArticulos, int cantArticulos){
    int i, j, posMin;
    Articulo aux;
    for(i=0;i<cantArticulos-1;i++){
        posMin=i;
        for(j=i+1;j<cantArticulos;j++){
            if(pArticulos[j].getID()<pArticulos[posMin].getID()){
                posMin=j;
            }
        }
        aux=pArticulos[i];
        pArticulos[i]=pArticulos[posMin];
        pArticulos[posMin]=aux;
    }
 }

void ordenarPUArticulos(Articulo *pArticulos, int cantArticulos){
    int i, j, posMin;
    Articulo aux;
    for(i=0;i<cantArticulos-1;i++){
        posMin=i;
        for(j=i+1;j<cantArticulos;j++){
            if(pArticulos[j].getPu()<pArticulos[posMin].getPu()){
                posMin=j;
            }
        }
        aux=pArticulos[i];
        pArticulos[i]=pArticulos[posMin];
        pArticulos[posMin]=aux;
    }
 }

void ordenarStockArticulos(Articulo *pArticulos, int cantArticulos){
    int i, j, posMin;
    Articulo aux;
    for(i=0;i<cantArticulos-1;i++){
        posMin=i;
        for(j=i+1;j<cantArticulos;j++){
            if(pArticulos[j].getStock()<pArticulos[posMin].getStock()){
                posMin=j;
            }
        }
        aux=pArticulos[i];
        pArticulos[i]=pArticulos[posMin];
        pArticulos[posMin]=aux;
    }
 }

void mostrarVectorArticulos(Articulo *pArticulos, int cantArticulos){
    int i;
    cartelListarArticulos();
    for(i=0;i<cantArticulos;i++){
        pArticulos[i].mostrar(i+3);
        cout<<endl;
    }
}

void listarArticulosOrdenadosAZ(){
    int cantArticulos=contarRegistros();
    Articulo *pArticulos;
    pArticulos=new Articulo[cantArticulos];
    if(pArticulos==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }
    copiarArchivoArticulo(pArticulos,cantArticulos);
    ordenarAZArticulos(pArticulos, cantArticulos);
    mostrarVectorArticulos(pArticulos, cantArticulos);
    delete pArticulos;
}

void listarArticulosOrdenadosID(){
    int cantArticulos=contarRegistros();
    Articulo *pArticulos;
    pArticulos=new Articulo[cantArticulos];
    if(pArticulos==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }
    copiarArchivoArticulo(pArticulos,cantArticulos);
    ordenarIDArticulos(pArticulos, cantArticulos);
    mostrarVectorArticulos(pArticulos, cantArticulos);
    delete pArticulos;

}

void listarArticulosOrdenadosPU(){
    int cantArticulos=contarRegistros();
    Articulo *pArticulos;
    pArticulos=new Articulo[cantArticulos];
    if(pArticulos==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }
    copiarArchivoArticulo(pArticulos,cantArticulos);
    ordenarPUArticulos(pArticulos, cantArticulos);
    mostrarVectorArticulos(pArticulos, cantArticulos);
    delete pArticulos;

}

void listarArticulosOrdenadosStock(){
    int cantArticulos=contarRegistros();
    Articulo *pArticulos;
    pArticulos=new Articulo[cantArticulos];
    if(pArticulos==NULL){
        cout<<"ERROR DE ASIGNACION DE MEORIA";
        return;
    }
    copiarArchivoArticulo(pArticulos,cantArticulos);
    ordenarStockArticulos(pArticulos,cantArticulos);
    mostrarVectorArticulos(pArticulos,cantArticulos);
    delete pArticulos;

}

bool listarArticulosPorDefecto(){//lista todo el registro como fue cargado siempre y cuando "estado" sea true
       int cantReg,i;
       Articulo reg;
       cantReg=contarRegistros();
       cartelListarArticulos();
       for(i=0;i<cantReg;i++){
        reg.leerDeDisco(i);
        reg.mostrar(i+3);
        cout<<endl;}
       return cantReg;
}

bool listarArticulosDisponibles(){//lista todo el registro como fue cargado siempre y cuando "estado" sea true
       int cantReg,i=0,linea=0;
       Articulo reg;
       cartelListarArticulos();
       while(reg.leerDeDisco(i++)){
        if(reg.getEstado()){
        reg.mostrar(linea+3);
        cout<<endl;
        linea++;}
        }
       return cantReg;
}

bool listarArticulosNoDisponibles(){//lista todo el registro como fue cargado siempre y cuando "estado" sea true
       int cantReg,i=0,linea=0;
       Articulo reg;
       cantReg=contarRegistros();
       cartelListarArticulos();
       while(reg.leerDeDisco(i++)){
        if(!reg.getEstado()){
        reg.mostrar(linea+3);
        cout<<endl;
        linea++;}
        }
       return cantReg;
}

void listarArticulos(){
    int opc;
    do{
        opc=MenuListarArticulos();
        switch(opc){
        case 12:
            system("cls;");
            listarArticulosPorDefecto();
            system("pause");
            break;
        case 13:
            system("cls;");
            listarArticulosOrdenadosAZ();
            system("pause");
            break;
        case 14:
            system("cls;");
            listarArticulosOrdenadosID();
            system("pause");
            break;
        case 15:
            system("cls;");
            listarArticulosOrdenadosPU();
            system("pause");
            break;
        case 16:
            system("cls;");
            listarArticulosOrdenadosStock();
            system("pause");
            break;
        case 17:
            system("cls;");
            listarArticulosDisponibles();
            system("pause");
            break;
        case 18:
            system("cls;");
            listarArticulosNoDisponibles();
            system("pause");
            break;
        }
    }while(opc!=19);
}

bool modificarPrecioU(){//modifica el precio unitario de un articulo
    float pu;
    int id;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb");
    if(pArticulo==NULL){return false;}
    cout<<"INGRESE EL CODIGO DEL ARTICULO: ";
    cin>>id;
    int pos=buscarArticulo(id);
    if(pos<0){
            fclose(pArticulo);
            return false;
            }
    reg.leerDeDisco(pos);
    reg.mostrar();
    if(reg.getEstado()==true){
            cout<<"INGRESE EL NUEVO PRECIO: ";
            cin>>pu;
    reg.setPu(pu);
    bool modifico=reg.modificarEnDisco(reg,pos);
    return modifico;
    }
    else{return false;}
}

bool elmininarArticulo(){//cambia el estado de true a false
    bool nodisponible=false;
    char r;
    int id;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb+");
    if(pArticulo==NULL){return false;}
    cout<<"INGRESE EL CODIGO DEL ARTICULO: ";
    cin>>id;
    int pos=buscarArticulo(id);
    if(pos<0){
            fclose(pArticulo);
            return false;}
    reg.leerDeDisco(pos);
    reg.mostrar();
    cout<<"ELIMINAR ARTICULO (Y/N)?";
    cin>>r;
    if(r=='y'||r=='Y'){
            reg.leerDeDisco(pos);
            reg.setEstado(nodisponible);
            bool modifico=reg.modificarEnDisco(reg,pos);
            fclose(pArticulo);
            return modifico;
    }
    else{return false;}
}

bool altaArticulo(){// cambia el estado de false a true
    bool disponible=true;
    char r;
    int id;
    Articulo reg;
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb+");
    if(pArticulo==NULL){return false;}
    cout<<"INGRESE EL CODIGO DEL ARTICULO: ";
    cin>>id;
    int pos=buscarArticulo(id);
    if(pos<0){
            fclose(pArticulo);
            return false;}
    reg.leerDeDisco(pos);
    reg.mostrar();
            cout<<"DAR EL ALTA AL ARTICULO (Y/N)?";
            cin>>r;
    if(r=='y'||r=='Y'){
            reg.leerDeDisco(pos);
            reg.setEstado(disponible);
            bool modifico=reg.modificarEnDisco(reg,pos);
            fclose(pArticulo);
            return modifico;
    }
    else{return false;}
}

void seccionArticulos(){
    int opc;
    do{
        opc=Menuarticulos();
        switch(opc){
           case 12:
               char r;
               system("cls");
               do{
               system("cls");
               if(agregarArticulo()==1){cout<<"CARGADO CON EXITO"<<endl;}
               else{cout<<"ERROR AL LEER ARCHIVO"<<endl;}
               cout<<"DESEA AGREGAR OTRO ARTICULO (y/n)?"<<endl;
               cin>>r;
               cin.ignore();
               }while(r=='y'||r=='Y');
            break;
           case 13:
               system("cls");
               int id;
               cout<<"INGRESE ID DE ARTICULO: "<<endl;
               cin>>id;
               if(BuscarArticuloporId(id)==-2){cout<<"ARTICULO INEXISTENTE O ELIMINADO"<<endl;}
               system("pause");
            break;
           case 14:
                system("cls");
                listarArticulos();
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

///-------------------------------------------------------///

#endif // MENUARTICULOS_H_INCLUDED
