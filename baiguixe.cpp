#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void xoaxuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}
typedef struct Node{
	char name[256];
	int year;
	char brand[256];
} Node;

int main () {
	Node car[1000];
	char name3[256],name4[256];
	char cmd;
	int n,row,col,p=0;
	char park[100][100];
	for (int i=0;i < 100;i++) 
		for (int j=0;j<100;j++)	park[i][j] = '_';
	do {
	printf("====Program for management car parking====\n");
	printf("1) Numbers of Parking lots & columns:\n");
	printf("2) Insert new car:\n");
	printf("3) Search:\n");
	printf("4) Remove a car:\n");
	printf("5) Quit\n");
	scanf("%c",&cmd);fflush(stdin);
		while(cmd != '1' && cmd != '2' && cmd != '3' && cmd != '4' && cmd != '5') {
			printf("Lua chon khong hop le, hay nhap lai!");scanf("%c",&cmd);fflush(stdin);
		}
	switch (cmd) {
		case '1':
			printf("Nhap so luong cho de xe: ");scanf("%d",&n);fflush(stdin);
			printf("Nhap so luong cot: ");scanf("%d",&col);fflush(stdin);
			row=n/col;
			printf("So luong cho de xe: %d\nSo luong hang: %d\nSo luong cot: %d\n",n,row,col);
			break;
		case '2': {
			if (p == n) {
				printf("Bai do xe da day!\n");
				break;
			}
							 
			printf("Nhap bien so xe: ");fgets(car[p].name,sizeof(car[p].name),stdin);xoaxuongdong(car[p].name);fflush(stdin);
			printf("Nhap thuong hieu: ");fgets(car[p].brand,sizeof(car[p].brand),stdin);xoaxuongdong(car[p].brand);fflush(stdin);
			printf("Nhap nam san xuat: ");scanf("%d",&car[p].year);fflush(stdin);
	
			int dem = 0,tmp = p+1;
			while (tmp > row) {
				tmp -= row;dem++;
			}
			
			park[row - tmp][dem] = 'X';
			printf("Bai do xe hien tai:\n");
			for (int i=0;i < row;i++) {
				for (int j=0;j<col;j++)	printf("%c ",park[i][j]);
				printf("\n");
			} 
				
			p++;
			break;
		}
			
		case '3': 
		{
			printf("Nhap bien so xe can tim:");fgets(name3,sizeof(name3),stdin);xoaxuongdong(name3);fflush(stdin);
			int count;
			for (int i=0;i<=p;i++) 
				if (strcmp(car[i].name,name3)==0) {
					printf("Da tim thay xe!\n");
			int dem = 0,tmp = i+1;
			while (tmp > row) {
				tmp -= row;dem++;
			}
			printf("Xe can tim nam o toa do: [%d;%d]\n",row - tmp,dem);
			printf("Bien so xe: %s\n",car[i].name);
			printf("Thuong hieu: %s\n",car[i].brand);
			printf("Nam san xuat: %d\n",car[i].year);
					count++;
				}
			if (count == 0) printf("Khong tim thay xe!\n");
			break;
		}
		case '4':
		{	
		printf("Nhap bien so xe can di chuyen:");fgets(name4,sizeof(name4),stdin);xoaxuongdong(name4);fflush(stdin);
			int count2;
			for (int i=0;i<=p;i++) 
				if (strcmp(car[i].name,name4)==0) {
					printf("Da tim thay xe\n");
					count2++;
				}
			if (count2 == 0) printf("Khong tim thay xe!\n");
			break;
		}
		}
	} while (cmd != '5');
		
	
 return  0;
}
