#pragma once

template <typename T>
class CList
{
public:
	struct Node
	{
		T _data;
		Node* _Prev;
		Node* _Next;
	};

	class iterator
	{
	public:
		Node* _node;
	public:
		iterator(Node* node = nullptr)
		{
			// 인자로 들어온 Node 포인터를 저장
			_node = node;
		}

		iterator operator++(int)
		{
			// 현재 노드를 다음 노드로 이동
			_node = _node->_Next;
		}

		iterator& operator++()
		{
			_node = _node->_Next;
			return *this;
		}

		iterator operator--(int)
		{
			_node = _node->_Prev;
		}

		iterator& operator--()
		{
			_node = _node->_Prev;
			return *this;
		}

		T& operator *()
		{
			//현재 노드의 데이터를 뽑음
			return _node->_data;
		}
		bool operator==(const iterator& other)
		{
			if (_node->_data == other._node->_data)
				return true;
			else
			{
				return false;
			}
		}
		bool operator !=(const iterator& other)
		{
			if (_node->_data != other._node->_data)
				return true;
			else
			{
				return false;
			}
		}
	};

public:
	CList();
	~CList();

	iterator begin()
	{
		//첫번째 데이터 노드를 가리키는 이터레이터 리턴
		iterator* iter = new iterator();
		iter->_node = _head._Next;
		return *iter;

	}
	iterator end()
	{
		//Tail 노드를 가리키는(데이터가 없는 진짜 더미 끝 노드) 이터레이터를 리턴
		//	또는 끝으로 인지할 수 있는 이터레이터를 리턴
		iterator* iter = new iterator();
		iter->_node = _tail;
		return *iter;
	}

	void push_front(T data);
	void push_back(T data);
	T pop_front();
	T pop_back();
	void clear();
	int size() { return _size; };
	bool empty() { };

	iterator erase(iterator iter)
	{
		//	- 이터레이터의 그 노드를 지움.
		//	- 그리고 지운 노드의 다음 노드를 카리키는 이터레이터 리턴
		iterator temp;
		/*temp._node = iter._node->_Next;
		iter._node->_Prev->_Next = iter._node->_Next;
		iter._node->_Next->_Prev = iter._node->_Prev;*/
		return temp;

	}
	void remove(T Data)
	{
		CList<int>::iterator iter;
		for (iter = begin(); iter != end(); ++iter)
		{
			if (*iter == Data)
				erase(iter);
		}
	}

private:
	int _size = 0;
	Node _head;
	Node _tail;
};

template<typename T>
inline CList<T>::CList()
{
	
}

template<typename T>
inline CList<T>::~CList()
{

}

template<typename T>
inline void CList<T>::push_front(T data)
{
	Node* temp = new Node();
	temp->_data = data;

	temp->_Next= _head._Next;
	_head._Next._Prev = temp;
	_head._Next = temp;
	temp->Prev = &_head;
}

template<typename T>
inline void CList<T>::push_back(T data)
{
	Node temp;
	temp->_data = data;

	_tail._Prev._Next = temp;
	temp->_Prev = _tail._Prev;

	temp->_Next = &_tail;
	_tail._Prev = temp;

}

template<typename T>
inline T CList<T>::pop_front()
{
	T temp = _head._Next._data;
	_head._Next._Next._Prev = &_head;
	_head._Next = _head._Next._Next;

	return temp;
}

template<typename T>
inline T CList<T>::pop_back()
{
	T temp = _tail._Prev._data;
	_tail._Prev._Prev._Next = &_tail;
	_tail._Prev= _tail._Prev._Prev;


	return temp;
}

template<typename T>
inline void CList<T>::clear()
{
	// 노드 순회하면서 delete 해주기
	for (auto i = begin(); i < end(); i++)
	{
		delete i;

	}
}
