#include <stdio.h>
#define SWAP(a, b){int c;c = a; a = b; b = c;}
struct temp
{
	int min;
	int index;
};

void insertsort(int a[],int count)
{
    int i,j;
    for(i=1;i<count;i++)
    {
		if (a[i] < a[i - 1])
		{
			int temp = a[i];
			for(j = i;j>0;j--)
			{
				if (temp<a[j-1])
				{SWAP(a[j],a[j-1]);}
				else break;
			}
			//a[j] = temp;
		}
		
    }
}
void insertsort2(int num[],int count)
{
	int i, j;
	for (i = 1; i < count; i++) 
	{
		if (num[i] < num[i - 1]) 
		{
			int temp = num[i];
			for (j = i; j > 0; j--) 
			{
				if (num[j - 1] > temp) num[j] = num[j - 1];
				else break;
			}
			num[j] = temp;
		}
	}
}
void selectionsort(int a[],int count)
{
	struct temp temp1;
	for(int j=0;j<count;j++)
	{
		temp1.min = a[j];
		temp1.index = j;
		for(int i=j;i<count;i++)
		{
			if(a[i]<temp1.min)
			{
				temp1.min = a[i];
				temp1.index = i;
			}
		}
		SWAP(a[j],a[temp1.index]);
	}
	
}
int main()
{
    int x = 4,y = 6;
	int a[] = {8,3,1,7,6,2,5,9,4};
    //insertsort(a,sizeof(a)/sizeof(a[0]));
	selectionsort(a,9);
    for(int i =0;i<(sizeof(a)/sizeof(a[0]));i++)
    {
        printf("%d  ",a[i]);
    }
    return 0;
}