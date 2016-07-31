
#include <iostream>
#include <vector>
#include <map>
#include "test.h"

using namespace std;

void Tester::print(int i)
{
	cout << i << endl;
}

#define TRACE(s) cerr<< #s <<endl; s

int main() 
{
	Tester test;
	int i = 5;
	short j = 6;
	test.print(j);
	test.i_print(j);
	int i =0;
	//for (int i = 0; i < 5; i++)
	{
		TRACE(i);	
	}
    return 0;
}
