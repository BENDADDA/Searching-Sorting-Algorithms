#include<iostream>

using namespace std;
//the complexity time is O(n).
int Search(int table[],int element,int lenght)
{
	for(int i=0;i<lenght;i++)
		if(table[i]==element) return i;
	return -1;
}
int Search(int table[],int element,int lenght,int start_index)
{
	if(start_index==lenght) return -1;
	else if(table[start_index]==element) return start_index;
	else  return Search(table,element,lenght,++start_index);
}

int IsOrdered(int table[],int lenght)
{
	int iso=1;
	if(lenght>0 && table[0]>table[1]) iso=-1;
	for(int i=1;i<lenght-1;i++)
	{
		if((table[i+1]-table[i])*iso<0) return 0;
	}
	return iso;
}
int BinarySearch(int table[],int element,int lowerIndex,int higherIndex,int IsOrdered)
{
	int middle=(lowerIndex+higherIndex)/2;
	if(lowerIndex>higherIndex) return -1;
	else if(table[middle]==element) return middle;
	else
	{
		if((table[middle]-element)*IsOrdered>0) return BinarySearch(table,element,lowerIndex,middle-1,IsOrdered);
		else return BinarySearch(table,element,middle+1,higherIndex,IsOrdered);
	}
}
int Searching(int Array[],int Lenght,int Element)
{
	int iso=IsOrdered(Array,Lenght);
	if(iso)
		return BinarySearch(Array,Element,0,Lenght-1,iso);
	else return Search(Array,Element,Lenght);
}

int  main()
{

	int Array[]={0,1,2,3,4,5,6,7,8,9};
	int element;
	cout<<"You have to enter an integer number :";
	cin>>element;
	int result=Searching(Array,10,element);
	cout<<"The result :"<<result<<endl;

	system("pause");
	return 0;
}