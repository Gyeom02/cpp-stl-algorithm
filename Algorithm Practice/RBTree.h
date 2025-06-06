#pragma once
#include "pch.h"

template<typename T, typename T2 = int>
class RBTree
{
protected:
	enum Color : int
	{
		Red = 0,
		Black = 1,
	};

	struct Node
	{
		T _key;
		T2 _value;
		Color _color;
		std::shared_ptr<Node> left;
		std::shared_ptr<Node> right;
		std::shared_ptr<Node> parent;

		Node(T value,T2 value_2, Color color) : _key(value), _value(value_2), _color(color) {}
		~Node() = default;

		bool operator == ( shared_ptr<Node> node) { return _key == node->_key; }
		bool operator > (shared_ptr<Node> node) { return _key > node->_key; }
		bool operator < (shared_ptr< Node> node) { return _key < node->_key; }

		bool operator == (const T& data) { return _key == data; }
		bool operator > (const T& data) { return _key > data; }
		bool operator < (const T& data) { return _key < data; }

	};
	int numOfElement;
	std::shared_ptr<Node> nil;
	std::shared_ptr<Node> root;

protected:
	virtual shared_ptr<Node> MakeNode(Color color = Color::Red, const T& key = -1, const T2& value =-1);
	shared_ptr<Node> LeftRotate(shared_ptr<Node> node);
	shared_ptr<Node> RightRotate(shared_ptr<Node> node);
	void InsertFix(shared_ptr<Node> node);
	void InsertNode(shared_ptr<Node>& node, const T& data, const T2& val = -1);
	void EraseNode(shared_ptr<Node> node, const T& data);
	shared_ptr<Node> GetMaxNode(shared_ptr<Node> node);
	shared_ptr<Node> GetMinNode(shared_ptr<Node> node);
	void InorderTraversal(shared_ptr<Node> node);
public:
	RBTree() : numOfElement(0), nil(std::make_shared<Node>(-1, -1, Color::Black)), root(nullptr) {
		nil->left = nil->right = nil->parent = nil;

	}
	virtual ~RBTree() {}
	void InsertNode(const T& data, const T& data_2 = -1) { InsertNode(root, data, data_2); }
	void EraseNode(const T& data) { EraseNode(root, data); }
	void InorderTraversal() { InorderTraversal(root); }
};

#include "RBTree.h"

template<typename T, typename T2>
shared_ptr<typename RBTree<T, T2>::Node> RBTree<T, T2>::MakeNode(Color color, const T& value, const T2& value_2)
{
	shared_ptr<Node> node = make_shared<Node>(value, value_2, color);
	node->left = nil;
	node->right = nil;
	node->parent = nil;
	return node;
}

template<typename T, typename T2>
shared_ptr<typename RBTree<T, T2>::Node> RBTree<T, T2>::LeftRotate(shared_ptr<Node> node)
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

template<typename T, typename T2>
shared_ptr<typename RBTree<T, T2>::Node> RBTree<T, T2>::RightRotate(shared_ptr<Node> node)
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

template<typename T, typename T2>
void RBTree<T, T2>::InsertFix(shared_ptr<Node> node)
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

template<typename T, typename T2>
void RBTree<T, T2>::InsertNode(shared_ptr<Node>& node, const T& data, const T2& val)
{

	if (node == nullptr)
	{
		if (root == node)
		{
			root = MakeNode(Color::Black, data, val);
			//node->_color = Color::Black;

			InsertFix(root);
			return;
		}

	}

	shared_ptr<Node> temp = node; //node is root cause only call this function with root node
	shared_ptr<Node> prevNode = temp;
	bool bleft = false;
	while (temp != nil)
	{
		prevNode = temp;
		if (temp->_key > data)
		{
			temp = prevNode->left;
			bleft = true;
		}
		else if (temp->_key < data)
		{
			temp = prevNode->right;
			bleft = false;
		}
		else
		{
			cout << "Insert value == Parent Node Data" << endl;
		}
	}
	if (bleft)
	{
		prevNode->left = MakeNode(Color::Red, data, val);
		prevNode->left->parent = prevNode;
		temp = prevNode->left;
	}
	else 
	{
		prevNode->right = MakeNode(Color::Red, data, val);
		prevNode->right->parent = prevNode;
		temp = prevNode->right;
	}
	
	InsertFix(temp);
	return;
}

template<typename T, typename T2>
inline void RBTree<T, T2>::EraseNode(shared_ptr<Node> node, const T& data)
{
	if (node == nullptr)
		return;
	while (node != nil)
	{
		if (node->_key > data)
		{
			node = node->left;
			continue;
		}
		else if (node->_key < data)
		{
			node = node->right;
			continue;
		}
		else if (node->right != nil && node->left != nil)
		{
			shared_ptr<Node> maxNode = GetMaxNode(node->left);
			//it could be minNode to Use GetMinNode(Node->right)
			T md = maxNode->_key;
			maxNode->_key = node->_key;
			node->_key = md;
			EraseNode(node->left, maxNode->_key);
			return;
		}
		else
		{
			shared_ptr<Node> selectNode = nullptr;
			shared_ptr<Node> p_n = node->parent;
			if (node->right != nil)
			{
				selectNode = node->right;
				
			}
			else if (node->left != nil)
			{
				selectNode = node->left;
			}

			selectNode->parent = p_n;
			if (p_n->left == node)
			{
				p_n->left = selectNode;
			}
			else if (p_n->right == node)
			{
				p_n->right = selectNode;
			}
			node = selectNode;
			break;
		}
	}
	InsertFix(node);
}


template<typename T, typename T2>
inline shared_ptr<typename RBTree<T, T2>::Node> RBTree<T, T2>::GetMaxNode(shared_ptr<Node> node)
{
	if (node == nullptr)
		return nullptr;
	if (node->right == nullptr)
		return node;
	return GetMaxNode(node->right);
}


template<typename T, typename T2>
inline shared_ptr<typename RBTree<T, T2>::Node> RBTree<T, T2>::GetMinNode(shared_ptr<Node> node)
{
	if (node == nullptr)
		return nullptr;
	if (node->left == nullptr)
		return node;
	return GetMinNode(node->left);
}
template<typename T, typename T2>
inline void RBTree<T, T2>::InorderTraversal(shared_ptr<Node> node)
{
	//cout << " !" << endl;
	if (node == nil)
		return;
	InorderTraversal(node->left);
	cout << "Key : " << node->_key << " Value : " << node->_value  << " Parent : " << node->parent->_key << endl;
	InorderTraversal(node->right);
}

