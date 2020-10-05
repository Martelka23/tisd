#include "../inc/memory.h"

error_code memory_allocation(subscribers *subs)
{
    error_code error = OK;
    subs->capacity = subs->length + 10u;
    subscriber *new_subs = realloc((void *)(&(subs->sub)), subs->capacity);
    if (new_subs != NULL)
    {
        subs->sub = new_subs;
    } else
    {
        printf("Ошибка выделения памяти!");
        error = MEMORY_ALLOCATION_ERROR;
    }
    
    return error;
}