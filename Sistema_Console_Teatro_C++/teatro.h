#ifndef TEATRO_H_INCLUDED
#define TEATRO_H_INCLUDED

struct Teatro{
    unsigned int lin,col,MaxLinha,capacidade,contador=0;
    int *v;
    //unsigned int teatro[1][1];

    Teatro(unsigned linha,unsigned coluna){

        v = new int[linha*coluna];
        MaxLinha = linha;
        capacidade = linha*coluna;
        for(int i=0;i<capacidade;i++)
        {
            for(int j=0;j<coluna;j++){
                v[i]=0;
            }
        }

    }

    int insere(unsigned lin, unsigned col){
        v[lin*MaxLinha+col]=1;
        contador++;

    }
    void remover(unsigned lin, unsigned col){
        v[lin*MaxLinha+col]=0;
        contador--;

    }
    bool isOcupado(unsigned linha,unsigned coluna){
        return v[linha*MaxLinha+coluna]==1;

    }
    unsigned int getContador(){
        return contador;

    }
    unsigned int getMaximo(){
        return capacidade;
    }
    ~Teatro(){
    delete v;
    }


};

#endif // TEATRO_H_INCLUDED
