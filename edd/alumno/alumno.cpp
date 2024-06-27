#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;
struct alumno{
    char codi[11],nomb[20];
    float nota1,nota2,prom;
};
void inserta_d(alumno *,int &);
void elimina_d(alumno *,int &);
void modifica_d(alumno *,int &);
void buscar_o(alumno *,int );
void inserta_o(alumno *,int &);
void elimina_o(alumno *,int &);
void modifica_o(alumno *,int &);
void mostrar(alumno *,int );
int main (){
    alumno x[MAX];
    int op,opc,n=-1,i;
    do{
        system("cls");
        cout<<"\nM E N U";
        cout<<"\n===========";
        cout<<"\n\n1. ARRAY DESORDENADOS...";
        cout<<"\n\n2. ARRAY ORDENADOS...";
        cout<<"\n\n3. S A  I R";
        cout<<"\n\n\t\t\t OPCION: ";
        cin>>op;
        switch(op){
            case 1:
                do{
                    system("cls");
                    cout<<"\n\n\nARREGLOS DESORDENADOS";
                    cout<<"\n==========================";
                    cout<<"\n\n1. INSERTAR";
                    cout<<"\n\n2. ELIMINAR";
                    cout<<"\n\n3. MODIFICAR";
                    cout<<"\n\n4. MOSTRAR";
                    cout<<"\n\n4. MOSTRAR N";
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCION:  ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1: 
                            inserta_d(x,n);
                            mostrar(x,n);
                            break;
                        case 2:
                            elimina_d(x,n);
                            mostrar(x,n);
                            break;
                        case 3:
                            modifica_d(x,n);    
                            mostrar(x,n);
                            break;
                        case 4:
                            mostrar(x,n);
                            break;
                        case 5:
                            system("cls");
                            cout<<"n: "<<n<<"\n";
                            system("pause");
                            break;
                    }
                }while(opc>0 && opc<=5);
                break;
            case 2:
                do{
                    system("cls");
                    cout<<"\n\n\nARREGLOS ORDENADOS";
                    cout<<"\n==========================";
                    cout<<"\n\n1. INSERTAR";
                    cout<<"\n\n2. ELIMINAR";
                    cout<<"\n\n3. MODIFICAR";
                    cout<<"\n\n4. MOSTRAR";
                    cout<<"\n\n4. MOSTRAR N";
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCION:  ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1: 
                            inserta_o(x,n);
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 2:
                            elimina_o(x,n);
                            mostrar(x,n);
                            break;
                        case 3:
                            modifica_o(x,n);    
                            mostrar(x,n);
                            break;
                        case 4:
                            mostrar(x,n);
                            break;
                        case 5:
                            system("cls");
                            cout<<"n: "<<n<<"\n";
                            break;
                    }
                }while(opc>0 && opc<=5);
                break;
            case 3:
                break;
        }
    }while(op>0&&op<3);
}

void inserta_d(alumno *x,int &n){
    int i,j,cen;
    char codigo[11];
    if(n<MAX-1){
        cen =0;
        i=0;
        cout<<"\n\nDATOS DEL REGISTRO A INSERTAR: ";cout<<"\n\n\t\tCODIGO  : ";
        cin>>codigo;
        codigo[11]='\0';
        if(n>-1){
            while((i<=n)&&(cen==0)){
                if(strcmp(x[i].codi,codigo)==0)
                    cen=1;
                else
                    i++;
            }
        }   
    
        if(cen==0){
            n++;
            strcpy(x[i].codi,codigo);
            cout<<"\n\n\t\tNOMBRE  : ";cin>>x[i].nomb;
            cout<<"\n\n\t\tNOTA 1  : ";cin>>x[i].nota1;
            cout<<"\n\n\t\tNOTA 2  : ";cin>>x[i].nota2;
            x[i].prom=(x[i].nota1+x[i].nota2)/2;
            cout<<"\n\n\t\tPROMEDIO  : "<<x[i].prom;
        }else{
            cout<<"\n\n\n\nEL DATO YA ESTA REGISTRADO EN LA BASE DE DATOS. No se realizo la insercion.......";
        }
    }else{
        cout<<"\n\n\n\nEL ARREGLO ESTA LLENO. PELIGRO DE DESBORDAMIENTO. No se inserto ningun dato...";
    }
}
void elimina_d(alumno *x,int &n){
    int i,j,cen;
    char codigo[10];
    cout<<"\n\nDATO A ELIMINAR :    \n\n";
    cout<<"\tCODIGO  : ";cin>>codigo;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n&&cen==0){
            if(strcmp(x[i].codi,codigo)==0){
                cen=1;
                n--;
                for(j=1;j<=n;j++){
                    x[j]=x[j+1];
                }
            }else{
                i++;
            }
        }
        if(cen==0)
            cout<<"\n\n\t\t"<<codigo<<"NO ESTA EN EL ARREGLO\n\n";
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO...\n\n\n";
        system("pause");
    }
}
void modifica_d(alumno *x,int &n){
    int i,cen,op;
    char codigo1[10];
    cout<<"\n\t\tCODIGO DEL REGISTRO A MODIFICAR : \n\n";
    cout<<"\tCODIGO  : ";cin>>codigo1;
    if(n>-1){
        i=0;
        cen=0;
        while(i<=n && cen==0){
            if(strcmp(x[i].codi,codigo1)==0){
                cen=1;
                cout<<"\n\nQUE CAMPO DESEA MODIFICAR? \n\n";
                cout<<"1. CODIGO    2.NOMBRE    3.NOTA1     4.NOTA2 \n\n";
                cout<<"OPCION : ";cin>>op;
                switch(op){
                    case 1:
                        cout<<"\nINGRESA EL CODIGO CORRECTO : ";cin>>x[i].codi;
                        break;
                    case 2:
                        cout<<"\nINGRESA EL NOMBRE CORRECTO : ";cin>>x[i].nomb;
                        break;
                    case 3:
                        cout<<"\nINGRESA LA NOTA 1 CORRECTA : ";cin>>x[i].nota1;
                        x[i].prom=(x[i].nota1+x[i].nota2)/2;
                        break;
                    case 4:
                        cout<<"\nINGRESA LA NOTA 2 CORRECTA : ";cin>>x[i].nota2;
                        x[i].prom=(x[i].nota1+x[i].nota2)/2;
                        break;

                }   
            }else{
                i++;
            }
        }
        if(cen==0){
            cout<<"\n\n\t\tEL CODIGO "<<codigo1<<"NO ESTA EN EL ARREGLO\n\n";
            system("pause");
        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO...\n\n\n";
        system("pause");
    }
}
void buscar_o(alumno *x,int n){

}
void inserta_o(alumno *x,int &n){

}
void elimina_o(alumno *x,int &n){

}
void modifica_o(alumno *x,int &n){

}
void mostrar(alumno *x,int n){
    int i;
    for(i=0;i<=0;i++){
        cout<<"\nx["<<i+1;
        cout<<"\n\n\t\tCODIGO    : "<<x[i].codi;
        cout<<"\n\n\t\tNOMBRE    : "<<x[i].nomb;
        cout<<"\n\n\t\tNOTA 1    : "<<x[i].nota1;
        cout<<"\n\n\t\tNOTA 2    : "<<x[i].nota2;   
        cout<<"\n\n\t\tPROMEDIO  : "<<x[i].prom;
        cout<<"\n\n";
    }
    system("pause");
}