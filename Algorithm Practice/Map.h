#pragma once

#include "RBTree.h"

template<typename T1, typename T2>
class Map : public RBTree<T1, T2>// RBTree // ordered_map
{	
public:
	Map() {}
	virtual ~Map() {}

	void Insert(const T1& key, const T2& value)
	{
		RBTree<T1, T2>::InsertNode(key, value);
	}
	void Erase(const T1& key)
	{
		RBTree<T1, T2>::EraseNode(key);
	}
};

//
//template<typename T1, typename T2>
//class HashMap
//{
//
//
//
//};