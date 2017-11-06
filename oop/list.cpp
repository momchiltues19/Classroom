#include <iostream>
#include <list>
using namespace std;

void print_list(list<int>&lie)
{
        //auto is can replace list<int>::iterator
        for(auto it = lie.begin(); it!=lie.end(); ++it)
        {
                cout << (*it) << " ";
        }
        cout << endl;
}

int main()
{
        list<int> lie;
        cout << "size=" << lie.size() << endl;
        //cout << "cap=" << li.capacity() <<endl;
        cout << "empty=" << lie.empty() << endl;

        lie.push_back(0); //put element in the end of the list
        lie.push_back(1);
        lie.push_back(2);
        lie.push_back(3);
        cout << "size=" << lie.size() << endl; //obvi
        cout << "empty=" << lie.empty() << endl; //also obvi
        print_list(lie);

        lie.push_front(-1); //put element in the beggining of the list
        lie.push_front(-2);
        lie.push_front(-3);
        cout << "size=" << lie.size() << endl;
        print_list(lie);

        lie.insert(lie.begin(), -10); //puts el in the said place
        lie.insert(lie.end(), 10);
        print_list(lie);

        auto it = lie.begin(); //auto initializes iterator, also tells you the type? chorbi go obiasni mnogo zle
        it++;
        lie.insert(it, -9); //puts el in the second place(in the memory) of the list cause it = begin + 1
        print_list(lie);

        it = lie.begin();
        it++;
        lie.erase(it); //erases element *(begin + 1)
        print_list(lie);

        list<int> l1(10); //new list with 10 0s
        print_list(l1);

        int a[] = {0,1,2,3,4,5,6,7,8,9};
        list<int> l2(a, a+10);
        print_list(l2); //tuk veche slushash

        return 0;
}
