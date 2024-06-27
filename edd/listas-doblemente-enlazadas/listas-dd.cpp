#include <iostream>
#include <string.h>
using namespace std;
struct nodo{
    char nomb[20];
    nodo *ant, *sig;
};
void creard_i(nodo *&,nodo *&);
void creard_f(nodo *&,nodo *&);
void recorre(nodo *);
void insertad_i(nodo *&,nodo *&);
void insertad_f(nodo *&,nodo *&);
void insertad_ad(nodo *&,char *);
void insertad_dd(nodo *&,char *);
void eliminard_p(nodo *&,nodo *&);
void eliminard_u(nodo *&,nodo *&);
void eliminard_x(nodo *&,nodo *&,char *);
void eliminar_ad(nodo *&,char *);
void eliminar_dd(nodo *&,char *);

int main(){
    char codigo[10];
    nodo *p=NULL, *f=NULL;
    int op;
    char ref[40];
    do{
        system("cls");
        cout<<"\nLISTAS ENLAZADAS";
        cout<<"\n==============================";
        cout<<"\n\n1. CREAR POR EL INICIO";
        cout<<"\n\n2. CREAR POR EL FINAL";
        cout<<"\n\n3. INSERTAR AL INICIO";
        cout<<"\n\n4. INSERTAR AL FINAL ";
        cout<<"\n\n5. INSERTAR ANTES DE ";
        cout<<"\n\n6. INSERTAR DESPUES DE ";
        cout<<"\n\n7. ELIMINAR EL PRIMER NODO ";
        cout<<"\n\n8. ELIMINAR EL ULTIMO NODO ";
        cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO ";
        cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
        cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
        cout<<"\n\n12. M O S T R A R ";
        cout<<"\n\n13. S A L I R";
        cout<<"\n\n\t\t\t OPCION:  ";
        cin>>op;
        switch(op){
            case 1:
                system("cls");
                creard_i(p,f);
                break;
            case 2:
                system("cls");
                creard_f(p,f);
                break;
            case 3:
                system("cls");
                insertad_i(p,f);
                break;
            case 4:
                system("cls");
                insertad_f(p,f);//copiado hasta aca
                break;
            case 5:
                system("cls");
                cout<<"Ingrese el referencial"<<endl;
                cin>>ref;
                insertad_ad(p,ref);
                break;
            case 6:
                system("cls");
                cout<<"Ingrese el referencial"<<endl;
                cin>>ref;
                insertad_dd(p,ref);
                break;
            case 7:
                system("cls");
                eliminard_p(p,f);
                break;
            case 8:
                system("cls");
                eliminard_u(p,f);
                break;
            case 9:
                system("cls");
                cout<<"Ingrese el referencial"<<endl;
                cin>>ref;
                eliminard_x(p,f,ref);
                break;
            case 10:
                system("cls");
                cout<<"Ingrese el referencial"<<endl;
                cin>>ref;
                eliminar_ad(p,ref);
                break;
            case 11:
                system("cls");
                eliminar_dd(p,ref);
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;
            case 13:
                break;
        }
    }while(op>0&&op<13);
    return 0;
}

