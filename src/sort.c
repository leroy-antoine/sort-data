/*
** EPITECH PROJECT, 2025
** sort.c
** File description:
** sort
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/shell.h"

static int quick_sort_name(linked_list_t **head, int reverse)
{
    linked_list_t *minus = NULL;
    linked_list_t *plus = NULL;
    linked_list_t *pivot = *head;
    int error = 0;

    for (linked_list_t *tmp = (*head)->next; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->data->name, pivot->data->name) <= 0)
            error = copy_list(&minus, tmp);
        if (error == ERROR)
            return ERROR;
        if (strcmp(tmp->data->name, pivot->data->name) > 0)
            error = copy_list(&plus, tmp);
        if (error == ERROR)
            return ERROR;
    }
    if (minus != NULL)
        quick_sort_name(&minus, reverse);
    if (plus != NULL)
        quick_sort_name(&plus, reverse);
    return merge_list(head, minus, plus, reverse);
}

static int quick_sort_type(linked_list_t **head, int reverse)
{
    linked_list_t *minus = NULL;
    linked_list_t *plus = NULL;
    linked_list_t *pivot = *head;
    int error = 0;

    for (linked_list_t *tmp = (*head)->next; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->data->type, pivot->data->type) <= 0)
            error = copy_list(&minus, tmp);
        if (error == ERROR)
            return ERROR;
        if (strcmp(tmp->data->type, pivot->data->type) > 0)
            error = copy_list(&plus, tmp);
        if (error == ERROR)
            return ERROR;
    }
    if (minus != NULL)
        quick_sort_type(&minus, reverse);
    if (plus != NULL)
        quick_sort_type(&plus, reverse);
    return merge_list(head, minus, plus, reverse);
}

static int quick_sort_id(linked_list_t **head, int reverse)
{
    linked_list_t *minus = NULL;
    linked_list_t *plus = NULL;
    linked_list_t *pivot = *head;
    int error = 0;

    for (linked_list_t *tmp = (*head)->next; tmp != NULL; tmp = tmp->next) {
        if (tmp->data->ID <= pivot->data->ID)
            error = copy_list(&minus, tmp);
        if (error == ERROR)
            return ERROR;
        if (tmp->data->ID > pivot->data->ID)
            error = copy_list(&plus, tmp);
        if (error == ERROR)
            return ERROR;
    }
    if (minus != NULL)
        quick_sort_id(&minus, reverse);
    if (plus != NULL)
        quick_sort_id(&plus, reverse);
    return merge_list(head, minus, plus, reverse);
}

int sort(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)(data);
    int reverse = 0;

    if (head == NULL)
        return ERROR;
    if ((*head) == NULL || args == NULL)
        return ERROR;
    for (int i = 0; args[i] != NULL; i++) {
        if (i > 3)
            return ERROR;
        if (my_strcmp(args[i], "-r") == 0)
            reverse = 1;
    }
    if (my_strcmp(args[0], "ID") == 0)
        return quick_sort_id(head, reverse);
    if (my_strcmp(args[0], "NAME") == 0)
        return quick_sort_name(head, reverse);
    if (my_strcmp(args[0], "TYPE") == 0)
        return quick_sort_type(head, reverse);
    return ERROR;
}
