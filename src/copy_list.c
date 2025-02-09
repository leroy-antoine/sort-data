/*
** EPITECH PROJECT, 2025
** copy_list.c
** File description:
** copying a linked list into another
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/shell.h"

int copy_list(linked_list_t **copy, linked_list_t *original)
{
    linked_list_t *tmp = (*copy);

    if (original == NULL)
        return ERROR;
    (*copy) = malloc(sizeof(linked_list_t));
    if ((*copy) == NULL)
        return ERROR;
    (*copy)->data = malloc(sizeof(data_t));
    if ((*copy)->data == NULL)
        return ERROR;
    (*copy)->data->name = my_strdup(original->data->name);
    if ((*copy)->data->name == NULL)
        return ERROR;
    (*copy)->data->ID = original->data->ID;
    (*copy)->data->type = my_strdup(original->data->type);
    (*copy)->next = NULL;
    if ((*copy)->data->type == NULL)
        return ERROR;
    (*copy)->next = tmp;
    return SUCCESS;
}
