#include <iostream>
#include <string>
#define maxx 255
using namespace std;
struct anode{
       char ope; int val;
};
struct node{
       char ope; int val;
       node *l,*r;
};
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
char ope[4]={'+' , '-' , '*' , '/'};

void read(string&);
void write(anode[],int);
bool isope(char);
bool isnum(char);
int power(int,int);
int ctoi(char[],int);
int prio(char);
void get(string,anode[],int&);

int main(){
    string expr; anode suff[maxx]; int n = 0;
    read(expr);
    get(expr,suff,n);
    write(suff,n);
    fflush(stdin); getchar();
    return 0;
}

void read(string &expr){
     cout <<"Nhap bieu thuc tinh toan: ";
     cin >>expr;
}
void write(anode suff[],int n){
     cout <<"Chuyen thanh bieu thuc hau to: \n";
     for (int i = 0;i < n;i++)
     if (suff[i].ope != '.') cout <<suff[i].ope <<' ';
     else cout <<suff[i].val <<' ';
     cout <<endl;
}
bool isope(char c){
     int i = 0;
     while ((i < 4)&&(c != ope[i])) ++i;
     if (i < 4) return true;
     else return false;
}
bool isnum(char c){
     int i = 0;
     while ((i < 10)&&(c != num[i])) ++i;
     if (i < 10) return true;
     else return false;
}
int power(int x,int y){
    int p = 1;
    for (int i = 0;i < y;i++) p *= x;
    return p;
}
int ctoi(char c[],int n){
    int m = 0;
    for (int i = 0; i <= n;i++){
        int j = 0;    
        while ((j < 10)&&(c[i] != num[j])) j++;
        m += j*power(10,n-i);
    }
    return m;
}
int prio(char c){
    if (c == '$') return 0;
    else if ((c == '(')||(c == ')')) return 1;
         else if ((c == '+')||(c == '-')) return 2;
              else return 3;
}
void get(string expr,anode suff[],int& n){
     char cnum[5],stack[maxx]; int m,top = 0,i = 0;
     stack[top] = '$';
     while (i < expr.size()){
           if (isope(expr[i]))
              if (prio(expr[i]) > prio(stack[top]))
                 stack[++top] = expr[i++];
              else{
                   while (prio(expr[i]) <= prio(stack[top])){
                         suff[n].val = -1;
                         suff[n++].ope = stack[top--];
                   }
                   stack[++top] = expr[i++];
              }
           if (isnum(expr[i])){
              m = -1;
              while ((i < expr.size())&&(isnum(expr[i])))
                    cnum[++m] = expr[i++];
              m = ctoi(cnum,m);
              suff[n].ope = '.';
              suff[n++].val = m;
           }
           if (expr[i] =='(') stack[++top] = expr[i++];
           if (expr[i] ==')'){
              while (stack[top] != '('){
                    suff[n].val = -1;
                    suff[n++].ope = stack[top--];
              }
              top--;
              i++;
           }
     }
     while (stack[top] != '$'){
           suff[n].val = -1;
           suff[n++].ope = stack[top--];
     }
}  
