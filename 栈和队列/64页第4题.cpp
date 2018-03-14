#include <iostream>
using namespace std;

typedef struct LNode {
	char data;
	struct LNode *next;
}LNode,*LiStack;

typedef struct {
	char data[50];
	int top;
}SqStack;

LiStack CreatLiStack(LiStack &S) {
	//无头结点的链表，第一个结点有点麻烦，得特殊处理
	char x; LiStack p,q;
	cin >> x;
	if (x == '0')
		return NULL;
	S = (LiStack)malloc(sizeof(LNode));
	S->data = x;
	p = S;
	cin >> x;
	while (x != '0') {
		q = (LiStack)malloc(sizeof(LNode));
		q->data = x;
		p->next = q;
		p = q;
		cin >> x;
	}
	p->next = NULL;
	return S;
}

bool NO4(LiStack L,int n) {
	char *a; LiStack p=L;
	a = (char *)malloc(sizeof(char)*(n / 2));
	for (int i = 0; i <= n / 2-1; i++) {
		*(a + i) = p->data;
		p = p->next;
	}


	if (n % 2 == 1)
		p = p->next;

	for (int i = n / 2-1; i >= 0; i--) {
		if (p->data != *(a + i)) {
			free(a);
			return false;
		}
		p = p->next;
	}
	free(a);
	return true;
}

void xxmain() {
	LiStack L,p;
	L = CreatLiStack(L);
	cout << NO4(L,4) << endl;


	/*
	    p = S;
	    while (p != NULL) {
		cout << p->data << endl;
		p = p->next;
	}*/
	system("pause");
}