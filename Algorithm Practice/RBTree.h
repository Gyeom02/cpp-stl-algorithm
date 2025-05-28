#pragma once
#include "pch.h"

template<typename T>
class RBTree
{
private:
	enum Color : int
	{
		Red = 0,
		Black = 1,
	};

	struct Node
	{
		T _data;
		Color _color;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
		std::shared_ptr<Node> parent;

		Node(T value, Color color) : _data(value), _color(color) {}
		~Node() = default;

		bool operator == (const Node& node) { return _data == node->_data; }
		bool operator > (const Node& node) { return _data > node->_data; }
		bool operator < (const Node& node) { return _data < node->_data; }

		bool operator == (const T& data) { return _data == data; }
		bool operator > (const T& data) { return _data > data; }
		bool operator < (const T& data) { return _data < data; }

	};
	int numOfElement;
	std::shared_ptr<Node> nil;
	std::shared_ptr<Node> root;

private:
	shared_ptr<Node> MakeNode(Color color = Color::Red, const T& value = -1);
	shared_ptr<Node> LeftRotate(shared_ptr<Node> node);
	shared_ptr<Node> RightRotate(shared_ptr<Node> node);
	void InsertFix(shared_ptr<Node> node);
	void InsertNode(shared_ptr<Node> node, const T& data);
	void PrintAll(shared_ptr<Node> node, string* stringBuilder, string padding, const string& pointer, const bool hasRightChild) const;
	string ShowTree(shared_ptr<Node> node);
public:
	RBTree() : numOfElement(0), nil(std::make_shared<Node>(-1, Color::Black)), root(nullptr) {
		nil->left = nil->right = nil->parent = nil;

	}
	void InsertNode(const T& data) { InsertNode(root, data); }
	std::string ShowTree() const { return ShowTree(nil->right); }
};

#include "RBTree.h"

template<typename T>
shared_ptr<typename RBTree<T>::Node> RBTree<T>::MakeNode(Color color, const T& value)
{
	shared_ptr<Node> node = make_shared<Node>(value, color);
	node->left = nil;
	node->right = nil;
	node->parent = nil;
	return node;
}

template<typename T>
shared_ptr<typename RBTree<T>::Node> RBTree<T>::LeftRotate(shared_ptr<Node> node)
{
	shared_ptr<Node> node_r = node->right;
	shared_ptr<Node> node_r_l = node_r->left;

	node->right = node_r_l;
	if (node_r_l != nil)
	{
		node_r_l->parent = node;
	}

	node_r->parent = node->parent;
	if (node->parent == nil) //node->root == root node
	{
		root = node_r;
	}
	else if (node == node->parent->left)
		node->parent->left = node_r;
	else if (node == node->parent->right)
		node->parent->right = node_r;

	node_r->left = node;
	node->parent = node_r;

	return node_r;
}

template<typename T>
shared_ptr<typename RBTree<T>::Node> RBTree<T>::RightRotate(shared_ptr<Node> node)
{
	shared_ptr<Node> node_l = node->left;
	shared_ptr<Node> node_l_r = node_l->right;
	node->left = node_l_r;
	if (node->left != nil)
	{
		node->left->parent = node;
	}
	node_l->parent = node->parent;
	if (node->parent == nil) // node->parent == root node
	{
		root = node_l;
	}
	else if (node == node->parent->right)
		node->parent->right = node_l;
	else
		node->parent->left = node_l;

	node_l->right = node;
	node->parent = node_l;
	return node_l;
}

template<typename T>
void RBTree<T>::InsertFix(shared_ptr<Node> node)
{
	while (node->parent->_color == Color::Red)
	{
		shared_ptr<Node> G_node = node->parent->parent;
		if (node->parent == G_node->left)
		{
			shared_ptr<Node> uncle_node = G_node->right;
			if (uncle_node->_color == Color::Red)
			{
				uncle_node->_color = Color::Black;
				node->parent->_color = Color::Black;
				G_node->_color = Color::Red;
				node = G_node;
			}
			else
			{
				if (node->parent->right == node)
				{
					node = node->parent;
					LeftRotate(node);
				}
				node->parent->parent->_color = Color::Red;
				node->parent->_color = Color::Black;
				RightRotate(node->parent->parent);
			}
		}
		else
		{
			shared_ptr<Node> uncle_node = G_node->left;
			if (uncle_node->_color == Color::Red)
			{
				uncle_node->_color = Color::Black;
				node->parent->_color = Color::Black;
				G_node->_color = Color::Red;
				node = G_node;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					RightRotate(node);
				}

				node->parent->_color = Color::Black;
				node->parent->parent->_color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}
	root->_color = Color::Black;
}

template<typename T>
void RBTree<T>::InsertNode(shared_ptr<Node> node, const T& data)
{

	if (node == nullptr)
	{
		if (root == node)
		{
			root = MakeNode(data);
			root->_color = Color::Black;

			InsertFix(node);
			return;
		}

	}

	shared_ptr<Node> temp = node; //node is root cause only call this function with root node
	shared_ptr<Node> prevNode = nullptr;
	while (temp != nil)
	{
		prevNode = temp;
		if (temp > data)
		{
			temp = data->left;
		}
		else if (temp < data)
		{
			temp = data->right;
		}
		else
		{
			cout << "Insert value == Parent Node Data" << endl;
		}
	}

	temp = MakeNode(data);
	temp->parent = prevNode;
	if (prevNode < data)
		prevNode->right = temp;
	else
	{
		prevNode->left = temp;
	}
	InsertFix(temp);

}

template<typename T>
void RBTree<T>::PrintAll(shared_ptr<Node> node, string* stringBuilder, string padding, const string& pointer, const bool hasRightChild) const
{
}

template<typename T>
string RBTree<T>::ShowTree(shared_ptr<Node> node)
{
	return string();
}
