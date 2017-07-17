import java.io.*;
class mergeSort {

	public static void merge_sort(int a[], int left, int right) {

		if(left<right){

			int middle=(left+right)/2;
			merge_sort(a,left,middle);
			merge_sort(a,middle+1,right);
			merge(a,left,middle,right);
		}
	}

	public static void merge(int a[], int l, int m, int r){

		int n1=m-l+1;
		int n2=r-m;
		int i,j;
		int L[] = new int[n1];
		int R[] = new int[n2];

		for (i = 0; i < n1; i++)
        	L[i] = a[l + i];
    	for (j = 0; j < n2; j++)
        	R[j] = a[m + 1+ j];

        i=0;j=0;
		int k=l;
		while (i < n1 && j < n2)
    	{
           if (L[i] <= R[j])
        	{
           		 a[k] = L[i];
            	i++;
        	}
        	else
        	{
            	a[k] = R[j];
            	j++;
        	}
        	k++;
    	}
 
    /* Copy the remaining elements of L[], if there
       are any */
    	while (i < n1)
    	{
        	a[k] = L[i];
        	i++;
        	k++;
    	}
 
    /* Copy the remaining elements of R[], if there
       are any */
    	while (j < n2)
    	{
       		a[k] = R[j];
        	j++;
        	k++;
    	}

    	System.out.println("After MergeSort");
		for(int z:a)
			System.out.print(z+" ");

		System.out.println(""); 
		
	}

	public static void main(String args[]){

		
		int a[]={3,2,1,-1,0,-13,1,1,4,6,4,2,18,3,0};
		merge_sort(a,0,a.length-1);

		System.out.println("After MergeSort");
		for(int z:a)
			System.out.print(z+" ");

		System.out.println(""); 

	}
}