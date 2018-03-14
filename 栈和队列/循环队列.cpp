#include <iostream>
using namespace std;

#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int front, rear;
}RoQueue;

void InitRoQ(RoQueue &Q) {
	Q.front = Q.rear = 0;
}

bool EnRoQ(RoQueue &Q,int x) {
	if ((Q.rear + 1) % MaxSize == Q.front)
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool DeRoQ(RoQueue &Q, int &x) {
	if (Q.front == Q.rear)
		return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}