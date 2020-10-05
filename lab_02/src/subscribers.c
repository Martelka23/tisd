#include "../inc/subscribers.h"


// error_code memory_allocation(subscribers *subs)
// {
//     error_code error = OK;
//     subs->capacity = subs->length + 10u;
//     subscriber *new_subs = realloc((void *)subs->sub, (subs->capacity * sizeof(subscribers)));
//     if (new_subs != NULL)
//     {
//         subs->sub = new_subs;
//     } else
//     {
//         printf("Ошибка выделения памяти!");
//         error = MEMORY_ALLOCATION_ERROR;
//     }
    
//     return error;
// }

void sub_cpy(subscribers *subs, subscribers *new)
{
    new->length = subs->length;
    new->capacity = subs->capacity;
    // memory_allocation(new);
    subscriber *new_sub = new->sub;
    subscriber *sub = subs->sub;
    for (int i = 0; i < new->length; new_sub++, sub++, i++)
    {
        strcpy(new_sub->surname, sub->surname);
        strcpy(new_sub->name, sub->name);
        new_sub->number = sub->number;
        strcpy(new_sub->address, sub->address);
        new_sub->status_type = sub->status_type;
        if (sub->status_type == 'p')
        {
            new_sub->status.private_.birthday.year = sub->status.private_.birthday.year;
            new_sub->status.private_.birthday.month = sub->status.private_.birthday.month;
            new_sub->status.private_.birthday.day = sub->status.private_.birthday.day;
        } else if (new_sub->status_type == 's')
        {
            strcpy(new_sub->status.service.organization, sub->status.service.organization);
            strcpy(new_sub->status.service.position, sub->status.service.position);
        }
    }
}
// Функции для чтения из файла


size_t read_count_of_elements(FILE *file)
{
    size_t count = 0;
    char string[MAX_INPUT_LENGTH];
    while (!feof(file))
    {
        fgets(string, MAX_INPUT_LENGTH, file);
        if (string[0] == 'p' || string[0] == 's')
            count++;
    }
    rewind(file);

    return count;
}

void formating(char *string, int max_length)
{
    size_t i = 0u;
    while (i < max_length && string[i++] != '\n')
        ;
    string[--i] = '\0';
}

void read_elements(FILE *file, subscribers *subs)
{
    subscriber *sub = subs->sub;
    char tmp[SYMBOL_LENGTH];
    for (unsigned short i = 0u; i < subs->length; i++, sub++)
    {
        fscanf(
            file,
            "%s%s%lu\n",
            sub->surname, sub->name, &sub->number
        );
        printf("%s\n%s\n%lu\n", sub->surname, sub->name, sub->number);

        fgets(sub->address, MAX_ADDRESS_LENGTH, file);
        formating(sub->address, MAX_ADDRESS_LENGTH);
        printf("%s\n", sub->address);

        fscanf(file, "%c\n", &sub->status_type);
        printf("%c\n", sub->status_type);

        if (sub->status_type == 'p')
        {
            fscanf(
                file,
                "%hu%hu%hu\n",
                &sub->status.private_.birthday.year,
                &sub->status.private_.birthday.month,
                &sub->status.private_.birthday.day
            );
            printf("%hu\n%hu\n%hu\n",
                sub->status.private_.birthday.year,
                sub->status.private_.birthday.month,
                sub->status.private_.birthday.day);
        }
        else if (sub->status_type == 's')
        {
            fgets(sub->status.service.position, MAX_NAME_LENGTH, file);
            formating(sub->status.service.position, MAX_NAME_LENGTH);
            printf("%s\n", sub->status.service.position);

            fgets(sub->status.service.organization, MAX_NAME_LENGTH, file);
            formating(sub->status.service.organization, MAX_NAME_LENGTH);
            printf("%s\n", sub->status.service.organization);
        }
        fgets(tmp, SYMBOL_LENGTH, file);
    }
}

error_code read_subs(subscribers *subs)
{
    error_code error = OK;
    FILE *file = fopen("subscribers.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка при открытии файла!");
        error = READ_FILE_ERROR;
    }
    if (!error)
    {
        subs->length = read_count_of_elements(file);
        // error = memory_allocation(subs);
    }
    if (!error)
        read_elements(file, subs);

    fclose(file);

    return error;
}


// Функция для записи в файл
void save(subscribers *subs)
{
    FILE *file = fopen("subscribers.txt", "w");
    subscriber *sub = subs->sub;
    for (int i = 0; i < subs->length; i++, sub++)
    {
        fprintf(
            file,
            "%s\n%s\n%lu\n%s\n%c\n",
            sub->surname, sub->name, sub->number, sub->address, sub->status_type
        );
        if (sub->status_type == 'p')
            fprintf(
                file,
                "%hu %hu %hu\n\n",
                sub->status.private_.birthday.year, 
                sub->status.private_.birthday.month,
                sub->status.private_.birthday.day
            );
        else if (sub->status_type == 's')
            fprintf(
                file,
                "%s\n%s\n\n",
                sub->status.service.position,
                sub->status.service.organization
            );
    }
    fclose(file);
}



