#include<iostream>
#include<conio.h>
#define max 10
using namespace std;

void warshall(int a[][max],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				a[i][j]=a[i][j]||a[i][k]&&a[k][j];
}

void main()
{
	int a[max][max],n,i,j;

	cout<<"Enter number of vertices \n";
	cin>>n;

	cout<<"Enter adjacency matrix \n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	warshall(a,n);

	cout<<"path matrix \n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<a[i][j]<<"\t";
		cout<<"\n";
	}
	getch();
}