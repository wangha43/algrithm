#include <math.h>
#include <iostream>

using namespace std;

void  get_gaussian_kernel(int size,double sigma)
{
	double gaus[size][size];
	const double PI =4.0*atan(1.0);
	int center = size/2;
	double sum=0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			gaus[i][j]=(1/(2*PI*sigma*sigma))*exp(-((i-center)*(i-center)+(j-center)*(j-center))/(2*sigma*sigma));
			sum+=gaus[i][j];
		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			gaus[i][j]/=sum;
			cout<<gaus[i][j]<<"  ";  
		}
		cout << endl;
	}
	return;
}

int main(int argc, char const *argv[])
{
	get_gaussian_kernel(3,1);
	return 0;
}