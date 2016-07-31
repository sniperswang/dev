#include <stdio.h>
#include <iostream>
using namespace std;

#define f(x) \
	void test() \
	{ \
		printf("%s\n",x); \
	}

class Tester
{
	public:
	f(str)
	inline Tester()
	{
		memset(str,'a',sizeof(str));
	}

	inline void print()
	{
		printf("%s\n",str);
	}

	void print(int i);
	inline void i_print(int i)
	{
	}
	private:
	char str[100];
};
