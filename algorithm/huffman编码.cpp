/*
huffman编码
题目：
标题
huffman编码  
时间限制
2 S 
内存限制
10000 Kb 
问题描述 
假设用于通信的电文由ｎ（4<n<30）个字符组成，字符在电文中出现的频度（权值）为w1w2…wn，试根据该权值序列构造哈夫曼树，并计算该树的带权路径长度。 
问题输入 
一组数据，第１行为ｎ的值，第２行为ｎ个整数，表示字符的出现频度。 
问题输出 
输出一个整数，表示所构造哈夫曼树的带权路径长度。 
输入样例 
8 
7  19  2  6  32  3  21  10
 
输出样例 
261 
 


2020/11/8 晚，数据结构第三次上机题

极度不情愿地敲代码。。。

突然发现需要用到优先队列，我吐了！

啊，还是用STL吧 

优先级貌似有毛病，>号就对了，<反而不对 ？？？ 

*/

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct Edge {
	int wigth;
	Edge* left;
	Edge* right;
};

Edge ww[300];


struct cmp {
	bool operator() (Edge* a, Edge* b) {
		return a->wigth > b->wigth;
	}
};

int getLength(Edge* w, int deep){
	if(w->right==NULL){
		//cout<<w->wigth<<" "<<deep<<endl;
		return w->wigth*deep;
	}else{
		return getLength(w->left, deep+1)+getLength(w->right, deep+1);
	}
}

priority_queue <Edge*,vector<Edge*>, cmp> q;
int main() {
	int num;
	cin>>num;
	int i=0;
	for(i=0; i<num; i++) {
		cin>>ww[i].wigth;
		ww[i].left=ww[i].right=NULL;
		q.push(&ww[i]);
	}
	while(q.size()!=1){
		Edge* x=&ww[++i];
		
		// 先拿出来 
		Edge* a=q.top();
		q.pop();
		Edge* b=q.top();
		q.pop();
		
		x->wigth=a->wigth+b->wigth;
		x->left=a,x->right=b;
		q.push(x);
	}
	
	Edge* xxx=q.top();
	cout<<getLength(xxx, 0);
	
	return 0;
}
