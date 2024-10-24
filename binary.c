#include<stdio.h>
int binarysearch(int array[],int x,int low,int high)
{
	while(low<=high)
	{
	int mid=low+(high-low)/2;
	if(x==array[mid])
		return mid;
	if(x>array[mid])
		low=mid+1;
	else
		high=mid-1;
	}
	return -1;
}
int main()
{
	int n;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	int array[n];
	printf("Enter %d sorted elements :\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	int x;
	printf("Enter the number to search for:");
	scanf("%d",&x);
	int result=binarysearch(array,x,0,n-1);
	if(result==-1)
		printf("Not found\n");
	else
		printf("Element is found at %d\n",result);
	return 0;
}
