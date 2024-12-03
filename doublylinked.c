#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *end = NULL;
static int size = 0;
void insert_head(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = head;
    node->prev = NULL;

    if (head != NULL) {
        head->prev = node;
        head = node;
    } else {
        head = node;
        end = node;
    }
    size++;
}
void insert_end(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    if (end == NULL) {
        head = node;
        end = node;
    } else {
        node->prev = end;
        end->next = node;
        end = node;
    }
    size++;
}
void insert(int data, int pos) {
    int count = 1;
    struct node *node, *temp;
    temp = head;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;

    do {
        if (count == pos) {
            node->next = temp->next;
            if (temp->next != NULL) {
                (temp->next)->prev = node;
            }
            node->prev = temp;
            temp->next = node;
            size++;
            break;
        } else {
            count++;
            temp = temp->next;
        }
    } while (count <= pos);
}
void delete_head() {
    struct node *temp;
    if (head != NULL) {
        printf("\nNode deleted: %d", head->data);
        temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            end = NULL;
        }
        free(temp);
        size--;
    } else {
        printf("\nLinked List is Empty!!");
    }
}
void delete_end() {
    if (head == NULL) {
        printf("Linked list is empty!!");
    } else {
        printf("\nNode deleted: %d", end->data);
        struct node *temp;
        temp = end;
        end = end->prev;
        if (end == NULL) {
            head = NULL;
        } else {
            end->next = NULL;
        }
        free(temp);
        size--;
    }
}
void delete(int pos) {
    int count = 1;
    struct node *temp, *next_temp;
    temp = head;
    next_temp = temp->next;

    do {
        if (count == pos) {
            temp->next = next_temp->next;
            if (next_temp->next != NULL) {
                (next_temp->next)->prev = temp;
            }
            printf("\nNode deleted: %d", next_temp->data);
            free(next_temp);
            size--;
            break;
        } else {
            count++;
            temp = next_temp;
            next_temp = next_temp->next;
        }
    } while (count <= pos);
}
void display_forward() {
    if (head == NULL) {
        printf("\nLinked List is Empty!!");
    } else {
        struct node *link = head;
        printf("List (forward): ");
        while (link->next != NULL) {
            printf("%d ", link->data);
            link = link->next;
        }
        printf("%d\n", link->data);
    }
}
void display_reverse() {
    if (end == NULL) {
        printf("\nLinked List is Empty!!");
    } else {
        struct node *link = end;
        printf("List (reverse): ");
        while (link->prev != NULL) {
            printf("%d ", link->data);
            link = link->prev;
        }
        printf("%d\n", link->data);
    }
}
void find_number_in_linked_list(struct node *link, int search_value) {
    int count = 1; 
    while (link != NULL) {
        if (link->data == search_value) {
            printf("\nThe number is found in the linked list: %d at position %d", link->data, count);
            return;
        }
        count++;
        link = link->next;
    }
    printf("\nThe number is not found in the linked list!!");
}
void search() {
    int data;
    printf("\nEnter the number you want to search: ");
    scanf("%d", &data);
    find_number_in_linked_list(head, data);
}
int main() {
    int ch, data, pos;
    do {
        printf("\nChoose an option:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a particular position\n");
        printf("4. Delete head\n");
        printf("5. Delete end\n");
        printf("6. Delete from a position\n");
        printf("7. Display list forward\n");
        printf("8. Display list reverse\n");
        printf("9. Search for a number\n");
        printf("10. Exit\n");
        printf("Enter your choice (1-10): ");
        scanf("%d", &ch);
	switch (ch) {
            case 1:
                printf("Enter the data you need to store: ");
                scanf("%d", &data);
                insert_head(data);
                break;
            case 2:
                printf("Enter the data you need to store: ");
                scanf("%d", &data);
                insert_end(data);
                break;
            case 3:
                printf("Enter the data you need to store: ");
                scanf("%d", &data);
                printf("Enter the position where you need to store (Head=0: End=%d): ", size);
                scanf("%d", &pos);
                if (pos < 0 || pos > size)
                    printf("\nInvalid Position!!");
                else if (pos == 0)
                    insert_head(data);
                else if (pos == size)
                    insert_end(data);
                else
                    insert(data, pos);
                break;
            case 4:
                delete_head();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("Enter the position where you need to delete from (Head=0: End=%d): ", size - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= size)
                    printf("\nInvalid Position!!");
                else if (pos == 0)
                    delete_head();
                else if (pos == size - 1)
                    delete_end();
                else
                    delete(pos);
                break;
            case 7:
                display_forward();
                break;
            case 8:
                display_reverse();
                break;
            case 9:
                search();
                break;
            case 10:
                printf("\nThe Program is successfully exiting!!\n");
                break;
            default:
                printf("\nWrong Input!!");
        }
    } while (ch != 10);
    return 0;
}

