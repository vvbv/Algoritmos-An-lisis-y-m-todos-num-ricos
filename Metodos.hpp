#ifndef Metodos_hpp_
#define Metodos_hpp_

#include <iostream>
#include <cmath> 
using namespace std;

class Metodos{

    private:

    public:
        Metodos();
        ~Metodos();
        void biseccion( double a, double b, int particiones, double error, double admisibilidad_epsilon );
        void newton_rapson( double x_previo, int iteraciones );
        

};

#endif