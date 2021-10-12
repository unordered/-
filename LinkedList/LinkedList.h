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
			// ���ڷ� ���� Node �����͸� ����
			_node = node;
		}

		iterator operator++(int)
		{
			// ���� ��带 ���� ���� �̵�
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
			//���� ����� �����͸� ����
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
		//ù��° ������ ��带 ����Ű�� ���ͷ����� ����
		iterator* iter = new iterator();
		iter->_node = _head._Next;
		return *iter;

	}
	iterator end()
	{
		//Tail ��带 ����Ű��(�����Ͱ� ���� ��¥ ���� �� ���) ���ͷ����͸� ����
		//	�Ǵ� ������ ������ �� �ִ� ���ͷ����͸� ����
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
		//	- ���ͷ������� �� ��带 ����.
		//	- �׸��� ���� ����� ���� ��带 ī��Ű�� ���ͷ����� ����
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
	// ��� ��ȸ�ϸ鼭 delete ���ֱ�
	for (auto i = begin(); i < end(); i++)
	{
		delete i;

	}
}
