#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct {
	char name[50];
	int hr;
	int min;
}place;

void Load(place des[],int &num) {
	int i = 0;
	FILE *file;
    file = fopen("20201.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    while (fscanf(file,"%s%d%d\n",des[i].name, &des[i].hr,&des[i].min)!=EOF) {
        
        i++;
    }
    num = i;
    fclose(file);
}

void Print(place des[], int num) {
	int i;
	printf("\n%-50s%-10s%-10s\n","Dia diem","Gio","Phut");
	for (i = 0; i < num; i++)
		printf("%-50s%-10d%-10d\n",des[i].name,des[i].hr,des[i].min);
}

struct LinkedList{
    place des;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; 
 
node CreateNode(place des){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList)); 
    temp->next = NULL;
    temp->des = des; 
    return temp;
}
 
node AddTail(node head, place des){
    node temp,p;
    temp = CreateNode(des);
    if(head == NULL){
        head = temp;     
    }
    else{
        p  = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return head;
}
 
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%-50s%-10d%-10d\n",p->des.name,p->des.hr,p->des.min);
    }
}

node InitHead(){
    node head;
    head = NULL;
    return head;
}

node Input(int num, place des[]){
    node head = InitHead();
    for(int i = 0; i < num; ++i){
       head = AddTail(head, des[i]);
    }
    return head;
}

void SearchDes(place des[], int num) {
	char name[50];
	int i,count = 0;
	printf("Hay nhap ten dia diem can tim kiem: ");scanf("%s",name);fflush(stdin);
	printf("\n%-50s%-10s%-10s\n","Dia diem","Gio","Phut");
	for (i = 0; i < num; i++) {
		if (strcmp(des[i].name,name)==0) {
			printf("%-50s%-10d%-10d\n",des[i].name,des[i].hr,des[i].min);
			count++;
		}
	}
	if (count == 0) printf("Ban chua toi dia diem do trong ngay!\n");
	return;
}

void SearchTime(place des[], int num) {
	int hr,min,i,count = 0;
	printf("Hay nhap gio can tim kiem: ");scanf("%d",&hr);fflush(stdin);
	while (hr < 0 || hr >= 24) {
		printf("Gio khong hop le! Hay nhap lai: ");scanf("%d",&hr);fflush(stdin);
	};
	
	printf("Hay nhap phut can tim kiem: ");scanf("%d",&min);fflush(stdin);
	while (min < 0 || min >= 60) {
		printf("Phut khong hop le! Hay nhap lai ");scanf("%d",&min);fflush(stdin);
	} ;
	
	
	for (i = 0; i < num - 1; i++) 
		if (des[i].hr <= hr && des[i+1].hr>=hr) 
			if (des[i].min <= min && des[i+1].min>min) {
				printf("\nDia diem hien tai: %s\n",des[i].name);
				count++;
				return;
			}
	if (des[num].hr >= hr) 
		if (des[num].min >= min) {
			printf("\nDia diem hien tai: %s\n",des[num].name);
				count++;
				return;
		}
	if (count == 0) printf("\nKHONG tim thay lich su di chuyen!\n");
	return;
}

void TruyVet(place des[], int num) {
	char name[50];
	int hr,min,i,count = 0;
	printf("Hay nhap ten dia diem can tim kiem: ");scanf("%s",name);fflush(stdin);
	printf("Hay nhap gio can tim kiem: ");scanf("%d",&hr);fflush(stdin);
	while (hr < 0 || hr >= 24) {
		printf("Gio khong hop le! Hay nhap lai: ");scanf("%d",&hr);fflush(stdin);
	};
	
	printf("Hay nhap phut can tim kiem: ");scanf("%d",&min);fflush(stdin);
	while (min < 0 || min >= 60) {
		printf("Phut khong hop le! Hay nhap lai ");scanf("%d",&min);fflush(stdin);
	} ;
		
	for (i = 0; i < num; i++) 
		if (strcmp(des[i].name,name)==0) 
			if (des[i].hr >= hr) 
				if (des[i].min >= min) {
				printf("\nBan co kha nang bi lay Covid, can phai khai bao y te ngay lap tuc!\n");
				return;
				count++;
			}
	if (count == 0) printf("\nLich su di chuyen cua ban OK!\n");
	return;
}


int main() {
	char choice;
	int count,num;
	int N=0,B;
	place des[100];
	node head;
	
	do {
		printf("\n====CHUONG TRINH TRUY VET COVID19====\n");
		printf("1. Nap file log lich su di chuyen.\n");
		printf("2. Tim kiem lich su di chuyen theo dia diem.\n");
		printf("3. Tim kiem lich su di chuyen theo thoi gian.\n");
		printf("4. Kiem tra truy vet moi nhat.\n");
		printf("5. Thoat\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &choice);fflush(stdin);
				while (choice != '4' && choice != '3' && choice != '2' && choice != '1' && choice != '5')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &choice);fflush(stdin);
				}
		
			switch (choice) {
				case '1': 
					Load(des,num);
					Print(des,num);
					head = Input(num,des);
					break;
				
				case '2': 
					SearchDes(des,num);
					break;
				case '3': 
					SearchTime(des,num);
					break;
				case '4': 
					TruyVet(des,num);
					break;
				case '5': return 0;		
			}
	} while (choice != '5');
	return 0;
} 
