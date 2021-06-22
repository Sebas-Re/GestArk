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

    Vendedor(const int i=1,bool e=true){
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
    bool iDAutomatico();
    void cargar();
    void mostrar();
    void mostrar(int);
    void VerificacionID(int ID);
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

};

bool Vendedor::iDAutomatico(){
    FILE *pArchivo;
    pArchivo=fopen(ARCHIVOVENDEDOR,"rb");
    if(pArchivo==NULL){return false;}
    fseek(pArchivo,-sizeof (Vendedor),2);
    fread(this, sizeof (Vendedor),1,pArchivo);
    idVendedor+=1;
    fclose(pArchivo);
    return true;
}

void Vendedor::cargar(){
    //int x;
    Persona::Cargar();
/*    cout<<"ID DEL VENDEDOR: ";
    cin >> x;
    VerificacionID (x);
    cin>>idVendedor;
    */
    cout<<"CATEGORIA DEL VENDEDOR: ";
    cin>>Categoria;
}
/*
void Vendedor::VerificacionID (int ID){
Vendedor reg;
bool Existe=false;

    FILE *ArchivoVendedor;
    ArchivoVendedor=fopen(ARCHIVOVENDEDOR, "rb");


    if (ArchivoVendedor == NULL)
    {
        cout << "Error al abrir";
        system("pause");
    }
//Está comentado porque al principio, si el archivo no está creado, da error pero es un falso positivo, porque sigue el proceso de verificacion y asignacion de ID;



    do
    {

        if (Existe == true)
        {
            cout << "ID en uso, por favor ingrese un nuevo ID: ";
            cin >> ID;
            cout << endl;
        }

        Existe = false;
        fseek(ArchivoVendedor, 0 * sizeof reg, 0);

        while (fread(&reg, sizeof reg, 1, ArchivoVendedor) == 1)
        {
            if (reg.getIdVendedor() == ID)
            {
                Existe = true;
            }
        }

        if (Existe == false)
        {
            idVendedor = ID;
        }

    } while (Existe == true);

    fclose(ArchivoVendedor);

}
*/
void Vendedor::mostrar(){
    cout<<"-----------------------------"<<endl;
    cout<<"ID VENDEDOR: "<<idVendedor<<endl;
    cout<<"CATEGORIA VENDEDOR: "<<Categoria<<endl;
    Persona::Mostrar();

}


void Vendedor::mostrar(int y){
    gotoxy(4,y);
    cout<<idVendedor;
    gotoxy(8,y);
    cout<<Categoria;
    gotoxy(12,y);
    Persona::Mostrar(y);

}


bool Vendedor::leerDeDisco(int pos){
    FILE *pArchivo;

    pArchivo=fopen(ARCHIVOVENDEDOR, "rb");
    if(pArchivo==NULL){return false;}
    fseek(pArchivo, sizeof (Vendedor)*pos, 0); /// Nos ubicamos para leer
    if(fread(this, sizeof (Vendedor), 1, pArchivo)){ /// Sacamos el registro del archivo
        fclose(pArchivo);
        return true;
    }
    fclose(pArchivo);
    return false;
}

bool Vendedor::grabarEnDisco(){
    FILE *pVendedor;
    pVendedor=fopen(ARCHIVOVENDEDOR  ,"ab");
    if(pVendedor==NULL){return false;}
    bool escribio=fwrite(this,sizeof (Vendedor),1,pVendedor);
    fclose(pVendedor);
    return escribio;

}

bool Vendedor::modificarEnDisco(int pos){
    FILE *pArchivo;

    pArchivo=fopen(ARCHIVOVENDEDOR, "rb+");
    if (pArchivo==NULL){return false;}

    fseek(pArchivo, sizeof (Vendedor)*pos, 0);
    if (fwrite(this, sizeof (Vendedor), 1, pArchivo)){
        fclose(pArchivo);
        return true;
    }
    fclose(pArchivo);
    return false;
}


///-------------------------------------------------------///
#endif // CLSVENDEDOR_H_INCLUDED
