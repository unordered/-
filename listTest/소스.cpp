#include <cstdio>
#include <list>

using namespace std;

int main()
{
	list<int> * intList = new list<int>();
	intList->push_back(1);
	intList->push_back(2);
	intList->push_back(3);
	intList->push_back(4);
	intList->push_back(5);
	intList->push_back(6);
	intList->push_back(7);
	intList->push_back(8);
	intList->push_back(9);
	intList->push_back(10);
	intList->push_back(11);
	intList->push_back(12);

	auto end = intList->end(); 
	for (auto iter = intList->begin(); intList->end() != iter; )
	{
		if (*iter == 12)
		{
			iter = intList->erase(iter);
			int j = 0;
		}
		else
		{
			iter++;
		}
	}


	printf("end!");
	return 0;

}