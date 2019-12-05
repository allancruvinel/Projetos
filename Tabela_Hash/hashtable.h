#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#define W 5

using namespace std;

struct Node{
    int info;
    Node *prox;
};

struct Hash{
    Node *h[W];

    Hash(){
        for(int i=0;i<W;i++)
            h[i]=NULL;
    }
    int fht(int x){
        return x % W;
    }
    bool listavazia(int lista){
        return h[lista]==NULL;
    }

    void insere(int x){
        Node *aux = new Node;
        aux->info = x;
        if(h[fht(x)] == NULL || x <= h[fht(x)]->info){
            aux->prox = h[fht(x)];
            h[fht(x)] = aux;
        }
        else{
            Node *aux2 = h[fht(x)];
            while(aux2->prox!=NULL && aux2->prox->info<x){
                aux2 = aux2->prox;
            }
            aux->prox = aux2->prox;
            aux2->prox = aux;
        }
    }

     void mostralista(){
        for(int i=0;i<W;i++){
            Node *aux = h[i];
            cout<<"h["<<i<<"]->";
            while(aux != NULL){
                cout<<aux->info<<"->";
                aux = aux->prox;
            }
            cout<<"NULL"<<endl;
        }
    }
    int buscaElemento(int x){
        for(int i=0;i<W;i++){
            Node *aux = h[i];
            while(aux != NULL){
                if(x==aux->info){
                    return i;
                }
                aux = aux->prox;
            }
        }
        return -1;
    }

    int remover(int x){
        for(int i=0;i<W;i++){
            Node *aux = h[i];
            if(aux!=NULL){

                if(h[i]->info==x&&h[i]->prox==NULL){
                    h[i]=NULL;
                }
                else if(h[i]->info==x){
                    h[i]=h[i]->prox;
                }

                while(aux->prox != NULL){
                    if(x==aux->prox->info&&aux->prox->prox==NULL){
                        aux->prox=NULL;
                        break;

                    }
                    else if(x==aux->prox->info){
                        aux->prox = aux->prox->prox;
                    }
                    aux = aux->prox;
                }
            }
        }
        return 0;
    }
};


#endif // HASHTABLE_H_INCLUDED
