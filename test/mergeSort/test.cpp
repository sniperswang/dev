#include <iostream>
#include <vector>
#include <map>

using namespace std;

void merge(int* array, int p, int q, int r)
{
	int m = q-p+1;
	int n = r-q;
	int *left = new int[m+1];	
	int *right = new int[n+1];
	for (int i = 0; i < m; i++)
	{
		left[i] = array[p+i];
	}
	
	for (int i = 0; i < n; i++)
	{
		right[i] = array[q+1+i];
	}

	left[m] = INT_MAX;
	right[n] = INT_MAX;

	int i = 0;
	int j = 0;
	int index=0;
	while (true)
	{	
		if (left[i] > right [j] || (i == m))
		{
			array[p+index] = right[j];
			j++;
		}
		else 
		{
			array[p+index] = left[i];
			i++;
		}
		index++;
		if ( i == m && j == n)
		{
			break;
		}
	}
	delete[] left;
	delete[] right;
}

void mergeSort(int* array, int p, int r)
{
	if (p < r) 
	{
		int q = ( p + r) / 2;
		mergeSort(array, p, q);
		mergeSort(array, q+1, r);
		merge(array, p ,q, r); 
	}
}
  
int main() 
{
	int fool [] = {9,8,7,6,5,4,3,2,1};
	mergeSort(fool, 0, 8);
	for (int i =0 ;i < 9; i++)
	{
		cout << fool[i] << ",";
	}
	cout << endl;
   return 0;
}
