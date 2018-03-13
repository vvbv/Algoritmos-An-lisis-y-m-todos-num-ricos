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


void Metodos::newton_rapson( double x_previo, int iteraciones ){
    cout << "Raiz: " << x_previo << " Iteración: " << iteraciones - 1 << endl;
    double funcion_evaluada = ( x_previo * x_previo ) - 5; // Función evaluada en x² - 5
    if( iteraciones == 0 ){
        return;
    }else{
        double derivada_evaluada = (2 * x_previo); // Derivada 2x
        double resultado_iteracion = x_previo - ( funcion_evaluada / derivada_evaluada );
        newton_rapson( resultado_iteracion, iteraciones - 1 );
    }
};

//Funcion x² - 5
void Metodos::secante( double a, double b, double particiones, double delta, double error ){

    double ax = a;
    double bx = b;
    double a_evaluado = (ax * ax) - 5;
    double b_evaluado = ( bx * bx ) - 5;
    
    cout << " Intervalo #1 [" << ax << ", " << a_evaluado << "]" << endl;
    cout << " Intervalo #2 [" << bx << ", " << b_evaluado << "]" << endl;

    for( int x = 0; x < particiones; x++ ){
        
        if( abs( a_evaluado ) < abs( b_evaluado ) ){

            double tmp;
            tmp = ax;
            ax = bx;
            bx = tmp;

        }

        double s = (b - a)/(b_evaluado - a_evaluado);
        a = bx;
        a_evaluado = b_evaluado;
        b = bx - (s * b_evaluado);
        b_evaluado = (bx * bx) - 5;  

        cout << " Intervalo #1 [" << ax << ", " << a_evaluado << "]" << endl;
        cout << " Intervalo #2 [" << bx << ", " << b_evaluado << "]" << endl;

    };

};