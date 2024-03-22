#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct l_list
{
    struct l_list *prev;
    char name[20];
};

struct l_list *add_to_list(struct l_list *list, char *name)
{
    struct l_list *new_item = malloc(sizeof(struct l_list));
    strcpy(new_item->name, name);
    new_item->prev = list;
    return new_item;
}

int main()
{
    struct l_list *list = {0};
    char name[20] = "";

    while (strcmp(name, "Q") != 0)
    {
        printf("Add a name or Q to exit: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        list = add_to_list(list, name);
    }

    struct l_list *tail = list;

    while (list != NULL)
    {
        printf("%s\n", list->name);
        list = list->prev;
    }

    list = tail;

    while (list != NULL)
    {
        struct l_list *next = list->prev;
        free(list);
        list = next;
    }

    return 0;
}