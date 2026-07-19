#include <stdio.h>
#include "phonebook.h"

int main() {
    int choice;

    start_contacts();

    do {
        printf("ТЕЛЕФОННАЯ КНИГА\n");
        printf("Всего контактов: %d\n", contact_count);
        printf("Введите номер действия:\n");
        printf("1 Посмотреть список контактов\n");
        printf("2 Добавление контакта\n");
        printf("3 Редактирование контакта\n");
        printf("4 Удаление контакта\n");
        printf("0 Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                show_contacts();
                break;
            case 2:
                add_contact();
                break;
            case 3:
                edit_contact();
                break;
            case 4:
                delete_contact();
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

    return 0;
}