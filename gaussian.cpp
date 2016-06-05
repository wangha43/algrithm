/* 
*高斯消去法求解矩阵
*/
#include <iostream>
using namespace std;
template <class T>
/*
 *申请一个二维数组
 */
T ** Allocation2D(int m,int n)
{
	T **a;
	a = new T *[m];
	for (int i = 0; i < m; ++i)
	{
		a[i]= new T[n];
	}
	return a;
}

int main(){
	int i,j,k;
	int n;
	float **a;
	cout<<"输入系数矩阵的N值,N:"<<endl;
    cin>>n;
//初始化
    a = Allocation2D<float>(n,n+1);
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n+1; ++j)
    	{
    		cin >>a[i][j];
    	}
    }

//化为上三角矩阵
for(k=0;k<n-1;k++){
	for(i=k+1;i<n;i++){
		for(j=k+1;j<n+1;j++){
			a[i][j]=a[i][j]-a[i][k]*a[k][j]/a[k][k];
		}
	}
}

float temp;

//求出第一个解 最后一行
a[n-1][n] = a[n-1][n]/a[n-1][n-1];
//逐步求解
for(k=n-2;k>=0;k--){
	temp=0;
	for(j=k+1;j<n;j++){
		temp=temp+a[k][j]*a[j][n];
	}
	a[k][n]=(a[k][n]-temp)/a[k][k];
}

for(i=0;i<n;i++){
	cout<<"x"<<i<<": "<<a[i][n]<<endl;
}
return 0;
}													