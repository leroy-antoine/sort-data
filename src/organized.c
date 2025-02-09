/*
** EPITECH PROJECT, 2024
** organized.c
** File description:
** organized
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"
#include "my_struct.h"
#include "../include/my_struct.h"

static void free_list(linked_list_t **head)
{
    linked_list_t *tmp = {0};

    while ((*head) != NULL) {
        tmp = (*head)->next;
        free((*head)->data->name);
        free((*head)->data->type);
        free((*head)->data);
        free((*head));
        (*head) = tmp;
    }
    free((*head));
}

int organized(void)
{
    linked_list_t *head = NULL;

    workshop_shell(&head);
    if (head != NULL)
        free_list(&head);
    return SUCCESS;
}
