#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;


int main(void)
{
	/*
	map<char, int> Numbers;
	
	Numbers['A'] = 10;
	Numbers['B'] = 20;
	Numbers['C'] = 30;
	Numbers['D'] = 40;
	Numbers['E'] = 50;
	Numbers['F'] = 60;
	
	for (map<char, int>::iterator iter = Numbers.begin();
		iter != Numbers.end(); ++iter)
	{
		cout << iter->first << " : " << iter->second << endl;
	}
	*/
	
	map<char, list<int>> Numbers;


	list<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	Numbers['A'] = A;

	list<int> B;
	B.push_back(10);
	B.push_back(20);
	B.push_back(30);
	B.push_back(40);
	B.push_back(50);
	B.push_back(60);
	Numbers['B'] = B;

	list<int> C;
	C.push_back(100);
	C.push_back(200);
	C.push_back(300);
	C.push_back(400);
	Numbers['C'] = C;

	list<int> D;
	D.push_back(40);
	Numbers['D'] = D;

	list<int> E;
	E.push_back(1000);
	E.push_back(2000);
	E.push_back(3000);
	E.push_back(4000);
	E.push_back(5000);
	Numbers['E'] = E;

	list<int> F;
	F.push_back(60);
	Numbers['F'] = F;


	for (map<char, list<int>>::iterator iter = Numbers.begin();
		iter != Numbers.end(); ++iter)
	{
		cout << iter->first << endl;

		for (list<int>::iterator iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << (*iter2) << endl;
		}

		cout << endl << endl;
	}

	return 0;
}

