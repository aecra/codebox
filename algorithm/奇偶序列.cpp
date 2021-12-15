/*
标题  
奇偶序列
时间限制 
2S 
内存限制
10000 Kb 
问题描述 
输入一个整数组成的序列，然后将序列中的奇数位置结点依序放在前面，偶数位置结点依序放在后面，组成一个新的序列。输出此新序列。
问题输入
输入共两行，第一行是一个正整数n，表示序列长度，n<100。第二行是n个整数，中间用空格隔开，表示序列中的元素。
问题输出
在一行上输出新生成的序列，数字中间用空格隔开。
输入样例
7
10 2 30 4 50 60 7
输出样例
10 30 50 7 2 4 60


2020/11/8 晚



*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;


int main() {
	queue<int> front;
	queue<int> back;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i%2){
			front.push(x);
		}else{
			back.push(x);
		}
	}
	
	while(front.size()){
		cout<<front.front()<<" ";
		front.pop();
	}
	while(back.size()){
		cout<<back.front()<<" ";
		back.pop();
	}
	
	return 0;
}
