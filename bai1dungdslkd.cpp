#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct address{
	char ten[20];
	char phone[256];
	char email[256];	
}Address;

struct LinkedList{
    Address ad;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; 

int Compare(Address ad1, Address ad2) {
	return strcmp(ad1.ten,ad2.ten);
} 

node CreateNode(Address ad){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->ad = ad; 
    return temp;
}
 
node AddHead(node head, Address ad){
    node temp = CreateNode(ad); 
    if(head == NULL){
        head = temp; 
    }else{
        temp->next = head; 
        head = temp; 
    }
    return head;
}

node AddTail(node head, Address ad){
    node temp,p;
    temp = CreateNode(ad);
    if(head == NULL){
        head = temp;     
    }
    else{
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}

node AddAt(node head, Address ad, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, ad); 
    }else{
        
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            head = AddTail(head, ad);
        }else{
            node temp = CreateNode(ad);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}

node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; 
    return head;
}
 
node DelAt(node head, Address ad){
    node p = head;
    while(p != NULL){
        if (Compare(p->next->ad,ad)==0) {
        	p->next = p->next->next;
        	return head;
		}
        p = p->next;
    }
    return head;
}
 
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%s\n",p->ad.ten);
    	printf("%s\n",p->ad.phone);
    	printf("%s\n",p->ad.email);
    }
}

Address Search(node head, char value[] ){
    for(node p = head; p != NULL; p = p->next) 
    	if(strcmp(p->ad.ten,value)==0) return p->ad;	
	printf("Khong tim thay!");	
} 

node InitHead(){
    node head;
    head = NULL;
    return head;
}
 
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
 

node loadFile(){
 	FILE *file;
 	file = fopen("address.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    node head = InitHead();
    Address ad;
    while (1) {
        fscanf(file,"%s", ad.ten);
		if (strcmp("#", ad.ten) == 0) break;
		fscanf(file,"%s", ad.phone);
		fscanf(file,"%s",ad.email);
		head = AddTail(head,ad);
    }
    fclose(file);
    return head;
}



void Sort(node head) {
	node i,j;
	for (i = head;i != NULL; i = i->next) {
		for (j = i->next;j != NULL; j = j->next) {
			if (Compare(i->ad,j->ad)>0) {
				Address temp = i->ad;
				i->ad=j->ad;
				j->ad=temp;
			}
		}
	}
}

void printFile(Address ad) {
	FILE *fptr;
   	fptr = fopen("addressoutput.txt","w");
    if(fptr == NULL) {
      printf("Error!");   
      exit(1);             
    }
 	fprintf(fptr,"%s\n",ad.ten);
    fprintf(fptr,"%s\n", ad.phone);
    fprintf(fptr,"%s\n", ad.email);
	fprintf(fptr, "%c",'#');
    fclose(fptr);
}

int main() {
	char ten[256];
    printf("Bat dau thuc hien!\n");
    
    node head = loadFile();
    int n = Length(head);
	
    Traverser(head);
    printf("\n%d\n",n);
	Sort(head);
    Traverser(head);
    printf("Tim kiem!\nHay nhap ten nguoi can tim: ");scanf("%s",ten);
    Address result = Search(head,ten);
    if (strcmp(result.ten,"") != 0) {
    	head = AddHead(head,result);
    	DelAt(head,result);
	}
    Traverser(head);
	return 0;
}
