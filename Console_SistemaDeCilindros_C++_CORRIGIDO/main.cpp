#include <iostream>
#include "listalinear.h"
#include "cilindro.h"
using namespace std;
int main()
{
    int tamanho;
    cout<<"Digite o tamanho da lista:";
    cin>>tamanho;
    Lista<Cilindro> lista(tamanho);
    int opc;
    Cilindro x;
    do{
        cout << "Lista Linear" << endl;
        cout<<"1-insere"<<endl;
        cout<<"2-remove"<<endl;
        cout<<"3-exibe"<<endl;
        cout<<"9-fim"<<endl;
        cout<<"Selecione:";
        cin>>opc;
        switch(opc){
        case 1:
            if(lista.listacheia()){
                cout<<"Lista cheia..."<<endl;
            }
            else{
                cout<<"Valor altura ";
                cin>>x.altura;
                cout<<"Valor raio ";
                cin>>x.raio;
                lista.inserir(x);
            }
            break;
        case 2:
            if(lista.listavazia()){
                cout<<"Lista vazia...."<<endl;
            }
            else{
                x= lista.remover();
            }
            break;
        case 3:
            if(lista.listavazia()){
                cout<<"Lista vazia...."<<endl;
            }
            else{
                cout<<"Elementos da Lista:"<<endl;
                for(int i=0;i<=lista.indice;i++){
                    x = lista.v[i];
                    cout<<"Cilindro "<<i+1<<" altura "<<x.altura<<" raio : "<<x.raio<<" volume = "<<x.volume(x.altura,x.raio)<<endl;
                }
            }
            break;
        case 9:
            cout<<"Fim..."<<endl;
            break;
        default:
            cout<<"opcao invalida"<<endl;
            break;
        }
    }while(opc!=9);
    return 0;
}
