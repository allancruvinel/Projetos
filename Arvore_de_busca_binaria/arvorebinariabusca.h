#ifndef ARVOREBINARIABUSCA_H_INCLUDED
#define ARVOREBINARIABUSCA_H_INCLUDED
#include <iostream>

using namespace std;

template <typename Tipo>
struct Node {
    Tipo info;
    Node<Tipo> *pEsq;
    Node<Tipo> *pDir;
};
template <typename Tipo>
struct Bst{
    Node<Tipo> *pRaiz;
    Bst(){
        pRaiz=NULL;
    }
    void insere(Node<Tipo> *&t,Tipo x){
        if(t==NULL){
            t = new Node<Tipo>;
            t->info=x;
            t->pEsq=NULL;
            t->pDir=NULL;
        }
        else{
            if(x<t->info){
                insere(t->pEsq,x);
            }
            else{
                insere(t->pDir,x);
            }
        }
    }

    bool arvorevazia(){
        return pRaiz==NULL;
    }
    void preOrdem(Node<Tipo>*t){
        if(t!=NULL){
            cout<<t->info<<" ";
            preOrdem(t->pEsq);
            preOrdem(t->pDir);
        }
    }

    void emOrdem(Node<Tipo>*t){
        if(t!=NULL){

            emOrdem(t->pEsq);
            cout<<t->info<<" ";
            emOrdem(t->pDir);
        }
    }

    void posOrdem(Node<Tipo>*t){
        if(t!=NULL){
            posOrdem(t->pEsq);
            posOrdem(t->pDir);
            cout<<t->info<<" ";
        }
    }
    bool buscaElemento(Node<Tipo>*t,Tipo x){
        if(t!=NULL){

            buscaElemento(t->pEsq,x);
            if(t->info==x){
                return true;
            }
            buscaElemento(t->pDir,x);
        }
        return false;

    }
    void retornaMax(Node<Tipo>*t){
        if(t->pDir!=NULL){
            retornaMax(t->pDir);
        }
        else{
             cout<<"\n o Maximo eh "<<t->info<<endl;
        }
    }
    void retornaMin(Node<Tipo>*t){
        if(t->pEsq!=NULL){
            retornaMin(t->pEsq);
        }
        else{
             cout<<"\n o Minimo eh "<<t->info<<endl;
        }
    }



};

#endif // ARVOREBINARIABUSCA_H_INCLUDED
