#include <stdio.h>
#include <stdlib.h>
#define count 6

void prim(int a[][count],int u[],int w[],int b[],int n)
{
	//u记录访问
	//w记录距离 相对时候记录小的
	//指向0顶点
	//b记录顶点开始位置
	int i=0,j=0,m=0,min=100;
	//初始化
	for(i=0;i<count;i++)
    {
        u[i]=0;
        w[i]=a[0][i];
        b[i]=0;
    }
    u[0]=1;

    //从0顶点开始 
    for (int i = 1; i < n; ++i)
    {
    	for (int m = 1; m < n; ++m)
    	{
    		if( !u[m] && w[m]<min )
    		{
    			min = u[m];
    			j = m;
    		}
    	}
    	//找出最小点
    	// n to j
    	u[j] = 1;
    	//更新w 有无小的边界
    	for (int m = 1; m < n; ++m)
    	{
    		if( !u[m] && a[j][m] < w[m])
    		{
    			w[m] = a[j][m];
    			b[m] = j;
    		}
    	}
    }

}

int main()
{	
	int u[count],w[count],b[count],a[count][count];
	int i,j=0;
	for(i=0;i<count;i++)
    {
        for(j=0;j<count;j++)
        {
                a[i][j]= 100;
        }
    }

    a[0][1]=6,a[0][2]=1,a[0][3]=5;
    a[1][0]=6,a[1][2]=5,a[1][4]=3;
    a[2][0]=1,a[2][1]=5,a[2][3]=5,a[2][4]=6,a[2][5]=4;
    a[3][0]=5,a[3][2]=5,a[3][5]=2;
    a[4][1]=3,a[4][2]=6,a[4][5]=6;
    a[5][3]=2,a[5][2]=4,a[5][4]=6;
    prim(a,u,w,b,count);

	return 0;
}