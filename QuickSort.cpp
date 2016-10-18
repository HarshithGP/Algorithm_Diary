#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define max 100000
using namespace std;

int partition(int a[],int L,int R)
{
	int i,j,temp,key;
	i=L;j=R+1;key=a[L];

	do
	{
		do
		++i;
		while(key>=a[i]);

		do
		--j;
		while(key<a[j]);

		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	while(i<j);

	temp=a[L];
	a[L]=a[j];
	a[j]=temp;

	return j;
}

void quicksort(int a[],int L,int R)
{
	if(L<R)
	{
		int s=partition(a,L,R);
		quicksort(a,L,s-1);
		quicksort(a,s+1,R);
	}
}

void main()
{
	int a[max],i,n;
	clock_t start,stop;
	srand((unsigned)time(NULL));

	cout<<"Enter the number of elements \n";
	cin>>n;

	for(i=1;i<=n;i++)
		a[i]=rand();

	start=clock();
	quicksort(a,0,n-1);
	stop=clock();

	cout<<"Sorted list \n";
	for(i=1;i<=10;i++)
		cout<<a[i]<<"\t";

	cout<<"Time taken : "<<(double)(stop-start)/CLOCKS_PER_SEC;

	getch();
}