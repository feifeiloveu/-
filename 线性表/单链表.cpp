#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList CreatList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	int x; LNode *r=L, *s;
	cin >> x;
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}


int NO21(LinkList L,int x) {
	if (x <= 0)
		return 0;
	int n; LinkList p,q;
	p = L->next; q = L; n = 1;
	while (p != NULL) {
		if (n < x)
			n++;
		else
			q = q->next;
		p = p->next;
	}
	if (q == L)
		return 0;
	cout << q->data << endl;
	return 1;
}

int ListLength(LinkList L) {
	LinkList p = L; int n = 0;
	while (p->next != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

LinkList NO22(LinkList str1, LinkList str2) {
	LinkList s1=str1->next, s2=str2->next;
	int n1=ListLength(str1), n2=ListLength(str2);
	
	for (; n1 > n2; n1--)
		s1 = s1->next;
	for (; n1 < n2; n2--)
		s2 = s2->next;
	while (s1 != s2) {
		s1 = s1->next;
		s2 = s2->next;
	}
	return s1;
}

void NO23(LinkList L,int n) 
{
	int *a,m;
	a = (int *)malloc(sizeof(int)*(n + 1));
	for (int i = 0; i <= n; i++)
		*(a + i) = 0;
	LinkList p = L,q;             //ֻ��һ��ָ�룬����ǰһ�����,��q���ͷŽ���ã���ȻҲ����������㣬��һ��
	while (p->next != NULL) 
	{
		m = p->next->data > 0 ? p->next->data : -p->next->data;
		if (*(a + m) == 0) {
			*(a + m) = 1;
			p = p->next;
		}
		else {
			q = p->next;
			p->next = q->next;
			free(q);
		}//ע��˴���ûɾ���Ļ���pҪ�����ɾ���˾Ͳ���
	}
	free(a);
}


void main() {
	LNode *L, *s,*r; int x;
	L = CreatList(L); 

	NO23(L, 30);

	s = L->next;
	if (s == NULL)
		cout << "����Ϊ��" << endl;
	else 
		while (s != NULL) {
		cout << s->data << endl;
		s = s->next;
		}


	//����22��ĵ���
	//��ͬ���
	/*LNode *str1, *str2;
	LNode *com;
	com = (LinkList)malloc(sizeof(LNode));
	com->data = 5;
	r = com;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 6;
	r->next = s;
	r = s;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 7;
	r->next = s;
	r = s; r->next = NULL;

	//str1
	str1 = (LinkList)malloc(sizeof(LNode));
	r = str1;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 123; r->next = s; r = s;
	r->next = com;

	//str2
	str2 = (LinkList)malloc(sizeof(LNode));
	r = str2;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 646;
	r->next = s; r = s;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 79564;
	r->next = s; r = s;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = 5613216;
	r->next = s; r = s;
	r->next = com;

	cout << NO22(str1, str2)->data << endl;
	s = str2->next;
	if (s == NULL)
	cout << "����Ϊ��" << endl;
	else
	while (s != NULL) {
	cout << s->data << endl;
	s = s->next;
	}*/
}