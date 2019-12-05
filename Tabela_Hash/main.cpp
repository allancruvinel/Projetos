#include <iostream>#
#include "hashtable.h"

using namespace std;

int main()
{
    int opc =0,x;
    Hash h;
    while(opc!=9){
    cout << "bem vindo a HASH\n Insira a opcao desejada\n" << endl;
    cout << "1-Insere" << endl;
    cout << "2-Remove" << endl;
    cout << "3-Busca" << endl;
    cout << "4-Exibe na Tela" << endl;
    cout << "9-Sair" << endl;
    cin>>opc;
        switch(opc){
        case 1:
            cout<<"\n insira o numero desejado"<<endl;
            cin>>x;
            h.insere(x);
            break;
        case 2:
            cout<<"\n insira o numero q deseja remover"<<endl;
            cin>>x;
            h.remover(x);
            break;
        case 3:
            cout<<"\n insira o numero desejado"<<endl;
            cin>>x;
            if(h.buscaElemento(x)>-1){
                cout<<"Elemento encontrado na no local de h["<<h.buscaElemento(x)<<"] "<<endl;
            }
            else
            {
                cout<<"\n Elemento nao encontrado"<<endl;
            }
            break;
        case 4:
            h.mostralista();
            break;
        case 9:
            cout<<"ENCERRANDO APLICACAO"<<endl;
            break;
        default:
            cout<<"Opcao Invalida"<<endl;
            break;
        }
    }

    return 0;
}
