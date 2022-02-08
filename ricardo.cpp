#include<stdio.h>
#include<string.h>
int main () {
	char s[100];
	int t,i,count = 0;
	fgets(s,sizeof(s),stdin);
	t = strlen(s);
	for  (i=0;i<t;i++)
	if (s[i] >= 'A' && s[i] <= 'Z') count++;
	printf("%d",count);
	return 0;
}
