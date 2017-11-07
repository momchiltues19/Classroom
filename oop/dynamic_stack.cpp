#include <iostream>
#include <exception>

using namespace std;

class Stack
{
	const static int chunk_ = 2;	
	int size_;
	int *data_;
	int top_;
public: 
	Stack () : size_(chunk_), data_(new int[chunk_]), top_(-1) {}
	~Stack ()
	{
		cout << "destroying" << endl;
		delete [] data_;	
	}
	void push(int v)
	{
		if (top_ >= (size_-1))
		{
			resize();
		}
		data_[++top_] = v;
	}
		
	int pop()
	{
		if(top_ < 0)
		{
			throw exception();
		}
		return data_[top_--];
	}
private:
	void resize()
	{
		cout << "resizing" << endl;
		int *temp = data_;
		data_ = new int[chunk_ + size_];
		for(int i = 0; i < size_; i++)
		{
			data_[i] = temp[i];
		}	
		delete [] temp;
		size_ += chunk_;
		cout << "resize" << endl;
	}
};

int main()
{
 	Stack mystk;
	mystk.push(3);
	mystk.push(2);
	mystk.push(1);
	try
	{
		cout << mystk.pop() << endl;
		cout << mystk.pop() << endl;
		cout << mystk.pop() << endl;
	} catch (const exception & e) {
		cout << "sth went wrong" << endl;
	}	
	return 0;
}
