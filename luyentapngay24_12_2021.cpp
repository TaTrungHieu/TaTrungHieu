#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
	int queue[100];
	int front = 0;
	int rear;
}Num;

void Enqueue(int queue[], int element, int& rear) {
    queue[rear] = element;    
    rear++;
}
 
 
void Dequeue(int queue[], int& front, int rear) {
    if(front == rear)            
        printf("UnderFlow\n");
    else {
        queue[front] = 0;        
        front++;
    }
}
 
int Front(int queue[], int front) {
    return queue[front];
}

int Check(int queue[],int element) {
	int i = 0;
	for (i = 0;queue[i]!=0;i++) if (element == queue[i]) return 0;
	return 1;
}

void Del(int queue[],int value,int front) {
	for (i=front;queue[i]!=0;i++) 
		if (queue[i] == value) {
			while(queue[i] != 0) {
				queue[i]=queue[i+1];
				i++;
			}
			break;
		}	
	
}

void printQueue(int queue[], int front) {
	int i;
	printf("\n");
	for (i = front;queue[i]!=0;i++) {
		printf("%d->",queue[i]);
	}
	printf("NULL\n\n");
}

int main() {
	char chon,choice2;
	int N,i,j,QueueCheck[10000],QueueMatch[10000],RearCheck=0,RearMatch=0,FrontCheck=0,FrontMatch=0,temp=0;
	Num num[10];
	do {
		printf("====Nhap vao so bat ky de thuc hien chuc nang====\n");
		printf("1) Nhap vao gia tri N (so luong cac queue)\n");
		printf("2) Nhap (i, j) de chen j vao queue i (i < N)\n");
		printf("3) Hien thi cac phan tu trong queue i\n");
		printf("4) Kiem tra va xoa phan tu trung lap (neu co)\n");
		printf("5) Thoat.\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &chon);fflush(stdin);
				while (chon != '4' && chon != '3' && chon != '2' && chon != '1' && chon != '5')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &chon);fflush(stdin);
				}
			switch (chon) {
				case '1': 
					printf("Nhap so luong cac queue N (N<10): ");scanf("%d",&N);fflush(stdin);
					while (N >= 10 || N < 1)  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%d", &N);fflush(stdin);
				}
					break;
				case '2': {
					int check = 0;
					do {
						printf("Hay nhap theo thu tu bo so (i;j):");scanf("%d%d",&i,&j);fflush(stdin);
						if (i >= N || i < 0 || j <= 0) {
							printf("Nhap sai! Ket thuc chuc nang 2!\n");
							check = 1;
						}
						if (check == 1) break;
						if (Check(num[i].queue,j)==0) {
							printf("Nhap sai! Ket thuc chuc nang 2!\n");
							check = 1;
							break;
						}
						printf("Ban co chac muon nhap bo so (i;j) nay khong:\n1.Yes\n2.No\n");scanf("%c",&choice2);fflush(stdin);
						while (choice2 != '2' && choice2 != '1' )  {
							printf("Lua chon khong hop le! Nhap lai: "); 
							scanf("%c", &choice2);fflush(stdin);
						}
					} while (choice2 != '1');
					if (check == 1) break;
					Enqueue(num[i].queue,j,num[i].rear);
					printf("Queue %d:\n",i);	
					printQueue(num[i].queue,num[i].front);	
					if (Check(QueueCheck,j)==1) Enqueue(QueueCheck,j,RearCheck);
					else Enqueue(QueueMatch,j,RearMatch);
					printf("Queue check:\n");printQueue(QueueCheck,FrontCheck);
					printf("Queue match:\n");printQueue(QueueMatch,FrontMatch);
					break;
				}
							
					
				case '3': 
					printf("Nhap i de in ra hang doi tuong ung:");scanf("%d",&i);fflush(stdin);
					while (i >= N)  {
						printf("Lua chon khong hop le! Nhap lai: "); 
						scanf("%d", &i);fflush(stdin);
					}
					printQueue(num[i].queue,num[i].front);
					break;
				case '4': {
					
						int k;printf("Nhap k: ");scanf("%d",&k);fflush(stdin);
						Del(num[0].queue,k,num[0].front);
					
					break;
				}
					
					
				case '5': return 0;
									
			}
	} while (chon != '5');
	

}
