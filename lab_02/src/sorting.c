#include "../inc/sorting.h"



void swap(subscriber *a, subscriber *b)
{
    subscriber tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_keys(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_keys(int *a, int l)
{
    printf("\nОтсортированный список ключей:\n");
    for (int i = 0; i < l; i++)
        printf("%d %d\n", i, a[i]);
}

int subcmp(subscriber *a, subscriber *b)
{
    return strcmp(a->surname, b->surname);
}

double bubble_sort_no_keys(subscribers *subs)
{
    START_TIMER
    for (int i = 0; i < subs->length - 1; i++)
    {
        for (int j = 0; j < subs->length - 1; j++)
        {
            if (subcmp(&subs->sub[j], &subs->sub[j + 1]) > 0)
            {
                swap(&subs->sub[j], &subs->sub[j + 1]);
            }
        }
    }
    END_TIMER
}

double bubble_sort_with_keys(subscribers *subs, int print)
{
    START_TIMER
    int keys[subs->length];
    for (int i = 0; i < subs->length; i++)
    {
        keys[i] = i;
    }
    for (int i = 0; i < subs->length - 1; i++)
    {
        for (int j = 0; j < subs->length - 1; j++)
        {
            if (subcmp(&subs->sub[keys[j]], &subs->sub[keys[j + 1]]) > 0)
            {
                swap_keys(&keys[j], &keys[j + 1]);
            }
        }
    }
    subscriber tmp[subs->length];
    for (int i = 0; i < subs->length; i++)
        tmp[i] = subs->sub[keys[i]];
    for (int i = 0; i < subs->length; i++)
        subs->sub[i] = tmp[i];
    if (print)
        print_keys(keys, subs->length);

    END_TIMER
}

double quick_sort_no_keys(subscriber *subs, int first, int last)
{
    START_TIMER
    int i, j, pivot;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while (subcmp(&subs[i], &subs[pivot]) <= 0 && i<last)
                i++;
            while (subcmp(&subs[j], &subs[pivot]) > 0 && j > first)
                j--;
            if(i<j)
            {
                swap(&subs[i], &subs[j]);
            }
        }
        swap(&subs[pivot], &subs[j]);
        quick_sort_no_keys(subs,first,j-1);
        quick_sort_no_keys(subs,j+1,last);
    }
    END_TIMER
}

void qsort_with_keys(subscriber *subs, int *keys, int first, int last)
{
    int i, j, pivot;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while (subcmp(&subs[keys[i]], &subs[keys[pivot]]) <= 0 && i<last)
                i++;
            while (subcmp(&subs[keys[j]], &subs[keys[pivot]]) > 0 && j > first)
                j--;
            if(i<j)
            {
                swap_keys(&keys[i], &keys[j]);
            }
        }
        swap_keys(&keys[pivot], &keys[j]);
        qsort_with_keys(subs, keys, first,j-1);
        qsort_with_keys(subs, keys, j+1,last);
    }
}

double quick_sort_with_keys(subscribers *subs, int print)
{
    START_TIMER
    int keys[subs->length];
    for (int i = 0; i < subs->length; i++)
    {
        keys[i] = i;
    }
    qsort_with_keys(subs->sub, keys, 0, subs->length - 1);
    subscriber tmp[subs->length];
    for (int i = 0; i < subs->length; i++)
        tmp[i] = subs->sub[keys[i]];
    for (int i = 0; i < subs->length; i++)
        subs->sub[i] = tmp[i];
    if (print)
        print_keys(keys, subs->length);
    END_TIMER
}

double main_sort(subscribers *subs, int choise, int print)
{
    double t;
    subscribers sorted;
    sorted.length = 0;
    sub_cpy(subs, &sorted);
    if (choise == 1)
    {
        t = bubble_sort_with_keys(&sorted, print);
    }
    else if (choise == 2)
    {
        t = bubble_sort_no_keys(&sorted);
    }
    else if (choise == 3)
    {
        t = quick_sort_with_keys(&sorted, print);
    }
    else if (choise == 4)
    {
        t = quick_sort_no_keys(sorted.sub, 0, sorted.length - 1);
    }
    if (print)
    {
        print_all_subscribers(&sorted);
        printf("Время сортировки %d ~ %.6f(с)\n", choise, t);
    }
    // free(sorted.sub);
    return t;
}

error_code sort_subs(subscribers *subs)
{
    print_sort_menu_interface();
    int choise;
    scanf("%d", &choise);
    
    if (choise == 5)
    {
        print_sort_comparison_interface();
        int choises[2];
        scanf("%d%d", &choises[0], &choises[1]);
        double times[2];
        for (int i = 0; i < 2; i++)
            times[i] = main_sort(subs, choises[i], 0);
        printf("Время сортировки %d ~ %.6f(с)\n", choises[0], times[0]);
        printf("Время сортировки %d ~ %.6f(с)\n", choises[1], times[1]);
        printf("Сортировка 1 быстрее сортировки 2 в %.4f раз\n", times[1] / times[0]);
    } else
    {
        main_sort(subs, choise, 1);
    }
    


    return OK;
}