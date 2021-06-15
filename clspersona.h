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
    void Mostrar();

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

};

void Persona::Cargar(){

    cout << "DNI: ";
    cin >> Dni;
            while( buscarDNICliente(Dni) > -1){
        cout<<"EL DNI CLIENTE YA SE ENCUENTRA REGISTRADO."<<endl;
        cout << "Ingrese un DNI valido: ";
        cin >> Dni;
    }

   // setDni(Dni);

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

void Persona::Mostrar(){

    cout << "DNI: " << Dni << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Apellido: " << Apellido << endl;
    cout << "Fecha de Nacimiento: ";
    FechaDeNacimiento.mostrar();
    cout << endl;
    cout << "Email: " << Email << endl;
    cout << "Telefono: " << Telefono << endl;
}



///-------------------------------------------------------///
#endif // CLSPERSONA_H_INCLUDED
