#pragma once

#include <memory>

template<typename T>
class AVLTree
{
private:
	struct AVLTreeNode
	{
	public:
		T data;
		int height;
		std::shared_ptr<AVLTreeNode> _left;
		std::shared_ptr<AVLTreeNode> _right;

		AVLTreeNode(T value) : data(value), height(1), _left(nullptr), _right(nullptr)  {}
	};
	int GetBalanceFactor(std::shared_ptr<AVLTreeNode> node);
	int GetHeight(std::shared_ptr<AVLTreeNode> node);
	void UpdateHeight(std::shared_ptr<AVLTreeNode> node);
	std::shared_ptr<AVLTreeNode> root;
public:
	AVLTree() :root(nullptr) {}
	~AVLTree() = default;

	void Insert(T value);
	void Erase(T value);
	void PrintAll();

private:
	std::shared_ptr<AVLTreeNode> LeftRotate(std::shared_ptr<AVLTreeNode> root);
	std::shared_ptr<AVLTreeNode> RightRotate(std::shared_ptr<AVLTreeNode> root);
	std::shared_ptr<AVLTreeNode> Insert(std::shared_ptr<AVLTreeNode> node, T value);
	void Erase(std::shared_ptr<AVLTreeNode> node, T value);
	void PrintAll(std::shared_ptr<AVLTreeNode> node);
};


#include "AVLTree.h"
#include "pch.h"

template<typename T>
int AVLTree<T>::GetBalanceFactor(std::shared_ptr<AVLTreeNode> node)
{
	return (node == nullptr) ? 0 : GetHeight(node->_left) - GetHeight(node->right);
}

template<typename T>
int AVLTree<T>::GetHeight(std::shared_ptr<AVLTreeNode> node)
{
	return (node == nullptr) ? 0 : node->height;
}

template<typename T>
void AVLTree<T>::UpdateHeight(std::shared_ptr<AVLTreeNode> node)
{
	if (node)
	{
		node->height = 1 + std::max(node->_left->height, node->_right->height);
	}
}

template<typename T>
void AVLTree<T>::Insert(T value)
{
	root = Insert(root, value);
}

template<typename T>
void AVLTree<T>::Erase(T value)
{
	Erase(root, value);
}

template<typename T>
void AVLTree<T>::PrintAll()
{
	PrintAll(root);
	std::cout << std::endl;
}

template<typename T>
std::shared_ptr<typename AVLTree<T>::AVLTreeNode> AVLTree<T>::LeftRotate(std::shared_ptr<AVLTreeNode> root)
{
	std::shared_ptr<AVLTreeNode> node = root->_right;
	std::shared_ptr<AVLTreeNode> node_r_left = node->left;


	node->_left = root;
	root->_right = node_r_left;

	UpdateHeight(node);
	UpdateHeight(root);
	return node;
}

template<typename T>
std::shared_ptr<typename AVLTree<T>::AVLTreeNode> AVLTree<T>::RightRotate(std::shared_ptr<AVLTreeNode> root)
{
	std::shared_ptr<AVLTreeNode> node = root->left;
	std::shared_ptr<AVLTreeNode> node_l_right = node->right;


	node->_right = root;
	root->_left = node_l_right;

	UpdateHeight(node);
	UpdateHeight(root);
	return node;
}

template<typename T>
std::shared_ptr <typename AVLTree<T>::AVLTreeNode> AVLTree<T>::Insert(std::shared_ptr<AVLTreeNode> node, T value)
{
	if (node == nullptr)
	{
		node = std::make_shared<typename AVLTree<T>::AVLTreeNode>(value);
		return node;
	}

	if (node->data > value)
	{
		node->_left = insert(node->_left, value);
	}
	else if (node->data < value)
	{
		node->_right = insert(node->_right, value);
	}
	else
	{
		//TODO ERROR
		std::cout << "AVLTree Insert Error node->data == value" << endl;
		return node;
	}

	UpdateHeight(node);

	int balance = GetBalanceFactor(node);
	if (balance < -1) // RR
	{
		//TOOD LeftRotate
		if (value < node->_right->data)
			RightRotate(node->right);
		LeftRotate(node);
	}
	else if (balance > 1) // LL
	{
		//TODO RightRoate
		if (value > node->_left->data)
			LeftRotate(node->left);
		RightRotate(node);
	}


	return node;
}

template<typename T>
void AVLTree<T>::Erase(std::shared_ptr<AVLTreeNode> node, T value)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->data > value) // Ã£¾Ò´Ù
	{

	}
}

template<typename T>
void AVLTree<T>::PrintAll(std::shared_ptr<AVLTreeNode> node)
{
	if (node == nullptr)
		return;
	inorderTraversal(node->left);
	std::cout << node->data << " ";
	inorderTraversal(node->right);
}
