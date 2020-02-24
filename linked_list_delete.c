#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *next;
}*head;


void create_list(int n);
void delete_first_node();
void display_list();



int main()
{
    int n, choice;

    //printf("Number of nodes: ");
    scanf("%d", &n);
    create_list(n);

    //printf("\nData in the list \n");
   // display_list();

    printf("\nPress 1 to delete first node: ");
    scanf("%d", &choice);

    if(choice == 1)
        delete_first_node();

   // printf("\nData in the list \n");
    display_list();

    return 0;
}



void create_list(int n)
{
    struct node *newNode, *temp;
    int value, i;

    head = (struct node *)malloc(sizeof(struct node));


    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {

        //printf("Enter the data of node 1: ");
        scanf("%d", &value);

        head->value = value;
        head->next = NULL;

        temp = head;


        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                //printf("Enter the data of node %d: ", i);
                scanf("%d", &value);

                newNode->value = value;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }


    }
}



void delete_first_node()
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

       // printf("\nData deleted = %d\n", toDelete->value);


        free(toDelete);

    }
}


void display_list()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d\n", temp->value);
            temp = temp->next;
        }
    }
}
