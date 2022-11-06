// Tp1_Ex2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int Code1(int n)
{
	int count=0;
	int i;int x;int j;int a;
	a=1;x=0;
	//-------------------------------
	for(i=n;i>1;i=i/2)
		for(j=0;j<=n;j++)
		{
			x+=a;
			count++;//counter
		}
	//-------------------------------
	return count;
}
int Code2(int n)
{
	int count=0;
	int i;int j;
	//-------------------------------
	i=1;
	while(i<n){
		j=1;
		while(j<2*n)
		{
			j*=2;
			count++;//counter
		}
		i++;}
	//---------------------------------
	return count;
}
int Code3(int n)
{
	int count=0;
	int k;
	//-------------------------
	int i=n,j=1,x=0;
	do
	{
		for(k=1;k<=j;k++)
		{
			x++;
			count++;//counter
		}
		j=j*2; i--;
	}while(i!=0);
	//----------------------
	return count;
}
int PowerR(int x,int n)
{
	int r;
	if(n==0)return 1;
	if(n%2==0)
	{
		r=PowerR(x,n/2);
		return r*r;
	}
	else
	{
		r=PowerR(x,(n-1)/2);
		return x*r*r;
	}
}
//Iteration
int PowerI(int x,int n)
{
	if(n==0) return 1;
	int count=0;int *Array=new int[1];
	while(n>0)
	{		
		Array[count]=n%2;
		n/=2;
		count++;
	}
	int s=1;
	for(int i=count-1;i>=0;i--)
	{
		if(Array[i]==0) s=s*s;
		else s=s*s*x;
	}
	return s;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<PowerI(2,10)<<endl;
	int n;	
	cout<<"n=";
	cin>>n;n++;
	cout<<"Code 1:-----------------------:"<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<i<<"::"<<Code1(i)<<endl;
	}
	cout<<"Code 2:-----------------------:"<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<i<<"::"<<Code2(i)<<endl;
	}
	cout<<"Code 3:-----------------------:"<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<i<<"::"<<Code3(i)<<endl;
	}
	
	cout<<endl;
	system("pause");
	return 0;
}

