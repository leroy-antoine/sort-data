/*
** EPITECH PROJECT, 2025
** merge_list.c
** File description:
** merges two lists into another
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "../include/shell.h"

static int merge_reverse(linked_list_t **head, linked_list_t *minus,
    linked_list_t *plus)
{
    linked_list_t *tmp = plus;

    if (tmp != NULL) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = (*head);
        tmp->next->next = minus;
        (*head) = plus;
    } else
        (*head)->next = minus;
    return SUCCESS;
}

static void free_it(linked_list_t *freed)
{
    linked_list_t *temp = NULL;

    while (freed != NULL) {
        temp = freed->next;
        free(freed->data->name);
        free(freed->data->type);
        free(freed->data);
        free(freed);
        freed = temp;
    }
}

int merge_list(linked_list_t **head, linked_list_t *minus,
    linked_list_t *plus, int reverse)
{
    linked_list_t *tmp = minus;
    linked_list_t *freed = (*head)->next;

    if ((*head)->next != NULL)
        free_it(freed);
    if (reverse)
        return merge_reverse(head, minus, plus);
    if (tmp != NULL) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = (*head);
        tmp->next->next = plus;
        (*head) = minus;
    } else
        (*head)->next = plus;
    return SUCCESS;
}
