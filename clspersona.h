#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
///CLASE PERSONA
///-------------------------------------------------------///

class Persona{

protected:
    int Dni;
    Cadena Nombre;
    Cadena Apellido;
    Cadena Email;
    int Telefono;
    Fecha FechaDeNacimiento;

public:

    Persona (const int D=0, const char *n="0000", const char *a="0000", const char *e="0000", const int T=0){
    Dni=D;
    Nombre=n;
    Apellido=a;
    Email=e;
    Telefono=T;
    }


void Cargar();
void Mostrar();

void setNombre(const char *n){Nombre=n;}
void setApellido(const char *a){Apellido=a;}
void setEmail(const char *e){Email=e;}
void setDni(const int d){Dni=d;}
void setTel(const int t){Telefono=t;}
void setFechaDeNacimiento(Fecha f){FechaDeNacimiento=f;}


int getDni() {return Dni;}
void getNombre() {Nombre.Mostrar();}
void getApellido() {Apellido.Mostrar();}
void getEmail() {Email.Mostrar();}    ///DA ERROR
int getTel() {return Telefono;}

};



void Persona::Cargar(){
char x[30];
int y;

cout << "DNI: ";
cin >> Dni;
cout << endl;
cout << "Nombre: ";
cin.ignore();
cin.getline(x, 30);
Nombre=x;
cout << endl;
cout << "Apellido: ";
cin.getline(x, 30);
Apellido=x;
cout << endl;
cout << "Email: ";
cin.getline(x, 30);
Email=x;
cout << endl;
cout << "Fecha de Nacimiento: ";
FechaDeNacimiento.cargar();
cout << "Telefono: ";
cin >> Telefono;
cout << endl;


}

void Persona::Mostrar(){

cout << "DNI: " << Dni << endl;

cout << "Nombre: ";
Nombre.Mostrar();
cout << endl;

cout << "Apellido: ";
Apellido.Mostrar();
cout << endl;

cout << "Email: ";
Email.Mostrar();
cout << endl;

cout << "Telefono: " << Telefono << endl;

}



///-------------------------------------------------------///
#endif // CLSPERSONA_H_INCLUDED
