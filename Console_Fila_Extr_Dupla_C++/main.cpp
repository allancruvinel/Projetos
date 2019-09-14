#include <iostream>
#include "filadupla.h"

using namespace std;

int main()
{
    cout << "Fila dupla" << endl;
    int tam = 10;
    Fila<int>f(tam);
    int opc,x;

    do
    {
        cout<<"1 - insere no final"<<endl;
        cout<<"2 - remove do inicio"<<endl;
        cout<<"3 - insere no inicio"<<endl;
        cout<<"4 - remove do final"<<endl;
        cout<<"5 - primeiro da fila"<<endl;
        cout<<"6 - ultimo da fila"<<endl;
        cout<<"7 - exibe a fila (do inicio ate o final)"<<endl;
        cout<<"9 - fim"<<endl;
        cout<<"Selecione:"<<endl;

        cin>>opc;
        switch(opc)
        {

        case 1://insere no final
            if(f.filacheia())
            {
                cout<<"fila cheia"<<endl;
            }
            else
            {
                cout<<"digite o numero"<<endl;
                cin>>x;
                f.inserirfinal(x);
                cout<<"Sucesso"<<endl;
            }
            break;

        case 2:// remove inicio
            if(f.filavazia())
            {
                cout<<"fila vazia"<<endl;
            }
            else
            {
                cout<<"removido: "<<f.removerinicio()<<endl;
            }
            break;

        case 3://insere no começo
             if(f.filacheia())
            {
                cout<<"fila cheia"<<endl;
            }
            else
            {
                cout<<"digite o numero"<<endl;
                cin>>x;
                f.inseririnicio(x);
                cout<<"Sucesso"<<endl;
            }

            break;

        case 4://remover no final
            if(f.filavazia())
            {
                cout<<"fila vazia"<<endl;
            }
            else
            {
                cout<<"removido: "<<f.removerfinal()<<endl;
            }
            break;
        case 5:// primeiro da fila
            if(f.filavazia())
            {
                cout<<"fila vazia"<<endl;
            }
            else
            {
                cout<<"primeiro: "<<f.primeiro()<<endl;
            }
            break;

        case 6:// ultimo da fila
            if(f.filavazia())
            {
                cout<<"fila vazia"<<endl;
            }
            else
            {
                cout<<"ultimo: "<<f.ultimo()<<endl;
            }

            break;

        case 7://exibir
            if(f.filavazia())
            {
                cout<<"fila vazia"<<endl;
            }
            else
            {
                cout<<"elementos da Fila "<<endl;
                if(f.inic<=f.fim)
                {
                    for(int i = f.inic;i<=f.fim;i++)
                    {
                        cout<<f.v[i]<<" ";
                    }
                }
                else
                {
                    for(int i = f.inic; i<f.tamanho;i++)
                    {
                        cout<<f.v[i]<<" ";
                    }
                    for(int i =0;i<=f.fim;i++)
                    {
                        cout<<f.v[i]<<" ";
                    }
                }
            }
            cout<<"\n"<<endl;
            break;

        case 9:
            cout<<"fim"<<endl;
            break;
        default:
            cout<<"opcao invalida"<<endl;
            break;
        }

    }
    while(opc!=9);
    return 0;
}
