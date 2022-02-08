#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};
 
struct Node *head, *tail, *abc ; 
 

struct Node* NewNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
 

void InsertFirst(int x) {
    struct Node* newNode = NewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
 

void InsertLast(int x) {
    struct Node* newNode = NewNode(x);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
 
 
void DelHead() {
    if(head == NULL) {
        return;
    }
    head = head->next;
    head->prev = NULL;
}
 

void DelTail() {
    if(head == NULL) {
        return;
    }
    tail = tail->prev;
    tail->next = NULL;
}
 

void Print() {
    struct Node* temp = head;
    printf("\nForward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
 

void ReversePrint() {
    struct Node* temp = tail;
    if(temp == NULL) return; 
    printf("\nReverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}

void Size() {
	struct Node* temp = head;
    int count;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nSize: %d",count);
}
void Clear() {
	head = NULL;
	tail = NULL;
}

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
} 

void Erase(Node* p) {
if(p == NULL) return;
if(head == tail && p == head){
head = NULL; tail = NULL; delete p;
}
if(p == head){
head = p->next; head->prev = NULL;
delete p; return;
}
if(p == tail){
tail = p->prev; tail->next = NULL;
delete p; return;
}
p->prev->next = p->next; p->next->prev = p->prev; delete p;
} 

int main() {
	int a,b,c,d,e,f,g,h;
 	srand((int)time(0));
    a = random(0,100);
    b = random(0,100);
    c = random(0,100);
    d = random(0,100);
    e = random(0,100);
    f = random(0,100);
    g = random(0,100);
    h = random(0,100);
    head = NULL; 
    
    InsertLast(a);
    Print(); 
    
    InsertLast(b);
    Print(); 
    
    InsertFirst(c);
    Print(); 
    
    InsertLast(d);
    Print(); 
    
    InsertLast(e);
    Print(); 
    
    InsertLast(f);
    Print(); 
    
    InsertFirst(g);
    Print(); 
    
    InsertLast(h);
    Print(); 
    
    DelHead();
    Print(); 
    
    abc = head;
    
	Erase(abc);
    DelTail();
    Print(); 
    
    Size();
    Clear();
}
