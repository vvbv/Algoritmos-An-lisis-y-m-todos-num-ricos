#include "Metodos.cpp"

int main(){

    Metodos metodos;
    //metodos.biseccion( 9, 0.5, 10, 0.1, 0.1 );
    //metodos.newton_rapson(10000, 1000000);
    metodos.secante( 9, -0.001, 20, 0, 0 );
    return 0;
};

