#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

///CLASE PERSONA
///-------------------------------------------------------///


class Persona{

protected:
    int Dni;
    char Nombre[25];
    char Apellido[25];
    char Email[30];
    char Telefono[20];
    Fecha FechaDeNacimiento;

public:

    Persona (const int D=0, const char *n="0000", const char *a="0000", const char *e="0000", const char* T="0000"){
        Dni=D;
        strcpy(Nombre, n);
        strcpy(Apellido, a);
        strcpy(Email, e);
        strcpy(Telefono, T);
    }

    void Cargar();
    void MostrarCliente();
    void MostrarVendedor();
    void MostrarVendedor(int);
    void mostrarCliente(int);

    void setNombre(const char *n){strcpy(Nombre, n);}
    void setApellido(const char *a){strcpy(Apellido, a);}
    void setEmail(const char* e){strcpy(Email, e);}
    void setDni(const int d){Dni=d;}
    void setTel(const char * T){strcpy(Telefono, T);}
    void setFechaDeNacimiento(Fecha f){FechaDeNacimiento=f;}


    int getDni() {return Dni;}
    char * getNombre() {return Nombre;}
    char * getApellido() {return Apellido;}
    char * getEmail() {return Email;}
    char * getTel() {return Telefono;}
    Fecha getFecha() {return FechaDeNacimiento;}

};

void Persona::Cargar(){
    bool vCli=false, vVen=false;
    cout << "DNI: ";
    cin >> Dni;
    vCli=verificarCliente(Dni);
    vVen=verificarVendedor(Dni);
    while(vCli==true || vVen==true){
        if (vCli){
            cout<<"EL DNI DEL CLIENTE YA SE ENCUENTRA REGISTRADO."<<endl;
            cout << "Ingrese un DNI valido: ";
            cin >> Dni;
        }
        if (vVen){
            cout<<"EL DNI DEL VENDEDOR YA SE ENCUENTRA REGISTRADO."<<endl;
            cout << "Ingrese un DNI valido: ";
            cin >> Dni;
        }
        vCli=verificarCliente(Dni);
        vVen=verificarVendedor(Dni);
    }
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(Nombre, 25);
    cout << "Apellido: ";
    cin.getline(Apellido, 25);
    cout << "Fecha de Nacimiento: ";
    FechaDeNacimiento.cargar();
    cout << "Email: ";
    cin.ignore();
    cin.getline(Email, 30);
    cout << "Telefono: ";
    cin.getline(Telefono, 20);

}

void Persona::MostrarCliente(){

    cout << "DNI: " << Dni << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "Fecha de Nacimiento: ";
    FechaDeNacimiento.mostrar();
    cout << endl;
    cout << "Email: " << Email << endl;
    cout << "Telefono: " << Telefono << endl;
}

void Persona::MostrarVendedor(){

    cout << "DNI: " << Dni << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "Fecha de Ingreso: ";
    FechaDeNacimiento.mostrar();
    cout << endl;
    cout << "Email: " << Email << endl;
    cout << "Telefono: " << Telefono << endl;
}

void Persona::MostrarVendedor(int y){

    cout << Dni;
    gotoxy(34,y);
    cout << Nombre;
    gotoxy(59,y);
    cout << Apellido;
    gotoxy(84,y);
    FechaDeNacimiento.mostrar();
    gotoxy(100,y);
    cout << Email;
    gotoxy(145,y);
    cout << Telefono<<endl;
}

void Persona::mostrarCliente(int y){
    gotoxy(4,y);
    cout << Dni;
    gotoxy(19,y);
    cout << Nombre;
    gotoxy(38,y);
    cout << Apellido;
    gotoxy(57,y);
    FechaDeNacimiento.mostrar();
    gotoxy(72,y);
    cout << Email;
    gotoxy(106,y);
    cout << Telefono<<endl;
}


///-------------------------------------------------------///
#endif // CLSPERSONA_H_INCLUDED
