#include "Metodos.hpp"

Metodos::Metodos(){}
Metodos::~Metodos(){}

// Intervalo [a, b]
// Punto medio = c
void Metodos::biseccion( double a, double b, int particiones, double delta, double admisibilidad_epsilon ){

    // Funcion x²
    double a_evaluado = ( a * a ) - 5; // Esto representa x²
    double b_evaluado = ( b * b ) - 5;
    double error = b_evaluado - a_evaluado; // Elemento medio del intervalo 

     cout << "Entrada: a => " << a << ":" << a_evaluado
             << " b =>" << b << ":" << b_evaluado << endl;

    if ( 
        ( ( a_evaluado > 0 ) && ( b_evaluado > 0 ) ) || 
        ( ( a_evaluado < 0 ) && ( b_evaluado < 0 ) ) || 
        ( ( a_evaluado == 0 ) && ( b_evaluado == 0 ) )
    ){
        cout << "Termina: a => " << a << ":" << a_evaluado
             << " b =>" << b << ":" << b_evaluado << endl;
    }else{
        for( int x = 0; x < particiones; x++ ){

            error = error/2;
            double c = a_evaluado + error;
            double resultado_c = ( c * c ) - 5; // c Evaluado en X² 
            cout << resultado_c << endl;
            if( ( abs( error ) < delta ) || ( abs( resultado_c ) < admisibilidad_epsilon ) ){
                break;
            }else{
                if ( 
                    ( ( a_evaluado > 0 ) && ( b_evaluado < 0 ) ) || 
                    ( ( a_evaluado < 0 ) && ( b_evaluado > 0 ) ) 
                ){
                    biseccion( a, resultado_c, particiones, delta, admisibilidad_epsilon );
                }else{
                    biseccion( resultado_c, b, particiones, delta, admisibilidad_epsilon );
                }
            }

        }
    }
};


void Metodos::newton_rapson(){

};