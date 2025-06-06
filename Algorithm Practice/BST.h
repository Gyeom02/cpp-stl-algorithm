#pragma once
#include "pch.h"

template<typename T>
class BST
{
private:
	struct Node
	{
		shared_ptr<Node> left;
		shared_ptr<Node> right;
		T data;

		Node(const T& _d) :data(_d), left(nullptr), right(nullptr) {}
		~Node() { cout << " Node Destructor : " << data << endl; }
	};

	shared_ptr<Node> root;
public:
	BST() :root(nullptr) {}
	~BST() { cout << "BST Destructor" << endl; }

	void Insert(const T& _d) { root = Insert(root, _d); }
	void Erase(const T& _d) { root = Erase(root, _d); }

private:
	shared_ptr<Node> Insert(shared_ptr<Node> root, const T& _d);
	shared_ptr<Node> Erase(shared_ptr<Node> node, const T& _d);
	shared_ptr<Node> GetMaxNode(shared_ptr<Node> node);
	shared_ptr<Node> GetMinNode(shared_ptr<Node> node);

};

template<typename T>
inline shared_ptr<typename BST<T>::Node> BST<T>::Insert(shared_ptr<Node> node, const T& _d)
{
	if (node == nullptr)
	{
		shared_ptr<Node> temp = make_shared<Node>(_d);
		return temp;

	}
	if (_d < node->data)
	{
		node->left = Insert(node->left, _d);
	}
	else if (_d > node->data)
	{
		node->right = Insert(node->right, _d);
	}
	else
	{
		cout << "BST Does Not Treat Same Value Data " << endl;
	}
	return node;
}

template<typename T>
inline shared_ptr<typename BST<T>::Node > BST<T>::Erase(shared_ptr<Node> node, const T& _d)
{
	if (node == nullptr)
		return node;
	if (_d < node->data)
	{
		node->left = Erase(node->left, _d);
	}
	else if (_d > node->data)
	{
		node->right = Erase(node->right, _d);
	}
	else if (node->left && node->right)
	{
		shared_ptr<Node> temp = GetMaxNode(node->left);
		T tempD = temp->data;
		temp->data = node->data;
		node->data = tempD;
		node->left = Erase(node->left, temp->data);
	}
	else
	{
		if (node->left)
		{
			node = node->left;

		}
		else if (node->right)
		{
			node = node->right;
		}
	}
	return node;
}

template<typename T>
inline shared_ptr<typename BST<T>::Node> BST<T>::GetMaxNode(shared_ptr<Node> node)
{
	if (node == nullptr)
		return node;
	if (node->right == nullptr)
		return node;

	return GetMaxNode(node->right);
}

template<typename T>
inline shared_ptr<typename BST<T>::Node> BST<T>::GetMinNode(shared_ptr<Node> node)
{
	if (node == nullptr)
		return node;
	if (node->left == nullptr)
		return node;
	return GetMinNode(node->left);
}
