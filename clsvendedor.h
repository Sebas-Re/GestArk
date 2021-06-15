#ifndef CLSVENDEDOR_H_INCLUDED
#define CLSVENDEDOR_H_INCLUDED
///CLASE VENDEDOR
///-------------------------------------------------------///
class Vendedor: public Persona{
protected:
    int idVendedor;
    int Categoria;
    bool Estado;
public:

    Vendedor(const int i=0,bool e=true){
        idVendedor=i;
        Categoria=i;
        Estado=e;
    }


    //sets

    void setIdVendedor(int d){idVendedor=d;}
    void setcategoria(int d){Categoria=d;}
    void setEstado(bool d){Estado=d;}
    //gets

    int getIdVendedor(){return idVendedor;}
    int getCategoria(){return Categoria;}
    bool getEstado(){return Estado;}
    //metodos
    void cargar();
    void mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(Vendedor reg, int pos);
};

void Vendedor::cargar(){
    Persona::Cargar();
    cout<<"ID DEL VENDEDOR: ";
    cin>>idVendedor;
    cout<<"CATEGORIA DEL VENDEDOR: ";
    cin>>Categoria;
    Estado=true;
}

void Vendedor::mostrar(){
    cout<<"-----------------------------"<<endl;
     Persona::Mostrar();
    cout<<"ID VENDEDOR: "<<idVendedor<<endl;
    cout<<"CATEGORIA VENDEDOR: "<<Categoria<<endl;
}

bool Vendedor::leerDeDisco(int pos){
    FILE *pVendedor;
    pVendedor=fopen(ARCHIVOVENDEDOR,"rb");
    if(pVendedor==NULL){return false;}
    fseek(pVendedor,pos*sizeof(Vendedor),0);
    bool leyo=fread(this,sizeof (Vendedor),1,pVendedor);
    fclose(pVendedor);
    return leyo;
}


bool Vendedor::grabarEnDisco(){
    FILE *pVendedor;
    pVendedor=fopen(ARCHIVOVENDEDOR  ,"ab");
    if(pVendedor==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Vendedor),1,pVendedor);
    fclose(pVendedor);
    return escribio;

}


bool Vendedor::modificarEnDisco(Vendedor reg, int pos){
    FILE *pVendedor;
    pVendedor=fopen(ARCHIVOVENDEDOR,"rb+");
    if(pVendedor==NULL){return false;}
    fseek(pVendedor,pos*sizeof reg,0);
    bool escribio=fwrite(&reg,sizeof reg,1,pVendedor);
    fclose(pVendedor);
    return escribio;
}




///-------------------------------------------------------///
#endif // CLSVENDEDOR_H_INCLUDED
