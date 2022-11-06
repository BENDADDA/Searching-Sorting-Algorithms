// TP2EX1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
//the complexity time :T(n)=O(n^2)
void CreateTable(int *table,int n,int i)
{
	if(i==0) table[0]=1;// ... 1
	else
	{
		table[i]=0;//... n-1
		for(int j=0;j<i;j++)// .... (1+2+3+ ... +n-1)=(n(n-1)/2).
			table[i]+=table[j];// .... (1+2+3+ ... +n-1)=(n(n-1)/2).
		table[i]*=i;//... n-1
	}
	if(i<n) CreateTable(table,n,i+1);// ...n
	else return;//...... 1
}
//the complexity time:T(n)=O(n).
void createTable(int *table,int n,int i,int sum)
{
	if(i==0) table[0]=1;
	else 
	{
		sum+=table[i-1];
		table[i]=i*sum;
	}
	if(i<n) createTable(table,n,i+1,sum);
	else return;
}
//the complexe time:T(n)=O(n).
void createTable(int *table,int n,int i)
{
	if(i<=1)table[i]=1;//...2
	else table[i]=i*i*1.0/(i-1)*table[i-1];//...n-2
	if(i<n) createTable(table,n,i+1);//... n
	else return;// ....1
}
void createTable(int Table[],int Lenght)
{
	createTable(Table,Lenght,0);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Array[100];
	createTable(Array,10);
	for(int i=0;i<10;i++)
		cout<<"["<<Array[i]<<"]";
	cout<<endl;
	system("pause");
	return 0;
}

