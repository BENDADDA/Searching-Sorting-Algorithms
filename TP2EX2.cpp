// TP2EX2.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

struct Cell
{
	int i;
	int j;
	int value;
	Cell(int i,int j,int value)
	{
		this->i=i;
		this->j=j;
		this->value=value;
	}
	Cell()
	{}
};
struct OptimalMatrix
{

	Cell *Array;
	int size;
	int count;
	OptimalMatrix(int size)
	{
		this->size=size;
		this->count=0;
		Array=new Cell[this->size];
	}
	OptimalMatrix()
	{
		this->size=1;
		this->count=0;
		Array=new Cell[1];
	}
	void Add(int i,int j,int value)
	{
		if(value!=0)
		{
			if(size==count){Array=CopyArray(Array,size,2*size);size=size*2;}
			Array[count++]=Cell(i,j,value);
			
		}
		
	}

	Cell *CopyArray(Cell *A,int FirstSize,int SecondSize)
	{
		Cell *B=new Cell [SecondSize];
		for(int i=0;i<FirstSize;i++)
			B[i]=A[i];
		return B;
	}
	void Add(int Matrix[],int Lenght,int Lenght0)
	{
		for(int i=0;i<Lenght;i++)
			for(int j=0;j<Lenght0;j++)
				Add(i,j,Matrix[i*Lenght0+j]);
	}
	void Print()
	{
		for(int i=0;i<count;i++)
			cout<<"["<<Array[i].i<<"]["<<Array[i].j<<"]("<<Array[i].value<<")"<<endl;
	}	
	~OptimalMatrix()
	{
		
			delete []Array;
	}
};

int main()
{
	OptimalMatrix Matrix=OptimalMatrix(1);
	int M[][3]={{1,0,3},{0,3,0},{0,0,0}};
	for(int i=0;i<100;i++)
		for(int j=0;j<10;j++)
			Matrix.Add(i,j,5);

	Matrix.Print();
	cout<<Matrix.size;

	return 0;
}

