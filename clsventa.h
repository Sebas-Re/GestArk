#ifndef CLSVENTA_H_INCLUDED
#define CLSVENTA_H_INCLUDED
///CLASE Venta
///-------------------------------------------------------///

float CalculoDeImporte(int id, int cv);


class Venta
{
private:
    int Nventa;
    int IDarticulo;
    int DNIcliente;
    int IDvendedor;
    float importe;
    int cantVendida;
    Fecha fe;
    bool estado;
public:
    //constructor
    Venta(int nv=0, int iart=0, int dc=0, int iv=0, float im=0, int cv=0,bool e=false)
    {
        Nventa=nv;
        IDarticulo=iart;
        DNIcliente=dc;
        IDvendedor=iv;
        importe=im;
        cantVendida=cv;
        estado=e;
    }
    //sets
    void setNventa(int v)
    {
        Nventa=v;
    }
    void setIDarticulo(int v)
    {
        IDarticulo=v;
    }
    void setDNIcliente(int v)
    {
        DNIcliente=v;
    }
    void setimporte(float v)
    {
        importe=v;
    }
    void setcantVendida(int v)
    {
        cantVendida=v;
    }
    void setestado(bool v)
    {
        estado=v;
    }
    //gets
    int getNventa()
    {
        return Nventa;
    }
    int getIDarticulo()
    {
        return IDarticulo;
    }
    int getDNIcliente()
    {
        return DNIcliente;
    }
    int getIDvendedor()
    {
        return IDvendedor;
    }
    float getImporte()
    {
        return importe;
    }
    int getCantidadVendida()
    {
        return cantVendida;
    }
    bool getEstado()
    {
        return estado;
    }
    Fecha getFe()
    {
        return fe;
    }

    //Metodos
    void cargar();
    void mostrar();
    void VerificacionIDven (int id);
    void VerificacionIDart (int id);
    void VerificacionDNI(int dni);
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(Venta venta, int pos);

};

void Venta::cargar()
{
    int x, pos;
    Articulo aux;

    rlutil::locate(1,30);
    cout << "Articulos disponibles: ";
    listarArticulosDisponibles(31);
    rlutil::locate(1,4);
    cout<<"INGRESE ID DE ARTICULO: ";cin>>x;
    VerificacionIDart(x);

    BorrarArea(1,29);
    rlutil::locate(1,30);
    cout << "Clientes disponibles: ";
    listarClientes(31);

    rlutil::locate(1,5);
    cout<<"INGRESE DNI DEL CLIENTE: "; cin >> x;
    VerificacionDNI (x);

    BorrarArea(1,29);
    rlutil::locate(1,30);
    cout << "Vendedores disponibles: ";
    listarVendedores(31);
    rlutil::locate(1,6);
    cout << "INGRESE ID DEL VENDEDOR: ";cin >> x;
    VerificacionIDven(x);

    BorrarArea(1,29);

    rlutil::locate(1,7);
    pos=buscarArticulo(IDarticulo);
    aux.leerDeDisco(pos);
   cout << "Stock Disponible: "<<aux.getStock();

    rlutil::locate(1,8);
    cout<<"INGRESE CANTIDAD VENDIDA: ";cin>>cantVendida;



    while(verificarstock(cantVendida,IDarticulo)==0){

        cout<<"INGRESE CANTIDAD VENDIDA: ";cin>>cantVendida;
    }

    if((controlstock(cantVendida,IDarticulo,true))==0){cout<<"NO SE PUDO MODIFICAR STOCK"<<endl;}
            else{   BorrarArea(1,9);
                    rlutil::locate(1,9);
                    cout<<"STOCK ACTUALIZADO"<<endl;}
    setimporte (calcularimporte(cantVendida,IDarticulo));
    generarPedido(IDarticulo);


    rlutil::locate(1,10);
    cout << "IMPORTE: " << importe << endl;
    cout<<"INGRESE FECHA DE VENTA"<<endl;
    fe.cargar();
    estado=true;
}


