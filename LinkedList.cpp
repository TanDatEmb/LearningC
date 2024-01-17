#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
// hien thi list thuan
void printList(struct node *list)
{

    printf("\n[head] =>");
    // bat dau tu phan dau cua list
    while (list != NULL)
    {
        printf(" %d =>", list->data);
        list = list->next;
    }

    printf(" [null]\n");
}
// hien thi list nguoc
void reverse_print(struct node *list)
{
    if (list == NULL)
    {
        printf("[null] => ");
        return;
    }
    reverse_print(list->next);
    printf(" %d =>", list->data);
}
// chen link tai vi tri dau tien
void insert_firt(int data)
{
    // cap phat bo nho cho node moi
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->data = data;
    link->next = head;

    // tro first toi first node moi
    head = link;
}
// chen link tai vi tri cuoi cung
void insert_last(int data)
{
    // cap phat bo nho cho node moi
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->data = data;
    link->next = NULL;

    // neu head la trong, tao list moi
    if (head == NULL)
    {
        head = link;
        return;
    }

    current = head;
    // di chuyen toi phan cuoi list
    while (current->next != NULL)
        current = current->next;

    // chen link vao phan cuoi cua list
    current->next = link;
}

void size_of_list(struct node *list)
{
    int size = 0;

    if (list == NULL)
    {
        printf("Kich co cua Danh sach lien ket: %d \n", size);
        return;
    }

    current = list;
    size = 1;
    while (current->next != NULL)
    {
        current = current->next;
        size++;
    }
    printf("Kich co cua Danh sach lien ket: %d \n", size);
}

void find_data(int item)
{
    int pos = 0;
    int cnt = 0;
    if (head == NULL)
    {
        printf("Danh sach lien ket chua duoc khoi tao");
        return;
    }

    current = head;
    while (current->next != NULL)
    {
        if (current->data == item)
        {
            printf("Tim thay %d tai vi tri %d\n", item, pos);
            cnt++;
        }
        current = current->next;
        pos++;
    }
    if (current->data == item)
        {
            printf("Tim thay %d tai vi tri %d\n", item, pos);
            cnt++;
        }
    if (!cnt)
    {
        printf("%d khong ton tai trong list", item);
    }
}

int main()
{
    insert_last(10);
    insert_last(11);
    insert_firt(9);
    insert_last(12);
    insert_last(13);
    insert_firt(8);
    insert_last(14);

    printList(head);
    size_of_list(head);
    find_data(56);
    return 0;
}