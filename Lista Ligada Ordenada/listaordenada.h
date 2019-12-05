#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED
using namespace std;
template <typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};
template <typename Tipo>
struct Lista{
    Node<Tipo> *h;
    Lista(){
    h=NULL;
    }
    bool insere(Tipo x){
        bool v=true;
        Node<Tipo> *aux = new Node<Tipo>;
        if(aux==NULL)
        {
            v=false;
        }
        else{
            aux->info=x;
            if(h==NULL || x<h->info){
                aux->prox=h;
                h=aux;
            }
            else{
                Node<Tipo> *aux2=h;
                while(aux2->prox!=NULL && x>aux2->prox->info){
                    aux2=aux2->prox;
                }
                aux->prox = aux2->prox;
                aux2->prox = aux;
            }
        }
        return v;
    }
    int remover(int x){
        Node<Tipo> *aux = h;
        if(aux==NULL){
            cout<<"Fila Vazia"<<endl;
            return 0;
        }
        else{
            if(h->info==x&&h->prox==NULL){
                h=NULL;
            }
            else if(h->info==x){
                h=h->prox;
            }
            while(aux->prox!=NULL){
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
        return 0;
    }
};



#endif // LISTAORDENADA_H_INCLUDED
