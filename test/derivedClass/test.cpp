
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class A
{
public:
	A()
	{
		// print() // wrong
	}
	virtual void print() = 0;
	void test ()
	{
		print();
	}
};

class B: public A
{
public:
	B()
	{
		print();
	}
	void print()
	{
		cout << "print B" << endl;
	}
};
  
int main() 
{
	A *a = new B;
	//a->print(); // print b;
	a->test();
    return 0;
}
