#include <iostream>
#include "teatro.h"


using namespace std;

int main()
{


    int opk = 0;
    unsigned int lin,col,linha,coluna;
    cout<<"Ola bem vindo ao programa de controle de poltronas de teatro\n digite a quantidade de linhas ";
    cin>>lin;
    cout<<"digite a quantidade de colunas ";
    cin>>col;

    Teatro t(lin,col);

    do{
        cout<<"escolha a opcao desejada"<<endl;
        cout<<"1 - inserir"<<endl;
        cout<<"2 - remover"<<endl;
        cout<<"3 - visao geral"<<endl;
        cout<<"9 - sair "<<endl;
        cin>>opk;
        switch(opk){


            case 1:{
                cout<<"insira a linha e a coluna que deseja inserir"<<endl;
                cin>>linha;
                cin>>coluna;
                if(t.isOcupado(linha,coluna)){
                    cout<<"Impossivel inserir. espaco ocupado"<<endl;
                    cout<<"Valor no Espaco "<cout<<t.v[linha*t.MaxLinha+coluna]<<endl;

                }
                else
                {
                    t.insere(linha,coluna);
                    cout<<"usuario inserido com sucesso! contato atual "<<endl;
                }
                break;
            }
            case 2:{
                cout<<"insira a linha e a coluna que deseja remover"<<endl;
                cin>>linha;
                cin>>coluna;
                if(!t.isOcupado(linha,coluna)){
                    cout<<"Impossivel remover. espaco vazio"<<endl;
                    cout<<"Valor no Espaco "<cout<<t.v[linha*t.MaxLinha+coluna]<<endl;

                }
                else
                {
                    t.remover(linha,coluna);
                    cout<<"usuario removido com sucesso"<<endl;
                }
                break;
            }
            case 3:{

                for(int i = 0;i<lin;i++)
                {
                    for(int j=0;j<col;j++)
                        {
                            cout<<t.v[i*t.MaxLinha+j]<<" ";
                        }
                    cout<<endl;
                }
                cout<<"assentos reservados "<<t.getContador()<<"\ncapacidade maxima "<<t.getMaximo()<<" \n\n";
                break;
            }

        }
    }
    while(opk!=9);
    return 0;

}
