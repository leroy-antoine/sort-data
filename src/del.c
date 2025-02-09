/*
** EPITECH PROJECT, 2024
** del.c
** File description:
** del
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/my_struct.h"
#include "shell.h"

static void free_it(linked_list_t *tmp)
{
    free(tmp->data->name);
    free(tmp->data->type);
    free(tmp->data);
    free(tmp);
}

static int delete_it(int to_delete, linked_list_t **head)
{
    linked_list_t *tmp = {0};
    linked_list_t *current_head = (*head);

    if ((*head)->data->ID == to_delete) {
        tmp = (*head);
        (*head) = (*head)->next;
        free_it(tmp);
        return SUCCESS;
    }
    while (current_head != NULL) {
        if (current_head->next != NULL &&
            to_delete == current_head->next->data->ID) {
            tmp = current_head->next;
            current_head->next = current_head->next->next;
            free_it(tmp);
            return SUCCESS;
        } else
            current_head = current_head->next;
    }
    return ERROR;
}

int del(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)(data);
    int to_delete = 0;
    int return_value = SUCCESS;

    if ((*head) == NULL)
        return ERROR;
    if (args == NULL)
        return ERROR;
    if (data == NULL)
        return ERROR;
    for (int i = 0; args[i] != NULL; i++) {
        to_delete = my_getnbr(args[i]);
        if (to_delete < 0)
            return ERROR;
        return_value = delete_it(to_delete, (head));
    }
    return return_value;
}
