#include <stdio.h>
#include <string.h>

typedef double (*operation)(double, double);

typedef struct {
    char name[10];
    operation func;
} Command;

double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double divi(double a, double b) { return a / b; }

int main() {
    Command commands[] = {
        {"add", add},
        {"sub", sub},
        {"mul", mul},
        {"div", divi}
    };
    int count = sizeof(commands) / sizeof(commands[0]);
    
    char cmd[10];
    double a, b;
    int i, found;
    
    printf("Калькулятор. Команды: add, sub, mul, div\n");
    printf("Для выхода введите 'exit'\n\n");
    
    while (1) {
        printf("Введите команду: ");
        scanf("%s", cmd);
        
        if (strcmp(cmd, "exit") == 0) break;
        
        found = 0;
        for (i = 0; i < count; i++) {
            if (strcmp(cmd, commands[i].name) == 0) {
                found = 1;
                break;
            }
        }
        
        if (!found) {
            printf("Неизвестная команда!\n");
            continue;
        }
        
        printf("Введите два числа: ");
        scanf("%lf %lf", &a, &b);
        
        // Проверка деления на ноль
        if (strcmp(commands[i].name, "div") == 0 && b == 0) {
            printf("На ноль делить нельзя!\n\n");
            continue;
        }
        
        double result = commands[i].func(a, b);
        printf("Ответ: %.2lf\n\n", result);
    }
    
    printf("До свидания!\n");
    return 0;
}