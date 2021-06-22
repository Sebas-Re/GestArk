#ifndef MENUVENDEDOR_H_INCLUDED
#define MENUVENDEDOR_H_INCLUDED

int buscarDNIVendedor(int dniBuscado){
    Vendedor registro;
    int pos=0;
    while(registro.leerDeDisco(pos)==1){
        if(dniBuscado==registro.getDni()){
            return pos;
            pos++;
        }
        pos;
    }
    return -1;
}

bool verificarVendedor(int d){
    int posicion=0;
    Vendedor registro;

    while(registro.leerDeDisco(posicion)){
        if(d==registro.getDni()){
            return true;
        }
        posicion++;
    }
    return false;
}

int agregarVendedor(){
    int r;
    int contador=0;
    Vendedor registro;
    do{
        registro.iDAutomatico();
        cout << "ID del nuevo vendedor, asignado automaticamente: " << registro.getIdVendedor() << endl;
        registro.cargar();
        if(!registro.grabarEnDisco()){
            cout << "Error al guardar el archivo.";
            system("pause");
            return contador;
        }
        contador++;
        cout<<"DESEA AGREGAR OTRO VENDEDOR (y/n)?"<<endl;
        r=getch();
    }while(r==121||r==89);
    return contador;
}

int mostrarVendedorPorDni(int dni){//busca Vendedor por DNI y lo muestra si "estado" esta en true
    Vendedor registro;
    int pos=0;
    pos=buscarDNIVendedor(dni);
    if(pos<0){return -2;}

    if(!registro.leerDeDisco(pos)){return -3;}

    if(!registro.getEstado()){return -1;}

    registro.mostrar();
}

bool listarVendedores(){
    Vendedor registro;
    int pos=0, i=0;
    while(registro.leerDeDisco(pos++)){
        if(registro.getEstado()){
            registro.mostrar(i+3);
            i++;
            cout << endl;
        }
    }
    return pos;

}

int modificarCategoria(){
    int dni, pos;
    bool modifico=false;
    Vendedor registro;

    cout<<"INGRESE DNI DEL VENDEDOR: ";
    cin>>dni;

    pos=buscarDNIVendedor(dni);
    if(pos<0){return -2;}


    if(!registro.leerDeDisco(pos)){return -3;}
    if(registro.getEstado()==true){
        int catNueva;
        cout<<"INGRESE LA NUEVA CATEGORIA: ";
        cin >> catNueva;
        registro.setcategoria(catNueva);
        modifico=registro.modificarEnDisco(pos);
    }
    return modifico;
}

int eliminarVendedor(){//cambia el estado de true a false
    int r;
    int dni, pos;
    bool modifico=false;
    Vendedor registro;

    cout<<"INGRESE DNI DEL VENDEDOR: ";
    cin>>dni;

    pos=buscarDNIVendedor(dni);
    if(pos<0){return -2;}

    if(!registro.leerDeDisco(pos)){return -3;}

    cout<<"ELIMINAR VENDEDOR (Y/N)?";
    r=getch();
    if(r!=121 && r!=89){
        modifico = -1;
        return modifico;
    }
    registro.setEstado(false);
    modifico=registro.modificarEnDisco(pos);
    return modifico;
}

int altaVendedor(){//cambia el estado de true a false
    int r;
    int dni, pos;
    bool modifico=false;
    Vendedor registro;

    cout<<"INGRESE DNI DEL VENDEDOR: ";
    cin>>dni;

    pos=buscarDNIVendedor(dni);
    if(pos<0){return -2;}

    if(!registro.leerDeDisco(pos)){return -3;}

    cout<<"DAR DE ALTA AL VENDEDOR (Y/N)?";
    r=getch();
    if(r!=121 && r!=89){
        modifico = -1;
        return modifico;
    }
    registro.setEstado(true);
    modifico=registro.modificarEnDisco(pos);
    return modifico;
}

void seccionVendedor(){
    int opc;
    do{
        int checkeo=0;
        opc=menuVendedor();
        switch(opc){
        case 12:
            {
                int agregados=0;
                system("cls");
                agregados = agregarVendedor();
                cout << agregados <<"VENDEDOR/s CARGADO/s CON EXITO!"<<endl;
                break;
            }
        case 13:
            {
                system("cls");
                int dni;
                cout<<"INGRESE DNI DEL VENDEDOR: "<<endl;
                cin>>dni;
                checkeo=mostrarVendedorPorDni(dni);
                if(checkeo==-1){cout<<"El vendedor esta dado de baja."<<endl;}
                if(checkeo==-2){cout<<"El vendedor no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                system("pause");
                break;
            }
        case 14:
            {
                system("cls");
                int leyo;
                leyo=listarVendedores();
                if (leyo==0){cout << "Error al leer el archivo" << endl;}
                system("pause");
                break;
            }
        case 15:
            {
                system("cls");
                checkeo=modificarCategoria();
                if(checkeo==-2){cout<<"El vendedor no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Categoria modificada con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        case 16:
            {
                system("cls");
                checkeo=eliminarVendedor();
                if(checkeo==-1){cout<<"El vendedor no fue dado de baja."<<endl;}
                if(checkeo==-2){cout<<"El vendedor no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Vendedor dado de baja con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        case 17:
            {
                system("cls");
                checkeo=altaVendedor();
                if(checkeo==-1){cout<<"El vendedor no fue dado de alta."<<endl;}
                if(checkeo==-2){cout<<"El vendedor no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Vendedor dado de alta con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        }
    }while(opc!=18);

}
#endif // MENUVENDEDOR_H_INCLUDED
