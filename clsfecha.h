#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
///CLASE FECHA
///-------------------------------------------------------///
class Fecha{
private:
    int dia,mes,anio;
public:
    ///constructor
    Fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes=m;
        anio=a;
    }
    void cargar();
    void mostrar();
    ///sets
    void setdia(int d){if (d>0||d<=31){dia=d;}}
    void setmes(int d){if(d<12||d>1){mes=d;}}
    void setanio(int d){if(d>1900){anio=d;}}
    ///gets
    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}
    bool verificar();
};

///FUNCIONES FECHA
bool Fecha::verificar(){
    int diasMeses[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(anio==0 || anio<1900 ){return false;}
    if(mes <=0 || mes>12){return false;}
    if(dia<=0 || dia>31){return false;}
    if(mes==2 && dia > 29){return false;}
    if(dia>diasMeses[mes-1]){return false;}
    if(anio==0){return false;}
    if ( !((anio%4==0)||(anio%400==0 && anio%100!=0)) && dia==29 && mes==2){return false;}

    return true;
}
void Fecha::cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    while(!verificar()){
        cout << "Ingrese una fecha validad por favor!" << endl;
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }

}

void Fecha::mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
///-------------------------------------------------------///

#endif // CLSFECHA_H_INCLUDED
