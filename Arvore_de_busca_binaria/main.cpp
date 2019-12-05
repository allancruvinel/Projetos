#include <iostream>
#include "arvorebinariabusca.h"
using namespace std;

int main()
{
    int opc =0,x;
    Bst<int> t1;
    while(opc!=9){
    cout << "bem vindo a arvore binaria de busca BST!\n Insira a opcao desejada\n" << endl;
    cout << "1-Insere" << endl;
    cout << "2-percursos" << endl;
    cout << "3-Busca" << endl;
    cout << "4-Maximo" << endl;
    cout << "5-Minimo" << endl;
    cout << "9-Sair" << endl;
    cin>>opc;
        switch(opc){
        case 1:
            cout<<"\n insira o numero desejado"<<endl;
            cin>>x;
            t1.insere(t1.pRaiz,x);
            break;
        case 2:
            if(t1.arvorevazia()){
                cout<<"\nSem Elementos na arvore"<<endl;
            }
            else
            {
                cout<<"\pre ordem "<<endl;
                t1.preOrdem(t1.pRaiz);
                cout<<"\npos ordem "<<endl;
                t1.posOrdem(t1.pRaiz);
                cout<<"\nem ordem "<<endl;
                t1.emOrdem(t1.pRaiz);
                cout<<endl;
            }
            break;
        case 3:
            if(t1.arvorevazia()){
                cout<<"\nSem Elementos na arvore"<<endl;
            }
            else
            {
                cout<<"\nInsira o Valor para checar"<<endl;
                cin>>x;
                if(t1.buscaElemento(t1.pRaiz,x)){
                    cout<<"\nElemento existente na arvore"<<endl;
                }
                else
                {
                    cout<<"\nElemento inexistente"<<endl;
                }
            }
            break;
        case 4:
            if(t1.arvorevazia()){
                cout<<"\nSem Elementos na arvore"<<endl;
            }
            else
            {
                t1.retornaMax(t1.pRaiz);
            }
            break;
        case 5:
            if(t1.arvorevazia()){
                cout<<"\nSem Elementos na arvore"<<endl;
            }
            else
            {
                t1.retornaMin(t1.pRaiz);
            }
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
