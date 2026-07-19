#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

// ========== ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ==========
struct Contact phone_book[MAX_CONTACTS];
int contact_count = 0;
int next_id = 1;

// ========== ИНИЦИАЛИЗАЦИЯ НАЧАЛЬНЫХ КОНТАКТОВ ==========
void start_contacts() {
    phone_book[contact_count].id = next_id++;
    strcpy(phone_book[contact_count].last_name, "Иванов");
    strcpy(phone_book[contact_count].first_name, "Иван");
    strcpy(phone_book[contact_count].patronymic, "Иванович");
    strcpy(phone_book[contact_count].job, "ООО Рога и Копыта");
    strcpy(phone_book[contact_count].position, "Генеральный директор");
    strcpy(phone_book[contact_count].phone_numbers, "+7-999-111-22-33, +7-999-111-22-34");
    strcpy(phone_book[contact_count].emails, "ivan@rogaikopita.ru");
    strcpy(phone_book[contact_count].social_media, "vk.com/ivanov, t.me/ivanov");
    contact_count++;

    phone_book[contact_count].id = next_id++;
    strcpy(phone_book[contact_count].last_name, "Петрова");
    strcpy(phone_book[contact_count].first_name, "Мария");
    strcpy(phone_book[contact_count].patronymic, "Сергеевна");
    strcpy(phone_book[contact_count].job, "ЗАО ТехноПром");
    strcpy(phone_book[contact_count].position, "Главный бухгалтер");
    strcpy(phone_book[contact_count].phone_numbers, "+7-888-222-33-44");
    strcpy(phone_book[contact_count].emails, "maria@tehnoprom.ru");
    strcpy(phone_book[contact_count].social_media, "vk.com/maria_p");
    contact_count++;

    phone_book[contact_count].id = next_id++;
    strcpy(phone_book[contact_count].last_name, "Сидоров");
    strcpy(phone_book[contact_count].first_name, "Алексей");
    strcpy(phone_book[contact_count].patronymic, "Петрович");
    strcpy(phone_book[contact_count].job, "ООО IT-Решения");
    strcpy(phone_book[contact_count].position, "Ведущий программист");
    strcpy(phone_book[contact_count].phone_numbers, "+7-777-333-44-55");
    strcpy(phone_book[contact_count].emails, "alexey@itsolutions.ru");
    strcpy(phone_book[contact_count].social_media, "github.com/alexey_s");
    contact_count++;

    phone_book[contact_count].id = next_id++;
    strcpy(phone_book[contact_count].last_name, "Козлова");
    strcpy(phone_book[contact_count].first_name, "Елена");
    strcpy(phone_book[contact_count].patronymic, "Дмитриевна");
    strcpy(phone_book[contact_count].job, "ГБОУ Школа №123");
    strcpy(phone_book[contact_count].position, "Учитель математики");
    strcpy(phone_book[contact_count].phone_numbers, "+7-666-444-55-66");
    strcpy(phone_book[contact_count].emails, "elena@school123.ru");
    strcpy(phone_book[contact_count].social_media, "");
    contact_count++;
}

// ========== ПОИСК КОНТАКТА ПО ID ==========
int find_contact(int id) {
    for (int i = 0; i < contact_count; i++) {
        if (phone_book[i].id == id) {
            return i;
        }
    }
    return -1;
}

