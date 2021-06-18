#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED
///MENU CONFIGURACION
///-------------------------------------------------------///
///ARCHIVOS ARTICULO
///-------------------------------------------------------///
void mostrarArticuloBackup(){
    FILE *p;
    Articulo aux;
    p=fopen(ARCHIVOARTICULO_BKP,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

void mostrarArticuloinicial(){
    FILE *p;
    Articulo aux;
    p=fopen(ARCHIVOINICIAL,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

bool hacerBackupArticulo(){
    FILE *p,*i;
    Articulo aux;
    char r;
    int pos=0;
    p=fopen(ARCHIVOARTICULO_BKP,"wb");
    if(p==NULL) return false;

    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,p);
    }
    fclose(p);
    cout<<"PRIMERA VEZ CREANDO BACKUP(y/n)?"<<endl;
    cin>>r;
    if(r=='y'||r=='Y'){
    cout<<"SE CREARA TAMBIEN UN ARCHIVO PARA ESTABLECER LOS DATOS DE INICIO: "<<endl;
    system("pause");
    pos=0;
    i=fopen(ARCHIVOINICIAL,"wb");
    if(i==NULL) return false;
    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVOS DATOS DE INICIO."<<endl;
    mostrarArticuloinicial();
    }
    cout<<"------------------------"<<endl<<endl<<endl<<endl;
    cout<<"------------------------"<<endl;
    cout<<"ARCHIVO BACKUP: "<<endl;
    mostrarArticuloBackup();
    return true;
}

bool restablecerArchivoArticulo(){
    FILE *p, *bk;
    Articulo aux;

    bk=fopen(ARCHIVOARTICULO_BKP, "rb");
    if(bk==NULL) return false;

    p=fopen(ARCHIVOARTICULO,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

bool restablecerarchivosArticuloinicio(){
    FILE *p, *bk;
    Articulo aux;
    bk=fopen(ARCHIVOINICIAL, "rb");
    if(bk==NULL) return false;
    p=fopen(ARCHIVOARTICULO,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }
    fclose(p);
    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }
    fclose(bk);
    system("pause");
    return true;

}
///-------------------------------------------------------///
///ARCHIVOS CLIENTE
///-------------------------------------------------------///
void mostrarClienteBackup(){
    FILE *p;
    Cliente aux;
    p=fopen(ARCHIVOCLIENTE_BKP,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

void mostrarClienteinicial(){
    FILE *p;
    Cliente aux;
    p=fopen(ARCHIVOINICIALCLIENTE,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

bool hacerBackupCliente(){
    FILE *p,*i;
    Cliente aux;
    char r;
    int pos=0;
    p=fopen(ARCHIVOCLIENTE_BKP,"wb");
    if(p==NULL) return false;

    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,p);
    }
    fclose(p);
    cout<<"PRIMERA VEZ CREANDO BACKUP(y/n)?"<<endl;
    cin>>r;
    if(r=='y'||r=='Y'){
    cout<<"SE CREARA TAMBIEN UN ARCHIVO PARA ESTABLECER LOS DATOS DE INICIO: "<<endl;
    pos=0;
    i=fopen(ARCHIVOINICIALCLIENTE,"wb");
    if(i==NULL) return false;
    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVOS DATOS DE INICIO."<<endl;
    mostrarClienteinicial();
    }
    cout<<"------------------------"<<endl<<endl<<endl<<endl;
    cout<<"------------------------"<<endl;
    cout<<"ARCHIVO BACKUP: "<<endl;
    mostrarClienteBackup();
    return true;
}

bool restablecerArchivoCliente(){
    FILE *p, *bk;
    Cliente aux;

    bk=fopen(ARCHIVOCLIENTE_BKP, "rb");
    if(bk==NULL) return false;

    p=fopen(ARCHIVOCLIENTE,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

bool restablecerarchivosClientesinicio(){
    FILE *p, *bk;
    Cliente aux;
    bk=fopen(ARCHIVOINICIALCLIENTE, "rb");
    if(bk==NULL) return false;
    p=fopen(ARCHIVOCLIENTE,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }
    fclose(p);
    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }
    fclose(bk);
    system("pause");
    return true;

}
///-------------------------------------------------------///
///ARCHIVOS VENTA
///-------------------------------------------------------///
void mostrarVentaBackup(){
    FILE *p;
    Venta aux;
    p=fopen(ARCHIVOVENTAS_BKP,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

void mostrarVentainicial(){
    FILE *p;
    Venta aux;
    int pos=0;
    p=fopen(ARCHIVOVENTASINICIAL,"rb");
    if(p==NULL) return;

    while(fread(&aux, sizeof aux, 1, p)==1){
        aux.mostrar();
    }
    fclose(p);
}

bool hacerBackupVentas(){
    FILE *p,*i;
    Venta aux;
    char r;
    int pos=0;
    p=fopen(ARCHIVOVENTAS_BKP,"wb");
    if(p==NULL) return false;

    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,p);
    }
    fclose(p);
    cout<<"PRIMERA VEZ CREANDO BACKUP(y/n)?"<<endl;
    cin>>r;
    if(r=='y'||r=='Y'){
    cout<<"SE CREARA TAMBIEN UN ARCHIVO PARA ESTABLECER LOS DATOS DE INICIO: "<<endl;
    pos=0;
    i=fopen(ARCHIVOVENTASINICIAL,"wb");
    if(i==NULL) return false;
    while(aux.leerDeDisco(pos++)==1){
        fwrite(&aux, sizeof aux, 1,i);
    }
    fclose(i);
    cout<<"ARCHIVOS DATOS DE INICIO."<<endl;
    mostrarVentainicial();
    }
    cout<<"------------------------"<<endl<<endl<<endl<<endl;
    cout<<"------------------------"<<endl;
    cout<<"ARCHIVO BACKUP: "<<endl;
    mostrarVentaBackup();
    return true;
}

bool restablecerArchivoVentas(){
    FILE *p, *bk;
    Venta aux;

    bk=fopen(ARCHIVOVENTAS_BKP, "rb");
    if(bk==NULL) return false;

    p=fopen(ARCHIVOVENTAS,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }

    fclose(p);

    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }

    fclose(bk);
    system("pause");

    return true;
}

bool restablecerarchivosVentasinicio(){
    FILE *p, *bk;
    Venta aux;
    bk=fopen(ARCHIVOVENTASINICIAL, "rb");
    if(bk==NULL) return false;
    p=fopen(ARCHIVOVENTAS,"wb");
    if(p==NULL) {
            fclose(bk);
            return false;
    }
    fclose(p);
    while(fread(&aux, sizeof aux, 1, bk)==1){
         aux.grabarEnDisco();
    }
    fclose(bk);
    system("pause");
    return true;
}
///-------------------------------------------------------///
void seccionConfiguracion(){
    int opc;
    do{
        opc=Menuconfiguracion();
        switch(opc){
        case 12:
                system("cls");
                if(hacerBackupArticulo()==false){cout<<"ERROR AL CREAR ARCHIVO BACKUP"<<endl;}
                else{cout<<"ARCHIVO BACKUP CREADO CON EXITO."<<endl;}
                system("pause");
            break;
        case 13:
                system("cls");
                if(hacerBackupCliente()==false){cout<<"ERROR AL CREAR ARCHIVO BACKUP"<<endl;}
                else{cout<<"ARCHIVO BACKUP CREADO CON EXITO"<<endl;}
                system("pause");
            break;
        case 14:
                system("cls");
                if(hacerBackupVentas()==false){cout<<"ERROR AL CREAR ARCHIVO BACKUP"<<endl;}
                else{cout<<"ARCHIVO BACKUP CREADO CON EXITO"<<endl;}
                system("pause");
            break;
        case 15:
                system("cls");
                if(restablecerArchivoArticulo()==false){cout<<"ERROR AL RESTABLECER ArchivoArticulo.dat"<<endl;}
                else{cout<<"ARCHIVO RESTABLECIDO DE MANERA EXITOSA."<<endl;}
                system("pause");
            break;
        case 16:
                system("cls");
                if(restablecerArchivoCliente()==false){cout<<"ERROR AL RESTABLECER ArchivoCliente.dat"<<endl;}
                else{cout<<"ARCHIVO RESTABLECIDO DE MANERA EXITOSA."<<endl;}
                system("pause");
            break;
        case 17:
                system("cls");
                if(restablecerArchivoVentas()==false){cout<<"ERROR AL RESTABLECER Archivoventas.dat"<<endl;}
                else{cout<<"ARCHIVO RESTABLECIDO DE MANERA EXITOSA."<<endl;}
                system("pause");
            break;
        case 18:
                system("cls");
                cout<<"SE RESTABLECERA LA INFORMACION QUE SE GUARDO EN EL PRIMER BACKUP."<<endl;
                if(restablecerarchivosArticuloinicio()==false){cout<<"ERROR AL RESTABLECER ARCHIVOARTICULO"<<endl;}
                else{cout<<"SE RESTABLECIO EL ARCHIVO ARTICULO"<<endl;}
                if(restablecerarchivosClientesinicio()==false){cout<<"ERROR AL RESTABLECER EL ARCHIVOCLIENTE"<<endl;}
                else{cout<<"SE RESTABLECIO EL ARCHIVO CLIENTE"<<endl;}
                if(restablecerarchivosVentasinicio()==false){cout<<"ERROR AL RESTABLECER ARCHIVOVENTAS"<<endl;}
                else{cout<<"SE RESTABLECIO EL ARCHIVO VENTAS"<<endl;}
                system("pause");
            break;
        }
    }while(opc!=19);
}

#endif // MENUCONFIGURACION_H_INCLUDED
