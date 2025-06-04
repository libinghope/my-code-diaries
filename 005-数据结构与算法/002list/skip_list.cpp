#include<iostream>
#include<vector>
using namespace std;

//跳表节点
struct SkipNode
{
    int key;
    int value;
    vector<SkipNode*> next;

    //构造函数，初始化
    SkipNode(int k, int v, int level) : key(k), value(v)
    {
        for (int i = 0; i < level; i++)
        {
            next.push_back(nullptr);
        }
    }

};

class SkipList
{

public:
    //头结点
    SkipNode* head;
    
    //列表最大层数
    int maxLevel;

    //整型的最小值和最大值
    const int minInt = INT_MIN;
    const int maxInt = INT_MAX;

public:
    //构造函数
    SkipList(int maxLevel, int iniValue);

    //析构函数
    ~SkipList();

    //随机层数方法
    int randomLevel();

    //插入, 查找， 删除
    SkipNode* insert(int k, int v);
    SkipNode* find(int k);
    SkipNode* deleteNode(int k);

    //打印
    void printNode();

private:

    //尾节点
    SkipNode* tail;
    
    //找到当前列表或者node的最大层数
    int nodeLevel(vector<SkipNode*> p);
};

//初始化
 SkipList::SkipList(int maxLevel, int iniValue) : maxLevel(maxLevel)
{
    //初始化头结点和尾节点为整型最小值和最大值
    head = new SkipNode(minInt, iniValue, maxLevel);
    tail = new SkipNode(maxInt, iniValue, maxLevel);

    //所有层数上的头结点指向尾节点
    for (int i = 0; i < maxLevel; i++)
    {
        head->next[i] = tail;
    }
}

SkipList::~SkipList()
{
    delete head;
    delete tail;
}

int SkipList::randomLevel()
{
	int random_level = 1;
	int seed = time(NULL);
	static uniform_int_distribution<int> u(0, 1);

	while (random_level < maxLevel)
	{
		random_level++;
	}

	return random_level;
}

int SkipList::nodeLevel(vector<SkipNode*> next)
{
	int node_level = 0;
	
	if (next[0]->key == maxInt)
	{
		return node_level;
	}

	for (int i = 0; i < next.size(); i++)
	{
		if (next[i] != nullptr && next[i]->key != maxInt)
		{
			node_level++;
		}
		else
		{
			break;
		}
	}
	return node_level;
}

/*插入：
1）首先用查找函数来判断该结点是否已经存在，如果存在，则更新该结点的值
2）获取新节点的随机层数
3）找到合适的插入位置
4）插入，并调整每层前后node的指针*/
SkipNode* SkipList::insert(int k, int v)
{
	int x_level = randomLevel();
	SkipNode* new_node = nullptr;
	SkipNode* tmp = head;

	new_node = find(k);

	if (new_node) {
		
		new_node->value = v;
		//cout << "\ninthis node " << k << " has already existed. And its value has been updated to " << v << endl;
		return head;
	}

	//cout << "key: " << k << ", randomLevel: " << x_level << endl;

	new_node = new SkipNode(k, v, x_level);

	for (int i = (x_level - 1); i > -1; i--)
	{
		while (tmp->next[i] != nullptr && tmp->next[i]->key < k)
		{
			tmp = tmp->next[i];
		}

		new_node->next[i] = tmp->next[i];
		tmp->next[i] = new_node;
	}

	return head;
}

/*查找：
由于列表有序，首先找到小于该结点的最近的结点，如果下一个结点等于目标结点，则返回该节点。
如果不是，则返回空*/
SkipNode* SkipList::find(int x)
{
	SkipNode* tmp = head;
	int current_level = nodeLevel(tmp->next);

	for (int i = (current_level - 1); i > -1; i--)
	{
		while (tmp->next[i] != nullptr && tmp->next[i]->key < x)
		{
			tmp = tmp->next[i];
		}
	}
	tmp = tmp->next[0];

	if (tmp->key == x)
	{
		//cout << "\ninthis key " << x << " has been found\n";
		return tmp;
	}
	else
	{
		//cout << " \ninthis key " << x << " doesn't exit\n";
		return nullptr;
	}
}

/*删除：
1) 用 find(x) 方法判断该结点是否存在. 如果不存在，则返回当前list, 并告知该结点不存在。
2) 找到小于该结点的最近的结点。
3) 更改该节点每层的前面的结点的指针。*/
SkipNode* SkipList::deleteNode(int x)
{
	SkipNode* node = find(x);
	if (!node)
	{
		// "\n inthis deleting node" << x << "doesn't exist" << endl;
		return head;
	}
	else
	{
		SkipNode* tmp = head;
		int x_level = node->next.size();

		//cout << "\ninthe deleting node " << x << "'s level is " << x_level << endl;

		for (int i = (x_level - 1); i > -1; i--)
		{
			while (tmp->next[i] != nullptr && tmp->next[i]->key < x)
			{
				tmp = tmp->next[i];
			}
			tmp->next[i] = tmp->next[i]->next[i];

			//cout << "inthis node " << x << " has been deleted from level " << i << endl;
		}

		return head;
	}
}


// 分层打印

void SkipList::printNode()
{

	for (int i = 0; i < maxLevel; i++)
	{
		SkipNode* tmp = head;
		int lineLen = 1;

		if (tmp->next[i]->key != maxInt)
		{
			cout << "\n";
			cout << "This is level " << i << ":" << endl;
			cout << "{";

			while (tmp->next[i] != nullptr && tmp->next[i]->key != maxInt)
			{
				cout << "(" << "Key: " << tmp->next[i]->key << ", ";
				cout << "Value: " << tmp->next[i]->value << ")";

				tmp = tmp->next[i];

				if (tmp->next[i] != nullptr && tmp->next[i]->key != maxInt)
				{
					cout << ", ";
				}

				if (lineLen++ % 5 == 0) cout << "\n";
			}
			cout << "}" << "\n";
		}
	}
}