void creard_i(nodo *&p,nodo *&f){
    nodo *q;
    char op;
    p=NULL;
    f=NULL;
    do{
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL INICIO...";
        q = new nodo;
        cout<<"\n\nNOMBRE:  ";
        cin>>q->nomb;
        q->ant=NULL;
        q->sig=p;
        if(p==NULL){
            f=q;
        }else{
            p->ant=q;
        }
        p=q;
        cout<<"\n\n\t\t\t MAS DATOS(S/N)? ";
        cin>>op;
    }while(op=='s' || op == 'S');
}
void creard_f(nodo *&p,nodo *&f){
    nodo *q,*r;
    char op;
    p=NULL;
    f=NULL;
    do{
        system("cls");
        cout<<"\n\nCREANDO LISTA POR EL FINAL...";
        q = new nodo;
        cout<<"\n\nNOMBRE:  ";
        cin>>q->nomb;
        q->sig=NULL;
        q->ant=f;
        if(p==NULL){
            p=q;
        }else{
            f->sig=q;
        }
        f=q;
        cout<<"\n\n\t\t\t MAS DATOS(S/N)? ";
        cin>>op;
    }while(op=='s' || op == 'S');
}
void recorre(nodo *p){
    nodo *q;
    system("cls");
    q=p;
    cout<<"\n\n\tLISTA DE DATOS:\n";
    cout<<"\t======================";
    while(q!=NULL){
        cout<<"\n\n\t\t\t"<<q->nomb;
        q=q->sig;
    }
    cout<<"\n\n\t\t\t";
}
void insertad_i(nodo *&p,nodo *&f){
    nodo *q;
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL INICIO...";
    q=new nodo;
    cout<<"\n\n NOMBRE :  ";
    cin>>q->nomb;
    q->sig=p;
    q->ant =NULL;
    if(p==NULL){
        f=q;
    }else{
        p->ant=q;
    }
    p=q;

}
void insertad_f(nodo *&p,nodo *&f){
    nodo *q,*r;
    system("cls");
    cout<<"\n\nINSERTANDO DATO POR EL FINAL...";
    q=new nodo;
    cout<<"\n\n NOMBRE :  ";
    cin>>q->nomb;
    q->ant=f;
    q->sig=NULL;
    if(p==NULL){
        p=q;
    }else{
        f->sig=q;
    }
    f=q;
}
void insertad_ad(nodo *&p,char *ref){
    if(p!=NULL){
        int cen;
        nodo *q,*x,*r;
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 && cen==0){
            if(q->sig!=NULL){
                q=q->sig;
            }else{
                cen =1;
            }
        }
        if(cen==0){
            x = new nodo;
            cout<<"Ingrese el nuevo objeto: ";
            cin>>x->nomb;
            x->sig=q;
            r=q->ant;
            x->ant=r;
            q->ant =x;
            if(p==q){
                p=q;
            }else{
                r->sig=x;
            }
        }else{
            cout<<"No existe el dato de referencia"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void insertad_dd(nodo *&f,char *ref){
    if(f!=NULL){
        int cen;
        nodo *q,*x,*r;
        q=f;
        cen=0;
        while(strcmp(q->nomb,ref)!=0 && cen==0){
            if(q->ant!=NULL){
                q=q->ant;
            }else{
                cen =1;
            }
        }
        if(cen==0){
            x = new nodo;
            cout<<"Ingrese el nuevo objeto: ";
            cin>>x->nomb;
            x->ant=q;
            r=q->sig;
            x->sig=r;
            q->sig =x;
            if(f==q){
                f=q;
            }else{
                r->ant=x;
            }
        }else{
            cout<<"No existe el dato de referencia"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void eliminard_p(nodo *&p,nodo *&f){
    if(p!=NULL){
        nodo *q;
        q=p;
        p=p->sig;
        if(q==f){
            f=NULL;
        }else{
            p->ant = NULL;
        }
        delete q;
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void eliminard_u(nodo *&p,nodo *&f){
    if(p!=NULL){
        nodo *q,*r;
        q=f;
        r=f->ant;
        if(p==q){
            p=NULL;
        }else{
            p->sig = NULL;
        }
        delete q;
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void eliminard_x(nodo *&p,nodo *&f,char *x){
    if(p!=NULL){
        nodo *q,*r,*s;
        int cen;
        q=p;
        cen=0;
        while(strcmp(q->nomb,x) && cen == 0){
            if(q->sig != NULL){
                q=q->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            if(p==f){
                p=NULL;
                f=NULL;
            }else{
                if(p==q){
                    p=p->sig;
                    p->ant=NULL;
                }else{
                    if(q==f){
                        f=f->ant;
                        f->sig=NULL;
                    }else{
                        r=q->ant;
                        s=q->sig;
                        r->sig=s;
                        s->ant=r;
                    }
                }
            }
            delete q;
        }else{
            cout<<"El nodo referencias no existe"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void eliminar_ad(nodo *&p,char *ref){
    if(p!=NULL){
        nodo *q,*r,*s;
        int cen;
        q=p;
        cen=0;
        while(strcmp(q->nomb,ref) && cen == 0){
            if(q->sig != NULL){
                q=q->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            if(p==q){
                cout<<"No existe el nodo anterior a "<<ref<<endl;
            }else{
                r=q->ant;
                if(p==q){
                    p=p->sig;
                    p->ant=NULL;
                }else{
                    if(q==r){
                        p=q;
                        p->ant=NULL;
                    }else{
                        s=r->ant;
                        s->sig=q;
                        q->ant=s;
                    }
                    delete r;
                }
            }
        }else{
            cout<<"El nodo referencias no existe"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
void eliminar_dd(nodo *&f,char *ref){
    if(f!=NULL){
        nodo *q,*r,*s;
        int cen;
        q=f;
        cen=0;
        while(strcmp(q->nomb,ref) && cen == 0){
            if(q->ant != NULL){
                q=q->ant;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            if(f==q){
                cout<<"No existe el nodo despues de "<<ref<<endl;
            }else{
                r=q->sig;
                s=r->sig;
                q->sig=s;
                if(r==f){
                    r=q;
                }else{
                    s->ant = q;
                    delete r;
                }
            }
        }else{
            cout<<"El nodo referencias no existe"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}
