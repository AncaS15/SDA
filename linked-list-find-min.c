#include <stdlib.h>
#include <stdio.h>

struct NOD
{
    int data;
    struct NOD *next;
};

struct NOD *add_to_end(struct NOD *head);
int find_min_in_list(struct NOD *head);

int main()
{
    int nr_noduri, i;
    struct NOD *head = NULL;
    scanf("%d", &nr_noduri);
    for (i = 0; i < nr_noduri; i++)
    {
        head = add_to_end(head);
    }
    printf("%d", find_min_in_list(head));
    return 0;
}

struct NOD *add_to_end(struct NOD *head)
{
    struct NOD *current = head;

    struct NOD *new_node = (struct NOD *)malloc(sizeof(struct NOD));
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head != NULL)
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    else
    {
        head = new_node;
    }

    return head;
}

////////////////////////////////////////////////////////////////////////////////

int find_min_in_list(struct NOD *head){
    struct NOD *nod_curent=head;
    int min=head->data;
    while(nod_curent!=NULL){
        if(nod_curent->data<min)
            min=nod_curent->data;
        nod_curent=nod_curent->next;
    }
    return min;
}
