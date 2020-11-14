#include "../inc/list.h"

// Выделение памяти
void list_memory_allocation(list_t *l)
{
    l->end->next = malloc(sizeof(node_t));

    l->end = l->end->next;

    l->end->next = NULL;
}

// Инициализация списка
void list_creating(list_t *l)
{
    l->begin = malloc(sizeof(node_t));

    l->end = l->begin;
    l->begin->next = NULL;
}

// Освобождение памяти
void list_memory_deallocation(list_t *l)
{
    if (l->begin != NULL)
    {
        for (node_t *current = l->begin->next, *p = l->begin; current != NULL; p = current, current = current->next)
            free(p);
        l->begin = NULL;
        l->end = NULL;
        l->length = 0;
    }
}

// Вставка в конец
void list_push(list_t *l, int x)
{
    if (l->begin == NULL)
        list_creating(l);
    else
        list_memory_allocation(l);

    l->end->num = x;
    l->length += 1;
}

// Вставка элемента
void list_insert(list_t *l, int index, int x)
{
    node_t *current = l->begin;
    for (int i = 0; i < index && current != NULL; i++, current = current->next)
        ;


    node_t *tmp = NULL;
    tmp = malloc(sizeof(node_t));
    tmp->num = x;

    //Если это не последний элемент, то next перекидываем на следующий узел
    if (current->next) {
        tmp->next = current->next;
    //иначе на NULL
    } else {
        tmp->next = NULL;
    }
    current = tmp;
}

// Замена элемента
void list_change_element(list_t *l, int index, int x)
{
    node_t *current = l->begin;
    for (int i = 0; i < index && current != NULL; i++, current = current->next)
        ;

    current->num = x;
}

// Вывод на экран
void list_print(list_t * const l)
{
    for (node_t *current = l->begin; current != NULL; current = current->next)
        printf(" %d ", current->num);
    printf("\n");
}