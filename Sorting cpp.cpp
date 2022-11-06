// Sorting cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
template<class T>
struct Sorting
{
	
	bool IsAscending;
	T *Array;
	T *TempArray;
	Sorting(bool IsAscending)
	{
		this->IsAscending=IsAscending;
	}
	Sorting()
	{
		this->IsAscending=true;
	}
	//Bubble Sort.
	 void BubbleSort(T Array[],int Lenght)
	{
		for(int i=1;i<Lenght;i++)
		{
			for(int j=0;j<Lenght-i;j++)
				if(Compare(Array[j],Array[j+1]))Swap(Array,j,j+1);
		}
	}
	 //Selection Sort. 
	 void SelectionSort( T Array[],int Lenght)
	{
		int p;
		for(int i=0;i<Lenght-1;i++)
		{
			p=i;
			for(int j=i+1;j<Lenght;j++)
				if(Compare(Array[p],Array[j]))p=j;
			Swap(Array,p,i);
		}
	}
	 //Insertion Sort.
	 void InsertionSort(T Array[],int Lenght)
	 {
		 for(int i=1;i<Lenght;i++)
		 {
			 int x=Array[i];
			 int j=i;
			 while(j>0 && Compare(Array[j-1],x))
			 {
				 Array[j]=Array[j-1];
				 j--;
			 }
			 Array[j]=x;
		 }
	 }
	 //MergeSort
	 void MergeSort(T Array[],int Lenght)
	 {
		 this->Array=Array;
		 TempArray=new T[Lenght];
		 doMergeSort(Array,0,Lenght-1);	 
	 }
	 void doMergeSort(T Array[],int LowIndex,int HighIndex)
	 {
		 if(LowIndex==HighIndex) return;
		 int MiddleIndex=(LowIndex+HighIndex)/2;
		 doMergeSort(Array,LowIndex,MiddleIndex);
		 doMergeSort(Array,MiddleIndex+1,HighIndex);
		 DoSort(Array,LowIndex,MiddleIndex,HighIndex);
	 }
	 void DoSort(T Array[],int LowIndex,int MiddleIndex,int HighIndex)
	 {
		 for(int i=LowIndex;i<=HighIndex;i++)
			 TempArray[i]=Array[i];
		 int i=LowIndex;
		 int j=LowIndex;
		 int k=MiddleIndex+1;
		 while(j<=MiddleIndex && k<=HighIndex)
		 {
			 if(Compare(TempArray[j],TempArray[k])) 
			 {
				 Array[i]=TempArray[k];
				 k++;
			 }
			 else
			 {
				 Array[i]=TempArray[j];
				 j++;
			 }
			 i++;
		 }
		 while(j<=MiddleIndex)
		 {
			 Array[i]=TempArray[j];
			 i++;
			 j++;
		 }
	 }
	//heap sort
	int total;
	void Heapify(T Array[], int p)
	{
		int l = 2 * p + 1;
		int r = 2 * p + 2;
		int n=-1;
		if (l <= total) n = l;
		if (r <= total)
			if (Compare(Array[r],Array[l])) n = r;

		if (n != -1 && Compare(Array[n],Array[p]))
		{
			Swap(Array, n, p);
			Heapify(Array, n);
		}
		else return;
	}
        
