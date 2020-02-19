#include<stdio.h>
 
void sort(int[],int,int);
void merge(int[],int,int,int,int);
int n,c;
int main()
{
	int i;
	scanf("%d",&n); 
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d,",&a[i]); 
		
	sort(a,0,n-1); 
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	putchar('\n');
	printf("%d",c);
	return 0;
}
 
void sort(int a[],int i,int j)
{
	int m;
	if(i<j) // strictly less than
	{
		m=(i+j)/2; 
		sort(a,i,m); 
		sort(a,m+1,j); 
		merge(a,i,m,m+1,j); 
		
		c++; 
	}
}
 
void merge(int a[],int f1,int r1,int f2,int r2)
{
	int temp[n];	
	int i,j,k;
	i=f1;
	j=f2;
	k=0;
	
	while(i<=r1 && j<=r2)
	{
		if(a[i]<=a[j]) // for stability
			temp[k++]=a[i++]; 
		else
			temp[k++]=a[j++]; 
	}
	
	while(i<=r1) 
		temp[k++]=a[i++];
		
	while(j<=r2)
		temp[k++]=a[j++];  
		
	
	for(i=f1,j=0;i<=r2;i++,j++) 
	    a[i]=temp[j];
}
