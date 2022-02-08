#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int start[5][3] = {{0,1,2},{1,2,0},{2,1,0},{0,2,1},{1,2,0}};
typedef struct {
	int puz[5][3] = {{0,1,2},{1,2,0},{2,1,0},{0,2,1},{1,2,0}};
}config;
typedef struct {
	char ten[256];
	int point = 0;
	int color;
	char Col[256];
}game;

void Print(int a[][3]) {
	int i,j;
	printf("\n|--------------------|\n");
	for (i=0;i<5;i++) {
		for (j = 0; j<3; j++) {
			if (a[i][j] == 0) printf("| %5s", "Xanh");
			if (a[i][j] == 1) printf("| %5s", "Vang");
			if (a[i][j] == 2) printf("| %5s", "Do");
		}
		printf("|\n");
		printf("|--------------------|\n\n");
	}
}

void Change(int a[][3]) {
	int i,j,m,n,color;
	printf("Nhap chi so hang (1<=m<=5):"); scanf("%d",&m);fflush(stdin);
	while ( m<1 || m > 5) {
		printf("Khong hop le! Xin moi nhap lai (1<=m<=5):"); scanf("%d",&m);fflush(stdin);
	}
	
	
	printf("Nhap chi so cot (1<=n<=3):"); scanf("%d",&n);fflush(stdin);
	while ( n<1 || n > 3) {
		printf("Khong hop le! Xin moi nhap lai (1<=n<=3):"); scanf("%d",&n);fflush(stdin);
	}
	
	
	printf("O hien tai dang la mau");
	if (a[m-1][n-1] == 0) printf(" Xanh. ");
	if (a[m-1][n-1] == 1) printf(" Vang. ");
	if (a[m-1][n-1] == 2) printf(" Do. ");
	
	
	printf("Ban muon doi thanh o mau gi?\n0. Xanh\n1. Vang\n2. Do\n");scanf("%d",&color);fflush(stdin);
	while ( color != 0 && color != 1 && color != 2) {
		printf("Khong hop le! Xin moi nhap lai:"); scanf("%d",&color);fflush(stdin);
	}
	
	
	if (a[m-1][n-1] == color) {
		printf("Mau ban da chon khong thay doi!\n");Print(a);
	}
	
	else {
		int temp = a[m-1][n-1];
		for (int j=0;j<3;j++) {
			if (a[m-1][j] == color) a[m-1][j] = temp;
		}
		a[m-1][n-1] = color;
		Print(a);
	}
}

void Game(int a[][3], int &point, int color) {
	int i,j,m,n;
	for(m=0; m<5; m++) {
		
		printf("\nDang o hang thu %d:\n",m+1);
		printf("Nhap chi so cot (1<=n<=3):"); scanf("%d",&n);fflush(stdin);
		while ( n<1 || n > 3) {
			printf("Khong hop le! Xin moi nhap lai (1<=n<=3):"); scanf("%d",&n);fflush(stdin);
		}
				
		printf("\nO ban vua di vao la mau");
		if (a[m][n-1] == 0) printf(" Xanh. ");
		if (a[m][n-1] == 1) printf(" Vang. ");
		if (a[m][n-1] == 2) printf(" Do. ");
		printf("\n");
		
		if (a[m][n-1] == color) {
			printf("\nBan duoc cong 1 diem!\n");
			point++;
		}
	}
}
	
void Diem(game player[]) {
	printf("|%10s| %20s| %10s| %10s|\n","Round","Player","Color","Score");
	int i;
	for (i=0;i<4;i++) {
		printf("|%10d| %20s| %10s| %10d|\n",i+1,player[i].ten,player[i].Col,player[i].point);
	}
}
void xoaxuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}

int main() {
	char choice,choice3;
	int count;
	int N=0,B;
	config single;
	game player[4]; 
		
	do {
		printf("\n====Nhap vao so bat ky de thuc hien chuc nang====\n");
		printf("1) Khoi tao cau hinh game\n");
		printf("2) Thay doi cau hinh game\n");
		printf("3) Choi game\n");
		printf("4) Hien thi diem\n");
		printf("5) Thoat\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &choice);fflush(stdin);
				while (choice != '4' && choice != '3' && choice != '2' && choice != '1' && choice != '5')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &choice);fflush(stdin);
				}
			switch (choice) {
				case '1': Print(start);
					break;
				case '2': Change(single.puz); 
					break;
				case '3': {
					int i,j;
					for (i=0; i<4; i++) {
						printf("Player %d:\n",i+1);
						printf("Ten: ");fgets(player[i].ten,sizeof(player[i].ten),stdin);xoaxuongdong(player[i].ten);
						printf("Color:\n0. Xanh\n1. Vang\n2. Do\n");scanf("%d",&player[i].color);fflush(stdin);
						while ( player[i].color != 0 && player[i].color != 1 && player[i].color != 2) {
							printf("Khong hop le! Xin moi nhap lai:"); scanf("%d",&player[i].color);fflush(stdin);
						}
						if (player[i].color == 0) strcpy(player[i].Col,"Xanh");
						if (player[i].color == 1) strcpy(player[i].Col,"Vang");
						if (player[i].color == 2) strcpy(player[i].Col,"Do");
						Game(start,player[i].point,player[i].color);
					}
					count = 1;
					break;
				}
				
				case '4': 
					if (count != 1) {
						printf("\nChoi game di da thi moi hien thi bang diem duoc!\n");
						break;	
					}
					Diem(player);
					break;
				case '5': return 0;
									
			}
	} while (choice != '5');
	return 0;
} 
