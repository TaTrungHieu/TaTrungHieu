#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct {
	char ID[10];
	char grade[5];
	char name[30];
	double height;
} xh;

void xxd(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}
void insert(xh hv[],char name[], char grade[], char ID[], double height, int pos) {
	strcpy(hv[pos].name,name);
	strcpy(hv[pos].ID,ID);
	strcpy(hv[pos].grade,grade);
	hv[pos].height = height;
	
}
void print(xh hv[], int pos) {
	printf("ID: %s\n",hv[pos].ID);
	printf("Name: %s\n",hv[pos].name);
	printf("Grade: %s\n",hv[pos].grade);
	printf("Height: %.2lf",hv[pos].height);
}
void del(xh hv[],int k,int a[]) {
	for (int i=k;i>=0;i--) {
		strcpy(hv[i].name,"");
		strcpy(hv[i].ID,"");
		strcpy(hv[i].grade,"");
		hv[i].height = 0;
		a[i] = 0;
	}
}
int main () {
	xh hv[100];
	char chon, grade[5],ID[10],name[30];
	double height,h;
	int n,cap,pos,blank,a[100],count,num;
	do {
		printf("====Program for Narabemasu====");
		printf("\n1) Numbers of Students:");
		printf("\n2) Insert new member:");
		printf("\n3) Search:");
		printf("\n4) Remove a member:");
		printf("\n5) Quit");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &chon); fflush(stdin);
			while (chon != '4' && chon != '3' && chon != '2' && chon != '1' && chon != '5')  {
				printf("Lua chon khong hop le! Nhap lai: "); 
				scanf("%c", &chon);
				fflush(stdin);
			}
			switch(chon) {
				case '1': {
					printf("Nhap so luong hoc vien can xep hang: ");scanf("%d",&n);fflush(stdin);
					printf("Nhap so luong hoc vien toi da: ");scanf("%d",&cap);fflush(stdin);
					printf("So luong hoc vien can xep hang: %d\n",n);
					printf("So luong hoc vien toi da: %d\n",cap);
					for (int i=0;i<cap;i++) a[i] = 0;
					break;
				}
					
				case '2': {
					printf("Ban da chon chuc nang 2. Hay nhap thong tin cho hoc vien:\n");
					printf("Ten: ");fgets(name,sizeof(name),stdin);fflush(stdin);xxd(name);
					printf("ID: ");scanf("%s",ID);fflush(stdin);
					printf("Grade: ");scanf("%s",grade);fflush(stdin);
					printf("Height: ");scanf("%lf",&height);fflush(stdin);
					printf("Chi so hang mong dung: ");scanf("%d",&pos);fflush(stdin);
					if (a[pos] == 0) {
						insert(hv,name,grade,ID,height,pos);
						a[pos]++;
						num++;
					}
					else {
						for (blank=pos;blank>=0;blank--)
							if (a[blank] == 0) break;
						printf("Vi tri %d da co nguoi dung, nhung vi tri %d truoc do van trong!\n",pos,blank);
					}
					printf("So luong hoc vien trong hang: %d\n",num);
					break;
				}
					
				case '3': {
					printf("Nhap chieu cao can tim: ");scanf("%lf",&height);fflush(stdin);
					for (int i=0;i<cap;i++) 
						if (hv[i].height == height) {
							count++;
							print(hv,i);
						}
					if (count == 0) printf("Khong tim thay hoc vien!");
					count = 0;
					break;
				}
					
					
		    	case '4': {
		    		printf("ID: ");scanf("%s",ID);fflush(stdin);
		    		for (int i=0;i<cap;i++) 
						if (strcmp(hv[i].ID,ID)==0) {
							del(hv,i,a);
						}
		    		printf("Khong tim thay hoc vien!");
					break;
				}
		    	case '5': 
		    		return 0;
		}
		printf("\n\n********\n\n");
	} while (chon != '5');
}
