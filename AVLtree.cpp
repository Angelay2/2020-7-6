/*
ƽ������ = �������ĸ߶�-�������ĸ߶�
ֻ�����²���Ļ��߶�Ϊ0�Ľ���������
ÿ����һ���ڵ�
	1.��Ҫ�Ӵ˽ڵ�ĸ���㿪ʼ����ƽ�����ӵĸ���
		����ԭ��: ����Ǵ�����������������, �� -- ƽ������
				  ����Ǵ�����������������, ��++ƽ������
	2. �ж��Ƿ���Ҫ����
		�������֮��:
			a. ƽ������Ϊ 0, ֹͣ����
			b. ƽ������Ϊ-1/1, �������ϸ��� 
			c. ƽ������Ϊ-2/2, ���ӽڵ�ƽ������Ϊ-1/1, ��������/����, ֹͣ���� (-2->��߸�, 2->�ұ߸�)
		�����ĸ߶ȷ����仯, �Ʊ�Ӱ�츸���
	3. ������ϵ���޸�, subL, subLR, parent  -----> ����ʼ��Ϊ��ȫƽ�������
		1. subL->right = parent
		2. parent->left = subLR
		3. if(subLR); subLR->parent = parent (subLR����ǿ�)
		4. if(parent != root)
			subL->parent = parent->parent     
				if(parent->parent->left == parent)
					parent->parent->left = subL;
				else
					parent->parent->right = subL;
			else // ���¸����
				root = subL;
				subL->parent = nullptr;
		5. parent->parent = subL;
		6. ����ƽ������: sub->_bf = parent->_bf = 0;
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

		// 1. ����
		while (parent)
		{
			//ƽ�����Ӹ���
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//�ж��Ƿ���Ҫ�������º͵���
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				//�������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					//��ߵ���߸ߣ���������
					RotateR(parent);
				}

				break;
			}
		}
	}
private:
	Node* _root;
};