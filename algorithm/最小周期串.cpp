/*
最小周期串
描述：
如果一个字符串可以由某个长度为k的字符串重复多次得到，我们说该串以k为周期。例如，abcabcabcabc以3为周期（注意，它也以6和12为周期）。输入一个长度不超过80的串，输出它的最小周期。
输入说明：
每组数据为一个字符串。
输出说明：
输出每组字符串的最小周期。
输入样例：
GeeGeeGee
输出样例：
3



2020/11/8 晚



*/

#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string get(string s, int x){
	string pianduan;
	for(int i=0;i<x;i++){
		pianduan+=s[i];
	}
	string out;
	for(int i=0;i<s.length()/x;i++){
		out+=pianduan;
	}
	return out;
}

int main() {
	string s;
	cin>>s;
	int xx=s.length();
	for(int i=1;i<s.length();i++){
		if(s.length()%i==0&&get(s,i)==s){
			xx=i;
			break;
		}
	}
	cout<<xx<<endl;
	return 0;
}