	//the complexty time is O(n.Log(n)).
	void HeapSort(T Array[],int n)
	{
		total = n - 1;
		for (int i = total / 2; i >= 0; i--)
			Heapify(Array, i);

		for (int i = total; i >0; i--)
		{

			Swap(Array, 0, i);
			total--;
			Heapify(Array, 0);
		}

	}
    // quick sort,the complexty time is O(n^2).
	void QuickSort(T Array[],int Lenght)
	{
		sort(Array, 0, Lenght - 1);
	}
	void sort(T Array[], int low, int upper)
	{
		if (low >= upper) return;

		T pivot = Array[low];
		int start = low;
		int stop = upper;
		while (low < upper)
		{
			while ((Compare(pivot,Array[low]) || pivot==Array[low]) && low < upper)
			{
				low++;
			}
			while ((Compare(Array[upper],pivot) && pivot!=Array[upper]) && low <= upper)
			{
				upper--;
			}
			if (low < upper)
			{
				Swap(Array, upper, low);
			}
		}
		Swap(Array, upper, start);
		sort(Array, start, upper - 1);
		sort(Array, upper + 1, stop);

	}
	 //couting Sort
	void CountingSort(int Array[],int Lenght)
	{
		int max,min;
		int range;
		int *Count;
		max=min=Array[0];
		for(int i=0;i<Lenght;i++)
		{
			if(max<Array[i]) max=Array[i];
			if(min>Array[i]) min=Array[i];
		}
		CountingSort(Array,Lenght,min,max);
	}
	void CountingSort(int Array[],int Lenght,int min,int max)
	{	
		int range;
		int *Count;
		range=max-min;
		if(!range) return;
		Count=new int[range+1];
		for(int i=0;i<=range;i++)
			Count[i]=0;
		for(int i=0;i<Lenght;i++)
		{
			Count[Array[i]-min]++;
		}
		int j=0;
		for(int i=0;i<=range;i++)
		{
			while(Count[i]>0)
			{
				Array[j]=i+min;
				Count[i]--;
				j++;
			}
		}
		if(!IsAscending)
			for(int i=0,j=Lenght-1;i<j;i++,j--)
			{
				int temp=Array[i];
				Array[i]=Array[j];
				Array[j]=temp;
			}
		delete Count;
	}
	//Cocktail Sort
	void CocktailSort( T Array[],int Lenght)
	{
		CocktailSort(Array,0,Lenght-1);
	}
	void CocktailSort(T Array[],int lower,int upper)
	{
		if(lower>=upper) return;
		int pmin,pmax;
		pmax=pmin=lower;
		for(int i=lower+1;i<=upper;i++)
		{		
			if(Compare(Array[i],Array[pmax])) pmax=i;
			if(Compare(Array[pmin],Array[i])) pmin=i;
		}
		if(Array[pmin]==Array[pmax]) return;
		if(pmin==upper) pmin=pmax;
		Swap(Array,pmax,upper);
		Swap(Array,pmin,lower);
		CocktailSort(Array,lower+1,upper-1);
	}
	//Dichotomous insertion Sort
	void DichotomousInsertionSort(T Array[],int Length)
	{
		
		for(int i=1;i<Length;i++)
		{
			int low=0,high=i;
			int middle;
			T element=Array[i];
			while(low!=high)
			{
				middle=(low+high)/2;
				if(Compare(Array[middle],element)) high=middle;
				else low=middle+1;
			}
			for(int j=i;j>low;j--) 
				Array[j]=Array[j-1];
			Array[low]=element;

		}		

	}
	// Sorting
	void Sort(T Array[],int Lenght)
	{
		Sort(Array,Lenght,'h');
	}
	void Sort(T Array[],int Length,char sortingType)
	{
		switch(sortingType)
		{
			case 'b':{BubbleSort(Array,Length);break;}
			case 's':{SelectionSort(Array,Length);break;}
			case 'i':{InsertionSort(Array,Length);break;}
			case 'h':{HeapSort(Array,Length);break;}
			case 'm':{MergeSort(Array,Length);break;}
			case 'c':{CocktailSort(Array,Length);break;}
			case 'q':{QuickSort(Array,Length);break;}
			case 'd':{DichotomousInsertionSort(Array,Length);break;}
			default:break;
		}
	}
	 //Swaping.
	 void Swap(T Array[],int a,int b)
	{
		T temp=Array[a];
		Array[a]=Array[b];
		Array[b]=temp;
	}

	 //Compare two values ​​of type T.
	 bool Compare(T firstValue,T secondValue)
	{
		if(IsAscending)return (firstValue-secondValue>0);
		return (firstValue-secondValue<0);
	}
	~Sorting()
	{
		delete TempArray;
	}
	 
};

int _tmain(int argc, _TCHAR* argv[])
{
	int Array[]={3,0,9,1,7,91,40,5,-1,30,15,8,4};
	
	int Length=sizeof(Array)/sizeof(Array[0]);
	(new Sorting<int>(true))->Sort(Array,Length,'s');
	
	for(int i=0;i<Length;i++)
		cout<<"["<<Array[i]<<"]";

	cout<<endl;
	system("pause");
	return 0;
}