#include<iostream>
#include<conio.h>
#define max 10
using namespace std;

void bfs(int a[][max],int n,int s)
{
	int i,v[max],q[max],f=0,r=-1;

	for(i=1;i<=n;i++)
		v[i]=0;

	v[s]=1;
	q[++r]=s;
	cout<<s;

	while(f<=r)
	{
		s=q[f];
		f++;

		for(i=1;i<=n;i++)
		{
			if(a[s][i]&&!v[i])
			{
				q[++r]=i;
				v[i]=1;
				cout<<"->"<<i;
			}
		}
	}
}

void main()
{
	int a[max][max],n,src,i,j;
	cout<<"Enter no of vertices \n";
	cin>>n;

	cout<<"Enter adjacency matrix \n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	cout<<"Enter source vertex \n";
	cin>>src;

	bfs(a,n,src);
	getch();
}