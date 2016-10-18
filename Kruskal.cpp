#include<iostream>
#include<conio.h>
using namespace std;
void kruskal(int n, int c[][10])
{
	int i,j,u,v,parent[10],e=0,mincost=0,min,a,b;
	for(i=1;i<=n;i++)
		parent[i]=0;

	cout<<"edges of spanning tree are \n";
	while(e!=n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(c[i][j]<min)
				{
					min=c[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		while(parent[u]!=0)
			u=parent[u];
		while(parent[v]!=0)
			v=parent[v];
		if(u!=v)
		{
			e=e+1;
			mincost=mincost+min;
			parent[v]=u;
			cout<<a<<"---->"<<b<<"="<<min<<"\n";
		}
		c[a][b]=c[b][a]=999;
	}
	cout<<"Mincost is "<<mincost;
}
void main()
{
int n, c[10][10],i,j;
cout<<"enter the num of vertices\n";
cin>>n;
cout<<"enter the cost matrix\n";
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cin>>c[i][j];
}
}
kruskal(n,c);
getch();
}