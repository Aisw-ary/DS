#include<stdio.h>
int main()
{
	int c,first,last,m,n,search,a[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter %d integers",n);
	for(c=0;c<n;c++)
	{
		scanf("%d",&a[c]);
	}
	printf("Enter the value to find:");
	scanf("%d",&search);
	first=0;
	last=n-1;
	m=(first+last)/2;
	while(first<=last)
	{
		if(a[m]<search)
		{
			first=m+1;
		}
		else if(a[m]==search)
		{
			printf("%d find at location %d",search,m+1);
			break;
		}
		else 
		{
			last=m-1;
			m=(first+last)/2;
		}
		if(first>last)
		{
			printf("Not found");
		}
		
	}
	return 0;
}

		
