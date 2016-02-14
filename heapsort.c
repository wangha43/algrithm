#include <stdio.h>
#include <stdlib.h>
//i开始 n为节点总数 从0开始 i的子节点 2i+1 2i+2 
void heap_min_sort(int a[],int i,int n){
	int j,temp;
	temp = a[i];
	j = 2*i+1;
	//查处两个子节点中较大的那一个
	while(j<n){
		if(j+1 < n && a[j+1]<a[j])
			j++;
		if(a[j]>=temp)
			break;
		a[i]=a[j];
		i = j;
		j = 2*i+1;
	}
	a[i]=temp;
}
//建堆
void make_min_heap(int a[],int n){
	for(int i = n/2-1;i>=0;i--){
		heap_min_sort(a,i,n);
	}
	for(i=n-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        array[i]=array[0]^array[i];
        array[0]=array[0]^array[i];
        array[i]=array[0]^array[i];
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(array,0,i);
    }
}

 void display_array(const int first, const int len, const int *array)
{
	int i;
	static int count=0;
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

int main(){
	int len,i;
	int *array;
	printf("input count of number:");
	scanf("%d",&len);
	array=(int *)malloc(sizeof(int)*len);
	// memset((void *)array,0,(unsigned long) 4*len);//初始化为0
	printf("input numbers:");
	for( i=0; i<len; i++)
	{
		scanf("%d",&array[i]);
	} 
	display_array(0,len,array);
	make_min_heap(array,len-1);
	display_array(0,len,array);
	free(array);
	return 0;
}