#include <iostream>
#include <vector>
#include <map>

using namespace std;

class A
{
	public:
	A(int i)
	{
		throw i;
	}
};

class B
{
	public:
	B(int c)
	{
	}
};

class C: private A
{
public:
	B b_;
	C()
	try
		: A(1)
		,b_(2)
	{
	}catch(...)
	{
		cout << "we catch it" << endl;
		std::overflow_error e("Yao over flow");
		throw e;
	}
};

void f()
try
{
}
catch (...)
{
}

class D
{
};
  
int main() 
{
	D d;
	C c;
    return 0;
}
