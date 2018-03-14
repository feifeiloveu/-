#include <iostream>
using namespace std;

#define MaxSize 10   //方便检验而已，若是考试，建议还是50或者100
typedef struct {
	int data[MaxSize];
	int top[2];
}ShareSt;

void InitShareSt(ShareSt &S) {
	S.top[0] = -1; S.top[1] = MaxSize;
	for (int i = 0; i < 10; i++)//将其全部初始置零只是方便检验，考试不这么做
		S.data[i] = 0;
}

bool PushSha(ShareSt &S,int i,int x) {
	if (i != 0 && i != 1)
		return false;
	if (S.top[1] - S.top[0] == 1) {
		cout << "栈满" << endl;
		return false;
	}
	switch (i) {
	case 0:S.data[++S.top[0]] = x; break;
	case 1:S.data[--S.top[1]] = x; break;
	}
	return true;
}

bool PopSha(ShareSt &S, int i, int &x) {
	if (i != 0 && i != 1)
		return false;

	switch (i) {
	case 0:
		if (S.top[0] == -1) {
			cout << "栈空"<<endl;
				return false;
		}
		else {
			x = S.data[S.top[0]--];
			return true;
		}
	case 1:
		if (S.top[1] == MaxSize) {
			cout << "栈空" << endl;
			return false;
		}
		else {
			x = S.data[S.top[1]++];
			return true;
		}
	}//switch
}

void sharemain() {
	ShareSt S; int x;
	InitShareSt(S);
	PushSha(S, 0, 1);
	PushSha(S, 1, 2);
	PushSha(S, 0, 888);
	PushSha(S, 1, 999);
	PopSha(S, 0, x); PopSha(S, 1, x);

	//输出共享栈
	for (int i = S.top[0]; i >= 0; i--) {
		cout << S.data[i] << endl;
	}
	for (int i = S.top[1]; i < MaxSize;i++) {
		cout << S.data[i] << endl;
	}
	system("pause");
}

