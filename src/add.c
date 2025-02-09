/*
** EPITECH PROJECT, 2024
** add.c
** File description:
** add to the linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_struct.h"
#include "shell.h"

static void print_add(linked_list_t **head, int *return_value)
{
    if (*return_value == ERROR)
        return;
    mini_printf("%s n°%d - \"%s\" added.\n",
    (*head)->data->type, (*head)->data->ID, (*head)->data->name);
}

static int handle_errors(char **args, linked_list_t *new_node)
{
    int len_arg = 0;

    if (new_node == NULL)
        return ERROR;
    for (int i = 0; args[i] != NULL; i++)
        len_arg += 1;
    if (len_arg % 2 != 0)
        return ERROR;
    return SUCCESS;
}

static linked_list_t *create_node(linked_list_t *new_node)
{
    new_node = malloc(sizeof(linked_list_t));
    new_node->data = malloc(sizeof(data_t));
    return new_node;
}

static void set_id(linked_list_t *new_node)
{
    static int count = 0;

    new_node->data->ID = count;
    count += 1;
}

static int check_type(char **args, linked_list_t *new_node, int i)
{
    new_node->data->type = my_strdup(args[i]);
    new_node->data->name = my_strdup(args[i + 1]);
    if (my_strcmp(new_node->data->type, "WIRE") == 0)
        return SUCCESS;
    if (my_strcmp(new_node->data->type, "ACTUATOR") == 0)
        return SUCCESS;
    if (my_strcmp(new_node->data->type, "DEVICE") == 0)
        return SUCCESS;
    return ERROR;
}

static int push_to_list(char **args, linked_list_t **head,
    int return_value)
{
    linked_list_t *new_node = {0};

    for (int i = 0; args[i] != NULL; i += 2) {
            new_node = create_node(new_node);
        if (handle_errors(args, new_node) == ERROR)
            return ERROR;
        if ((*head) == NULL) {
            return_value = check_type(args, new_node, i);
            set_id(new_node);
            new_node->next = NULL;
            (*head) = new_node;
        } else {
            return_value = check_type(args, new_node, i);
            set_id(new_node);
            new_node->next = (*head);
            (*head) = new_node;
        }
        print_add(head, &return_value);
    }
    return return_value;
}

int add(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)(data);
    int return_value = SUCCESS;

    return_value = push_to_list(args, head, return_value);
    return return_value;
}
