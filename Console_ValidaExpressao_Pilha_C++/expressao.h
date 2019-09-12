#include <iostream>
#include "pilhasequencial.h"
#ifndef EXPRESSAO_H_INCLUDED
#define EXPRESSAO_H_INCLUDED
using namespace std;
struct Expressao{


    int tam;
    bool checaexp(string exp){
        Pilha<char> x(exp.length());
        int contCha=0,contCol=0,ContPar=0;
        for(int i = 0;i<exp.length();i++){

            if(exp[i]=='{')
            {
                contCha++;
            }
            if(exp[i]=='[')
            {
                contCol++;
            }
            if(exp[i]=='(')
            {
                ContPar++;
            }

            if(exp[i]=='}')
            {
                contCha--;
            }
            if(exp[i]==']')
            {
                contCol--;
            }
            if(exp[i]==')')
            {
                ContPar--;
            }

            if((x.elementodotopo()=='{')&&(exp[i]=='}'))
                {
                    x.desempilha();
                }
            else if(exp[i]=='{'){
                x.empilha(exp[i]);
            }
            else if(x.elementodotopo()=='['&&exp[i]==']')
                {
                    x.desempilha();
                }
            else if(exp[i]=='['){
                x.empilha(exp[i]);
            }
            else if(x.elementodotopo()=='('&&exp[i]==')')
                {
                    x.desempilha();
                }
            else if(exp[i]=='('){
                x.empilha(exp[i]);
            }
        }
        if(contCha+contCol+ContPar!=0){
            return false;
        }
        else
        {
            return x.pilhavazia();
        }

    }

};

#endif // EXPRESSAO_H_INCLUDED
