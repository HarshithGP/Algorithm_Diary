#include<iostream>
#include<conio.h>
using namespace std;
void prim(int n,int a[][10])
{
	int i,j,u,v,visit[10],e=0,mincost=0,min;
	for(i=1;i<=n;i++)
		visit[i]=0;

	visit[1]=1;
	cout<<"Edges of spanning tree are \n";
	while(e!=n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(visit[i]==1)
				{
					if(a[i][j]<min)
					{
						min=a[i][j];
						u=i;
						v=j;
					}
				}
			}
		}
		if(visit[v]==0)
		{
			visit[v]=1;
			e=e+1;
			mincost=mincost+min;
			cout<<u<<"->"<<v<<"="<<min<<"\n";
		}

		a[u][v]=a[v][u];
	}

	cout<<" mincost = "<<mincost<<endl;
}

void main()
{
	int n,a[10][10],i,j;
	cout<<"Enter the num of vertices \n";
	cin>>n;
	cout<<"Enter cost matrix \n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	prim(n,a);
	getch();
}