#include<iostream>
#include<string.h>
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
        while(strcmp(r->nomb,ref)!=0 and cen==0){
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
nodo *inserta_dd(nodo *p, char ref[]){
    nodo *q, *r;
    int cen;
    if(p!=NULL){
        r=p;
        cen=0;
        while(strcmp(r->nomb,ref)!=0 and cen==0){           //r->nomb!=ref
            if(r->sig!=NULL){
                r=r->sig;
            }
            else
                cen=1;
        }
        if(cen==0){
            q=new(nodo);
            cout<<"ESCRIBA EL DATO A INSERTAR DESPUES DEL DATO REFERENCIAL: ";
            cin>>q->nomb;
            q->sig=r->sig;
            r->sig=q;
        }
        else cout<<"EL DATO REFERENCIAL NO SE ENCONTRO";   
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
    
}
nodo *elimina_p(nodo *p){
    nodo *q;
    if(p!=NULL){
        q=p;
        p=p->sig;
        delete(q);
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
}
nodo *elimina_u(nodo *p){
    nodo *q, *r;
    if(p!=NULL){
        q=p;
        if(p->sig==NULL){
            p=NULL;
        }
        else{
            while(q->sig!=NULL){
                r=q;
                q=q->sig;
            }
            r->sig=NULL;
        }
        delete(q); 
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
}
nodo *elimina_x(nodo *p, char x[]){
    nodo *q, *r;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while(strcmp(q->nomb,x)!=0 and cen==0){
            if(q->sig!=NULL){
                r=q;
                q=q->sig;
            }
            else 
                cen=1;
        }
        if(cen==0){
            if(p==q)
                p=p->sig;
            else
                r->sig=q->sig;
            delete(q);
        }
        else cout<<"EL NODO X NO EXISTE";
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
}
nodo *elimina_ad(nodo *p, char ref[]){
    nodo *q, *r, *t;
    int cen;
    if(p!=NULL){
        if(p->nomb==ref){
            cout<<"NO HAY NODO ANTERIOR AL REFERENCIAL";
        }
        else{
            q=p;
            r=q;
            cen=0;
            while(strcmp(q->nomb,ref)!=0 and cen==0){
                if(q->sig!=NULL){
                    t=r;
                    r=q;
                    q=q->sig;
                }
                else
                    cen=1;
            }
            if(cen==0){
                if(p->sig==q)
                    p=q;
                else
                    t->sig=q;
                delete(r);
            }
            cout<<"EL NODO REFERENCIAL NO EXISTE";
        }
    }
    else cout<<"LA LISTA ESTA VACIA";
    return (p);
}
nodo *elimina_dd(nodo *p, char ref[]){
    nodo *q, *r;
    int cen;
    if(p!=NULL){
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 and cen==0){
            if(q->sig!=NULL){
                q=q->sig;
            }
            else{
                cen=1;
            }
        }
        if(cen==0){
            if(q->sig==NULL){
                cout<<"NO HAY UN NODO DESPUES DEL REFERENCIAL";
            }
            else{
                r=q->sig;
                q->sig=r->sig;
                delete(r);
            }
        }
        else cout<<"NO EXISTE EL NODO REFERENCIAL";
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
