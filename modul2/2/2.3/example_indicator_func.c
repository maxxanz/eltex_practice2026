#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double sum(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divis(double a, double b) { return a / b; }

int main(){
    double a,b,result;
    double (*operations[])(double, double) = {sum, sub, mul, divis};
    // Выбираем операцию по индексу0
    scanf("%lf", &a);
    scanf("%lf", &b);
    for(int i=0; i<=3; i++){
        result = operations[i](a, b);
        printf("%lf\n", result);
    }
    return 0;
}