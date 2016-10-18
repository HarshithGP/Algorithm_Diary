#include<iostream>
#include<conio.h>
#define max 10
using namespace std;

void tsort(int a[][max],int n)
{
	int i,j,indeg[max]={0},flag=0;
	int s[max],top=-1;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			indeg[i]=indeg[i]+a[j][i];

		if(indeg[i]==0)
		{
			s[++top]=i;
			flag=1;
		}
	}

	if(flag==0)
		cout<<"Graph cyclic : topological ordering not possible \n";
	else
	{
		cout<<"Topological ordering  \n";
		while(top!=-1)
		{
			i=s[top];
			top--;
			cout<<i<<"\t";

			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{
					--indeg[j];
					if(indeg[j]==0)
						s[++top]=j;
				}
			}
		}
	}
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

	tsort(a,n);
	getch();
}
