//TODO: copy-constructor, push front, pop front, operator za prisvoyavane
#include <iostream>
using namespace std;

class ListError {};

class List 
{
	struct Node
	{
		int data_;
		Node* next_;
		Node* prev_;

	Node(int val)
	: data_(val), next_(0), prev_(0) {}
	};
	
	Node* head_;

public:
	List()
	: head_(new Node(0))
	{
		head_ -> next_ = head_;
		head_ -> prev_ = head_;
	}	

	~List()
	{
		while(!empty())
		{
			pop_back();
		}
		delete head_;
	}

	class iterator 
	{
		friend class List;
		
		List* list_;
		Node* current_;

		iterator(List* list, Node* current)
		: list_(list), current_(current) {}
	public:
		
		iterator& operator++()
		{
			current_ = current_ -> next_;
			return *this;
		}
		
		iterator operator++(int)
		{
			iterator res(list_, current_);			
			current_ = current_ -> next_;
			return res;
		}	

		int operator*()
		{
			return current_ -> data_;
		}
		
		bool operator==(const iterator& other)
		{
			return list_ == other.list_ && current_ == other.current_;
		}
		bool operator!=(const iterator& other)
		{
			return ! operator==(other);
		}
	};
		
	iterator begin()
	{
		return iterator(this, head_ -> next_);
	}

	iterator end()
	{
		return iterator(this, head_);
	}
	bool empty() const
	{
		return head_ -> next_ == head_;
	}

	void push_back(int val)
	{		
		Node* ptr = new Node(val);
		Node* back = head_ -> prev_;
		
		back -> next_ = ptr;
		ptr -> next_ = head_;
	
		head_ -> prev_ = ptr;
		ptr -> prev_ = back;
	}
	
	void pop_back()
	{
		if(empty())
		{
			throw ListError();
		}	
		Node* back = head_ -> prev_ ;
		Node* new_back = back -> prev_;
		
		new_back -> next_ = head_;
		head_ -> prev_ = new_back;
		delete back;
	}	
	
	int front() const
	{
		if(empty())
		{
			throw ListError();
		}
		return head_ -> next_ -> data_;
	}

	int back() const
	{
		if(empty())
		{
			throw ListError();
		}
		return head_ -> prev_ -> data_;
	}

	iterator insert(iterator pos, int val)
	{
		if(pos.list_ != this)
		{
			throw ListError();
		}

		Node* current = pos.current_;
		Node* prev = current -> prev_;
		Node* ptr = new Node(val);

		prev -> next_ = ptr;
		ptr -> prev_ = prev;

		ptr -> next_ = current;
		current -> prev_ = ptr; 
		
		return iterator(this, ptr);
	}

	iterator erase(iterator it)
	{
		Node* uno = it.current_ -> next_;
		Node* dos = it.current_ -> prev_;
		Node* help = uno;
		uno -> prev_ = dos;
		dos -> next_ = help;
		return iterator(this,uno);
	}

	class reverse_iterator
	{
		friend class List;
		
		List* list_;
		Node* current_;
		
		reverse_iterator(List* list,Node* cur)
		: list_(list), current_(cur) {}
	public:
		int operator*()
		{
			return current_ -> data_;
		}
	};
	reverse_iterator rbegin()
	{
		return reverse_iterator(this, head_); 
	}
	reverse_iterator rend()
	{
		return reverse_iterator(this, head_->next_);
	}
	//TODO: rbegin(); rend();
};

int main()
{
	List myl;
	
	
	myl.push_back(3);
	myl.push_back(2);
	myl.push_back(5);
		
	for(List::iterator it = myl.begin(); it != myl.end(); it++)
	{
		cout << *myl.erase(it) << endl;
	}
	
	//cout << *rit << endl;
		
	return 0;
}
