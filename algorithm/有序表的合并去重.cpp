/*
标题
有序表的合并去重
时间限制
1 S 
内存限制
10000Kb 
问题描述 
已知两个有序线性表L1和L2，每个线性表中数据元素的值为单调增的正整数（<100个），各线性表内部无重复元素。把L2中的元素合并到L1中，要求L1中数据元素的值仍为单调递增，且无重复元素。
问题输入 
第一行输入两个正整数a,b，分别表示第一个线性表L1和第二个线性表L2的长度；第2行依次输入L1中单调增的a个正整数；第3行依次输入L2中单调增的b个正整数。正整数均小于10000。
问题输出 
共有1行，最终合并并去重后的结果，每个数字之间有一个空格。
输入样例 
6 7
1 2 5 6 10 13
1 3 5 8 19 22 31
输出样例 
1 2 3 5 6 8 10 13 19 22 31




2020/11/8 晚



*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>, greater<int> > q;
int main() {
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a+b;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	
	int last;
	last=999999999;
	while(q.size()){
		int x=q.top();
		q.pop();
		if(x!=last){
			cout<<x<<" "; 
		}
		last = x;
	}
	return 0;
}
