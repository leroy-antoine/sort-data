/*
** EPITECH PROJECT, 2024
** disp.c
** File description:
** func used to display linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_struct.h"
#include "shell.h"

int disp(void *data, __attribute_maybe_unused__ char **args)
{
    linked_list_t *head = *(linked_list_t **)(data);

    while (head != NULL) {
        mini_printf("%s n°%d - \"%s\"\n",
        head->data->type, head->data->ID, head->data->name);
        head = head->next;
    }
    return SUCCESS;
}
