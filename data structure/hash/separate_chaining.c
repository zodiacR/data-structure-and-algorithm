#include <stdio.h>
#include <stdlib.h>

typedef int Element;

struct node{
    Element val;
    struct node* next; 
};

typedef struct node* Node;

struct hashtable{
    int loader;
    Node *table;
};

typedef struct hashtable HashTable;

HashTable* CreateHashTable(int size){
    HashTable* hash = (HashTable*)malloc(sizeof(struct hashtable));
    hash->loader = size;
    hash->table = (Node*)malloc(sizeof(Node)*size);
    for (int i = 0; i < size; i++){
        hash->table[i] = NULL;
    }

    return hash;
}

void Insert(HashTable* hash, Element value){
    int key = value % hash->loader;
    Node n = (Node)malloc(sizeof(struct node));
    n->val = value;
    n->next = NULL;

    if (!hash->table[key]){
        hash->table[key] = n;
    } else{
        n->next = hash->table[key]; 
        hash->table[key] = n;
    }

    printf("%d is inserted\n", value);
}

int Search(HashTable* hash, Element value){
    int key = value % hash->loader; 

    if (!hash->table[key]) return 0;
    else{
        Node tmp = hash->table[key];

        while (tmp){
            if (value == tmp->val) return 1;
            tmp = tmp->next;
        } 
        return 0;
    }
}

HashTable* Clear(HashTable* hash){
    for (int i = 0; i < hash->loader; i++){
        Node head = hash->table[i];

        while (head){
            Node tmp = head->next;
            free(head);
            head = tmp;
        }
    } 

    free(hash);
    return NULL;
}

void Iterate(HashTable* hash){
    for (int i = 0; i < hash->loader; i++){
        Node head = hash->table[i];

        printf("%d: ", i);
        while (head){
            printf("%d ", head->val);
            head = head->next;
        }
        printf("\n");
    } 
}

int main(){
    HashTable* hash = CreateHashTable(6);
    int arr[] = {50, 700, 76, 85, 92, 73, 101};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) Insert(hash, arr[i]);

    Iterate(hash);

    if(Search(hash, 40)) printf("%d is found\n", 40);
    else printf("%d is not found\n", 40);

    if(Search(hash, 70)) printf("%d is found\n", 70);
    else printf("%d is not found\n", 70);

    if(Search(hash, 73)) printf("%d is found\n", 73);
    else printf("%d is not found\n", 73);
    hash = Clear(hash);

    return 0;
}
