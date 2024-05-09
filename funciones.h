#include<iostream>
using namespace std;
struct nodo{
    char nomb[20];
    nodo *sig;
};

nodo *crea_i(nodo *p){
    nodo *q;
    char op;
    do{
        system("cls");
        q=new(nodo);
        cout<<"\n\nNOMBRE: ";
        cin>>q->nomb;
        q->sig=p;
        p=q;
        cout<<"\n\n\t\tMAS DATOS (S/N)? ";
        cin>>op;
    }while(op=='s' or op=='S');
    return (p);
}
nodo *crea_f(nodo *p){
    nodo *q, *r;
    char op;
    do{
        system("cls");
        q=new(nodo);
        cout<<"\n\nNOMBRE: ";
        cin>>q->nomb;
        q->sig=NULL;
        if(p==NULL)
            p=q;
        else{
            r->sig=q;
        }
        r=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)? ";
        cin>>op;
    }while(op=='s' or op=='S');
    return (p);
}
nodo *inserta_i(nodo *p){
    nodo *q;
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL INICIO ...";
    q=new(nodo);
    cout<<"\n\nNOMBRE: ";
    cin>>q->nomb;
    q->sig=p;
    p=q;
    return (p);
}
nodo *inserta_f(nodo *p){
    nodo *q, *r;
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL FINAL ...";
    q=new(nodo);
    cout<<"\n\nNOMBRE : ";
    cin>>q->nomb;
    q->sig=NULL;
    r=p;
    if(p==NULL)
        p=q;
    else{
        while(r->sig!=NULL){
            r=r->sig;    
        }
        r->sig=q;
    }
    return (p);
}
nodo *inserta_ad(nodo *p, char ref[]){
    nodo *q, *r, *t;
    int cen;
    if(p!=NULL){
        r=p;
        cen=0;
        while(r->nomb!=ref and cen==0){
            if(r->sig!=NULL){
                t=r;
                r=r->sig;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            q=new(nodo);
            cout<<"ESCRIBA EL DATO A INSERTAR ANTES DEL DATO REFERENCIAL: ";
            cin>>q->nomb;
            q->sig=r;
            if(p==r){
                p=q;
            }
            else{
                t->sig=q;
            }
        }
        else cout<<"EL DATO REFERENCIAL NO EXISTE: ";
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
}
void recorre(nodo *p){
    nodo *q;
    system("cls");
    q=p;
    cout<<"\n\n\tLISTA DE DATOS:\n";
    cout<<"\t================";
    while(q!=NULL){
        cout<<"\n\n\t\t"<<q->nomb;
        q=q->sig;
    }
    cout<<"\n\n\t\t\t";
}
