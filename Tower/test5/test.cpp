#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef std::vector< std::vector<unsigned int> > TestEntries;

unsigned int stockHelper(std::vector<unsigned int> testEntry )
{
	unsigned int profits = 0;
	int maxValue = testEntry[testEntry.size()-1];
	for (int i = testEntry.size() - 2; i >= 0; i--)
	{
		maxValue = testEntry[i] > maxValue ? testEntry[i]:maxValue;
		profits += maxValue - testEntry[i]; 
	}
	return profits;
}

/*
vector <unsigned int> stockMaximize(TestEntries testEntries)
{
	vector<unsigned int> result;
	int testNumber=1;
	for (auto & testEntry : testEntries)
	{
		//cout << "Test#[" << testNumber << "]";
		std::size_t priceIndex = 1;
		int len = testEntry.size();
		int profit = 0;
		for (auto & price : testEntry)
		{
		//cout << " Price" << priceIndex++ << " [" << price << "]";
		}
		//cout << endl;
		++testNumber;
	}
	return result;
}
*/

int main() 
{
	std::vector<unsigned int> testEntry;
	testEntry.push_back(1);
	testEntry.push_back(2);
	testEntry.push_back(100);

	cout << stockHelper(testEntry) << endl;
    return 0;
}
