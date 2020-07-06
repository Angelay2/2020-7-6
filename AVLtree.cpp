/*
平衡因子 = 右子树的高度-左子树的高度
只能在新插入的或者度为0的结点下面插入
每插入一个节点
	1.需要从此节点的父结点开始进行平衡因子的更新
		更新原则: 如果是从左子树更新上来的, 则 -- 平衡因子
				  如果是从右子树更新上来的, 则++平衡因子
	2. 判断是否需要调整
		如果更新之后:
			a. 平衡因子为 0, 停止更新
			b. 平衡因子为-1/1, 继续向上更新 
			c. 平衡因子为-2/2, 孩子节点平衡因子为-1/1, 进行右旋/左旋, 停止更新 (-2->左边高, 2->右边高)
		子树的高度发生变化, 势必影响父结点
	3. 右旋关系的修改, subL, subLR, parent  -----> 保持始终为完全平衡二叉树
		1. subL->right = parent
		2. parent->left = subLR
		3. if(subLR); subLR->parent = parent (subLR必须非空)
		4. if(parent != root)
			subL->parent = parent->parent     
				if(parent->parent->left == parent)
					parent->parent->left = subL;
				else
					parent->parent->right = subL;
			else // 更新根结点
				root = subL;
				subL->parent = nullptr;
		5. parent->parent = subL;
		6. 更新平衡因子: sub->_bf = parent->_bf = 0;
*/

template <class T>
struct AVLNode
{
	T _value;
	int _bf;
	AVLNode<T>* _parent;
	AVLNode<T>* _left;
	AVLNode<T>* _right;

	AVLNode(const T& val = T())
		:_value(val)
		, _bf(0)
		, _parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	AVLTree(Node* root = nullptr)
		:_root(root)
	{}

	bool insert(const T& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == val)
				return false;
			else if (cur->_value < val)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		cur = new Node(val);
		if (parent->_value < val)
			parent->_right = cur;
		else
			parent->_left = cur;

		// 1. 调整
		while (parent)
		{
			//平衡因子更新
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//判断是否需要继续更新和调整
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				//继续向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//左边的左边高，进行右旋
					RotateR(parent);
				}

				break;
			}
		}
	}
private:
	Node* _root;
};