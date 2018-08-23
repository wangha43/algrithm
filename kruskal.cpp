#include <iostream>
#define N 7

using namespace std;

typedef struct _node
{
	int val;
	int start;
	int end;
}Node;

Node V[N];

int cmp(const void *a,const void *b)
{
	return (*(Node*)a).val-(*(Node *)b).val;
}

int edge[N][3] = {{0,1,3},
				{0,4,1},
				{1,2,5},
				{1,4,4},
				{2,3,2},
				{2,4,6},
				{3,4,7}
};

int father[N] = {0,};
int cap[N] = {0,};

void make_set()
{
	for (int i = 0; i < N; ++i)
	{
		father[i] = i;
		cap[i] = 1;
		/* code */
	}
}

int find_set(int x)
{
	if(x != father[x])
	{
		father[x] = find_set(father[x]);
	}
	return father[x];
}

void Union(int x,int y)
{
	x = find_set(x);
	y = find_set(y);

	if(x == y)
		return ;
	if(cap[x] < cap[y])
		father[x] = find_set(y);
	else
	{
		if(cap[x] == cap[y])
			cap[x]++;
		father[y] = find_set(x);
	}
}

int kruskal(int n)
{
	int sum = 0;
	make_set();
	for (int i = 0; i < N; ++i)
	{
		if(find_set(V[i].start) != find_set(V[i].end))
		{
			Union(V[i].start,V[i].end);
			sum +=V[i].val;
		}
		/* code */
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; ++i)
	{
		V[i].start = edge[i][0];
		V[i].end = edge[i][1];
		V[i].val = edge[i][2];
	}
	qsort(V,N,sizeof(V[0]),cmp);
	cout << kruskal(0)<<endl;

	return 0;
}

