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
//    bool leerDeDisco(int pos);
//    bool grabarEnDisco();
//    bool modificarEnDisco(Vendedor reg, int pos);
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

/*bool Cliente::leerDeDisco(int pos){
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb");
    if(pCliente==NULL){return false;}
    fseek(pCliente,pos*sizeof(Cliente),0);
    bool leyo=fread(this,sizeof (Cliente),1,pCliente);
    fclose(pCliente);
    return leyo;
}

bool Cliente::grabarEnDisco(){
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"ab");
    if(pCliente==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Cliente),1,pCliente);
    fclose(pCliente);
    return escribio;

}

bool Cliente::modificarEnDisco(Cliente reg, int pos){
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb+");
    if(pCliente==NULL){return false;}
    fseek(pCliente,pos*sizeof reg,0);
    bool escribio=fwrite(&reg,sizeof reg,1,pCliente);
    fclose(pCliente);
    return escribio;
}*/




///-------------------------------------------------------///
#endif // CLSVENDEDOR_H_INCLUDED
