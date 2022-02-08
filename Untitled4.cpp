#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
	int key;
	char type[256];
}child;

void xoaxuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}

void LoadA(child kid[], int &num) {
	int i = 0;
	FILE *file;
    file = fopen("A.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    while (1) {
        fscanf(file,"%d\t%s",&kid[i].key, kid[i].type);
        if (strcmp(kid[i].type,":::")<0) strcpy(kid[i].type,"\n");
		if (kid[i].key == 0) break;
		printf("%d\t:%s \n",kid[i].key, kid[i].type);
		i++;
    }
    num = i;
    fclose(file);
}
int main() {
	char choice;
	child kid[100];
	int num;
	
		
	do {
		printf("\n====Nhap vao so bat ky de thuc hien chuc nang====\n");
		printf("1) Load file A\n");
		printf("2) Load file B\n");
		printf("3) Tim kiem\n");
		printf("4) Tong hop\n");
		printf("5) Thong ke\n");
		printf("6) Thoat\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &choice);fflush(stdin);
				while (choice != '4' && choice != '3' && choice != '2' && choice != '1' && choice != '5' && choice != '6')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &choice);fflush(stdin);
				}
			switch (choice) {
				case '1': 
					LoadA(kid,num);
					break;
				case '2':  
					break;
				case '3':
					break;
				case '4': 
					break;
				case '5': 
					break;
				case '6': return 0;
									
			}
	} while (choice != '6');
	return 0;
} 
