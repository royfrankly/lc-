#include <iostream>
#include "arrays.h"
#define max 5
using namespace std;
//codigo nombre nota1 nota2 promedio 
// promedio = (nota1 + nota2 )/2
struct alumno{
    char codi[10],nomb[20];
    float nota1,nota2,prom;
};
int main(){
    int x[max], op,opc,n=-1,dato,i;
    do{
        system("cls");
        cout<<"\n M E N U";
        cout<<"\n ==============";
        cout<<"\n\n1. ARRAY DESORDENADO";
        cout<<"\n\n2. ARRAY ORDENADO";
        cout<<"\n\n3. S A L I R";
        cout<<"\n\n\t\t\t OPCION:  ";
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
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCION:  ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1: 
                            cout<<"\n\t\t DATO A INSERTAR : ";cin>>dato;
                            inserta_d(x,n,max,dato);
                            mostrar(x,n);
                            break;
                        case 2:
                            cout<<"\n\t\t DATO A ELIMINAR : ";cin>>dato;
                            elimina_d(x,n,dato);
                            mostrar(x,n);
                            break;
                        case 3:
                            cout<<"\n\t\t DATO A MODIFICAR : ";cin>>dato;
                            modifica_d(x,n,dato);    
                            mostrar(x,n);
                            break;
                        case 4:
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                }while(opc>0 && opc<5);
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
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCION:  ";
                    cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1: 
                            cout<<"\n\t\t DATO A INSERTAR : ";cin>>dato;
                            inserta_o(x,n,max,dato);
                            break;
                        case 2:
                            cout<<"\n\t\t DATO A ELIMINAR : ";cin>>dato;
                            elimina_o(x,n,dato);
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 3:
                            cout<<"\n\t\t DATO A MODIFICAR : ";cin>>dato;
                            int dato2;
                            cout<<"\n\t\t DATO POR EL QUE MODIFICARA : ";cin>>dato2;
                            modifica_o(x,n,dato,dato2);    
                            mostrar(x,n);
                            break;
                        case 4:
                            mostrar(x,n);
                            system("pause");
                            break;
                        case 5:
                            break;
                    }
                }while(opc>0 && opc<5);
                break;
            case 3:
                break;   
        }
    }while(op>0 && op<3);

    return 0;
}