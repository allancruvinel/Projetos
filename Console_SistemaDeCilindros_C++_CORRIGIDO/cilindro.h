#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

struct Cilindro{
    float altura;
    float raio;

    float volume(float altura,float raio){
        return raio*raio*altura*3.1415;
    }
};

#endif // CILINDRO_H_INCLUDED
