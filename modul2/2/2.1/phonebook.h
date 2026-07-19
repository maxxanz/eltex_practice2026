#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_STR 100
#define MAX_CONTACTS 100

// Структура контакта
struct Contact {
    int id;
    char first_name[MAX_STR];
    char last_name[MAX_STR];
    char patronymic[MAX_STR];
    char job[MAX_STR];
    char position[MAX_STR];
    char phone_numbers[MAX_STR];
    char emails[MAX_STR];
    char social_media[MAX_STR];
};

// Глобальные переменные (объявлены как extern - доступны извне)
extern struct Contact phone_book[MAX_CONTACTS];
extern int contact_count;
extern int next_id;

// Прототипы функций
void start_contacts(void);
void add_contact(void);
void edit_contact(void);
void delete_contact(void);
void show_contacts(void);
int find_contact(int id);

#endif // CONTACTS_H