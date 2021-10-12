#include <iostream>
#include <list>

using namespace std;

int main()
{
	std::list<int> IntList;
	
	for (int i = 0; i < 105; i++)
		IntList.push_back(i);



	for (std::list<int>::iterator iter = IntList.begin(); iter != IntList.end(); )
	{
		if (*iter == 77)
		{
			iter = IntList.erase(iter);
		}
		else
		{
			iter++;
		}

	}

	for (auto e : IntList)
	{
		cout << e << endl;
	}


	return 0;
}