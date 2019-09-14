#ifndef FILASEQUENCIAL_H_INCLUDED
#define FILASEQUENCIAL_H_INCLUDED

template<typename Tipo>
struct Fila{
    Tipo *v;
    int fim;
    int inic;
    int qtde;
    int tamanho;

    Fila(int tam)
    {
        tamanho = tam;
        fim = -1;
        inic = 0;
        qtde = 0;
        v = new Tipo[tamanho];
    }

    void inserirfinal(Tipo x)
    {
        fim++;
        if(fim == tamanho)
        {
            fim = 0;
        }
        v[fim]=x;
        qtde++;
    }

    void inseririnicio(Tipo x)
    {
        inic--;
        if(inic < 0)
        {
            inic = tamanho-1;
        }
        v[inic]=x;
        qtde++;
    }

    Tipo removerinicio()
    {
        Tipo temp = v[inic];
        inic++;
        if(inic==tamanho)
        {
            inic = 0;
        }
        qtde--;
        return temp;
    }

    Tipo removerfinal()
    {
        Tipo temp = v[fim];
        fim--;
        if(fim<0)
        {
            fim = tamanho-1;
        }
        qtde--;
        return temp;
    }

    Tipo primeiro()
    {
        return v[inic];
    }

    Tipo ultimo()
    {
        return v[fim];
    }

    bool filacheia()
    {
        return qtde==tamanho;
    }

    bool filavazia()
    {
        return qtde==0;
    }

    ~Fila(){
        delete v;
    }


};


#endif // FILASEQUENCIAL_H_INCLUDED
