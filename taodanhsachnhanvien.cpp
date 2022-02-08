#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

typedef struct nhanvien{
	char ho[20];
	char dem[20];
	char ten[20];
	char hoten[256];
	int dd;
	int mm;
	int yy;	
}NhanVien;

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

void gen(NhanVien nv[], int n) {
	char ho[7][20] = {"Nguyen ","Ta ","Vu ","Do ","Hoang ","Le ","Pham "};
    char dem[7][20] = {"Van ","Thi ","Thanh ","Hieu ","Duc ","Trung ","Ngoc "};
    char ten[7][20] = {"Mai","Hiep","Hieu","Huy","Hoang","Anh","Thanh"};
    int rho,rdem,rten,i;
    for (i=0;i<n;i++) {
    	rho=random(1,7);strcpy(nv[i].ho,ho[rho-1]);
    	rdem=random(1,7);strcpy(nv[i].dem,dem[rdem-1]);
    	rten=random(1,7);strcpy(nv[i].ten,ten[rten-1]);
    	nv[i].dd = random(3,30);
    	nv[i].mm = random(1,12);
    	nv[i].yy = random(1970,2000);
    	strcat(nv[i].hoten,nv[i].ho);strcat(nv[i].hoten,nv[i].dem);strcat(nv[i].hoten,nv[i].ten);
	}
}
void print(NhanVien nv[], int n) {
	int i;
	for (i=0;i<n;i++) {
		printf("%s %s %s\n",nv[i].ho,nv[i].dem,nv[i].ten);
    	printf("%4d-%2d-%2d\n",nv[i].yy,nv[i].mm,nv[i].dd);
	}
}

void printFile(NhanVien nv[],int n) {
	FILE *fptr;
   	fptr = fopen("nhanvien.txt","w");
    if(fptr == NULL) {
      printf("Error!");   
      exit(1);             
    }
 	int i;
	for (i=0;i<n;i++) {
    	fprintf(fptr,"%s\n",nv[i].hoten);
    	fprintf(fptr,"%4d-%2d-%2d\n",nv[i].yy,nv[i].mm,nv[i].dd);
	}
	fprintf(fptr, "%c",'#');
    fclose(fptr);
}

void loadFile(NhanVien nv[], int *n){
 	FILE *file;
    file = fopen("nhanvien.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    int i;
    while (1) {
        fscanf(file,"%s %s %s",nv[i].ho, nv[i].dem , nv[i].ten);
		fscanf(file,"%d-%d-%d", &nv[i].yy , &nv[i].mm , &nv[i].dd);
        if (strcmp("#", nv[i].ho) == 0) break;
        i++;
    }
    *n = i;
    fclose(file);
}

int Compare(NhanVien nv1, NhanVien nv2) {
	int tTen = strcmp(nv1.ten,nv2.ten);
	int tDem = strcmp(nv1.dem,nv2.dem);
	int tHo = strcmp(nv1.ho,nv2.ho);
	if (tTen != 0) return tTen;
	else {
		if (tDem != 0) return tDem;
		else {
			if (tHo != 0) return tHo;
			else {
				if (nv1.yy<nv2.yy) return -1;
				else if (nv1.yy==nv2.yy) {
					if (nv1.mm<nv2.mm) return -1;
					else if (nv1.mm==nv2.mm) {
						if (nv1.dd<nv2.dd) return -1;
						else return 1;
					}
					else return 1;
				}
				else return 1;
			}
		}
		
	}
}


void merge(NhanVien arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    NhanVien L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (Compare(L[i],R[j])<0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}
 
void mergeSort(NhanVien arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void swap (NhanVien &a,NhanVien &b) {
	NhanVien temp = a;
	a = b;
	b = temp; 
}

int partition (NhanVien nv[], int low, int high)
{
    NhanVien pivot = nv[high];   
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && Compare(nv[left],pivot)<0) left++;
        while(right >= left && Compare(nv[left],pivot)>0) right--;
        if (left >= right) break;
        swap(nv[left], nv[right]);
        left++;
        right--;
    }
    swap(nv[left],nv[high]);
    return left;
}
 
void quickSort(NhanVien nv[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(nv, low, high);
        quickSort(nv, low, pi - 1);
        quickSort(nv, pi + 1, high);
    }
}

int main() {
	NhanVien nv[100];
    srand((int)time(0));
    int n;
        
	loadFile(nv,&n);
    
	
	quickSort(nv,0,n-1);
	print(nv,n);
	return 0;
}
