#include <iostream>
#include "listaordenada.h"
#include <stdlib.h>
using namespace std;

int main()
{

    cout << "Lista Ordenada!" << endl;
    Lista<int> lista;
    int x,opc;



    do
    {
        cout<<"1-Insere"<<endl;
        cout<<"2-Remove"<<endl;
        cout<<"3-Exibe lista"<<endl;
        cout<<"9-Fim"<<endl;
        cout<<"Selecione:";
        cin>>opc;

        switch(opc)
        {
        case 1:
            cout<<"Escreva o numero que deseja inserir"<<endl;
            cin>>x;
            lista.insere(x);
            break;
        case 2:
            cout<<"Escreva o numero que deseja remover"<<endl;
            cin>>x;
            lista.remover(x);
            break;
        case 3:
            Node<int> *aux=lista.h;
            if(aux==NULL){
                cout<<"Lista Vazia"<<endl;
            }
            while(aux !=NULL){
                cout<<aux->info<<" ";
                aux=aux->prox;
            }
            cout<<endl;
            break;
        }

    }
    while(opc!=9);





    return 0;
}
