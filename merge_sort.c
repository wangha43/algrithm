#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//显示数组
 void display_array(const int first, const int len, const int *array)
{
	int i;
	static count=0;
	printf("(%2d):",count++);
	for( i=0; i<first ; i++)
	{
		printf("    ");
	}
	for( i=0; i<len; i++)
	{
		printf("%3d ",array[i]);
	}
	printf("\n");
}
//合并
void merge(int *array,const int first, const int mid, const int last)
{
	int i,index;
	int first1,last1;
	int first2,last2;
	int *tmp;
	tmp = (int *)malloc((last-first+1)*sizeof(int));
	if( tmp == NULL )
		return;
	first1 = first;
	last1  = mid;
	first2 = mid+1;
	last2  = last;
	index = 0;
	while( (first1 <= last1) && (first2 <= last2) )
	{
		if( array[first1] < array[first2] )
		{
			tmp[index++] = array[first1];
			first1++;
		}
		else{
			tmp[index++] = array[first2];
			first2++;
		}
	}
	while( first1 <= last1 )
	{
		tmp[index++] = array[first1++];
	}
	while( first2 <= last2 )
	{
		tmp[index++] = array[first2++];
	}
	for( i=0; i<(last-first+1); i++)
	{
		array[first+i] = tmp[i];
	}
	free(tmp);
}
/*
void merge_sort(int *array, const int first, const int last)
{
	int mid=0;
	if(first < last)
	{
		mid=(first+last)/2;
		merge_sort(array,first,mid);
		merge_sort(array,mid+1,last);
		merge(array,first,mid,last);
		display_array(first, last-first+1, array+first);
	}
}
*/

void merge_sort(int *list, const int first, const int last)
{
	int len= last-first+1;
	int left_min,left_max;
	int right_min,right_max;
	int index;
	int i;
	int *tmp;
	tmp = (int *)malloc(sizeof(int)*len);
	if( tmp == NULL || len <= 0 )
		return;
	// 比较 ： 2 4 8 16... 
	for( i = 1; i < len; i *= 2 )
	{
		for( left_min = 0; left_min < len - i; left_min = right_max)
		{
			int j;
			right_min = left_max = left_min + i;
			right_max = left_max + i;
			j = left_min;
			if ( right_max > len )
				right_max = len;
			index = 0;
			while( left_min < left_max && right_min < right_max )
			{
				tmp[index++] = (list[left_min] > list[right_min] ? list[right_min++] : list[left_min++]);
			}
			//若左边的还有较大的剩下	则赋值给list右边  
			while( left_min < left_max )
			{
				list[--right_min] = list[--left_max];//右边的剩有较大的则不用转换
			}
			//将排好的从tmp中取出来
			while( index > 0 )
			{
				list[--right_min] = tmp[--index];
			}
			display_array(j,i*2,list+j);
		}
	}
	free(tmp);
}
int main(int argc, char **argv)
{
	int len,i;
	int *array;
	printf("input count of number:");
	scanf("%d",&len);
	array=(int *)malloc(sizeof(int)*len);
	memset((void *)array,0,4*len);//初始化为0
	printf("input numbers:");
	for( i=0; i<len; i++)
	{
		scanf("%d",&array[i]);
	} 
	display_array(0,len,array);
	merge_sort(array,0,len-1);
	free(array);
	return 0;
}