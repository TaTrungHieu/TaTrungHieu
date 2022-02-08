#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct address{
	char ten[20];
	char phone[256];
	char email[256];	
}Address;



void print(Address ad[], int n) {
	int i;
	for (i=0;i<n;i++) {
		printf("%s\n",ad[i].ten);
    	printf("%s\n", ad[i].phone);
    	printf("%s\n", ad[i].email);
	}
}

void printFile(Address ad) {
	FILE *fptr;
   	fptr = fopen("addressoutput.txt","w");
    if(fptr == NULL) {
      printf("Error!");   
      exit(1);             
    }
 	fprintf(fptr,"%s\n",ad.ten);
    fprintf(fptr,"%s\n", ad.phone);
    fprintf(fptr,"%s\n", ad.email);
	fprintf(fptr, "%c",'#');
    fclose(fptr);
}

void loadFile(Address ad[], int *n){
 	FILE *file;
 	file = fopen("address.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    int i;
    while (1) {
        fscanf(file,"%s", ad[i].ten);
		if (strcmp("#", ad[i].ten) == 0) break;
		fscanf(file,"%s", ad[i].phone);
		fscanf(file,"%s",ad[i].email);
        i++;
    }
    *n = i;
    fclose(file);
}

int Compare(Address ad1, Address ad2) {
	return strcmp(ad1.ten,ad2.ten);
}


void merge(Address arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    Address L[n1], R[n2];
 
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
 
void mergeSort(Address arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void binarySearch(Address ad[], int n, char x[]) {
  int r = n - 1; 
  int l = 0; 
  while (r >= l) {
    int mid = l + (r - l) / 2; 
    if (strcmp(ad[mid].ten,x)==0) {
    	printf("Da tim thay! Ket qua:\n");
		printf("%s\n",ad[mid].ten);
    	printf("%s\n", ad[mid].phone);
    	printf("%s\n", ad[mid].email);
    	printFile(ad[mid]);
		return;
	}
       	
    if (strcmp(ad[mid].ten,x)>0) r = mid - 1;
    if (strcmp(ad[mid].ten,x)<0) l = mid + 1;
  	}
  	printf("Khong tim thay!");
 }
int main() {
	Address ad[100];
    char ten[256];
    printf("Bat dau thuc hien!\n");
    int n;
    loadFile(ad,&n);
    mergeSort(ad,0,n-1);
	print(ad,n);
	printf("Tim kiem nhi phan!\nHay nhap ten nguoi can tim: ");scanf("%s",ten);
	binarySearch(ad,n,ten);
	return 0;
}
