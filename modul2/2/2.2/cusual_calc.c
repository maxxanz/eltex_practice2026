#include <stdio.h>
#include <stdlib.h>
#include "func_calc.h"

int main(){
    double a = 0;
    double b;
    int choice;
    double result = 0;
    do {
        
        // system("clear");
        printf("Первое число: ");
        scanf("%lf", &a);
        printf("Второе число: ");
        scanf("%lf", &b);
        printf("1)Сложение\n2)Вычитание\n3)Умножение\n4)Деление\n0)Выход\nВаш выбор: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                result = sum(a,b);
                printf("%lf\n", result);
                break;
            case 2:
                result = substruction(a,b);
                printf("%lf\n", result);
                break;
            case 3:
                result = multiplication(a,b);
                printf("%lf\n", result);
                break;
            case 4:
                if (b == 0){
                    printf("Делить на ноль нельзя\n");
                    break;
                }
                result = division(a,b);
                printf("%lf\n", result);
                break;
            case 0:
                printf("До свидания!\n");
                break;
            default:
                printf("Неверный ввод!\n");
                printf("Нажмите Enter для продолжения...");
                getchar();
        }
    } while (choice != 0);
}