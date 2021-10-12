#include <iostream>
#include "LinkedList.h"
#include <string>


class CPlayer
{
public:
	int id;
	std::string nickName;

	CPlayer(int id, std::string str)
	{
		this->id = id;
		nickName = str;
	}

	int GetId()
	{
		return id;
	}
};

int main()
{
	///////////////// 객체 삭제 샘플 코드 /////////////////////////



	CList<CPlayer*> ListPlayer;

	ListPlayer.push_back(new CPlayer(15,"AAA"));
	ListPlayer.push_back(new CPlayer(25, "BAA"));
	ListPlayer.push_back(new CPlayer(43, "CAA"));
	ListPlayer.push_back(new CPlayer(56, "DCA"));
	ListPlayer.push_back(new CPlayer(82, "KCA"));
	ListPlayer.push_back(new CPlayer(99, "BCA"));
	ListPlayer.push_back(new CPlayer(106,"ACA"));

	printf("순회 시작\n");

	for (CList<CPlayer*>::iterator iter = ListPlayer.begin(); iter != ListPlayer.end(); ++iter)
	{
		CPlayer* p = *iter;
		std::cout<<"id: "<< p->id << " nickName: " << p->nickName << std::endl;
	}




	for (CList<CPlayer*>::iterator iter = ListPlayer.begin(); iter != ListPlayer.end(); )
	{
		CPlayer* data = *iter;

		
		if ((*iter)->GetId() == 43)
		{
			//delete* iter;
			//iter = ListPlayer.erase(iter);
		}
		else
		{
			++iter;
		}
	}



	printf("삭제 후 순회\n");

	for (CList<CPlayer*>::iterator iter = ListPlayer.begin(); iter != ListPlayer.end(); ++iter)
	{
		CPlayer* p = *iter;
		std::cout << "id: " << p->id << " nickName: " << p->nickName << std::endl;
	}




	return 0;
}