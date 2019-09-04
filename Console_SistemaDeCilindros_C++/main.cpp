#include <iostream>
#include "cilindro.h"

using namespace std;

int main()
{


    int opk = 0;
    unsigned int cilin,col,linha,coluna,vol;
    double raio,altur;
    cout<<"Ola bem vindo ao programa de cilindros\n digite a quantidade de cilindros ";
    cin>>cilin;
    col=2;

    Cilindro t(cilin,col);

    do{
        cout<<"escolha a opcao desejada"<<endl;
        cout<<"1 - inserir"<<endl;
        cout<<"2 - remover"<<endl;
        cout<<"3 - visao geral"<<endl;
        cout<<"9 - sair "<<endl;
        cin>>opk;
        switch(opk){


            case 1:{
                if(t.getContador()!=t.getMaximo()/2){
                cout<<"insira o raio do cilindro"<<endl;
                cin>>raio;
                cout<<"insira a altura do cilindro"<<endl;
                cin>>altur;

                t.insere(raio,altur);
                cout<<"cilindro inserido com sucesso! "<<endl;
                }
                else
                {
                    cout<<"Maximo de cilindros inseridos, impossivel adicionar"<<endl;
                }



                break;
            }
            case 2:{
                    if(t.getContador()!=0)
                    {
                        cout<<"cilindro removido com sucesso"<<endl;
                    }
                    else
                    {
                        cout<<"Impossivel remover sem dados"<<endl;
                    }
                    t.remover();


                break;
            }
            case 3:{

                for(int i = 0;i<t.getContador();i++)
                {
                    cout<<"Cilindro "<<i+1<<" Raio = "<<t.v[i*t.MaxLinha+0]<<" Altura ="<<t.v[i*t.MaxLinha+1]<<" Volume = "<<t.getArea(i)<<" metros cubicos";
                    cout<<endl;
                }
                cout<<"Cilindros Cadastrados "<<t.getContador()<<"\ncapacidade maxima "<<t.getMaximo()/2<<" \n\n";
                break;
            }

        }
    }
    while(opk!=9);
    return 0;

}