void Venta::VerificacionIDart(int id){

    Articulo reg;
    bool IDexistente = true;

    FILE *ArchivoArticulo;
    ArchivoArticulo = fopen(ARCHIVOARTICULO, "rb");


    if (ArchivoArticulo == NULL)
    {
        cout << "Error al abrir";
        system("pause");
    }



    do
    {

        if (IDexistente == false)
        {
            cout << "ID no encontrado, por favor ingrese un nuevo ID: ";
            cin >> id;
            cout << endl;


        }

        IDexistente = false;
        fseek(ArchivoArticulo, 0 * sizeof reg, 0);

        while (fread(&reg, sizeof reg, 1, ArchivoArticulo) == 1)
        {
            if (reg.getID() == id && reg.getEstado() == true)
            {
                IDexistente = true;
                IDarticulo = id;
            }
        }

        if (id == -1)
        {
            return;
        }

    }
    while (IDexistente == false);

    fclose(ArchivoArticulo);

    BorrarArea(1, 5);
}


void Venta::VerificacionDNI(int dni)
{

    Cliente reg;
    bool DNIexistente = true;

    FILE *ArchivoClientes;
    ArchivoClientes = fopen(ARCHIVOCLIENTE, "rb");
    if (ArchivoClientes == NULL)
    {
        cout << "Error al abrir";
        system("pause");
    }

    do
    {

        if (DNIexistente == false)
        {
            cout << "DNI no encontrado, por favor ingrese un nuevo DNI: ";
            cin >> dni;
            cout << endl;



        }

        DNIexistente = false;
        fseek(ArchivoClientes, 0 * sizeof reg, 0);

        while (fread(&reg, sizeof reg, 1, ArchivoClientes) == 1)
        {
            if (reg.getDni() == dni && reg.GetEstado() == true)
            {
                DNIexistente = true;
            }
        }

        if (DNIexistente == true)
        {
            DNIcliente = dni;
        }

        if (dni == -1)
        {
            return;
        }

    }
    while (DNIexistente == false);

    fclose(ArchivoClientes);

    BorrarArea(1, 6);

}

void Venta::VerificacionIDven(int id)
{

    Vendedor reg;
    bool IDexistente = true;

    FILE *ArchivoVendedor;
    ArchivoVendedor = fopen(ARCHIVOVENDEDOR, "rb");


    if (ArchivoVendedor == NULL)
    {
        cout << "Error al abrir";
        system("pause");
    }



    do
    {

        if (IDexistente == false)
        {
            cout << "ID no encontrado, por favor ingrese un nuevo ID: ";
            cin >> id;
            cout << endl;


        }

        IDexistente = false;
        fseek(ArchivoVendedor, 0 * sizeof reg, 0);

        while (fread(&reg, sizeof reg, 1, ArchivoVendedor) == 1)
        {
            if (reg.getIdVendedor() == id && reg.getEstado() == true)
            {
                IDexistente = true;
                IDvendedor = id;
            }
        }

        if (id == -1)
        {
            return;
        }

    }
    while (IDexistente == false);

    fclose(ArchivoVendedor);

    BorrarArea(1, 7);

}

void Venta::mostrar()
{
    cout<<"-----------------------------"<<endl;
    cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
    cout<<"CLIENTE DNI: "<<DNIcliente<<endl;
    cout<<"ARTICULO : "<<IDarticulo<<endl;
    cout<<"IMPORTE DE VENTA: "<<importe<<endl;
    cout<<"CANTIDAD VENDIDA: "<<cantVendida<<endl;
    cout<<"FECHA DE VENTA: "<<"\t";
    fe.mostrar();
}

bool Venta::leerDeDisco(int pos)
{
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb");
    if(pVenta==NULL)
    {
        return false;
    }
    fseek(pVenta,pos*sizeof(Venta),0);
    bool leyo=fread(this,sizeof (Venta),1,pVenta);
    fclose(pVenta);
    return leyo;
}

bool Venta::grabarEnDisco()
{
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"ab");
    if(pVenta==NULL)
    {
        return false;
    }
    bool escribio=fwrite(this,sizeof (Venta),1,pVenta);
    fclose(pVenta);
    return escribio;

}

bool Venta::modificarEnDisco(Venta v, int pos)
{
    FILE *pVenta;
    pVenta=fopen(ARCHIVOVENTAS,"rb+");
    if(pVenta==NULL)
    {
        return false;
    }
    fseek(pVenta,pos*sizeof (v),0);
    bool escribio=fwrite(&v,sizeof v,1,pVenta);
    fclose(pVenta);
    return escribio;
}
///-------------------------------------------------------///


#endif // CLSVENTA_H_INCLUDED