// ========== ДОБАВЛЕНИЕ КОНТАКТА ==========
void add_contact() {
    system("clear");
    
    if (contact_count >= MAX_CONTACTS) {
        printf("Ошибка: книга переполнена!\n");
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    printf("========== ДОБАВЛЕНИЕ КОНТАКТА ==========\n\n");
    
    struct Contact new_contact;
    new_contact.id = next_id;
    next_id++;
    
    printf("Введите фамилию (обязательно): ");
    fgets(new_contact.last_name, MAX_STR, stdin);
    new_contact.last_name[strcspn(new_contact.last_name, "\n")] = '\0';
    
    while (strlen(new_contact.last_name) == 0) {
        printf("ФИО обязательно! Введите снова: ");
        fgets(new_contact.last_name, MAX_STR, stdin);
        new_contact.last_name[strcspn(new_contact.last_name, "\n")] = '\0';
    }

    printf("Введите имя (обязательно): ");
    fgets(new_contact.first_name, MAX_STR, stdin);
    new_contact.first_name[strcspn(new_contact.first_name, "\n")] = '\0';
    
    while (strlen(new_contact.first_name) == 0) {
        printf("ФИО обязательно! Введите снова: ");
        fgets(new_contact.first_name, MAX_STR, stdin);
        new_contact.first_name[strcspn(new_contact.first_name, "\n")] = '\0';
    }
    
    printf("Введите отчество (Enter - пропустить): ");
    fgets(new_contact.patronymic, MAX_STR, stdin);
    new_contact.patronymic[strcspn(new_contact.patronymic, "\n")] = '\0';
    
    printf("Введите место работы (Enter - пропустить): ");
    fgets(new_contact.job, MAX_STR, stdin);
    new_contact.job[strcspn(new_contact.job, "\n")] = '\0';
    
    printf("Введите должность (Enter - пропустить): ");
    fgets(new_contact.position, MAX_STR, stdin);
    new_contact.position[strcspn(new_contact.position, "\n")] = '\0';
    
    printf("Введите номера телефонов (Enter - пропустить): ");
    fgets(new_contact.phone_numbers, MAX_STR, stdin);
    new_contact.phone_numbers[strcspn(new_contact.phone_numbers, "\n")] = '\0';
    
    printf("Введите email-адреса (Enter - пропустить): ");
    fgets(new_contact.emails, MAX_STR, stdin);
    new_contact.emails[strcspn(new_contact.emails, "\n")] = '\0';
    
    printf("Введите соцсети/мессенджеры (Enter - пропустить): ");
    fgets(new_contact.social_media, MAX_STR, stdin);
    new_contact.social_media[strcspn(new_contact.social_media, "\n")] = '\0';
    
    phone_book[contact_count] = new_contact;
    contact_count++;
    
    printf("\nКонтакт добавлен! ID: %d\n", new_contact.id);
    printf("Нажмите Enter для продолжения...");
    getchar();
}

// ========== РЕДАКТИРОВАНИЕ КОНТАКТА ==========
void edit_contact() {
    system("clear");
    
    if (contact_count == 0) {
        printf("Нет контактов для редактирования!\n");
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    printf("========== РЕДАКТИРОВАНИЕ КОНТАКТА ==========\n");
    
    printf("Список контактов:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("  ID: %d - %s\n", phone_book[i].id, phone_book[i].last_name);
    }
    
    int id;
    printf("\nВведите ID контакта для редактирования: ");
    scanf("%d", &id);
    getchar();
    
    int index = find_contact(id);
    
    if (index == -1) {
        printf("Контакт с ID %d не найден!\n", id);
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    printf("\nТекущие данные:\n");
    printf("  Фамилия: %s\n", phone_book[index].last_name);
    printf("  Имя: %s\n", phone_book[index].first_name);
    printf("  Отчество: %s\n", phone_book[index].patronymic);
    printf("  Работа: %s\n", phone_book[index].job);
    printf("  Должность: %s\n", phone_book[index].position);
    printf("  Телефон: %s\n", phone_book[index].phone_numbers);
    printf("  Email: %s\n", phone_book[index].emails);
    printf("  Соцсети: %s\n", phone_book[index].social_media);
    
    printf("\nВведите новые данные (Enter - оставить без изменений):\n");
    
    char temp[MAX_STR];
    
    printf("Новая фамилия: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].last_name, temp);
    }
    
    printf("Новое имя: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].first_name, temp);
    }
    
    printf("Новое отчество: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].patronymic, temp);
    }
    
    printf("Новое место работы: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].job, temp);
    }
    
    printf("Новая должность: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].position, temp);
    }
    
    printf("Новые телефоны: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].phone_numbers, temp);
    }
    
    printf("Новые email: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].emails, temp);
    }
    
    printf("Новые соцсети: ");
    fgets(temp, MAX_STR, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (strlen(temp) > 0) {
        strcpy(phone_book[index].social_media, temp);
    }
    
    printf("\nКонтакт обновлен!\n");
    printf("Нажмите Enter для продолжения...");
    getchar();
}

// ========== ПОКАЗ ВСЕХ КОНТАКТОВ ==========
void show_contacts() {
    if (contact_count == 0) {
        printf("Телефонная книга пуста!\n");
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }

    printf("========== ВСЕ КОНТАКТЫ ==========\n");
    printf("Всего: %d контактов\n\n", contact_count);

    for (int i = 0; i < contact_count; i++) {
        printf("  ID контакта: %d\n", phone_book[i].id);
        printf("  ФИО: %s %s %s\n", 
            phone_book[i].last_name, 
            phone_book[i].first_name, 
            phone_book[i].patronymic);
        printf("  Место работы: %s\n", phone_book[i].job);
        printf("  Должность: %s\n", phone_book[i].position);
        printf("  Телефоны: %s\n", phone_book[i].phone_numbers);
        printf("  Email: %s\n", phone_book[i].emails);
        printf("  Соцсети: %s\n", phone_book[i].social_media);
        printf("---------------------------\n");
    }
    
    printf("Нажмите Enter для продолжения...");
    getchar();
}

// ========== УДАЛЕНИЕ КОНТАКТА ==========
void delete_contact() {
    system("clear");
    
    if (contact_count == 0) {
        printf("Нет контактов для удаления!\n");
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    printf("========== УДАЛЕНИЕ КОНТАКТА ==========\n");
    
    printf("Список контактов:\n");
    for (int i = 0; i < contact_count; i++) {
        printf("  ID: %d - %s %s\n", 
               phone_book[i].id, 
               phone_book[i].last_name, 
               phone_book[i].first_name);
    }
    
    int id;
    printf("\nВведите ID контакта для удаления: ");
    scanf("%d", &id);
    getchar();
    
    int index = find_contact(id);
    
    if (index == -1) {
        printf("Контакт с ID %d не найден!\n", id);
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    printf("\nВы собираетесь удалить контакт:\n");
    printf("  ID: %d\n", phone_book[index].id);
    printf("  ФИО: %s %s %s\n", 
           phone_book[index].last_name,
           phone_book[index].first_name,
           phone_book[index].patronymic);
    printf("  Место работы: %s\n", phone_book[index].job);
    
    printf("\nВы уверены, что хотите удалить этот контакт? (y/n): ");
    char confirm;
    scanf("%c", &confirm);
    getchar();
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("Удаление отменено.\n");
        printf("Нажмите Enter для продолжения...");
        getchar();
        return;
    }
    
    // Сдвиг контактов
    for (int i = index; i < contact_count - 1; i++) {
        phone_book[i] = phone_book[i + 1];
    }
    
    contact_count--;
    
    printf("\nКонтакт успешно удален!\n");
    printf("Нажмите Enter для продолжения...");
    getchar();
}