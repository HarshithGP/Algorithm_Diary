import java.io.*;
class quickSort{


	public static int partition(int arr[], int left, int right){

		
		int key=arr[right];
		int i=left-1;
		int j,temp;

		for(j=left; j<right;j++){

			if(arr[j]<key){

				i=i+1;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}

		temp = arr[i+1];
		arr[i+1]=arr[right];
		arr[right]=temp;

		return i+1;
		

		/*

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

	*/

	}

	public static void quicksort(int arr[],int left, int right){

		if(left<right){

			int q = partition(arr,left,right);
			quicksort(arr,left,q-1);
			quicksort(arr,q+1,right);
		}
	}

	public static void main(String args[]) throws IOException{

		int num[]={5,2,11,43,53,12,18,23};
		System.out.println("Before Sort");
		for(int x: num)
			System.out.print(x+" ");

		quicksort(num,0,num.length-1);
		System.out.println("\nAfter Sort");
		for(int x: num)
			System.out.print(x+" ");

		System.out.println("");

	}
}