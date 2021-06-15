#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
///MENU CLIENTE
///-------------------------------------------------------///
int buscarDNICliente(int dniBuscado){
    int posicion=0;
    Cliente registro;

    while(registro.leerDeDisco(posicion)){
        if(dniBuscado==registro.getDni()){
            return posicion;
        }
        posicion++;
    }
    return -1;
}

int agregarCliente(){//crea o agrega un registro cliente al final de los que esten hechos
    int r;
    int contador=0;
    do{
        Cliente cli;
        cli.cargar();
        if(!cli.grabarEnDisco()){
            cout << "Error al guardar el archivo.";
            system("pause");
            return contador;
        }
        contador++;
        cout<<"DESEA AGREGAR OTRO CLIENTE (y/n)?"<<endl;
        r=getch();
    }while(r==121||r==89);
    return contador;
}

int mostrarClientePorDNI(int dni){//busca cliente por DNI y lo muestra si "estado" esta en true
    Cliente cli;
    int pos=0;

    pos=buscarDNICliente(dni);
    if(pos<0){return -2;}

    if(!cli.leerDeDisco(pos)){return -3;}

    if(!cli.GetEstado()){return -1;}

    cli.mostrar();
}

int contarRegistrosClientes(){//Devuelve la cantidad de registros
    int c=0, tam;
    FILE *pClientes;
    pClientes=fopen(ARCHIVOCLIENTE, "rb");
    if(pClientes==NULL){return -1;}
    fseek(pClientes, 0, 2);
    tam=ftell(pClientes);
    fclose(pClientes);
    c=tam/sizeof(Cliente);
    return c;
}

int listarClientes(){//lista todo el registro siempre y cuando "estado" este en true
    Cliente registro;
    int pos=0;
    while(registro.leerDeDisco(pos++)){
        if(registro.GetEstado()){
            registro.mostrar();
            cout << endl;
        }
    }
    return pos;
}

int modificarMail(){//modifica el precio unitario de un articulo
    int dni, pos;
    bool modifico=false;
    Cliente cli;

    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;

    pos=buscarDNICliente(dni);
    if(pos<0){return -2;}


    if(!cli.leerDeDisco(pos)){return -3;}
    if(cli.GetEstado()==true){
        char mailNuevo[30];
        cout<<"INGRESE NUEVO MAIL: ";
        cin.ignore();
        cin.getline(mailNuevo, 30);
        cli.setEmail(mailNuevo);
        modifico=cli.modificarEnDisco(pos);
    }
    return modifico;
}

int eliminarCliente(){//cambia el estado de true a false
    int r;
    int dni, pos;
    bool modifico=false;
    Cliente cli;

    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;

    pos=buscarDNICliente(dni);
    if(pos<0){return -2;}

    if(!cli.leerDeDisco(pos)){return -3;}

    cout<<"ELIMINAR CLIENTE (Y/N)?";
    r=getch();
    if(r!=121 && r!=89){
        modifico = -1;
        return modifico;
    }
    cli.setEstado(false);
    modifico=cli.modificarEnDisco(pos);
    return modifico;
}

int altaCliente(){// cambia el estado de false a true
    int r;
    int dni, pos;
    Cliente cli;
    bool modifico=false;

    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;

    pos=buscarDNICliente(dni);
    if(pos<0){return -2;}

    if(!cli.leerDeDisco(pos)){return -3;}
    cout<<"DAR EL ALTA CLIENTE (Y/N)?" << endl;
    r=getch();
    if(r!=121 && r!=89){
        modifico = -1;
        return modifico;
    }
    cli.setEstado(true);
    modifico=cli.modificarEnDisco(pos);
    return modifico;
}

void seccionClientes(){
    int opc;
    do{
        int checkeo=0;
        opc=Menucliente();
        switch(opc){
        case 12:
            {
                int agregados=0;
                system("cls");
                agregados = agregarCliente();
                cout << agregados <<"CLIENTE/s CARGADO/s CON EXITO!"<<endl;
                break;
            }
        case 13:
            {
                system("cls");
                int dni;
                cout<<"INGRESE DNI DEL CLIENTE: "<<endl;
                cin>>dni;
                checkeo=mostrarClientePorDNI(dni);
                if(checkeo==-1){cout<<"El cliente esta dado de baja."<<endl;}
                if(checkeo==-2){cout<<"El cliente no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                system("pause");
                break;
            }
        case 14:
            {
                system("cls");
                int leyo;
                leyo=listarClientes();
                if (leyo==0){cout << "Error al leer el archivo" << endl;}
                system("pause");
                break;
            }
        case 15:
            {
                system("cls");
                checkeo=modificarMail();
                if(checkeo==-2){cout<<"El cliente no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Email modificado con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        case 16:
            {
                system("cls");
                checkeo=eliminarCliente();
                if(checkeo==-1){cout<<"El cliente no fue dado de baja."<<endl;}
                if(checkeo==-2){cout<<"El cliente no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Cliente dado de baja con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        case 17:
            {
                system("cls");
                checkeo=altaCliente();
                if(checkeo==-1){cout<<"El cliente no fue dado de alta."<<endl;}
                if(checkeo==-2){cout<<"El cliente no se encuentra registrado."<<endl;}
                if(checkeo==-3){cout<<"Error al leer el archivo."<<endl;}
                if(checkeo==1){cout<<"Cliente dado de alta con exito."<<endl;}
                if(checkeo==0){cout<<"Error al guardar los nuevos datos en el archivo."<<endl;}
                system("pause");
                break;
            }
        }
    }while(opc!=18);
}
///-------------------------------------------------------///






#endif // MENUCLIENTES_H_INCLUDED
