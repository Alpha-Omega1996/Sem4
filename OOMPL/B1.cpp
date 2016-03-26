#include "B1.h"
#include<iostream>
using std::cout;
using std::endl;
template <class T>
class Prime
{
	public:
		Prime(T data = 0)
		{
			val = data;
			type = (prime(val) == 0)? 1 : 0;
		}
		bool isPrime()
		{
			return type;
		}
	private:
	bool type;
	T val;
};

int main()
{
	Prime<int> p1(152);
	Prime<float> p2(5.0f);
	Prime<double> p3(0.05);
	cout<<p1.isPrime()<<p2.isPrime()<<p3.isPrime()<<endl;
	return 0;
}