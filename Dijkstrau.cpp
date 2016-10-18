#include<iostream>
#include<conio.h>
using namespace std;
#define V 9

void printPath(int parent[], int j)
{
	// Base Case : If j is source
	if (parent[j]==-1)
		return;

	printPath(parent, parent[j]);

	cout<<j;
}

// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	printf("Vertex\t Distance\tPath");
	for (int i = 1; i < V; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
		printPath(parent, i);
	}
}
void dijkstrau(int n,int a[][10],int s,int d[])
{
	int i,visit[10],min,count,u;
	int parent[10];

	for(i=1;i<=n;i++)
	{
		visit[i]=0;
		d[i]=a[s][i];
	}

	visit[s]=1;d[s]=0;count=1;

	while(count!=n)
	{
		min=999;

		for(i=1;i<=n;i++)
		{
			if(visit[i]==0&&d[i]<min)
			{
				min=d[i];
				u=i;
			}
		}

		visit[u]=1;
		count++;

		for(i=1;i<=n;i++)
		{
			if(visit[i]==0&&min+a[u][i]<d[i])
				d[i]=min+a[u][i];
		}
	}
}

void main()
{
	int n,src,a[10][10],i,j,dist[10];

	printf("Enter the number of vertices \n");
	cin>>n;

	cout<<"Enter the cost matrix \n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	cout<<"Enter the source \n";
	cin>>src;

	dijkstrau(n,a,src,dist);

	

	getch();
}



	
