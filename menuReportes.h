#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void imprimiPedido(){
    Pedido obj;
    int pos=0;

    while(obj.leerDeDisco(pos++)){
        obj.mostrar();
    }
}

void seccionReportes(){

    int opc;
    do{
        opc=menuReportes();
        switch(opc){
            case 12:
                system("cls");
                imprimiPedido();
                system("pause");
                break;
            case 13:

                break;
            case 14:
                system("cls");

                break;
            case 15:
                system("cls");

                break;
            case 16:
                system("cls");

                break;
            case 17:
                system("cls");

                break;
            case 18:
                system("cls");

                break;
            case 19:
                system("cls");

                break;
            case 20:
                system("cls");

                break;
        }
    }while(opc!=21);
}

#endif // MENUREPORTES_H_INCLUDED
