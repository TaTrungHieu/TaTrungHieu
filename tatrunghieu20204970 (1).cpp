#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

typedef struct {
	int id;
	char qg[5];
	char ten[30];
	double r[3];
	double kq;
} olp;

void xoaxuongdong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n') x[len-1]='\0';
}

void kqf(olp vdv[], int n) {
	for (int i = 0; i < n; i++) {
		vdv[i].kq = vdv[i].r[0];
		if (vdv[i].kq <= vdv[i].r[1]) vdv[i].kq = vdv[i].r[1]; 
		if (vdv[i].kq <= vdv[i].r[2]) vdv[i].kq = vdv[i].r[2]; 
	}
}

void nhap (olp vdv[], int n) {
	for (int i = 0; i < n; i++) {
		printf("VDV thu %d:\n", i+1);
		fflush(stdin);
		printf("Nhap ID: ");scanf("%d", &vdv[i].id);
		fflush(stdin);
		printf("Nhap quoc gia (3 chu cai in hoa): ");scanf("%s",vdv[i].qg);
		fflush(stdin);
		printf("Nhap ten VDV: ");fgets(vdv[i].ten, sizeof(vdv[i].ten), stdin);xoaxuongdong(vdv[i].ten);
	}
}

void in (olp vdv[], int n) {
	printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
	for (int i = 0; i < n; i++) {
		printf("%-8d %-8s %-25s \n", vdv[i].id, vdv[i].qg, vdv[i].ten);
	}
}

void cnkq(olp vdv[], int n) {
	printf("Luot nhay 1:\n");
		for (int i = 0; i < n; i++) {
			printf("Thanh tich cua van dong vien %d: ",i+1);scanf("%lf", &vdv[i].r[0]);fflush(stdin);
			while (vdv[i].r[0] > 20 || vdv[i].r[0] < 0) {
				printf("Ket qua khong hop le, hay nhap lai!");scanf("%lf", &vdv[i].r[0]);fflush(stdin);
			} 
		}
		printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			printf("%-8d %-8s %-25s %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0]);fflush(stdin);
		}
		
		
	printf("Luot nhay 2:\n");
		for (int i = 0; i < n; i++) {
			printf("Thanh tich cua van dong vien %d: ",i+1);scanf("%lf", &vdv[i].r[1]);fflush(stdin);
			while (vdv[i].r[1] > 20 || vdv[i].r[1] < 0) {
				printf("Ket qua khong hop le, hay nhap lai!");scanf("%lf", &vdv[i].r[1]);fflush(stdin);
			} 
		}
		printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			printf("%-8d %-8s %-25s %-8.2lf %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0], vdv[i].r[1]);
		}
		
		
	printf("Luot nhay 3:\n");
		for (int i = 0; i < n; i++) {
			printf("Thanh tich cua van dong vien %d: ",i+1);scanf("%lf", &vdv[i].r[2]);fflush(stdin);
			while (vdv[i].r[2] > 20 || vdv[i].r[2] < 0) {
				printf("Ket qua khong hop le, hay nhap lai!");scanf("%lf", &vdv[i].r[2]);fflush(stdin);
			} 
		}
		kqf(vdv,n);
		printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			printf("%-8d %-8s %-25s %-8.2lf %-8.2lf %-8.2lf %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0], vdv[i].r[1], vdv[i].r[2], vdv[i].kq);
		}
		fflush(stdin);
	}
	
