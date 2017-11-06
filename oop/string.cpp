#include <iostream> //SHTO E TO STRING?
#include <string>
using namespace std;

int main()
{

	string s1="Hello";
	string s2("world!");
	string s3=" ";
	
	string s;
	s= s1 + s3 + s2;
	cout << s << endl;		
	
	for(int i=0; i<s.size(); i++)
	{
		cout << s[i] << endl;
	}	
	
	auto pos = s.find("wo");
	if(pos!=string::npos)
	{
		cout << "string..." << endl;
		cout << s.substr(pos, 2) << endl;	
	} else {
		cout << "no string... :(" << endl;
	}

	pos = 0;
	while((pos=s.find("l", pos)) != string::npos)
	{
		cout << s.substr(pos, 2) << endl;
		pos ++;
	}
	return 0;
}
