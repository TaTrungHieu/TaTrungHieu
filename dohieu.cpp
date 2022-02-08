#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxx 100
void xoaXuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}
typedef struct Cuahang{
	int id;
	char goods[maxx];
}Store;
Store list[maxx];
int n;
void Tachchuoi(char Src[], char Des1[], char Des2[]){
	int k=0;
	while (Src[k] != '\t') k++;
	for (int i=0; i<k; i++) Des1[i]=Src[i];
	for (int j=k+1;j<n; j++) Des2[j-k-1]=Src[j];
}
void Sapxep(char s[]){
	size_t len = strlen(s);
	for (int i=0; i<len; i++){
		if (s[i]==',') continue;
		for (int j=i+1; j<len;j++){
			if (s[j] != ',')
				if (s[i]>s[j]){
					char tmp=s[i];
					s[i]=s[j];
					s[j]=tmp;
			}
		}
	}
}
void Nhap(){
	FILE * f=fopen("Input.txt", "r");
	fscanf(f,"%d\n",&n);
	char buf[maxx];
	int i=0;
	while (!feof(f)){
		fgets(buf, 256, f);
		char ID[10],Goods[maxx];
		Tachchuoi(buf,ID,Goods);
		Sapxep(Goods);
		list[i].id=atoi(ID);
		strcpy(list[i].goods,Goods);
		i++;
		fflush(stdin);
		}
	for (int i=0; i<n; i++){
		printf("%d-%s", list[i].id, list[i].goods);}
	fclose(f);
}	
int isexist(char c[]){
	for (int i=0; i<n; i++){
		if(list[i].id == atoi(c)){
			return i;
		}
	}
	return -1;
}	
void Chucnang1(){
	char c[10];
	printf("Hay nhap ten cua hang ma ban muon xem: ");
	scanf("%s", &c);
	if (isexist(c)!=-1){
			int i=isexist(c);
			puts(list[i].goods);
		}
	return;
	}
	
int isGoods(char c,int i){
	int x=strlen(list[i].goods);
	for (int k=0; k<x; k++){
		if (list[i].goods[k] == c) return i;
	}
	return -1;
}
void Chucnang2(){
	char s[10],c;
	while(strcmp(s,"Q")!=0){
		fflush(stdin);
		printf("Nhap ten cua hang: ");
		scanf("%s", &s);
		if (strcmp(s,"Q")==0) break;
		if (isexist(s)==-1) printf("Nhap sai ten cua hang, hay nhap lai!\n");
		else {
			int i=isexist(s);
			while(isGoods(c,i)==-1){
				fflush(stdin);
				printf("Nhap ten mon hang: ");
				scanf("%c", &c);
				if (isGoods(c,i)==-1) printf("Nhap sai ten mon hang, hay nhap lai!\n");
			}
			int k=isGoods(c,i);
			strcpy(&list[i].goods[k],&list[i].goods[k+2]);
		}
	}
}
void Chucnang3(){
	char s[10],c[10];
	int test=1;
	while(strcmp(s,"Q")!=0){
		fflush(stdin);
		printf("Nhap ten cua hang: ");
		scanf("%s", &s);
		if (strcmp(s,"Q")==0) break;
		if (isexist(s)!=-1) printf("Nhap sai ten cua hang, hay nhap lai!\n");
		else {
			int i=atoi(s);
			list[n+1].id=i;
			do{
				printf("Hay nhap danh sach mon hang cho cua hang moi: \n");
				scanf("%s", c);
				for (int i=0; i<strlen(c); i++){
				if(c[i]==',') continue;
				else{
					for (int j=0; j<n; j++)
						if(!isGoods(c[i],j) == -1) test = 0;
					}
				}
				if (test == 0) printf("Co mon hang khong ton tai, hay nhap lai!\n");
			}while(test == 0);
			strcpy(list[n+1].goods,c);
			n++;
		}
	}
}
void Chucnang4(){
	char s[10],c;
	Store ktra[n];
	int N;
	int S=0;
	do{
		printf("Nhap so cua hang muon di kiem tra: ");
		scanf("%d", &N);
	}while(N>n);
	int check=1;
	while(check<N){
		fflush(stdin);
		printf("Nhap ten cua hang: ");
		scanf("%s", &s);
		if (isexist(s) ==-1 || ktra[check-3].id==ktra[check].id) printf("Nhap sai ten cua hang, hay nhap lai!\n");
		else {
			int i=isexist(s);
			while(isGoods(c,i)==-1){
				fflush(stdin);
				printf("Nhap ten mon hang: ");
				scanf("%c", &c);
				if (isGoods(c,i)==-1 || strcmp(ktra[check-1].goods,ktra[check].goods) == 0) printf("Nhap sai ten mon hang, hay nhap lai!\n");
				else{
					ktra[check].id=i;
				
					S+=50;
					check++;
				}
			}
			
		}
	}
	printf("Chi phi tinh toan: %d", S);
}
int main() {
	int chon;
	Nhap();
	do{
		printf("Ban hay nhap chuc nang can thuc hien:\n");
		printf("1. Xac dinh cac mon hang trong cua hang\n");
		printf("2. Xoa di cac mon hang cua mot cua hang\n");
		printf("3. Them mot cua hang va cac mon hang trong do\n");
		printf("4. Tinh toan chi phi di lai\n");
		printf("5. Thoat\n");
		scanf("%d", &chon);
		switch(chon){
			case 1: Chucnang1(); break;
			case 2: Chucnang2(); break;
			case 3: Chucnang3(); break;
			case 4: Chucnang4(); break;
			case 5: break;
			default: {
				printf("Ki tu ban nhap vao khong hop le, hay nhap lai!\n");
				fflush(stdin);
				break;
				}
		}
	}while (chon != 5);
}

