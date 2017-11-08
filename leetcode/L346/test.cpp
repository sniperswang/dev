
#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		array = new int[size];
		sum = 0;
		total = 0;
		_size = size;
		memset(array, 0, sizeof(int)*size);
	}

	double next(int val) {
		if (array == NULL)
		{
			return 0.0;
		}
		int head = total % _size;
		sum -= array[head];
		sum += val;
		array[head] = val;
		total++;	
		return (total > _size) ? double(sum)/_size:double(sum)/total;
		
	}

private:
	int* array; 
	int sum;
	int total;
	int _size;

};
  
int main() 
{
	// [[5],[12009],[1965],[-940],[-8516],[-16446],[7870],[25545],[-21028],[18430],[-23464]]
	//["MovingAverage","next","next","next","next","next","next","next","next","next","next"]
    // [[5],[12009],[1965],[-940],[-8516],[-16446],[7870],[25545],[-21028],[18430],[-23464]]
	MovingAverage m(5);
	cout << m.next(12009) << endl; //= 1
	cout << m.next(1965) << endl; //= (1 + 10) / 2
	cout << m.next(-940) << endl; //= (1 + 10 + 3) / 3
	cout << m.next(-8516) << endl; //= (10 + 3 + 5) / 3
	cout << m.next(-16446) << endl; //= (3 + 5 + 4) / 4
	cout << m.next(7870) << endl; //= (3 + 5 + 4) / 4
	cout << m.next(25545) << endl; //= (3 + 5 + 4) / 4
	cout << m.next(-21028) << endl; //= (3 + 5 + 4) / 4
	cout << m.next(18430) << endl; //= (3 + 5 + 4) / 4
	cout << m.next(-23464) << endl; //= (3 + 5 + 4) / 4
    return 0;
}
