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
    char Proveedor[25];
    bool Estado;
public:
    ///constructor
    Articulo(int c=0, const char *d="0000", float p=0, int s=0, bool e=false){
        ID=c;
        strcpy(Descripcion,d);
        Pu=p;
        Stock=s;
        strcpy(Proveedor,d);
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
    void setProveedor(char *d){strcpy(Proveedor,d);}
    void setEstado(bool e){Estado=e;}
    ///Gets
    int getID(){return ID;}
    char *getDescripcion(){return Descripcion;}
    float getPu(){return Pu;}
    int getStock(){return Stock;}
    char *getProveedor(){return Proveedor;}
    bool getEstado(){return Estado;}
    ///Metodos
    void cargar();
    void mostrar();
    void mostrar(int y);
    bool leerDeDisco(int );
    bool grabarEnDisco();
    bool modificarEnDisco(Articulo reg, int pos);

};

void Articulo::cargar(){
        cout<<"INGRESE DESCRIPCION DEL ARTICULO: ";
        cargarCadena(Descripcion,24);
        cout<<"INGRESE PRECIO UNITARIO DEL ARTICULO: ";
        cin>>Pu;
        while(Pu<=0){
            cout<<"El PRECIO DEBE SER MAYOR A CERO"<<endl;
            cout<<"INGRESE PRECIO UNITARIO DEL ARTICULO: ";
            cin>>Pu;
        }
        cout<<"INGRESE EL STOCK DEL ARTICULO: ";
        cin>>Stock;
        cout<<"INGRESE PROVEEDOR DEL ARTICULO: ";
        cargarCadena(Proveedor,24);
        Estado=true;
        cout<<"------------------------"<<endl;
}

void Articulo::mostrar(int y){
        gotoxy(4,y);
        cout<<ID<<"\t";
        gotoxy(8,y);
        cout<<Descripcion<<"\t";
        gotoxy(35,y);
        cout<<Pu<<"\t";
        gotoxy(60,y);
        cout<<Stock<<"\t";
        gotoxy(75,y);
        if(Estado==true){cout<<"DISPONIBLE"<<endl;}
        else{cout<<"NO DISPONIBLE"<<endl;}
}

void Articulo::mostrar(){
        cout<<"------------------------"<<endl;
        cout<<"CODIGO DE ARTICULO: "<<ID<<endl;
        cout<<"DESCRIPCION: "<<Descripcion<<endl;
        cout<<"PRECIO UNITARIO: "<<Pu<<endl;
        cout<<"STOCK: "<<Stock<<endl;
        cout<<"PROVEEDOR: "<<Proveedor<<endl;
        cout<<"ESTADO: "<<"\t";
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
