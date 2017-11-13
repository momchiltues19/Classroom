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
	Stack() 
	: size_(chunk_), data_(new int[chunk_]), top_(-1) {}
	
	Stack(const Stack& other)
	: top_(other.top_), size_(other.size_), data_(new int[size_])
	{
		cout << "copying" << endl;		
		for (int i = 0; i <= top_; ++i)
		{		
			data_[i] = other.data_[i];
		}	
	} 	

	~Stack()
	{
		cout << "destroying" << endl;
		delete [] data_;	
	}

	Stack& operator=(const Stack& other)
	{
		if(this != other)
		{		
			delete [] data_;
			top_ = other.top_;
			size_ = other.size_;
			data_ = new int [size_];
			for(int i = 0; i <= top_; ++i)
			{
				data_[i] = other.data_[i];
			}	
		}
		return *this;
	}	
	
  	bool empty() const {
    	return top_ == -1;
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
		int *temp = data_;
		data_ = new int[chunk_ + size_];
		for(int i = 0; i < size_; i++)
		{
			data_[i] = temp[i];
		}	
		delete [] temp;
		size_ += chunk_;
	}
};

int sum(Stack st)
{
	int s = 0;
	while(!st.empty())
	{
		s += st.pop();
	}
	return s;
}

int main()
{
 	Stack mystk;
	for(int i = 0; i < 10; i++)
	{	
		mystk.push(i);
	}	

	cout << sum(mystk) << endl;
	
	Stack stk;
	stk = mystk;

	cout << sum(stk) << endl;
	try
	{
		while (!mystk.empty())
		{		
			cout << mystk.pop() << endl;
		}	
	} catch (const exception & e) {
		cout << "sth went wrong" << endl;
	}	
	return 0;
}
