#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shoe {
    char* brand;
    int size;
    int price;
};

struct shoe_node {
    struct shoe element;
    struct shoe_node *next;
}* head = NULL;

void insert_shoe(char *brand, int size, int price) {
    struct shoe_node *node = malloc(sizeof(struct shoe_node));
    struct shoe *tmp_shoe = malloc(sizeof(struct shoe));
    node->element = *tmp_shoe;
    node->next = NULL;

    node->element.brand = malloc(1);
    strcpy(node->element.brand, brand);
    node->element.size = size;
    node->element.price = price;

    if (head == NULL)
        head = node;
    else {
        struct shoe_node *tmp_node = head;
        while (tmp_node->next != NULL)
            tmp_node = tmp_node->next;

        tmp_node->next = node;

    }
}

void print_data() {
    if (head == NULL) {
        printf("No hay registros.");
        return;
    }

    struct shoe_node *tmp = head;
    while (tmp != NULL) {
        printf("Brand: %s\t| Size: %i\t| Price: %i\n", tmp->element.brand, tmp->element.size, tmp->element.price);
        tmp = tmp->next;
    }
}

void fill_data() {
    insert_shoe("Nike", 39, 62000);
    insert_shoe("Adidas", 41, 57000);
    insert_shoe("DC", 40, 34500);
}

int main() {
    fill_data();
    print_data();

    return 0;
}