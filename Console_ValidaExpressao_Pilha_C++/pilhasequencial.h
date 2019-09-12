#ifndef PILHASEQUENCIAL_H_INCLUDED
#define PILHASEQUENCIAL_H_INCLUDED

template<typename Tipo>
struct Pilha{
    Tipo *v;
    int topo;
    int tamanho;

    Pilha(int tam){
    tamanho = tam;
    topo = -1;
    v = new Tipo(tamanho);
    }

     ~Pilha(){
    delete v;
    }

    void empilha(Tipo x)
    {
        topo++;
        v[topo]=x;
    }

    Tipo desempilha(){
        Tipo temp = v[topo];
        topo--;
        return temp;
    }
    Tipo elementodotopo(){
        return v[topo];
    }

    bool pilhacheia(){
    return topo == tamanho-1;
    }

    bool pilhavazia(){
        return topo ==-1;
    }

};

#endif // PILHASEQUENCIAL_H_INCLUDED
