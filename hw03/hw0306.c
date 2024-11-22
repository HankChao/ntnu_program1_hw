#include <stdio.h>
#include <math.h>

int main(){
    printf( "sqrt(%f) = %f\n", 900.0, sqrt( 900.0 ) );
    printf( "cbrt(%f) = %f\n", -27.0, cbrt( -27.0 ) );
    printf( "pow(%f, %f) = %f\n", 2.0, 7.0, pow( 2.0, 7.0 ) );
    printf( "sin(%f) = %f\n", 0.0, sin( 0.0 ) );
    printf( "cos(%f) = %f\n", 0.0, cos( 0.0 ) );
    printf( "tan(%f) = %f\n", 0.0, tan( 0.0 ) );
    return 0;
}