void sx(olp vdv[], int n) {
	olp tmp;
	for (int i = 0; i < n; i++) 
		for (int j = i+1; j < n; j++) 
			if (vdv[i].kq < vdv[j].kq) {
				tmp = vdv[i];
				vdv[i] = vdv[j];
				vdv[j] = tmp;
			}
	printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
		for (int i = 0; i < n; i++) {
			printf("%-8d %-8s %-25s %-8.2lf %-8.2lf %-8.2lf %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0], vdv[i].r[1], vdv[i].r[2], vdv[i].kq);
		}
}
	
int main () {
	olp vdv[20];
	char chon, chon4,qg[5],ten[30];
	int n, dem=0,dem3=0;
	do {
		printf("MENU");
		printf("\n1-Nhap thong tin van dong vien");
		printf("\n2-In danh sach van dong vien");
		printf("\n3-Cap nhat ket qua thi dau");
		printf("\n4-Tim kiem");
		printf("\n5-In ket qua");
		printf("\n6-Thoat");
		printf("\nNhap lua chon cua ban: "); scanf("%c", &chon); fflush(stdin);
			while (chon != '4' && chon != '3' && chon != '2' && chon != '1' && chon != '5' && chon != '6')  {
				printf("Lua chon khong hop le! Nhap lai: "); 
				scanf("%c", &chon);
				fflush(stdin);
			}
			switch(chon) {
				case '1': 
					if (dem != 0) {
						printf("Ban da nhap roi! Hay lua chon cac chuc nang khac!");
						break;
					}
					do {
						fflush(stdin);
						printf("Nhap so luong van dong vien: ");
						scanf("%d", &n);
					} while( n <= 0 || n > 20);
					nhap(vdv,n);
					dem++;
					break;
					
				case '2': 
					if (dem == 0) {
						printf("Phai thuc hien chuc nang 1 truoc!"); 
						break;
					}
		 			in(vdv,n);
		 			break;
				
				case '3': 
					if (dem == 0) {
						printf("Phai thuc hien chuc nang 1 truoc!"); 
						break;
					}
					cnkq(vdv,n);
					dem3++;
		    		break;
		    
				case '4': 
		    		if (dem == 0) {
						printf("Phai thuc hien chuc nang 1 truoc!"); 
						break;
					}
					if (dem3 == 0) {
						printf("Phai thuc hien chuc nang 3 truoc!"); 
						break;
					}
		    		printf("\n1-Tim kiem theo quoc gia:");
		    		printf("\n2-Tim kiem theo ten van dong vien:");
		    		printf("\nNhap lua chon cua ban: "); scanf("%c", &chon4); fflush(stdin);
					while (chon4 != '1' && chon4 != '2')  {
						printf("Lua chon khong hop le! Nhap lai: "); 
						scanf("%c", &chon);
						fflush(stdin);
					}
					switch(chon4) {
						case '1':
							printf("Nhap ten quoc gia can tim kiem (3 chu cai in hoa): ");scanf("%s",qg);fflush(stdin);
							printf("%-8s %-8s %-25s %-8s %-8s %-8s %-8s\n", "ID", "Nation", "Name", "R1", "R2", "R3", "FR");
							for (int i = 0; i<n; i++) {
								if (strcmp(vdv[i].qg,qg)==0) 
									printf("%-8d %-8s %-25s %-8.2lf %-8.2lf %-8.2lf %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0], vdv[i].r[1], vdv[i].r[2], vdv[i].kq);
							}
							break;
						case '2':	
							printf("Nhap ten van dong vien can tim kiem: ");fgets(ten, sizeof(ten), stdin);xoaxuongdong(ten);fflush(stdin);
							for (int i = 0; i<n; i++) {
								if (strcmp(vdv[i].ten,ten)==0) 
									printf("%-8d %-8s %-25s %-8.2lf %-8.2lf %-8.2lf %-8.2lf\n", vdv[i].id, vdv[i].qg, vdv[i].ten, vdv[i].r[0], vdv[i].r[1], vdv[i].r[2], vdv[i].kq);
							}
							break;	
					}
		    		break;
				
				case '5': 
		    		if (dem == 0) {
						printf("Phai thuc hien chuc nang 1 truoc!"); 
						break;
					}
					if (dem3 == 0) {
						printf("Phai thuc hien chuc nang 3 truoc!"); 
						break;
					}
		    		sx(vdv,n);
		    		break;
		    	case '6': 
		    		return 0;
		}
		printf("\n\n********\n\n");
	} while (chon != '6');
}
