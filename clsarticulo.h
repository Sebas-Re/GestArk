#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED
///CLASE ARTICULO
///-------------------------------------------------------///
class Articulo{
private:
    int ID;
    char Descripcion[25];
    float Pu;
    int Stock;
    int idProveedor;
    bool Estado;
public:
    ///constructor
    Articulo(int c=0, const char *d="0000", float p=0, int s=0, bool e=false){
        ID=c;
        strcpy(Descripcion,d);
        Pu=p;
        Stock=s;
        idProveedor=c;
        Estado=false;
    }
    ///Sets
    void setID(int c){ID=c;}
    void setDescripcion(char *d){strcpy(Descripcion,d);}
    void setPu(float p){if(p>0){Pu=p;}
                        else{
                            while(p<=0){
            cout<<"El PRECIO DEBE SER MAYOR A CERO"<<endl;
            cout<<"INGRESE PRECIO UNITARIO DEL ARTICULO: ";
            cin>>p;}
            Pu=p;}
    }
    void setStock(int s){Stock=s;}
    void setIdProveedor(int d){idProveedor=d;}
    void setEstado(bool e){Estado=e;}
    ///Gets
    int getID(){return ID;}
    char *getDescripcion(){return Descripcion;}
    float getPu(){return Pu;}
    int getStock(){return Stock;}
    int getIdProveedor(){return idProveedor;}
    bool getEstado(){return Estado;}
    ///Metodos
  //  void iDAutomatico();
    void cargar();
    void mostrar();
    void mostrar(int y);
    bool leerDeDisco(int i);
    bool grabarEnDisco();
    bool modificarEnDisco(Articulo reg, int pos);
    void VerificarStock ();

};
/*
void Articulo::iDAutomatico(){
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVOARTICULO,"rb");
    fseek(pArchivo,-sizeof (Articulo),2);
    fread(this, sizeof (Articulo),1,pArchivo);
    ID+=1;
    fclose(pArchivo);
    cout<<"CODIGO AUTONUMERICO ASIGNADO: "<<ID<<endl;
}
*/

void Articulo::VerificarStock (){

    int s;

    cin >> s;

    while (s < 1 or s > 99999){
        cout << "Stock invalido, ingrese Stock: "<<endl;
        cin >> s;

    }

    Stock=s;
        BorrarArea(1,4);
        rlutil::locate(1,4);
        cout << "STOCK INGRESADO: " << Stock;

}

void Articulo::cargar(){
    int posProv=0;
    Proveedor nombreProveedor;

        cout<<"INGRESE DESCRIPCION DEL ARTICULO: ";
        cargarCadena(Descripcion,24);
        cout<<"INGRESE PRECIO UNITARIO DEL ARTICULO: ";
        cin>>Pu;
        while(Pu<=0){
            cout<<"El PRECIO DEBE SER MAYOR A CERO"<<endl;
            cout<<"INGRESE PRECIO UNITARIO DEL ARTICULO: ";
            cin>>Pu;
        }
        BorrarArea(1,3);
        rlutil::locate(1,3);
        cout << "EL PRECIO UNITARIO INGRESADO FUE: " << Pu;

        rlutil::locate(1,4);
        cout<<"INGRESE EL STOCK DEL ARTICULO: ";
        VerificarStock();


        rlutil::locate(1,25);
        cout << "PROVEEDORES DISPONIBLES: ";
        listarProveedorPorDefecto(26);

        rlutil::locate(1,5);
        cout<<"INGRESE EL ID DEL PROVEEDOR DEL ARTICULO: ";
        rlutil::locate(1,6);
        cin>>idProveedor;
        posProv=buscarProveedor(idProveedor);
        nombreProveedor.leerDeDisco(posProv);
        BorrarArea(1,5);
        rlutil::locate(1,5);


        cout<<"EL PROVEEDOR INGRESADO FUE: "<<nombreProveedor.getNombreProv();
        Estado=true;
        cout<<endl << "------------------------"<< endl;
}

void Articulo::mostrar(int y){
        Proveedor nombreProveedor;
        int posProv;
        posProv=buscarProveedor(idProveedor);
        nombreProveedor.leerDeDisco(posProv);
        y+=2;
        gotoxy(4,y);
        cout<<ID<<"\t";
        gotoxy(13,y);
        cout<<Descripcion<<"\t";
        gotoxy(33,y);
        cout<<"$ "<<Pu<<"\t";
        gotoxy(51,y);
        cout<<Stock<<"\t";
        gotoxy(62,y);
        if(Estado==true){cout<<"DISPONIBLE"<<endl;}
        else{cout<<"NO DISPONIBLE"<<endl;}
        gotoxy(79,y);
        cout<<nombreProveedor.getNombreProv();
}

void Articulo::mostrar(){
        Proveedor nombreProveedor;
        int posProv;
        posProv=buscarProveedor(idProveedor);
        nombreProveedor.leerDeDisco(posProv);

        cout<<"------------------------"<<endl;
        cout<<"CODIGO DE ARTICULO: "<<ID<<endl;
        cout<<"DESCRIPCION: "<<Descripcion<<endl;
        cout<<"PRECIO UNITARIO: $"<<Pu<<endl;
        cout<<"STOCK: "<<Stock<<endl;
        cout<<"PROVEEDOR: "<<nombreProveedor.getNombreProv()<<endl;
        cout<<"ESTADO: ";
        if(Estado==true){cout<<"DISPONIBLE"<<endl;}
        else{cout<<"NO DISPONIBLE"<<endl;}
        cout<<"------------------------"<<endl;
}

bool Articulo::leerDeDisco(int pos){
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb");
    if(pArticulo==NULL){return false;}
    fseek(pArticulo,pos*sizeof(Articulo),0);
    bool leyo=fread(this,sizeof (Articulo),1,pArticulo);
    fclose(pArticulo);
    return leyo;
}

bool Articulo::grabarEnDisco(){
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"ab");
    if(pArticulo==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Articulo),1,pArticulo);
    fclose(pArticulo);
    return escribio;

}

bool Articulo::modificarEnDisco(Articulo reg, int pos){
    FILE *pArticulo;
    pArticulo=fopen(ARCHIVOARTICULO,"rb+");
    if(pArticulo==NULL){return false;}
    fseek(pArticulo,pos*sizeof reg,0);
    bool escribio=fwrite(&reg,sizeof reg,1,pArticulo);
    fclose(pArticulo);
    return escribio;
}
///-------------------------------------------------------///
#endif // CLSARTICULO_H_INCLUDED
