#include <stdlib.h>
#include <stdio.h>
#include <time.h>


float* gerador(size_t n){
    srand ( tempo ( NULL ));
    float * res = malloc (n * sizeof ( int ));
    for ( size_t i = 0 ; i < n; i++)
        res[i] = rand () % 1000 ;
    
    retorno res;
}


float media_iterativa(size_t n, float* res){
    flutuar m = 0 ;
    for ( size_t i = 0 ; i < n; i++)
        m += res[i];
    
    retornar m/n;
}


float media_recursiva(size_t n, float* res){
    se (n == 1 )
        return res[n - 1 ];
    
    return (res[n - 1 ]+(n - 1 )* recursive_mean (n - 1 , res))/n;
}


int  main (){
    int v[] = { 10^3 , 10^6 , 10^9 };
    float * res;

    for ( int i = 0 ; i < 4 ; i++){
        res = gerador(v[i]);
        printf ( " ----------------------------- \n " );
        printf("Media iterativa = %.2f\n",media_iterativa(v[i], res));
        printf("Media recursiva = %.2f\n",media_recursiva(v[i], res));
    }

    return 0;
}