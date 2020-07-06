#include <set>
#include <map>
#include <iostream>
using namespace std;

void testMap()
{
	//multimap: ����keyֵ�ظ�
	multimap<int, int> m;
	//map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(1, 2));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(1, 3));
	//��������key��������ı���
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
	//multiset: ���Դ���ظ�������
	multiset<int> m;
	m.insert(1);
	m.insert(2);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	m.insert(1);
	//��������
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