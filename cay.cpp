#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node{
int id;
Node* leftMostChild;// con tro tro den nut con trai nhat
Node* rightSibling;// con tro tro den nut anh em ben phai
};
Node* root;// con tro tro den nut goc

Node* find(Node* r, int v){
if(r == NULL) return NULL;
if(r->id == v) return r;
Node* p = r->leftMostChild;
while(p != NULL){
Node* h = find(p,v);
if(h != NULL) return h;
p = p->rightSibling;
}
return NULL;
}

int count(Node* r){
if(r == NULL) return 0;
int s = 1;
Node* p = r->leftMostChild;
while(p != NULL){
s += count(p);
p = p->rightSibling;
}
return s;
}

int countLeaves(Node* r){
if(r == NULL) return 0;
int s = 0;
Node* p = r->leftMostChild;
if(p == NULL) s = 1;
while(p != NULL){
s += countLeaves(p);
p = p->rightSibling;
}
return s;
}

int height(Node* p){
if(p == NULL) return 0;
int maxh = 0;
Node* q = p->leftMostChild;
while(q != NULL){
int h = height(q);
if(h > maxh) maxh = h;
q = q->rightSibling;
}
return maxh + 1;
}

int depth(Node* r, int v, int d){
// d la do sau cua nut r
if(r == NULL) return -1;
if(r->id == v) return d;
Node* p = r->leftMostChild;
while(p != NULL){
if(p->id == v) return d+1;
int dv = depth(p,v,d+1);
if(dv > 0) return dv;
p = p->rightSibling;
}
return -1;
}
int depth(Node* r, int v){
return depth(r,v,1);
}

Node* parent(Node* p, Node* r){
if(r == NULL) return NULL;
Node* q = r->leftMostChild;
while(q != NULL){
if(p == q) return r;
Node* pp = parent(p, q);
if(pp != NULL) return pp;
q = q->rightSibling;
}
return NULL;
}

Node * MakeNode(int value)
{
    struct Node * temp=(Node * )malloc(sizeof(Node));
    temp->id = value;
    temp->leftMostChild = temp->rightSibling=NULL;
    return temp;
}
Node insertNode(Node *r,Node *p,int id) {
	p->rightSibling=MakeNode(id);
}
int main () {
	Node *p;
	root->leftMostChild = p;
	MakeNode(10);
	insertNode(root,p,10);
	return 0;
}
