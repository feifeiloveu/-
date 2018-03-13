#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct {
	int data[MaxSize];
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

bool Push(SqStack &S, int x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S,int &x) {
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

void main() {
	SqStack S; int x;
	CreatStack(S);
	Push(S, 100);

	OutPut(S);
	system("pause");
}