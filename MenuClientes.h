#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED
///MENU CLIENTE
///-------------------------------------------------------///
bool verificarcliente(Cliente cli){
    int pos=0;
    Cliente aux;
    aux.setDni(cli.getDni());
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb");
    if(pCliente==NULL){return false;}
    while((cli.leerDeDisco(pos))==1){
        if(aux.getDni()==cli.getDni()){
           fclose(pCliente);
           return true;}
        pos++;
    }
    fclose(pCliente);
    return false;
}

bool agregarCliente(){//crea o agrega un registro cliente al final de los que esten echos
    Cliente cli;
    cli.cargar();
    if(verificarcliente(cli)){
        cout<<"CLIENTE YA EXISTE"<<endl;
        return false;
    }
    else{
        bool grabo=cli.grabarEnDisco();
        return grabo;
    }
}

int buscarCliente(int codigo){//recibe "id" del registro y devuelve la posicion donde se encuentra el registro
    Cliente cli;
    int pos=0;
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb");
    if(pCliente==NULL){return -1;}
    while((cli.leerDeDisco(pos))==1){
        if(cli.getDni()==codigo){
            fclose(pCliente);
            return pos;
        }
        pos++;
    }
    fclose(pCliente);
    return -2;
}

int BuscarClientporDNI(int dni){//busca articulo por id y lo muestra si "estado" esta en true
    Cliente cli;
    int pos=0;
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb");
    if(pCliente==NULL){return -1;}
    pos=buscarCliente(dni);
    if(pos<0){return -2;}
    cli.leerDeDisco(pos);
    if(cli.GetEstado()==true){cli.mostrar();}
    else{return -2;}
    fclose(pCliente);

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

bool listarClientes(){//lista todo el registro siempre y cuando "estado" este en true
    int cantReg,i;
    Cliente cli;
    cantReg=contarRegistrosClientes();
    for(i=0;i<cantReg;i++){
        cli.leerDeDisco(i);
        if(cli.GetEstado()){
            cli.mostrar();
            cout<<endl;
        }
    }
    return cantReg;
}

bool modificarMail(){//modifica el precio unitario de un articulo
    char mail[30];
    int dni,pos;
    Cliente cli;
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb");
    if(pCliente==NULL){return false;}
    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;
    pos=buscarCliente(dni);
    if(pos<0){
        fclose(pCliente);
        return false;
        }
    cli.leerDeDisco(pos);
    cli.mostrar();
    if(cli.GetEstado()==true){
        cout<<"INGRESE NUEVO MAIL: ";
        cin>>mail;
        cli.setEmail(mail);
        bool modifico=cli.modificarEnDisco(cli,pos);
        return modifico;
    }
    else{return false;}
}

bool eliminarCliente(){//cambia el estado de true a false
    bool nodisponible=false;
    char r;
    int dni;
    Cliente cli;
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb+");
    if(pCliente==NULL){return false;}
    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;
    int pos=buscarCliente(dni);
    if(pos<0){
            fclose(pCliente);
            return false;}
    cli.leerDeDisco(pos);
    cli.mostrar();
    cout<<"ELIMINAR CLIENTE (Y/N)?";
    cin>>r;
    if(r=='y'||r=='Y'){
            cli.leerDeDisco(pos);
            cli.setEstado(nodisponible);
            bool modifico=cli.modificarEnDisco(cli,pos);
            fclose(pCliente);
            return modifico;
    }
    else{return false;}
}

bool altaCliente(){// cambia el estado de false a true
    bool disponible=true;
    char r;
    int dni;
    Cliente cli;
    FILE *pCliente;
    pCliente=fopen(ARCHIVOCLIENTE,"rb+");
    if(pCliente==NULL){return false;}
    cout<<"INGRESE DNI DEL CLIENTE: ";
    cin>>dni;
    int pos=buscarCliente(dni);
    if(pos<0){
            fclose(pCliente);
            return false;}
            cli.leerDeDisco(pos);
            cli.mostrar();
            cout<<"DAR EL ALTA CLIENTE (Y/N)?";
            cin>>r;
    if(r=='y'||r=='Y'){
            cli.leerDeDisco(pos);
            cli.setEstado(disponible);
            bool modifico=cli.modificarEnDisco(cli,pos);
            fclose(pCliente);
            return modifico;
    }
    else{return false;}
}

void seccionClientes(){
    int opc;
    do{
        opc=Menucliente();
        switch(opc){
        case 12:
               char r;
               system("cls");
               do{
                system("cls");
               if(agregarCliente()==1){cout<<"CARGADO CON EXITO"<<endl;}
               cout<<"DESEA AGREGAR OTRO CLIENTE (y/n)?"<<endl;
               cin>>r;
               cin.ignore();
               }while(r=='y'||r=='Y');
            break;
        case 13:
                system("cls");
                int dni;
                cout<<"INGRESE DNI DEL CLIENTE: "<<endl;
                cin>>dni;
                if(BuscarClientporDNI(dni)==-2){cout<<"CLIENTE NO ENCONTRADO"<<endl;}
                system("pause");
            break;
        case 14:
                system("cls");
                if(listarClientes()==false){cout<<"ERROR AL LEER ARCHIVO CLIENTES"<<endl;}
                system("pause");
            break;
        case 15:
                system("cls");
                if(modificarMail()){cout<<"MODIFICADO CON EXITO"<<endl;}
                else{cout<<"ERROR AL MODIFICAR MAIL"<<endl;}
                system("pause");
            break;
        case 16:
                system("cls");
                if(eliminarCliente()){cout<<"CLIENTE ELIMINADO CON EXITO"<<endl;}
                else{cout<<"ERROR AL INTENTAR ELIMINAR CLIENTE"<<endl;}
                system("pause");
            break;
        case 17:
                system("cls");
                if(altaCliente()){cout<<"ALTA CLIENTE EXITOSA"<<endl;}
                else{cout<<"ERROR AL INTENTAR ALTA DE CLIENTE"<<endl;}
                system("pause");
            break;
        }
    }while(opc!=18);
}
///-------------------------------------------------------///





#endif // MENUCLIENTES_H_INCLUDED
