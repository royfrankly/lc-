#include <iostream>
using namespace std;
void inserta_d(int *x, int &n, int max, int dato){
    if(n<max-1){
        n++;
        x[n]=dato;
    }else{
        cout<<"\n\n\t\t\tARRAY LLENO. NO SE PUEDE INSERTAR...\n\n\n";
        system("pause");
    } 
}
void elimina_d(int *x, int &n, int dato){
    int i,j,cen;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(x[i]==dato){
                cen=1;
                n--;
                for(j=i;j<=n;j++){
                    x[j]=x[j+1];
                }
            }else{
                i++;
            }
        }
        if(cen == 0)
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO\n\n";
    }else{
        cout<<"\n\n\t\t\tARRAY VACIO. NO SE PUEDE ELIMINAR...\n\n\n";
        system("pause");
    }
}
void modifica_d(int *x, int n, int dato){
    int i,cen;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(x[i]==dato){
                cen=1;
                cout<<"\n\n\t\tDATO A MODIFICAR : ";cin>>x[i];
            }else{
                i++;
            }
        }
        if(cen == 0){
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\nEL ARREGLO ESTA VACIO. NO SE PUEDE MODIFICAR...\n\n\n";
        system("pause");
    }
}
void mostrar(int *x, int n){
    int i;
    if(n>-1){
        for(i=0;i<=n;i++){
            cout<<"\n\t\tx["<<i+1<<"]: "<<x[i]<<"\n";
        }
    }else{
        cout<<"\n\n\t\t\tARRAY VACIO. NO SE PUEDE MOSTRAR...\n\n\n";
        system("pause");
    }
}
void inserta_o(int *x,int &n, int max, int dato){
    int i,j;
    if(n<max-1){
        n++;
        i=0;
        while((i<n)&&(dato>x[i])){
            i++;
        }
        for(j=n;j>i;j--){
            x[j]=x[j-1];
        }
        x[i]=dato;
    }else{
        cout<<"\n\n\t\t\tARRAY LLENO. NO SE PUEDE INSERTAR...\n\n\n";
        system("pause");
    }
}
void elimina_o(int *x, int &n, int dato){
    int i,j,cen;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(x[i]==dato){
                cen=1;
                n--;
                for(j=i;j<=n;j++){
                    x[j]=x[j+1];
                }
            }else{
                i++;
            }
        }
        if(cen == 0){
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\n\t\t\tARRAY VACIO. NO SE PUEDE ELIMINAR...\n\n\n";
        system("pause");
    }

}
void modifica_o(int *x, int &n, int dato){
    int i,cen;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(x[i]==dato){
                cen=1;
                cout<<"\n\n\t\tDATO A MODIFICAR : ";cin>>x[i];
                i=0;
                while((i<n)&&(x[i]<x[i+1])){
                    i++;
                }
                if(i<n){
                    dato=x[i];
                    i++;
                    while((i<=n)&&(dato>x[i])){
                        x[i-1]=x[i];
                        i++;
                    }
                    x[i-1]=dato;
                }
            }else{
                i++;
            }
        }
        if(cen == 0){
            cout<<"\n\n\t\t"<<dato<<"NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\nEL ARREGLO ESTA VACIO. NO SE PUEDE MODIFICAR...\n\n\n";
        system("pause");
    }
}
int busca(int *x,int n, int dato){
    int i, pos;
    i=0;
    while((i<=n)&&(x[i]!=dato)){
        i++;
    }
    if((i>=n)&&(x[i]!=dato)){
        pos=-1;
    }else{
        pos=i;
    }
    return pos;
}