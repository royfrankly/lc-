#include <iostream>
#include <cstring>
using namespace std;
struct nodo {
    char inf[20];
    nodo *izq,*der;
};
nodo *crear_a(nodo *);
void preorden(nodo *);
void inorden(nodo *);
void postorden(nodo *);
nodo *buscar(nodo *raiz, const char *dato);
int main(void){
    nodo *raiz=NULL;
    int op;
    char dato[30];
    do{
        system("cls");
        cout<<"\n\n\n MENU - ARBOLES BINARIOS\n";
        cout<<"****************************************\n\n";
        cout<<"1. CARGAR EL ARBOL\n\n";
        cout<<"2. RECORRIDO PREORDEN\n\n";
        cout<<"3. RECORRIDO INORDEN\n\n";
        cout<<"4. RECORRIDO POSTORDEN\n\n";
        cout<<"5. BUSCAR UN NODO\n\n";
        cout<<"6. S A L I R\n\n";
        cout<<"\t\t\tOPCION : ";
        cin>>op;
        system("cls");
        switch(op){
            case 1:
                raiz = crear_a(raiz);
                cout<<"\n\n";
                system("pause");
                break;
            case 2:
                cout<<"\n\nRECORRIDO PREORDEN: \n\n";
                preorden(raiz);
                cout<<"\n\n";
                system("pause");
                break;
            case 3:
                cout<<"\n\nRECORRIDO INORDEN: \n\n";
                inorden(raiz);
                cout<<"\n\n";
                system("pause");
                break;
            case 4:
                cout<<"\n\nRECORRIDO POSTORDEN: \n\n";
                postorden(raiz);
                cout<<"\n\n";
                system("pause");
                break;
            case 5:
                cout<<"\n\t busrcar nodo: \n\n";
                cout<<"ingrese el dato: ";
                cin>>dato;
                buscar(raiz,dato);
                cout<<"\n\n";
                system("pause");
                break;
        }
    }while(op<6);
    return 0;
}
nodo *crear_a(nodo *raiz){
    char op;
    nodo *q;
    if(raiz ==NULL)
        raiz = new nodo;
    cout<<"\n\nDATO : ";
    cin>>raiz->inf;
    cout<<"\n"<<raiz->inf<<" - TIENE RAMA IZQUIERDA(S/N): ";
    cin>>op;
    if(op=='s' || op=='S'){
        q = new nodo ;
        raiz->izq=q;
        crear_a(raiz->izq);
    }else{
        raiz->izq=NULL;
    }
    cout<<"\n"<<raiz->inf<<" - TIENE RAMA DERECHA(S/N): ";
    cin>>op;
    if(op=='s' || op=='S'){
        q = new nodo ;
        raiz->der=q;
        crear_a(raiz->der);
    }else{
        raiz->der=NULL;
    }
    return raiz;
}


void preorden(nodo *raiz){
    if(raiz!=NULL){
        cout<<"\n\n\t - "<<raiz->inf;
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}
void inorden(nodo *raiz){
    if(raiz!=NULL){
        inorden(raiz->izq);
        cout<<"\n\n\t - "<<raiz->inf;
        inorden(raiz->der);
    }
}
void postorden(nodo *raiz){
    if(raiz!=NULL){
        postorden(raiz->izq);
        postorden(raiz->der);
        cout<<"\n\n\t - "<<raiz->inf;
    }
}
/*
nodo *buscar(nodo *raiz, const char *dato) {
    if(raiz !=NULL){
        if (strcmp(dato, raiz->inf) < 0) {
            if(raiz->izq==NULL){
                cout<<"La informacion no se encuentra en el arbol"<<endl;
            }else{
                buscar(raiz->izq,dato);
            }
        }else if(strcmp(dato, raiz->inf) > 0){
            if(raiz->der==NULL){
                cout<<"La informacion no se encuentra en el arbol"<<endl;
            }else{
                buscar(raiz->der,dato);
            }
        }else{
            cout<<"la informacion eta en el arbol"<<endl;
        }
    return raiz;
    }
}
*/
nodo *buscar(nodo *raiz, const char *dato) {
    if (raiz == NULL) {
        cout << "La informacion no se encuentra en el arbol" << endl;
        return NULL;
    }

    if (strcmp(dato, raiz->inf) < 0) {
        return buscar(raiz->izq, dato);
    } else if (strcmp(dato, raiz->inf) > 0) {
        return buscar(raiz->der, dato);
    } else {
        cout << "La informacion esta en el arbol" << endl;
        return raiz;
    }
}