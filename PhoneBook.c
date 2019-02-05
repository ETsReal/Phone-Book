#include <malloc.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


typedef struct Contact
{
    char name[10];
    int number;
} Contact;


typedef struct Node
{
    Contact* contactObject;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
} LL;

void add(LL* lista, Contact* contact1){
    Node* new_node = malloc(sizeof(Node));
    new_node ->  contactObject = contact1;
    if (lista -> head == NULL){
        lista -> head = new_node;
    }
    else{
        Node* current = lista -> head;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = new_node;
    }
}
 
void printLL(LL* lista){
    int cont = 1;
    Node* current = lista -> head;
    while(current != NULL){
        printf("Contact number %d: \n name -> %s \n number -> %d \n", cont,current -> contactObject -> name, current -> contactObject -> number);
        current = current -> next;
        cont++;
    }
    if (cont == 1){
        printf("List is empty! \n");
    }
}

int shearch(LL* lista, Contact* contact1){
    Node* current = lista -> head;
    while (current != NULL){
        if (current -> contactObject == contact1){
            printf("Value found! \n");
            return current -> contactObject -> number;
        }
        current = current -> next;
    }
    printf("Value not found \n");
    return -1;
}

bool removeNode(LL* lista, char name[10]){
    Node* current = lista -> head;
    if (strcmp(lista -> head -> contactObject -> name, name) == 0){
        lista -> head = lista -> head -> next;
        return true;
    }
    else{
        while (current -> next != NULL){
            if (strcmp(current -> next -> contactObject -> name, name) == 0){
                current -> next = current -> next -> next;
                return true;
            }
            current = current -> next;
        }
    }
    return false;
}

void Menu(){
    printf("1 - Add User \n");
    printf("2 - Remove User \n");
    printf("3 - See Contacts \n");
}



int main(){
    LL* lista = malloc(sizeof(lista));
    lista -> head = NULL;

    Menu();
    int option;

    while (option != 4){
        printf("Enter option: \n");
        scanf("%d", &option);

        if (option == 1){
            char nameToBeAdded[10];
            int numberToBeAdded;
            printf("What's the name? \n");
            scanf("%s", nameToBeAdded);
            printf("What's the number? \n");
            scanf("%d", &numberToBeAdded);
            Contact* newContact = malloc(sizeof(Contact));
            strcpy(newContact -> name, nameToBeAdded);
            newContact -> number = numberToBeAdded;
            add(lista, newContact);
            printLL(lista);
        }

        else if (option == 2){
            char nameToBeShearched[10];
            printf("What's the name u want remove? \n");
            scanf("%s", nameToBeShearched);
            removeNode(lista, nameToBeShearched);

        }

        else if (option == 3){
            printLL(lista);
        }
    }
}
