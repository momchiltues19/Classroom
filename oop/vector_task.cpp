#include <iostream>

using namespace std;

class VectorErrors {};
class Vector {
	int capacity_;
	int size_;
	int* buffer_;
public:
	Vector(int capacity)
	: capacity_(capacity),
	  size_(0),
	  buffer_(new int[capacity])
	{}

	~Vector() {
		delete [] buffer_;
	}

	int size() const
	{
		return size_;
	}
	
	int capacity() const
	{
		if (size_ > capacity_) throw VectorErrors();		
		return capacity_;
	}

	bool empty() const
	{
		return size_ == 0;
	}

	void push_back(const int& value)
	{
		buffer_[size_++] = value;
	}	
	
	int& front()
	{
		return buffer_[0];
	}		

	const int& front() const
	{
		return buffer_[0];
	}		

	void clear()	
	{
		for(int i = 0; i < size_; i++)
			buffer_[i] = 0;
		size_ = 0;
	}

	int& operator[](int n)
	{
		if(n > capacity_) throw VectorErrors();
		return buffer_[n];
	}
	
	const int& operator[](int n) const
	{	
		if(n > capacity_) throw VectorErrors();		
		return buffer_[n];
	}
};

int main()
{
	Vector myvec(10);
	cout << "size: "<< myvec.size() << endl;
	cout << "capacity: "<< myvec.capacity() << endl;
	cout << "empty: "<< myvec.empty() << endl;
	for(int i = 0; i < 10; i++)
	{
		myvec.push_back(i);
	}	
	cout << "third el: "<< myvec[3] << endl;
	myvec.clear();
	cout << "after clear: "<< myvec[3] << endl;
	return 0;
}
