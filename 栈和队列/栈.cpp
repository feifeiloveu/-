#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct {
	char data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &S) {
	S.top = -1;
}//≥ı ºªØ

bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}//≈–ø’

bool Push(SqStack &S, char x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S,char &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack &S, int &x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

void OutPut(SqStack S) {
	while (S.top != -1) {
		cout << S.data[S.top] << endl;
		S.top--;
	}
}

SqStack CreatStack(SqStack &S) {
	int x;
	S.top = -1;
	cin >> x;
	while (x != 9999) {
		S.data[++S.top] = x;
		cin >> x;
	}
	return S;
}

bool NO3(char a[]) {
	int top = -1;
	for (int i = 0; a[i] != '\0';i++) {
		if (a[i] == 'I')
			top++;
		else
			top--;
		if (top == -2)
			return false;
	}
	if (top == -1)
		return true;
	else
		return false;
}

bool NO1P87( char a[]) {
	SqStack S; char x;
	InitStack(S);
	for (int i = 0; a[i] != '\0'; i++) {
		switch (a[i]) {
		case '(':Push(S, '('); break;
		case '[':Push(S, '['); break;
		case '{':Push(S, '{'); break;
		case ')':Pop(S, x); if (x != '(') return false;
			break;
		case ']':Pop(S, x); if (x != '[') return false;
			break;
		case '}':Pop(S, x); if (x != '}') return false;
			break;
		default:break;
		}
	}
	if (StackEmpty(S)) {
		cout << "¿®∫≈∆•≈‰" << endl;
		return true;
	}
	else {
		cout << "¿®∫≈≤ª∆•≈‰" << endl;
		return false;
	}
}

double NO3P87(int n, int x) {
	struct {
		int no;
		double val;
	}st[MaxSize];
	int top = -1;
	for (int i = n; i > 1; i--) {
		st[++top].no = i;
	}
	double fv1 = 1, fv2 = 2*x;
	while (top != -1) {
		double temp;
		temp = 2 * x*fv2 - 2 * (st[top].no - 1)*fv1;
		fv1 = fv2; fv2 = temp;
		top--;
	}
	switch(n) {
	case 0:return 1; break;
	case 1:return 2 * x; break;
	default:return fv2; break;
	}
}

void main() {
	//SqStack S; int x;
	//InitStack(S);
	cout << NO3P87(2, 40) << endl;
	

	system("pause");
}