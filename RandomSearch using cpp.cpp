// RandomSearch using cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int NextRandom(int minValue,int maxValue)
{
	return rand()%(maxValue-minValue+1)+minValue;
}

//Best case : T(n)=1;
//Worse case :T(n)=n;
//Average case :T(n)=n/2;
//So the complexity time is O(n).
int RandomSearch(int Array[],int Element,int LowIndex,int HighIndex)
{
	int randomValue,result=-1;
	if(LowIndex>HighIndex) return -1;
	randomValue=NextRandom(LowIndex,HighIndex);cout<<randomValue<<"-";
	if(Array[randomValue]==Element) return randomValue;
	if(rand()%2)
	{
		result=RandomSearch(Array,Element,LowIndex,randomValue-1);
		if(result==-1) result=RandomSearch(Array,Element,randomValue+1,HighIndex);
	}
	else
	{
		result=RandomSearch(Array,Element,randomValue+1,HighIndex);
		if(result==-1) result=RandomSearch(Array,Element,LowIndex,randomValue-1);
	}
	return result;	
}
int RandomSearch(int Array[],int Element,int Lenght)
{
	return RandomSearch(Array,Element,0,Lenght-1);
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Array[]={1,2,3,4,5,0,6,99,78,8,9,20};
	int Element;
	cout<<"Please ,Enter an element that you wanna search for it :";
	cin>>Element;
	for(int i=0;i<100;i++)
	{
		int Result=RandomSearch(Array,Element,12);
		cout<<"::Result="<<Result;
		cout<<endl;
	}
	system("pause");
    return 0;
}
