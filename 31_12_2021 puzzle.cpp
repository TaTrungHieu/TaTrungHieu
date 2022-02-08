#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
	int puz[7][7];
	int empi;
	int empj;
}config;

void Print(int a[][7], int N) {
	int i,j,k;
	for (k=0; k<2*N+1; k++) printf("%c",'*');
	printf("\n");
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (a[i][j] != 0) printf("%c%d",'*',a[i][j]);
			else printf("%c ",'*');
		}
		printf("%c\n",'*');
	}
	for (k=0; k<2*N+1; k++) printf("%c",'*');
	printf("\n");	
}

void Up (config num[], int N,int &count) {
	num[count] = num[count-1];
	int i = num[count].empi,j = num[count].empj;
	if (num[count].empi==N-1) {
		printf("Khong the thuc hien chuc nang Up!\n");
		return;
	} else {
		num[count].puz[i][j] = num[count].puz[i+1][j];
		num[count].puz[i+1][j] = 0;
		num[count].empi++;
		count++;
	}
	
}

void Down (config num[], int N,int &count) {
	num[count] = num[count-1];
	int i = num[count].empi,j = num[count].empj;
	if (num[count].empi==0) {
		printf("Khong the thuc hien chuc nang Down!\n");
		return;
	} else {
		num[count].puz[i][j] = num[count].puz[i-1][j];
		num[count].puz[i-1][j] = 0;
		num[count].empi--;
		count++;
	}
	
}

void Left (config num[], int N,int &count) {
	num[count] = num[count-1];
	int i = num[count].empi,j = num[count].empj;
	if (num[count].empj==N-1) {
		printf("Khong the thuc hien chuc nang Left!\n");
		return;
	} else {
		num[count].puz[i][j] = num[count].puz[i][j+1];
		num[count].puz[i][j+1] = 0;
		num[count].empj++;
		count++;
	}
	
}

void Right (config num[], int N,int &count) {
	num[count] = num[count-1];
	int i = num[count].empi,j = num[count].empj;
	if (num[count].empj==0) {
		printf("Khong the thuc hien chuc nang Right!\n");
		return;
	} else {
		num[count].puz[i][j] = num[count].puz[i][j-1];
		num[count].puz[i][j-1] = 0;
		num[count].empj--;
		count++;
	}
	
}
	

int main() {
	char choice,choice3;
	int count;
	int N=0,B;
	config num[1000];
	do {
		printf("====Nhap vao so bat ky de thuc hien chuc nang====\n");
		printf("1) Nhap vao gia tri N (kich thuoc puzzle)\n");
		printf("2) Nhap lan luot gia tri X cho tung o (Chu y 0 <=X<N*N)\n");
		printf("3) Di chuyen\n");
		printf("4) Rollback\n");
		printf("5) In cau hinh hien tai\n");
		printf("6) Thoat\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &choice);fflush(stdin);
				while (choice != '4' && choice != '3' && choice != '2' && choice != '1' && choice != '5' && choice != '6')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &choice);fflush(stdin);
				}
			switch (choice) {
				case '1': 
					printf("Nhap N (3<=N<=7): ");scanf("%d",&N);fflush(stdin);
					while (N > 7 || N < 3)  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%d", &N);fflush(stdin);
				}
				count = 0;
					break;
				case '2': {
					if (0==N) {
						printf("Ban phai nhap N truoc!\n");
						printf("Nhap N (3<=N<=7): ");scanf("%d",&N);fflush(stdin);
						while (N > 7 || N < 3)  {
						printf("Lua chon khong hop le! Nhap lai: "); 
						scanf("%d", &N);fflush(stdin);
						}
					}
					int i,j;
					for (i=0;i<N;i++) 
						for (j=0;j<N;j++) {
							printf("Nhap phan tu o vi tri [%d][%d]: ",i,j);
							scanf("%d", &num[0].puz[i][j]);fflush(stdin);
							if (num[0].puz[i][j] == 0) {
								num[0].empi = i;
								num[0].empj = j;
							}
						}
					count = 1;
					break;
				}
				case '3': {
					printf("U. Up\n");
					printf("D. Down\n");
					printf("L. Left\n");
					printf("R. Right\n");
					printf("Q. Quit\n");
					printf("\nNhap lua chon cua ban: "); scanf("%c", &choice3);fflush(stdin);
					while (choice3 != 'U' && choice3 != 'D' && choice3 != 'L' && choice3 != 'R' && choice3 != 'Q')  {
						printf("Lua chon khong hop le! Nhap lai: "); 
						scanf("%c", &choice3);fflush(stdin);
					}		
					switch (choice3) {
						case 'U': 
							Up(num,N,count);
							Print(num[count-1].puz,N);
							break;
						case 'D':
							Down(num,N,count);
							Print(num[count-1].puz,N);
							break;
						case 'L':
							Left(num,N,count);
							Print(num[count-1].puz,N);
							break;
						case 'R':
							Right(num,N,count);
							Print(num[count-1].puz,N);
							break;	
					}
					break;
				}
				case '4': 
					printf("Nhap so buoc can rollback: ");scanf("%d",&B);fflush(stdin);
					count=count - B;
					break;
				case '5': 
					Print(num[count-1].puz,N);
					break;
				case '6': return 0;
									
			}
	} while (choice != '6');
	return 0;
} 
