#ifndef LISTALINEAR_H_INCLUDED
#define LISTALINEAR_H_INCLUDED

template <typename Tipo>
struct Lista{
    Tipo *v;
    int indice;
    int tamanho;
    int qtde;

    Lista(int tam){
        tamanho = tam;
        qtde=0;
        indice=-1;
        v = new Tipo[tamanho];
    }
    ~Lista(){
        delete v;
    }
    void inserir(Tipo x){
        indice++;
        v[indice]=x;
        qtde++;
    }
    Tipo remover(){
        Tipo temp = v[indice];
        indice--;
        qtde--;
        return temp;
    }

    bool listacheia(){
        return qtde==tamanho;
    }
    bool listavazia(){
        return qtde==0;
    }
};
#endif // LISTALINEAR_H_INCLUDED
