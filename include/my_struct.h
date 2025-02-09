/*
** EPITECH PROJECT, 2024
** my_struct.h
** File description:
** struct for this project
*/

#ifndef MY_STRUCT
    #include <stdbool.h>
    #define MY_STRUCT
    #define ERROR 84
    #define SUCCESS 0

typedef struct flags_t {
    bool ID;
    bool TYPE;
    bool NAME;
    bool r;
} flags_t;

typedef struct data_t {
    char *type;
    char *name;
    int ID;
} data_t;

typedef struct linked_list_t {
    data_t *data;
    struct linked_list_t *next;
} linked_list_t;

int organized(void);
int copy_list(linked_list_t **copy, linked_list_t *original);
int merge_list(linked_list_t **head, linked_list_t *minus,
    linked_list_t *plus, int reverse);
#endif /* MY_STRUCT */
