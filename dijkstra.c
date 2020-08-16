#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6
#define INF 0xFFFFFFFF


/*vMatrix --邻接矩阵
 *apex    --起始顶点
 * prePoint --前驱顶点数组 经过的顶点
 *finalPointVal --长度数组 路径长度
 */

void dijkstra(unsigned int vMatrix[][MAX],
		int apex,
		unsigned int prePoint[],
		unsigned int finalPointVal[]
		)
{
	int i,k;
	unsigned int temp,min;
	int flag[MAX]={0};//记录最短路径获取与否


	for (int i = 0; i < MAX; ++i)
	{
		flag [i] = 0;
		prePoint [i] = 0;
		finalPointVal[i] = vMatrix[apex][i];
	}

	for (int i = 1; i < MAX; ++i)
	{
		min = INF;

		for (int j = 0; j < MAX; ++j)
		{
			if(flag[j] == 0 && finalPointVal[j] <min)
			{
				min = finalPointVal[j];
				k = j;
			}	
		}

		flag[k] = 1; //已经找到当前一条最短

		for (int j = 0; j < MAX;  ++j)
		{
			temp = (vMatrix[k][j] == INF ? INF : (min + vMatrix[k][j]));
			if (flag[j] == 0 && temp<finalPointVal[j])//对比是否比当前的长度更小 取最短 
			{
				finalPointVal[j] = temp;
				prePoint[j] = k;
			}
		}
	}

	for (int i = 0; i < MAX; ++i)
	{
		printf("shortest(1,%d) = %d\n", i+1,finalPointVal[i]);
	}
}

int main()
{
	unsigned int prePoint[MAX];
	unsigned int desPoint[MAX];
	unsigned int vMatrix[MAX][MAX] = {
		{0,1,12,INF,INF,INF},
		{INF,0,9,3,INF,INF},
		{INF,INF,0,INF,5,INF},
		{INF,INF,4,0,13,15},
		{INF,INF,INF,INF,0,4},
		{INF,INF,INF,INF,INF,0}
	};
	
	memset(prePoint,0,sizeof(prePoint));
	memset(desPoint,0,sizeof(desPoint));
	dijkstra(vMatrix,0,prePoint,desPoint);

	return 0;
}