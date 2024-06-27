#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
#include <math.h>
using namespace std;
int main()
{
    float num, raiz, cua;
    string seguir = "S";
    setlocale(LC_ALL,"");
    while(seguir == "S" or seguir == "s")
    {
        system("cls");
        cout<<"\n\tPrograma que calcula la raiz y el cuadrado de un número!";
        cout<<"\n\t-----------------------------------------------------\n\n";
        cout<<"\n\tDigite un número:\t";
        cin>>num;
        system("color 70");
        if(num < 0)
            cout<<"\n\tError: El nbúmero no tiene raiz real\n";
        else    
            raiz = sqrt(num);
        cua = pow(num,2);
        cout<<"\n\n\t Imprimir datos y resultados";
        cout<<"\n\t-----------------------------------------------------\n\n";
        cout<<"\n\tEl número digitado es:\t\t"<<num<<endl<<endl;
        if(num >= 0)
            cout <<"\n\t La raiz cuadrada es: \t\t"<<"+/-"<<raiz<<"\n\n";
        cout<<"\n\t El cuadrado del número es:\t"<<cua<<"\n\n";
        cout<<"\n\t---------------------------------------------\n\n";
        cout<<"\n\tDesea continuar procesando S o N\t";
        cin>> seguir;
        while(seguir != "S" and seguir != "s" and seguir != "N" and seguir != "n")
        {
            cout<<"\n\tERROR. Digite S o N\t";
            Sleep(500);cin>>seguir;
        }     
    }   
    cout<<endl<<endl;
    system("pause");
    return 0;
}