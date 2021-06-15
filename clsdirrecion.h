#ifndef CLSDIRRECION_H_INCLUDED
#define CLSDIRRECION_H_INCLUDED
///CLASE DIRECCION
///-------------------------------------------------------///
class Direccion{
private:
    Cadena Calle;
    int Numero;
    Cadena Localidad;
public:
    Direccion(int n=0){

        Numero=n;
    }
      //sets
      void setCalle(char *d){Calle=d;}
      void setNumero(int d){Numero=d;}
      void setLocalidad(char *d){Localidad=d;}
      //gets
      Cadena getCalle(){return Calle;}
      int getNumero(){return Numero;}
      Cadena getLocalidad(){return Localidad;}
      //metodos
      void cargar();
      void Mostrar();
};
///METODOS
void Direccion::cargar(){
    char palabra[30];
    cout<<"DIRECCION: "<<endl;
    cout<<"CALLE : "<<endl;
    cin.ignore();
    cin.getline(palabra, 30);
    Calle=palabra;
    cout<<"NUMERACION: "<<endl;
    cin>>Numero;
    cout<<"LOCALIDAD: "<<endl;
    cin.ignore();
    cin.getline(palabra, 30);
    Localidad=palabra;
}
void Direccion::Mostrar(){
    cout<<"DIRECCION: "<<endl;
    cout<<"CALLE: ";
    Calle.Mostrar();
    cout<<" Num: "<<Numero<<" LOCALIDAD: ";
    Localidad.Mostrar();
    cout << endl;
}


///-------------------------------------------------------///
#endif // CLSDIRRECION_H_INCLUDED
