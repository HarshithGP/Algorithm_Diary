#include<iostream>
#include<conio.h>
#define max 10
using namespace std;

int Max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
 void knapsack(int n,int m,int p[],int w[])
 {
	 int i,j,x[max],v[max][max];

	 for(i=0;i<=n;i++)
	 {
		 for(j=0;j<=m;j++)
		 {
			 if(i==0||j==0)
				 v[i][j]=0;
			 else if(w[i]>j)
				 v[i][j]=v[i-1][j];
			 else
				 v[i][j]=Max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		 }
	 }

	 cout<<"Path matrix \n";
	 for(i=0;i<=n;i++)
	 {
		 for(j=0;j<=m;j++)
			 cout<<v[i][j]<<"\t";
		cout<<"\n";	
	 }

	 for(i=1;i<=n;i++)
		 x[i]=0;

	 cout<<"Max profit "<<v[n][m]<<endl;

	 i=n;j=m;
	 while(i!=0&&j!=0)
	 {
		 if(v[i][j]!=v[i-1][j])
		 {
			 x[i]=1;
			 j=j-w[i];
		 }
		 i=i-1;
	 }

	 cout<<"Selected objects are \n";
	 for(i=1;i<=n;i++)
	 {
		 if(x[i]==1)
			 cout<<"object "<<i<<endl;
	 }
 }

 void main()
 {
	 int n,m,p[max],w[max],i;

	 cout<<"Enter no of items \n";
	 cin>>n;
	 cout<<"Enter capacity of knapsack \n";
	 cin>>m;

	 cout<<"Enter profits \n";
	 for(i=1;i<=n;i++)
		 cin>>p[i];

	 cout<<"Enter weights \n";
	 for(i=1;i<=n;i++)
		 cin>>w[i];

	 knapsack(n,m,p,w);

	 getch();
 }
