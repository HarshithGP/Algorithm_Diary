import java.io.*;
import java.util.Scanner;
class sort{

	static void insertionSort(int num[]){

		int i,j,key;

		for(j=1;j<num.length;j++){

			key=num[j];
			i=j-1;

			while(i>=0 && num[i]>key){
				num[i+1]=num[i];
				i--;
			}

			num[i+1]=key;
		}

		displayArray(num);
	}

	static int partition(int num[], int l, int r){

		int pivot=num[r];
		int i,j,temp;

		i=l-1;
		for(j=l;j<r;j++){
			if(num[j]<=pivot){
				i++;
				temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}

		temp=num[i+1];
		num[i+1]=num[r];
		num[r]=temp;

		return i+1;
	}

	static void quickSort(int num[], int l, int r){

		if(l<r){
			int m=partition(num,l,r);
			quickSort(num,l,m-1);
			quickSort(num,m+1,r);
		}
		
	}

	static void merge_sort(int num[], int l, int r){
		if(l<r){
			int m=(l+r)/2;
			merge_sort(num,l,m);
			merge_sort(num,m+1,r);
			merge(num,l,m,r);
		}
	}

	static void merge(int num[], int l, int m, int r){

		int n1=m-l+1;
		int n2=r-m;

		int left[] = new int[n1+1];left[n1]=999;
		int right[] = new int[n2+1];right[n2]=999;

		int i,j,k;

		for(i=0;i<n1;i++)
			left[i]=num[l+i];
		

		for(j=0;j<n2;j++)
			right[j]=num[m+j+1];
		

		i=0;j=0;
		for(k=l;k<=r;k++){
			if(left[i]<=right[j])
			{
				num[k]=left[i];
				i++;
				
			}
			else
			{
				num[k]=right[j];
				j++;
				
			}
		}
	}

	static void displayArray(int num[]){

		System.out.println("Sorted Array");

		for(int i:num)
			System.out.print(i+" ");
		System.out.println("");
	}


	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int num[] = { 3, 9,1,3,-8, -8, -1, 0, 0, 5, 1, 0,-1,7, -0};

		while(true){

			System.out.println("1.Insertion Sort \n2.Quick Sort \n3.Merge Sort \n0.Exit \n");
			int ch=sc.nextInt();
			switch(ch){
				case 1: insertionSort(num); break;
				case 2: quickSort(num,0,num.length-1);displayArray(num);break;
				case 3: merge_sort(num,0,num.length-1);displayArray(num);break;
				case 0: System.exit(0);
			}
		}
	}

}
