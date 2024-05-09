#include<iostream>
#include"funciones.h"
using namespace std;

int main(){
    char codigo[10];
    char nombre[20];
    nodo *p=NULL;
    int op;
    do{
        system("cls");
        cout<<"\nLISTAS ENLAZADAS";
        cout<<"\n=================";
        cout<<"\n\n1. CREAR POR EL INICIO";
        cout<<"\n\n2. CREAR POR EL FINAL";
        cout<<"\n\n3. INSERTAR AL INICIO";
        cout<<"\n\n4. INSERTAR AL FINAL";
        cout<<"\n\n5. INSERTAR ANTES DE";
        cout<<"\n\n6. INSERTAR DESPUES DE";
        cout<<"\n\n7. ELIMINAR EL PRIMER NODO";
        cout<<"\n\n8. ELIMINAR EL ULTIMO NODO";
        cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
        cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
        cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
        cout<<"\n\n12. M O S T R A R";
        cout<<"\n\n13. S A L I R ";
        cout<<"\n\n\t\t\t OPCION: ";
        cin>>op;
        switch(op){
            case 1:
                system("cls");
                p=NULL;
                p=crea_i(p);
                break;
            case 2:
                system("cls");
                p=NULL;
                p=crea_f(p);
                break;
            case 3:
                system("cls");
                p=inserta_i(p);
                break;
            case 4:
                system("cls");
                p=inserta_f(p);
                break;
            case 5:
                system("cls");
                cout<<"ESCRIBA DATO REFERENCIAL PARA INSERTARLO ANTES DE: ";
                cin>>nombre;
                p=inserta_ad(p,nombre);
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;

        }

        

    }while(op>0 and op<13);
    return 0;

}