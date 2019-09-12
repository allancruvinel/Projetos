#include <iostream>
#include "expressao.h"
using namespace std;

int main()
{
    string exp;
    int opc;
    Expressao z;
    cout << "Bem vindo ao programa de validacao de operacao! "<<endl;
    do{
        cout << "escreva a Opcao desejada "<<endl;
        cout << "1 - entrar com a operacao "<<endl;
        cout << "9 - sair "<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            cout << "escreva a Operacao desejada "<<endl;
            cin>>exp;
            if(z.checaexp(exp))
            {
                cout<<"expressao valida!"<<endl;
            }
            else
            {
                cout<<"expressao invalida!"<<endl;
            }
            break;

        case 9:
            cout<<"fim!"<<endl;
            break;
        default:
            cout<<"opcao invalida!"<<endl;
        break;
        }
    }while(opc!=9);
    return 0;
}
