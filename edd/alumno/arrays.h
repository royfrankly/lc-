#include <iostream>
using namespace std;
void intercambiar(int &dato1, int &dato2){
    int aux= dato1;dato1=dato2;dato2=aux;
}
void inserta_d(int *x,int &n,int max,int dato){
    if(n<max-1){
        n++;
        x[n]=dato;
    }else{
        cout<<"\n\n\t\t\tARREGLO LLENO, NO SE PUEDE INSERTAR...\n\n\n";
        system("pause");
    }
}
void elimina_d(int *x, int &n, int dato){
    int i,j,cen;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=0 && cen==0){
            if(x[i]==dato){
                cen=1;
                n--;
                for(j=i;j<=n;j++)
                    x[j]=x[j+1];
            }else
                i++;
        }
        if(cen==0){
            cout<<"\n\n\t\t"<<dato<<" NO ESTA EN EL ARREGLO\n\n";
            system("pause");

        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
        system("pause");
    }
}
void modifica_d(int *x, int n, int dato){
    int i,cen;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n && cen==0){
            if(x[i]==dato){
                cen = 1;
                cout<<"\n\n\t DATO QUE MODIFICA : ";
                cin>>x[i];
            }else{
                i++;
            }
        }
        if(cen == 0){
            cout<<"\n\n\n\t\t"<<dato<<" NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
        system("pause");
    }
}
void mostrar(int *x, int n){
    int i;
    if(n>-1){
        for(i=0;i<=n;i++){
            cout<<"\nx["<<i<<"] = "<<x[i];
        }
        cout<<"\n\n";
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO... \n\n\n";
    }
    
}
int buscar(int x[], int n, int dato){
    int i=0,pos;
    while(i<=n && x[i]<dato){
        i++;
    }
    if(i>n || x[i]>dato)
        pos = -i;
    else    
        pos = i;
    return pos;
}   
void inserta_o(int *x, int &n,int max, int dato){
    if(n<max-1){
        int pos=buscar(x,n,dato);
        if(pos<=0){
            pos=-pos;
            n++;
            for(int i=n;i>pos+1;i--){
                x[i]= x[i-1];
            }
            x[pos]=dato;
        }
    }else{
        cout<<"El arreglo, esta lleno"<<endl;
        system("pause");
    }
}
void elimina_o(int *x, int n, int dato){
    if(n>0){
        int pos = buscar(x,n,dato);
        if(pos>0){
            n--;
            for(int i=pos;i<n;i++)
                x[i]=x[i+1];
        }else{
            cout<<"el dato a eliminar, no existe"<<endl;
           system("pause");

        }
    }else{
        cout<<"el arreglo esta vacio"<<endl;
        system("pause");
    }
}
void modifica_o(int *x, int n, int dato1, int dato2){
    int i,cen;           
    if(n>-1){
        int pos = buscar(x,n,dato1);
        while(pos>=0 && pos <=n){
            if(x[pos-1]<dato2){
                if(dato2<x[pos+1]){
                    cout<<"el dato se modifico :)"<<endl;
                    system("pause");
                    break;
                }else{
                    intercambiar(x[pos+1],dato2);
                }
            }else{
                intercambiar(x[pos-1],dato2);
            }
        }
    }else{
        cout<<"Arreglo , vacio\n";
        system("pause");
    }
}