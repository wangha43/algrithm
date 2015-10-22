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

int choose_center(int i,int j){
	return ((i+j)/2);
}
void quickSort(int * a, int low, int high){  
    int pos;  
    if(low < high){  
        pos = findPos(a, low, high); 
        display_array(low,high,a); 
        quickSort(a, low, pos-1);  
        quickSort(a, pos+1, high);  
    }  
}  
  
int findPos (int * a, int low, int high){  
    int val = a[low];  
    while(low < high){  
        while(low < high && a[high] >= val){  //比标准小跳出循环 并赋值 相当于交换位置
            --high;  
        }  
        a[low] = a[high];  
  
        while(low < high && a[low] <= val){  //比标准大跳出循环 并赋值 相当于交换位置
            ++low;  
        }  
        a[high] = a[low];  
    }  
    a[low] = val;//最后得到的位置  
    return low;  //返回
}  
int main(int argc, char **argv)
{
	printf("quickSort\n");
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
	quickSort(array,0,len-1);
	free(array);
	return 0;
}