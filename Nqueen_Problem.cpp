#include<iostream>
#include<conio.h>
using namespace std;
int place(int x[],int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		if(i-x[i]==k-x[k]||i+x[i]==k+x[k]||x[i]==x[k])
			return 0;
	}
	return 1;
}

void nqueen(int n)
{
	int k=1,i,j,c=0,x[10];
	x[k]=0;
	while(k!=0)
	{
		x[k]=x[k]+1;
		while(!place(x,k)&&x[k]<=n)
			x[k]=x[k]+1;

		if(x[k]<=n)
		{
			if(k==n)
			{
				c=c+1;
				cout<<"solution "<<c<<endl;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						if(j==x[i])
							cout<<"Q \t";
						else
							cout<<"X \t";
					}
					cout<<"\n";
				}
			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else 
			k--;
	}
}

void main()
{
	int n;
	cout<<"Enter the number of queens \n";
	cin>>n;
	if(n==2||n==3)
		cout<<"No solution \n";
	else
		nqueen(n);

	getch();
}