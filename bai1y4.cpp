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

void Enqueue(Address queue[], Address element, int *rear, int arraySize) {
    if(*rear == arraySize)            
        printf("OverFlow\n");
    else {
        queue[*rear] = element;    
        *rear++;
    }
}
 
 
void Dequeue(Address queue[], int& front, int rear) {
    if(front == rear)            // Queue is empty
        printf("UnderFlow\n");
    else {
    	Address temp;
        queue[front] = temp;        // Delete the front element
        front++;
    }
}

void loadFile(Address ad[], int size){
 	FILE *file;
 	file = fopen("address.txt", "r");
    if(file == NULL) {
      printf("Error!");   
      exit(1);             
    }
    int rear = 0;
    Address temp;
    while (1) {
        fscanf(file,"%s", temp.ten);
		if (strcmp("#", temp.ten) == 0) break;
		fscanf(file,"%s", temp.phone);
		fscanf(file,"%s",temp.email);
        Enqueue(ad,temp,&rear,size);
    }
    fclose(file);
} 
char Front(char queue[], int front) {
    return queue[front];
}
int main() {
	Address ad[100];
    char ten[256];
    printf("Bat dau thuc hien!\n");
    int size = 10,rear=0;
    loadFile(ad,size);
    mergeSort(ad,0,size-1);
	print(ad,size);
	
	return 0;
}
