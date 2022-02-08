#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}

int main() {
	srand((int)time(0));
	printf("1. Ta Trung Hieu - %d\n",random(0,5));
	printf("2. Do Trung Hieu - %d\n",random(0,5));
	printf("3. Dang Xuan Tung Trung Hieu - %d\n",random(0,5));
	printf("4. Tran Anh Tuan - %d\n",random(0,5));
	printf("5. Nguyen Thi Thu Huyen - %d\n",random(0,5));
	printf("6. Dao Trong Hoan - %d\n",random(0,5));
	
	return 0;
}
