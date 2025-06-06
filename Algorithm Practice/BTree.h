#pragma once
#include "pch.h"
#include <vector>
template<typename T, int M>
class Btree_M // M means b " - " tree
{
private:
	struct Node 
	{
		T* keys;
		weak_ptr<Node>* child;
		bool bLeaf = true; // 리프노드인지 알려주는 Boolean
		int key_size = 0;
		const int max_keys = M;
		Node(const T& v) 
		{
			keys = new T[M]; child = new weak_ptr<Node>[M + 1]; keys[0] = v;
			for (int i = 0; i < M; i++)
				keys[i] = -1;
			for (int i = 0; i < M + 1; i++)
				child[i] = nullptr;
			
		} 
		~Node() { delete keys; keys = nullptr; delete child; child = nullptr; }

	};
	int child_max_size = M + 1;
	shared_ptr<Node> root;

private:
	shared_ptr<Node> Insert(shared_ptr<Node> node, const T& v, shared_ptr<Node> parent);
	shared_ptr<Node> Erase(shared_ptr<Node> node, const T& v);
	shared_ptr<Node> MakeNode(const T& v);
	//void SplitNode();
public:
	Btree() : root(nullptr) {}
	~Btree() { cout << "Btree Destructor " << endl; }

	void Insert(const T& v) { root = Insert(root, v); }
	void Erase(const T& v) { root = Erase(root, v); }
};


template<typename T, int M>
inline shared_ptr<typename Btree_M<T, M>::Node> Btree_M<T, M>::Insert(shared_ptr<Node> node, const T& v, shared_ptr<Node> parent)
{
	if (node == nullptr)
	{
		return MakeNode(v);;
	}
	if (node->bLeaf) // 리프노드이다
	{
		if (node->key_size >= M) // key full
		{
			if (parent == nullptr)
			{

			}
			else
			{
				T midkey = node->keys[M / 2];
				for (int i = midkey + 1; i < node->key_size; i++)
				{
					node->keys[i - 1] = node->keys[i];
				}
				node->key_size -= 1;
			}
			
		}
		else
		{

		}
	}
	else
	{
		int m = node->key_size - 1;
		while (m >= 0)
		{
			if (v > node->keys[m]) // 0, 1, 2 max = 2
			{
				break;
			}
			m--;
		}
		Insert(node->keys[m + 1], v, node);
	}
	return shared_ptr<Node>();
}

template<typename T, int M>
shared_ptr<typename Btree_M<T, M>::Node> Btree_M<T, M>::Erase(shared_ptr<Node> node, const T& v)
{
	return nullptr;
}

template<typename T, int M>
inline shared_ptr<typename Btree_M<T,M>::Node> Btree_M<T, M>::MakeNode(const T& v)
{
	shared_ptr<Node> temp = make_shared<T, M>(v);
	temp->key_size = 1;
	return temp;
}
