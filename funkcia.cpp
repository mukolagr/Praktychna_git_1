#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctime>

int mas( int a[][4], const int i, int imax, int sum1,int m)
{
	int sum = 0,j;
	for (j = 0;j < m;j++)
	{
		sum += a[i][j];
	}
	if (sum > sum1) imax=i;
	return imax;
}

int mass(int a[][4], const int i, int imax, int sum1,int m)
{
	int sum = 0, j;
	for (j = 0;j < m;j++)
	{
		sum += a[i][j];
	}
	if (sum > sum1) sum1=sum;
	return sum1;
}

int minznach(int a[][4], const int imax, int m)
{
	int min=0, j ;
	min = a[imax][0];
	for (j = 0;j < m;j++)
	{
		if (min > a[imax][j]) min = a[imax][j];
	}
	return min;
}

int main()
{
	using namespace std;
	int i, imax = 0, j, n = 1, sum1 = 0, min;
	const int m = 4;
	int a[m][m]{};
	cout << "Write a[4][4]=\n";
	srand(time(NULL));

	for (i = 0;i < m;i++)
	{
		for (j = 0;j < m;j++)
		{
			a[i][j] = rand() % 41-20;
			cout << a[i][j] << "\t";
		}
		imax = mas(a, i, imax, sum1,m);
		sum1 = mass(a, i, imax, sum1,m);
		cout << "\n";
	}
	min = minznach(a, imax, m);
	cout << "imax = " << imax << "\n";
	cout << "min = " << min << "\n";
	return 0;
}