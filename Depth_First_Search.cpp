#include<iostream>
#include<conio.h>
#include<stdio.h>
#define max 10
using namespace std;
void dfs(int a[][max],int n,int s,int v[])
{
	int i;
	v[s]=1;
	cout<<s;
	for(i=1;i<=n;i++)
	{
		if(a[s][i]&&!v[i])
		{
			v[i]=1;
			cout<<"->";
			dfs(a,n,i,v);

		}
	}
}

void main()
{
	int a[max][max],n,i,src,j,v[max];

	cout<<"Enter the number of vertices \n";
	cin>>n;

	cout<<"Enter adjacency matrix \n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	cout<<"Enter source vertex \n";
	cin>>src;

	for(i=1;i<=n;i++)
		v[i]=0;

	dfs(a,n,src,v);

	for(i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			cout<<"Graph is not connected \n";
			getch();
			exit(0);
		}
	}

	cout<<"Graph is connected \n";
	getch();
}



