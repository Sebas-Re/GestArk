#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED
///CLASE CLIENTE
///-------------------------------------------------------///

class Cliente: public Persona{

    protected:
        Direccion domicilio;
        bool Estado;

    public:
        ///constructor
        Cliente (bool e=true){
            Estado=e;
        }
        ///sets
        void setEstado(bool d){Estado=d;}
        ///gets
        bool GetEstado(){return Estado;}
        ///Metodos
        void cargar();
        void mostrar();
        bool leerDeDisco(int pos);
        bool grabarEnDisco();
        bool modificarEnDisco(Cliente reg, int pos);
    };

void Cliente::cargar(){

    Persona::Cargar();
    domicilio.cargar();
}

void Cliente::mostrar(){
    cout<<"-----------------------------"<<endl;
    Persona::Mostrar();
    domicilio.Mostrar();
}

bool Cliente::leerDeDisco(int pos){
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
}
///-------------------------------------------------------///
#endif // CLSCLIENTE_H_INCLUDED
