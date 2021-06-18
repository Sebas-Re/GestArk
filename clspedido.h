#ifndef CLSPEDIDO_H_INCLUDED
#define CLSPEDIDO_H_INCLUDED

class Pedido{
private:
    int nPedido;
    char producto[25];
    int cantSolicitada;
    char ProvaSolicitar[25];
    char envioMail[25];
public:
    Pedido(int d=0,const char *d="0000"){
        nPedido=d;
        strcpy(producto,d);
        cantSolicitada=d;
        strcpy(ProvaSolicitar,d);
        strcpy(envioMail,d);
    }
    //sets
    void setnPedido(int d;){nPedido=d;}
    void setProducto(char *d){strcpy(producto,d)}
    void setCantSolicitada(int d;){cantSolicitada=d;}
    void setProvasolicitar(char *d){strcpy(ProvaSolicitar,d);}
    void setEnvioMail(char *d){strcpy(envioMail,d);}
    //gets
    int getnPedido(){return nPedido;}
    char *getProducto(){return producto;}
    int getcantSolicitada(){return cantSolicitada;}
    char *getProvaSolicitar(){return ProvaSolicitar;}
    char *getEnvioMail(){return envioMail;}
    //metodos
    void mostrar();
    void mostrar(int y);
    bool leerDeDisco(int i);
    bool grabarEnDisco();
    bool modificarEnDisco(Proveedor reg, int pos);
};

void Pedido::mostrar(){
    cout<<"NUEMERO DE PEDIDO: "<<nPedido<<endl;
    cout<<"PRODUCTO: "<<producto<<endl;
    cout<<"CANTIDAD SOLICITADA: "<<cantSolicitada<<endl;
    cout<<"PROVEEDOR: "<<ProvaSolicitar<<endl;
    cout<<"MAIL: "<<envioMail<<endl;
}

void Pedido::mostar(int y){
    gotoxy(4,y);
    cout<<nPedido<<"\t";
    gotoxy(8,y);
    cout<<producto<<"\t";
    gotoxy(35,y);
    cout<<cantSolicitada<<"\t";
    gotoxy(60,y);
    cout<<ProvaSolicitar<<"\t";
    gotoxy(75,y);
    cout<<envioMail;
}

bool Pedido::leerDeDisco(int pos){
    FILE *pPedido;
    pPedido=fopen(ARCHIVOPEDIDO,"rb");
    if(pPedido==NULL){return false;}
    fseek(pPedido,pos*sizeof(Pedido),0);
    bool leyo=fread(this,sizeof (Pedido,1,pPedido);
    fclose(pPedido);
    return leyo;
}

bool Pedido::grabarEnDisco(){
    FILE *pPedido;
    pPedido=fopen(ARCHIVOPEDIDO,"ab");
    if(pPedido==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Pedido),1,pPedido);
    fclose(pPedido);
    return escribio;
}

bool Pedido::modificarEnDisco(Pedido reg, int pos){
    FILE *pPedido;
    pPedido=fopen(ARCHIVOPEDIDO,"rb+");
    if(pPedido==NULL){return false;}
    fseek(pPedido,pos*sizeof reg,0);
    bool escribio=fwrite(&reg,sizeof reg,1,pPedido);
    fclose(pPedido);
    return escribio;
}



#endif // CLSPEDIDO_H_INCLUDED
