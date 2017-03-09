#include <iostream>
#include <vector>

using namespace std;

bool find(int *array, int key, int len)
{
	int lowerbound = 0;
	int upperbound = len;
	int position;
	position = ( lowerbound + upperbound) / 2;

	while(lowerbound <= upperbound)
	{
		cout << " lowerbound :" << lowerbound << " upperbound:" << upperbound << " position:" << upperbound << endl;
		if ( array[position] == key )
		{
			cout << "find" << endl;
			return true;
		}

		if (array[position] > key)               // If the number is > key, ..
		{                                                       // decrease position by one.
			upperbound = position - 1;    
		}                                                      
		else                                                
		{                                                        // Else, increase position by one.
			lowerbound = position + 1;     
		}
		position = (lowerbound + upperbound) / 2;
	}
	cout << "not find" << endl;
	return false;
}

int main()
{
	int array[] = {1,2,3,4,6,7,8,9,10};
	vector <int> vec(array, array + 9);

	find(array,10,9);

	
}
