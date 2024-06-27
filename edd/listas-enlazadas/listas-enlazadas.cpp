#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
struct nodo{
    char nomb[26];
    nodo *sig;

};
nodo *crea_i(nodo *);
nodo *crea_f(nodo *);
void recorre(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
nodo *inserta_ad(nodo *,char *);
nodo *inserta_dd(nodo *,char *);
nodo *eliminar_p(nodo *);
nodo *eliminar_u(nodo *);
nodo *eliminar_x(nodo *,char *);
nodo *eliminar_ad(nodo*, char *);
nodo *eliminar_dd(nodo*, char *);
int main(){
    char codigo[10];
    nodo *p=NULL;
    int op;
    char ref[100];
    do{
        system("cls");
        cout<<"\nLISTAS ENLAZADAS";
        cout<<"\n===============";
        cout<<"\n\n1. CREAR POR EL INICIO";
        cout<<"\n\n2. CREAR POR EL FINAL";
        cout<<"\n\n3. INSERTAR AL INICIO";
        cout<<"\n\n4. INSERTAR AL FINAL";
        cout<<"\n\n5. INSERTAR ANTES DE";
        cout<<"\n\n6. INSERTAR DESPUES DE";
        cout<<"\n\n7. ELIMINA EL PRIMER NODO";
        cout<<"\n\n8. ELIMINAR EL ULTIMO NODO" ;
        cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
        cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A ";
        cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A ";
        cout<<"\n\n12. MOSTRAR";
        cout<<"\n\n13. SALIR";
        cout<<"\n\n\t\t\t OPCION:  ";
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
                cout<<"Digite el nombre del referente: ";
                cin>>ref;
                p=inserta_ad(p,ref);
                system("pause");
                break;
            case 6:
                system("cls");
                cout<<"Digite el nombre del referente: ";cin>>ref;
                p=inserta_dd(p,ref);
                system("pause");
                break;
            case 7:
                system("cls");
                p=eliminar_p(p);
                system("pause");
                break;
            case 8:
                system("cls");
                p=eliminar_u(p);
                system("pause");
                break;
            case 9:
                system("cls");
                cout<<"Digite el nombre del referente: ";cin>>ref;
                p=eliminar_x(p, ref);
                system("pause");
                break;
            case 10:
                system("cls");
                cout<<"Digite el nombre del referente:";
                cin>>ref;
                p=eliminar_ad(p,ref);
                system("pause");
                break;
            case 11:
                system("cls");
                cout<<"Digite el nombre del referente:";
                cin>>ref;
                p=eliminar_dd(p,ref);
                system("pause");
                
                
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;
            case 13:
                    break;
                    
       }
    }while(op>0 && op<14);
    return 0;
}
//)=====================funciones======================
nodo *crea_i(nodo *p){
    nodo *q;
    char op;
    do{
        system("cls");
        q=new(nodo) ;
        cout<<"\n\nNOMBRE  : ";
        cin>>q->nomb;
        q->sig=p;
        p=q;
        cout<< "\n\n\t\tMAS DATOS (S/N)?  ";
        cin>>op;
    }while(op=='s' || op=='S');      
    return(p);
}
nodo *crea_f(nodo *p){
    nodo *q,*r;
    char op;
    do{
        q=new nodo;
        cout<<"\n\nNOMBRE  :  ";
        cin>>q->nomb;
        q->sig=NULL;
        if(p==NULL)
            p=q;
        else{
            r->sig=q;
        }
        r=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)?  ";
        cin>>op;
    }while(op=='s' || op=='S');
    return p;
}
void recorre(nodo *p){
    nodo *q;
    system("cls");
    q=p;
    cout<<"\n\n\tLISTAS DE DATOS: \n";
    cout<<"\t==============)";
    while(q!=NULL){
        cout<<"\n\n\t\t"<<q->nomb;
        q=q->sig;
    }
    cout<<"\n\n\t\t\t";
}
nodo *inserta_i(nodo *p){
    nodo *q;
    system("cls");
    cout<<"\n\nINSERTA DATO POR EL INICIO ... ";
    q=new nodo;
    cout<<"\n\nNOMBRE  : ";
    cin>>q->nomb;
    q->sig=p;
    p=q;
    return p;
}
nodo *inserta_f(nodo *p){
    nodo *q,*r;
    system("cls");
    cout<<"\n\nINSERTA DATO POR EL FINAL ... ";
    q=new nodo;
    cout<<"\n\nNOMBRE  : ";
    cin>>q->nomb;
    q->sig=NULL;
    r=p;
    if(p==NULL){
        p=q;
    }else{
        while(r->sig!=NULL){
            r=r->sig;
        }
        r->sig=q;
    }
    return p;
}
nodo *inserta_ad(nodo *p,char *ref){
    if(p!=NULL){
        nodo *q,*r,*t;
        r=p;
        int cen=0;
        while(strcmp(r->nomb,ref)!=0 && cen==0){
            if(r->sig !=NULL){
                t=r;
                r=r->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            q = new nodo;
            cout<<"Ingrese el nuevo nombre: ";
            cin>>q->nomb;
            q->sig=r;
            if(p==r){
                p=q;
               cout<<"pasa1"<<endl;

            }else{
                t->sig=q;
                cout<<"pasa2"<<endl;
            }
        }else{
                cout<<"El dato no existe"<<endl;
        }
    }else{
        cout<<"Listas Vacia"<<endl;
    }
    return p;
}
nodo *inserta_dd(nodo *p,char *ref){
    if(p!=NULL){
        nodo *r=p;
        int cen =0;
        while(strcmp(r->nomb,ref)!=0 && cen==0){
            if(r->sig!=NULL){
                r= r->sig;
            }else{
                cen =1;
            }
        }
        if(cen==0){
            nodo *q = new nodo;
            cout<<"Ingrese el nuevo nombre:"<<endl;
            cin>>q->nomb;
            q->sig=r->sig;
            r->sig=q;
        }else{
            cout<<"El dato referencias no se encuentra"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}
nodo *eliminar_p(nodo *p){
    if(p!=NULL){
        nodo *q=p;
        p=p->sig;
        delete q;
        cout<<"Eliminado"<<endl;
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}
nodo *eliminar_u(nodo *p){
    if(p!=NULL){
        nodo *q=p;
        nodo *r;
        if(p->sig == NULL ){
            p=NULL;
            cout<<"Eliminado, lista vacia"<<endl;
        }else{
            while(q->sig!=NULL){
                r=q;
                q=q->sig;
            }
            r->sig=NULL;
            cout<<"Eliminado"<<endl;
        }
        delete q;
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}
nodo *eliminar_x(nodo *p,char *x){
    if(p!=NULL){
        nodo *q=p;
        nodo *r;
        int cen =0;
        while(strcmp(q->nomb,x) && cen==0){
            if(q->sig != NULL){
                r=q;
                q=q->sig;
            }else{
                cen =1;
            }
        }
        if(cen==0){
            if(p==q){
                p=p->sig;
            }else{
                r->sig=q->sig;
            }
            delete q;
        }else{
            cout<<"El nodo no existe"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}

nodo *eliminar_ad(nodo*p, char *ref){
    if(p!=NULL){
        if(strcmp(p->nomb,ref)==0){
            cout<<"No hay un nodo anterior al referente"<<endl;
        }else{
            
            nodo *q=p;
            nodo *r=q;
            nodo *t;
            int cen=0;
            while(strcmp(q->nomb,ref)!=0 && cen ==0){
                if(q->sig != NULL){
                    t = r;
                    r=q;
                    q=q->sig;
                }else{
                    cen=1;
                }
            }
            if(cen==0){
                if(p->sig ==q){
                    p=q;
                }else{
                    t->sig=q;
                }
                delete r;
            }else{
                cout<<"El referencial nodo no existe"<<endl;
            }
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}
nodo *eliminar_dd(nodo*p, char *ref){
    if(p != NULL){
        nodo *q=p;
        nodo *r;
        int cen =0;
        while(strcmp(q->nomb,ref)!=0 && cen ==0){
            if(q->sig!=NULL){
                q=q->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            if(q->sig==NULL){
                cout<<"no hay nodo despues del referencial"<<endl;
            }else{
                r=q->sig;
                q->sig=r->sig;
                delete r;
            }
        }else{
            cout<<"No existe el nodo referencial"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return p;
}

