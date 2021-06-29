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
    Pedido(int d=0,const char *e="0000"){
        nPedido=d;
        strcpy(producto,e);
        cantSolicitada=d;
        strcpy(ProvaSolicitar,e);
        strcpy(envioMail,e);
    }
    //sets
    void setnPedido(int d){nPedido=d;}
    void setProducto(char *d){strcpy(producto,d);}
    void setCantSolicitada(int d){cantSolicitada=d;}
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

void Pedido::mostrar(int y){
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
    bool leyo=fread(this,sizeof (Pedido),1,pPedido);
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

bool Pedido::modificarEnDisco(Proveedor reg, int pos){
    FILE *pPedido;
    pPedido=fopen(ARCHIVOPEDIDO,"rb+");
    if(pPedido==NULL){return false;}
    fseek(pPedido,pos*sizeof reg,0);
    bool escribio=fwrite(&reg,sizeof reg,1,pPedido);
    fclose(pPedido);
    return escribio;
}

void AsignacionNumeroPedido (Pedido &ven){
    FILE *pPedido;
    pPedido=fopen(ARCHIVOPEDIDO,"rb");
    fseek(pPedido,-sizeof (Pedido),2);
    fread(&ven,sizeof ven,1,pPedido);
    ven.setnPedido(ven.getnPedido()+1);
    fclose(pPedido);
}

void generarPedido(int idArticulo){
    int pos,i=0,v=0,ap=0,cantapedir=0;
    Pedido regp;
    Articulo rega;
    Proveedor regpr;
    Venta regv;
    pos=buscarArticulo(idArticulo);
    rega.leerDeDisco(pos);
    //aca se fija que haya menos de diez
    if(rega.getStock()<10){
        while(regp.leerDeDisco(i++)){
                //aca busca que el producto no este pedido
            if(strcmp(rega.getDescripcion(),regp.getProducto())){
                cout<<"YA SE GENERO UN PEDIDO PARA ESTE ARTICULO"<<endl;
            }
        }
        //asigna numero de pedido
        AsignacionNumeroPedido(regp);
        //aca le graba el nombre del producto
        regp.setProducto(rega.getDescripcion());
        while(regv.leerDeDisco(v++)){
                //aca recorre el archivo ventas y acumula cantvendida
            if(rega.getID()==regv.getIDarticulo()){
              cantapedir+=regv.getCantidadVendida();
            }
        }
        regp.setCantSolicitada(cantapedir);
        //agrego el proveedor
        regp.setProvasolicitar(rega.getProveedor());
        //recorro el archivo proveedor y saco el mail
        while(regpr.leerDeDisco(ap++)){
            if(strcmp(rega.getProveedor(),regpr.getNombreProv())){
                regp.setEnvioMail(regpr.getMailProv());
            }
        }
        if(!regp.grabarEnDisco()){cout<<"ERROR AL GENERAR PEDIDO"<<endl;}
    }

}

#endif // CLSPEDIDO_H_INCLUDED