// Функция вывода на экран
void print_all_subscribers(subscribers *subs)
{
    subscriber *sub = subs->sub;
    for (unsigned short i = 0; i < subs->length; sub++, i++)
    {
        printf(
            "%s"
            " %s"
            " %lu"
            " %s",
            sub->surname, sub->name, sub->number, sub->address
        );
        if (sub->status_type == 'p')
            printf(
                " %hu"
                " %hu"
                " %hu\n",
                sub->status.private_.birthday.year, 
                sub->status.private_.birthday.month,
                sub->status.private_.birthday.day
            );
        else
            printf(
                " %s"
                " %s\n",
                sub->status.service.position,
                sub->status.service.organization
            );
    }
}

void read_string(char *s)
{
    int i = 0;
    char c;
    scanf("%c", &c);
    for (scanf("%c", &c); c != '\n'; scanf("%c", &c), i++)
        s[i] = c;
    s[i] = '\0';
}


// Функция добавления абонента
error_code add_sub(subscribers *subs)
{
    subscriber sub;
    printf("<Ввод абонента>\nФамилия: ");
    scanf("%s", sub.surname);
    getchar();
    printf("Имя: ");
    scanf("%s", sub.name);
    getchar();
    printf("Номер: ");
    scanf("%lu", &(sub.number));
    getchar();
    printf("Адрес: ");
    read_string(sub.address);
    formating(sub.address, MAX_ADDRESS_LENGTH);
    getchar();
    printf("Статус p (личный) или s (служебный): ");
    scanf("%c", &sub.status_type);
    getchar();
    if (sub.status_type == 'p')
    {
        printf("<Ввод личного статуса>\nГод: ");
        scanf("%hu", &(sub.status.private_.birthday.year));
        getchar();
        printf("Месяц: ");
        scanf("%hu", &(sub.status.private_.birthday.month));
        getchar();
        printf("День: ");
        scanf("%hu", &(sub.status.private_.birthday.day));
        getchar();
    }
    else if (sub.status_type == 's')
    {
        printf("<Ввод служебного статуса>\nДолжность: ");
        fgets(sub.status.service.position, MAX_NAME_LENGTH, stdin);
        formating(sub.status.service.position, MAX_NAME_LENGTH);
        printf("Организация: ");
        fgets(sub.status.service.organization, MAX_NAME_LENGTH, stdin);
        formating(sub.status.service.organization, MAX_NAME_LENGTH);
    }
    // if (subs->length >= subs->capacity)
        // memory_allocation(subs);
    subs->sub[(subs->length)++] = sub;

    return OK;
}

void rm(subscribers *subs, int index)
{
    subs->length -= 1;
    for (int i = index; i < subs->length; i++)
        subs->sub[i] = subs->sub[i + 1];
}


void del_sub(subscribers *subs)
{
    int choise;
    printf("<Удаление абонента>\nВыберите поле, по которому хотите удалить:\n");
    printf(
            "\n1.Фамилия"
            "\n2.Имя"
            "\n3.Номер"
            "\n4.Адрес"
            "\n5.Год"
            "\n6.Месяц"
            "\n7.День"
            "\n8.Должность"
            "\n9.Организация\n"
    );
    scanf("%d", &choise);
    if (choise == 1)
    {
        char s[MAX_NAME_LENGTH];
        printf("Введите фамилию: ");
        read_string(s);
        for (int i = subs->length; i >= 0; i--)
            if (!strcmp(subs->sub[i].surname, s))
                rm(subs, i);
    } else if (choise == 2)
    {
        char s[MAX_NAME_LENGTH];
        printf("Введите имя: ");
        read_string(s);
        for (int i = subs->length; i >= 0; i--)
            if (!strcmp(subs->sub[i].name, s))
                rm(subs, i);
    } else if (choise == 3)
    {
        unsigned long int n;
        printf("Введите номер: ");
        scanf("%lu", n);
        for (int i = subs->length; i >= 0; i--)
            if (subs->sub[i].number == n)
                rm(subs, i);
    } else if (choise == 4)
    {
        char s[MAX_ADDRESS_LENGTH];
        printf("Введите адрес: ");
        read_string(s);
        for (int i = subs->length; i >= 0; i--)
            if (!strcmp(subs->sub[i].address, s))
                rm(subs, i);
    } else if (choise == 5)
    {
        unsigned long int n;
        printf("Введите год рождения: ");
        scanf("%lu", n);
        for (int i = subs->length; i >= 0; i--)
            if (subs->sub[i].status.private_.birthday.year == n)
                rm(subs, i);
    } else if (choise == 6)
    {
        unsigned long int n;
        printf("Введите месяц рождения: ");
        scanf("%lu", n);
        for (int i = subs->length; i >= 0; i--)
            if (subs->sub[i].status.private_.birthday.month == n)
                rm(subs, i);
    } else if (choise == 7)
    {
        unsigned long int n;
        printf("Введите день рождения: ");
        scanf("%lu", n);
        for (int i = subs->length; i >= 0; i--)
            if (subs->sub[i].status.private_.birthday.day == n)
                rm(subs, i);
    } else if (choise == 8)
    {
        char s[MAX_NAME_LENGTH];
        printf("Введите должность: ");
        read_string(s);
        for (int i = subs->length; i >= 0; i--)
            if (!strcmp(subs->sub[i].status.service.position, s))
                rm(subs, i);
    } else if (choise == 9)
    {
        char s[MAX_NAME_LENGTH];
        printf("Введите организацию: ");
        read_string(s);
        for (int i = subs->length; i >= 0; i--)
            if (!strcmp(subs->sub[i].status.service.organization, s))
                rm(subs, i);
    }   
}