#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct {
	int num;
	char item[10];
}store;

int Check(store shop[], int n) {
	int i = 0;
	while(shop[i].num != 0) {
		if (shop[i].num == n) return n;
		i++;
	}
	return -1;
}

int Check4(char x[], char c) {
	size_t len = strlen(x);
	int i;
	for (i = 0; i < len; i++ ) if (c == x[i]) return 1;
	return 0;
}

int CheckNum(store shop[], int n) {
	int i = 0;
	while(shop[i].num != 0) {
		if (shop[i].num == n) return i;
		i++;
	}
	return -1;
}
void Tach (char x[]) {
	size_t len = strlen(x);
	int i;
	for (i = 0; i < len; i++) 
		if (x[i] == ',') {
			int j;
			for (j = i; j < len; j++) x[j] = x[j+1];
		}
	return;
}

void Load(int &num, store shop[]) {
	int i = 0,j;
	FILE *file;
    file = fopen("Input.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    fscanf(file,"%d\n",&j);
    num = j;
    while (i<num) {
        fscanf(file,"%d\t%s",&shop[i].num, shop[i].item);
        if (shop[i].num == 0) break;
        Tach(shop[i].item);
		i++;
    }
    fclose(file);
}

void Item(char x[]) {
	size_t len = strlen(x);
	int i,j;
	for (i = 0; i < len; i++)
		for (j = i; j < len; j++) 
			if (x[i] > x[j]) {
				char temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
	for (i = 0; i < len-1; i++) printf("%c,",x[i]);
	printf("%c\n",x[len-1]);
	return;
}

void Thongke(store shop[],int &num) {
	int n;
	printf("Ban vua chon chuc nang thong ke!\n");
	printf("Nhap so hieu cua hang muon thong ke:");scanf("%d",&n);fflush(stdin);
	if (Check(shop,n)==-1) {
		printf("So hieu cua hang khong hop le!\nChuong trinh tu dong thoat chuc nang hien tai!"); 
		return;
	}
	printf("Cac san pham trong cua hang mang so hieu %d: ",n);Item(shop[CheckNum(shop,n)].item);
	return;
}

void XoaItem(store shop[],int &num) {
	int n,k,p,count = 0;
	char i;
	printf("Ban vua chon chuc nang xoa san pham!\n");
	printf("Nhap so hieu cua hang muon xoa san pham:");scanf("%d",&n);fflush(stdin);
	if (Check(shop,n)==-1) {
		printf("So hieu cua hang khong hop le!\nChuong trinh tu dong thoat chuc nang hien tai!"); 
		return;
	}
	printf("Cac san pham trong cua hang mang so hieu %d: ",n);Item(shop[CheckNum(shop,n)].item);
	do {
		printf("\nBan muon xoa san pham nao (Neu muon thoat hay nhap Q): ");scanf("%c",&i);fflush(stdin);
		if (i == 'Q') return;
		size_t len = strlen(shop[CheckNum(shop,n)].item);
		if (len == 1) if (shop[CheckNum(shop,n)].item[0] == i) {
			shop[CheckNum(shop,n)].item[0] =' ';
			printf("\nDa xoa xong!\nCua hang da chon hien khong con san pham!\nChuong trinh tu dong thoat chuc nang hien tai!\n");
			return;
		}
		for (k = 0; k < len; k++) 
			if (shop[CheckNum(shop,n)].item[k] == i) {
				for (p = k; p < len; p++) shop[CheckNum(shop,n)].item[p] = shop[CheckNum(shop,n)].item[p+1];
				count = 1;
			}
		if (count == 0) printf("\nSan pham ban vua nhap khong co trong cua hang!\n");		
	} while (i != 'Q');
	return;	
}

void Them(store shop[],int &num) {
	int n;
	printf("Ban vua chon chuc nang them 1 cua hang!\n");
	printf("Nhap so hieu cua hang: ");scanf("%d",&n);fflush(stdin);
	while (Check(shop,n) != -1) {
		printf("So hieu khong hop le, hay nhap lai!");scanf("%d",&n);fflush(stdin);
	}
	shop[num].num = n;
	printf("Cua hang duoc them se mang so hieu: %d\n",n);
	int i = 0;
	char c;
	do {
		printf("Nhap ten san pham thu %d trong cua hang mang so hieu %d (Neu muon thoat hay nhap Q): ",i+1,n);	
		scanf("%c",&c);fflush(stdin);
		if (c == 'Q') break;
		if (c != 'A' && c != 'B' && c != 'C' && c != 'D' ) printf("San pham nay khong nam trong danh sach san pham da co tai cac cua hang khac!\n");
		else {
			shop[num].item[i] = c;
			i++;
		}
	} while (c != 'Q');
	num++;
	
}
	
void ChiPhi(store shop[], char q4[], int shop4[]) {
	int N,n,i;
	char c;
	printf("Ban vua chon chuc nang tinh toan chi phi di lai!\n");
	printf("Nhap so luong cua hang can kiem tra N: ");scanf("%d",&N);fflush(stdin);
	for (i = 0; i < N; i++) {
		printf("Nhap so hieu cua hang thu %d muon kiem tra:",i+1);scanf("%d",&n);fflush(stdin);
		if (Check(shop,n)==-1) {
			printf("So hieu cua hang khong hop le!\nChuong trinh tu dong thoat chuc nang hien tai!"); 
			return;
		}
		printf("Cac san pham trong cua hang mang so hieu %d: ",n);Item(shop[CheckNum(shop,n)].item);
		size_t len = strlen(shop[CheckNum(shop,n)].item);
		if (len == 1) {
			printf("\nMac dinh chon san pham kiem tra la %c\n",shop[CheckNum(shop,n)].item[0]);
			q4[i] = shop[CheckNum(shop,n)].item[0];
		}
		else {
			printf("Ban muon kiem tra san pham nao: ");scanf("%c",&c);fflush(stdin);
			while (Check4(shop[CheckNum(shop,n)].item,c)!=1) {
				printf("Cua hang khong co san pham da chon!");
				printf("\nBan muon kiem tra san pham nao: ");scanf("%c",&c);fflush(stdin);
			} q4[i] = c;
		}
	}
}

int main() {
	char choice,choice3,q4[100];
	int count,num,shop4[100];
	int N=0,B;
	store shop[100];
	Load(num,shop);
	do {
		printf("\n====Ban hay chon chuc nang can thuc hien====\n");
		printf("1. Xac dinh cac mon hang trong cua hang\n");
		printf("2. Xoa di cac mon hang cua mot cua hang\n");
		printf("3. Them mot cua hang va cac mon hang trong do\n");
		printf("4. Tinh toan chi phi di lai\n");
		printf("5. Thoat\n");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &choice);fflush(stdin);
				while (choice != '4' && choice != '3' && choice != '2' && choice != '1' && choice != '5')  {
					printf("Lua chon khong hop le! Nhap lai: "); 
					scanf("%c", &choice);fflush(stdin);
				}
		
			switch (choice) {
				case '1': 
					Thongke(shop,num);
					break;
				case '2': 
					XoaItem(shop,num);
					break;
				case '3': 
					Them(shop,num);
					break;
				case '4': 
					ChiPhi(shop,q4,shop4);
					break;
				case '5': return 0;		
			}
	} while (choice != '5');
	return 0;
} 
