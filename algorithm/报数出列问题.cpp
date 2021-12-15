/*
标题  
报数出列问题
时间限制
1 S 
内存限制
10000 Kb 
问题描述 
已知N个人（以编号1，2，3，...，N分别表示）排成一列, 第一轮从编号为1的人开始依次报数，数到2的倍数的人出列；第二轮从头开始依次报数，数到3的倍数的人出列；第三轮再次从头开始依次报数，数到2的倍数的人出列；第四轮从头开始依次报数，数到3的倍数的人出列；依此规律重复下去，直到队列中的人数不超过三个为止。要求输出此时队列中剩下的人在初始队列中的编号。
问题输入 
一个正整数N，表示初始人数，N≤5000。
问题输出 
输出队列中剩下的人在初始队列中的编号，编号之间有一个空格。
输入样例 
20
输出样例 
1 7 19
提示
可以使用队列，每次操作时对队列中元素进行判断，不需要舍弃的就重新加入队列；

2020/11/8 晚





*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;


int main() {
	int a;
	cin>>a;
	queue<int> q;
	queue<int> p;
	for(int i=1;i<=a;i++){
		q.push(i);
	}
	
	int bao=2;
	while(q.size()>3||p.size()>3){
		if(bao==2){
			while(q.size()>1){
				int x1=q.front();q.pop();
				q.pop();
				p.push(x1);
			}
			while(q.size()){
				int x1=q.front();q.pop();
				p.push(x1);
			}
			bao=3;
		}else{
			while(p.size()>2){
				int x1=p.front();p.pop();
				int x2=p.front();p.pop();
				p.pop();
				q.push(x1);
				q.push(x2);
			}
			while(p.size()){
				int x1=p.front();p.pop();
				q.push(x1);
			}
			bao=2;
		}
		
	}
	
	if(q.size()!=0){
		while(q.size()!=0){
			cout<<q.front()<<" ";
			q.pop();
		}
	}else{
		while(p.size()!=0){
			cout<<p.front()<<" ";
			p.pop();
		}
	}
	
	
	return 0;
}
