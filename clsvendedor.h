#ifndef CLSVENDEDOR_H_INCLUDED
#define CLSVENDEDOR_H_INCLUDED
///CLASE VENDEDOR
///-------------------------------------------------------///
class Vendedor{
private:
    //
    int dni;
    int idVendedor;
    char Nombre[25];
    char Apellido[25];
    char Email[30];
    char Telefono[15];
    //
    Direccion dirV;
    int Categoria;
    bool Estado;
public:
    /*
    Vendedor(const int i=0,const char *d="00000",Direccion di=("0000",0),bool e=false){
        dni=i;
        idVendedor=i;
        strcpy(Nombre,d);
        strcpy(Apellido,d);
        strcpy(Email,d);
        strcpy(Telefono,d);
        dirV=d;
        Categoria=i;
        Estado=e;
    }
    */

    //sets
    void setDni(int d){dni=d;}
    void setIdVendedor(int d){idVendedor=d;}
    void setNombre(char *d){strcpy(Nombre,d);}
    void setApellido(char *d){strcpy(Apellido,d);}
    void setEmail(char *d){strcpy(Email,d);}
    void setTelefono(char *d){strcpy(Telefono,d);}
    void setcategoria(int d){Categoria=d;}
    void setEstado(bool d){Estado=d;}
    //gets
    int getDni(){return dni;}
    int getIdVendedor(){return idVendedor;}
    char *getNombre(){return Nombre;}
    char *getApellido(){return Apellido;}
    char *getEmail(){return Email;}
    char *getTelefono(){return Telefono;}
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
    cout<<"ID DEL VENDEDOR: ";
    cin>>idVendedor;
    cout<<"CATEGORIA DEL VENDEDOR: ";
    cin>>Categoria;
    cout<<"DNI DE VENDEDOR: ";
    cin>>dni;
    cin.ignore();
    cout<<"NOMBRE DLE VENDEDOR: ";
    cargarCadena(Nombre,24);
    cout<<"APELLIDO DEL VENDEDOR: ";
    cargarCadena(Apellido,24);
    cout<<"EMAIL DEL VENDEDOR: ";
    cargarCadena(Email,29);
    cout<<"TELEFONO DEL VENDEDOR: ";
    cargarCadena(Telefono,14);
    cout<<"DIRECCION DEL VENDEDOR: ";
    dirV.cargar();
    Estado=true;
}

void Vendedor::mostrar(){
    cout<<"-----------------------------"<<endl;
    cout<<"ID VENDEDOR: "<<idVendedor<<endl;
    cout<<"CATEGORIA VENDEDOR: "<<Categoria<<endl;
    cout<<"DNI VENDEDOR: "<<dni<<endl;
    cout<<"NOMBRE VENDEDOR: "<<Nombre<<endl;
    cout<<"APELLIDO VENDEDOR: "<<Apellido<<endl;
    cout<<"EMAIL VENDEDOR: "<<Email<<endl;
    cout<<"TELEFONO VENDEDOR: "<<Telefono<<endl;
    cout<<"DIRECCION: "<<"\t";
    dirV.Mostrar();
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
