#include <iomanip>  
#include <iostream>
#include <vector>
#include <map>
#include <assert.h>  
#include <unordered_map>
#include <time.h>   


using namespace std;


template <typename T>
class MyContainer
{
	public:
		void insert(const T& t);
		void remove(const T& t);
		T random(); 
		MyContainer();
		bool isExist(const T& t);

	private:
		vector<T> vec;
		int size;
		unordered_map<T, int> tmap;
};

template <typename T>
MyContainer<T>::MyContainer()
{
	size = 0;
}

template <typename T>
bool MyContainer<T>::isExist(const T& t)
{
	if ( tmap.find(t) != tmap.end() )
		return true;
	return false;
}

template <typename T>
void MyContainer<T>::insert(const T& t)
{
	vec.push_back(t);
	size++;
	tmap[t] = size - 1;
}

template <typename T>
void MyContainer<T>::remove(const T& t)
{
	if ( tmap.find(t) != tmap.end() )
	{
		int pos = tmap[t];
		vec[pos] = vec[size-1];
		tmap[vec[size-1]] = pos;
		vec.pop_back();
		tmap.erase(t);
		size--;
	}
}

template <typename T>
T MyContainer<T>::random()
{
	int i = rand() % size;
	cout << i << endl;
	return vec[i];
}

	
 
int main() 
{
	MyContainer<int> intVec;

	intVec.insert(6);
	intVec.insert(4);
	intVec.insert(-6);
	intVec.insert(10);
	intVec.insert(11);
	intVec.insert(12);

	intVec.remove(10);

	for (int i = 0; i < 100; i++)
		intVec.random();
	
	cout << intVec.isExist(-7) << endl;

    return 0;
}
