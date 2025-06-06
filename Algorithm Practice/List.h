#pragma once
#include "pch.h"
class SingleLinkedList
{

};

template<typename T>
class DoubleLinkedList
{
private:
	struct Node
	{
		T data;
		std::shared_ptr<Node> _head;
		std::shared_ptr<Node> _tail;
		Node(T _key = -1) : _head(nullptr), _tail(nullptr), data(_key) {}
	};
	std::shared_ptr<Node> head; // head->_tail == root == begin()
	std::shared_ptr<Node> end; //
public:
	class iterator
	{
	public:
		T& operator *() { return target->data; }
		bool operator ==(const iterator& iter) { return target == iter.target; }
		bool operator !=(const iterator& iter) { return target != iter.target; }
		iterator& operator ++ () { target = target->_tail; return *this; }
		iterator& operator -- () { target = target->_head; return *this; }
	private:
		iteraotr(shared_ptr<Node>& node) { target = node; }
		std::shared_ptr<Node> target;
	};

public:
	DoubleLinkedList() 
	{ 
		head = make_shared<Node>();
		end = make_shsared<Node>();
		head->_tail = end;
		end->_head = head;
	}
	~DoubleLinkedList() = default;

	iterator& Insert(T value, int index);
	void Insert_Back(T value);
	void Insert_Front(T value);
	T Pop_Front();
	T Pop_Back();
	iterator& Find(T value);
	bool Erase(T value);
	void Clear();
	bool Empty();
	iterator& Begin() { return iterator(head->_tail); }
	iterator& End() { return iterator(end); }
};

template<typename T>
inline DoubleLinkedList<T>::iterator& DoubleLinkedList<T>::Insert(T value, int index)
{

	//shared_ptr<Node> temp = Find();
	//for (int i = 0; i <= index; i++)
	//{
	//	temp = temp->_tail;
	//	if (temp == end)
	//		return;
	//}
	return NULL;
}

template<typename T>
inline void DoubleLinkedList<T>::Insert_Back(T value)
{
	shared_ptr<Node> newRoot = make_shared<Node>(value);
	newRoot->_tail = end;
	end->_head->_tail = newRoot;
	end->_head = newRoot;
	newRoot->_head = end->_head;
}

template<typename T>
inline void DoubleLinkedList<T>::Insert_Front(T value)
{

	shared_ptr<Node> newRoot = make_shared<Node>(value);
	newRoot->_tail = head->_tail;
	head->_tail->_head = newRoot;
	head->_tail = newRoot;
	newRoot->_head = head;
}

template<typename T>
inline T DoubleLinkedList<T>::Pop_Front()
{
	_ASSERT(head->_tail != end); // 리스트에 있는 밸류의 개수가 > 0 이다
	shared_ptr<Node> temp = Begin().target;
	T popValue = temp->data;
	
	head->_tail = temp->_tail;
	temp->_tail->_head = temp->_head;
	return popValue;

}

template<typename T>
inline T DoubleLinkedList<T>::Pop_Back()
{
	_ASSERT(head->_tail != end); // 리스트에 있는 밸류의 개수가 > 0 이다
	shared_ptr<Node> temp = end->_head;;
	T popValue = temp->data;

	head->_tail = temp->_tail;
	temp->_tail->_head = temp->_head;
	return popValue;
}

template<typename T>
inline bool DoubleLinkedList<T>::Erase(T value)
{
	_ASSERT(root != nullptr);
	shared_ptr<Node> temp = root;
	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			//Find!
			if (temp->_head)
			{
				temp->_head->_tail = temp->_tail;
				if (temp->_tail)
				{
					temp->_tail->_head = temp->_head;
				}
			}
			else root = nullptr;
			temp->_head = nullptr;
			temp->_tail = nullptr;
			return true;
		}
		temp = temp->_tail;
	}
	return false;
}

template<typename T>
inline void DoubleLinkedList<T>::Clear()
{
	
	if (head->_tail == end)
		return;
	shared_ptr<Node> temp = head->_tail;


	while (temp != nullptr)
	{
		shared_ptr<Node> tempTail = temp->_tail;
		temp->_head = nullptr;
		temp->_tail = nullptr;
		temp = tempTail;
	}
	head->_tail = end;
	end->_head = head;
}

template<typename T>
inline bool DoubleLinkedList<T>::Empty()
{
	return head->_tail == end ? true : false;
}
