/*
链表去重
问题描述：
给定一个键值为整数的单链表 L，将键值的绝对值有重复的结点删除：即对任意键值 K，只
有键值或其绝对值等于 K 的第一个结点被保留在 L 中。
输入说明：
输入的第一行包含两个整数，分别表示链表第一个结点的地址和结点个数 n（1≤n≤100）。结
点地址是一个非负的 5 位整数，NULL 指针用-1 表示。
随后 n 行，每行含 3 个整数，按下列格式给出一个结点的信息：
Address Key Next
其中 Address 是结点的地址，Key 是绝对值不超过 10000 的整数，Next 是下一个结点的地址。
输出说明：
输出的第一行为去重后链表 L 的长度，换行；接下来按顺序输出 L 的所有结点，每个结点
占一行，按照 Address Key Next 的格式输出，间隔 1 个空格。
测试样例：
输入样例 1
00100 5
99999 7 87654
23854 -15 00000
87654 -15 -1
00000 15 99999
00100 21 23854
输出样例 1
3
00100 21 23854
23854 -15 99999
99999 7 -1

2020/11/8 晚

链表。。。

卧槽，pos函数放在一个cout里面竟然会发生混乱出错！！！
原理不懂！！！ 

*/

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int a[100000][2];
bool b[10005];
int pos(int p) {
	if(p==-1) {
		return p;
	}
	if(p<10) {
		cout<<"0000";
		return p;
	}
	if(p<100) {
		cout<<"000";
		return p;
	}
	if(p<1000) {
		cout<<"00";
		return p;
	}
	if(p<10000) {
		cout<<"0";
		return p;
	}
}
int main() {
	for(int i=0; i<100000; i++) {
		a[i][0]=a[i][1]=0;
	}
	for(int i=0; i<10005; i++) {
		b[i]=false;
	}

	int start,n;
	cin>>start>>n;
	for(int i=0; i<n; i++) {
		int add;
		cin>>add;
		cin>>a[add][0]>>a[add][1];
	}

	int lastPosition=start;
	for(int i=start; i!=-1; i=a[i][1]) {
		if(b[a[i][0]>0?a[i][0]:-a[i][0]]) {
			// 已经有了，把这个节点删掉
			a[lastPosition][1]=a[i][1];
			n--;
		} else {
			// 还没有，那就标记上它有了
			b[a[i][0]>0?a[i][0]:-a[i][0]]=true;
			lastPosition=i;
		}
	}

	cout<<n<<endl;
	for(int i=start; i!=-1; i=a[i][1]) {
		cout<<pos(i);
		cout<<" ";
		cout<<a[i][0];
		cout<<" ";
		cout<<pos(a[i][1]);
		cout<<endl;
	}
	return 0;
}
