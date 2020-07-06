#include <set>
#include <map>
#include <iostream>
using namespace std;

void testMap()
{
	//multimap: 允许key值重复
	multimap<int, int> m;
	//map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(1, 2));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(1, 3));
	//遍历按照key进行有序的遍历
	for (auto p : m)
	{
		cout << p.first << "--->" << p.second << endl;
	}

	cout << "equal-range:" << endl;
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> pairIt = m.equal_range(1);
	multimap<int, int>::iterator it = pairIt.first;
	while (it != pairIt.second)
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
}

void testSet()
{
	//set<int> m;
	//multiset: 可以存放重复的数据
	multiset<int> m;
	m.insert(1);
	m.insert(2);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	//遍历有序
	for (auto& e : m)
	{
		cout << e << endl;
	}
	auto pairIt = m.equal_range(1);
	auto it = pairIt.first;
	while (it != pairIt.second)
	{
		cout << *it << endl;
		++it;
	}
}

int main()
{
	//testMap();
	testSet();
	return 0;
}