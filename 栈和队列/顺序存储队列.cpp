#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitSqQue(SqQueue &Q) {
	Q.front = Q.rear = 0;
}

bool EnSqQue(SqQueue &Q,int x) {
	if (Q.rear == MaxSize)
		return false;//尾部溢出了
	Q.data[Q.rear++] = x;
	return true;
}

bool DeSqQue(SqQueue &Q, int &x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front++];
	return true;
}

void sqqmain() {
	SqQueue Q; int x;
	InitSqQue(Q);
	EnSqQue(Q, 1); EnSqQue(Q, 2); EnSqQue(Q, 3); EnSqQue(Q, 4); EnSqQue(Q, 5); EnSqQue(Q, 6);
	DeSqQue(Q, x);

	//输出队列
	while (Q.front != Q.rear) {
		DeSqQue(Q, x);
		cout << x << endl;
	}
	system("pause");
}