#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

struct Cilindro{
    unsigned int lin,col,MaxLinha,capacidade,contador=0;
    double *v;
    //unsigned int teatro[1][1];

    Cilindro(unsigned linha,unsigned coluna){

        v = new double[linha*coluna];
        MaxLinha = coluna;
        capacidade = linha*coluna;
        for(int i=0;i<capacidade;i++)
        {
            v[i]=0;
        }

    }

    void insere(double raio, double altura){
        v[contador*MaxLinha+0]=raio;
        v[contador*MaxLinha+1]=altura;
        contador++;



    }
    double getArea(int cilin){
        double area;
        area =3.14159265358979323846264338327950288419716939937510582097 *(v[cilin*MaxLinha+0]*v[cilin*MaxLinha+0])*v[cilin*MaxLinha+1];
        return area;
    }
    void remover(){
        if(contador>0)
        {
        v[(contador-1)*MaxLinha+0]=0;
        v[(contador-1)*MaxLinha+1]=0;
        contador--;
        }

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
    ~Cilindro(){
    delete v;
    }


};

#endif // CILINDRO_H_INCLUDED
