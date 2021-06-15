#ifndef CLSVENTA_H_INCLUDED
#define CLSVENTA_H_INCLUDED
///CLASE ARTICULO
///-------------------------------------------------------///
class Venta{
private:
    int Nventa;
    int IDarticulo;
    int DNIcliente;
    float importe;
    int cantVendida;
    Fecha fe;
    bool estado;
public:
    //constructor
    Venta(int nv=0, int iart=0, int dc=0, float im=0, int cv=0, Fecha v=(0,0,0),bool e=false){
        Nventa=nv;
        IDarticulo=iart;
        DNIcliente=dc;
        importe=im;
        cantVendida=cv;
        fe=v;
        estado=e;
    }
    //sets
    void setNventa(int v){Nventa=v;}
    void setIDarticulo(int v){IDarticulo=v;}
    void setDNIcliente(int v){DNIcliente=v;}
    void setimporte(float v){importe=v;}
    void setcantVendida(int v){cantVendida=v;}
    void setestado(bool v){estado=v;}
    //gets
    int getNventa(){return Nventa;}
    int getIDarticulo(){ return IDarticulo;}
    int getDNIcliente(){return DNIcliente;}
    float getImporte(){return importe;}
    int getCantidadVendida(){return cantVendida;}
    bool getEstado(){return estado;}
    int getfeanio(){return fe.getanio();}
    int getfemes(){return fe.getmes();}


    //Metodos
    void cargar();
    void mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(Venta venta, int pos);
};

void Venta::cargar(){
    cout<<"INGRESE ID DE ARTICULO"<<endl;
    cin>>IDarticulo;
    cout<<"INGRESE DNI DEL CLIENTE"<<endl;
    cin>>DNIcliente;
    cout<<"INGRESE CANTIDAD VENDIDA"<<endl;
    cin>>cantVendida;
    cout<<"INGRESE FECHA DE VENTA"<<endl;
    fe.cargar();
    estado=true;
}

void Venta::mostrar(){
    cout<<"-----------------------------"<<endl;
    cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
    cout<<"CLIENTE DNI: "<<DNIcliente<<endl;
    cout<<"ARTICULO : "<<IDarticulo<<endl;
    cout<<"IMPORTE DE VENTA: "<<importe<<endl;
    cout<<"CANTIDAD VENDIDA: "<<cantVendida<<endl;
    cout<<"FECHA DE VENTA: "<<"\t";
    fe.mostrar();
}

bool Venta::leerDeDisco(int pos){
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb");
    if(pVenta==NULL){return false;}
    fseek(pVenta,pos*sizeof(Venta),0);
    bool leyo=fread(this,sizeof (Venta),1,pVenta);
    fclose(pVenta);
    return leyo;
}

bool Venta::grabarEnDisco(){
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"ab");
    if(pVenta==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Venta),1,pVenta);
    fclose(pVenta);
    return escribio;

}

bool Venta::modificarEnDisco(Venta v, int pos){
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb+");
    if(pVenta==NULL){return false;}
    fseek(pVenta,pos*sizeof (v),0);
    bool escribio=fwrite(&v,sizeof v,1,pVenta);
    fclose(pVenta);
    return escribio;
}
///-------------------------------------------------------///


#endif // CLSVENTA_H_INCLUDED
