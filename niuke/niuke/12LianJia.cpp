#include<iostream>
#include<set>

using namespace std;

int main_12() {
	int n;
	cin >> n;
	set<int> resutl_1_lianjia;
	while (n>0)
	{
		int temp;
		cin >> temp;
		resutl_1_lianjia.insert(temp);
		n--;
	}
	cout << resutl_1_lianjia.size() << endl;
	for (auto it = resutl_1_lianjia.begin(); it != resutl_1_lianjia.end();++it)
	{
		cout << *it << " ";
	}
	return 0;
}

/* 链家网内推笔试 2017.8.19 第二题*/
//#include<iostream>
//#include<vector>
//#include "12LianJia.h"
//
//using namespace std;
//
//int main() {
//	int n;
//	vector<int> vec1_lianjia;
//	cin >> n;
//	while (n>0)
//	{
//		int temp;
//		cin >> temp;
//		vec1_lianjia.push_back(temp);
//		n--;
//	}
//	int q;
//	vector<int> vec2_lianjia;
//	cin >> q;
//	while (q > 0)
//	{
//		int temp;
//		cin >> temp;
//		vec2_lianjia.push_back(temp);
//		q--;
//	}
//	for (int i = 1; i < vec1_lianjia.size();++i)
//	{
//		vec1_lianjia[i] = vec1_lianjia[i] + vec1_lianjia[i - 1];
//	}
//	vector<int> result_lianjia;
//	for (int i = 0; i < vec2_lianjia.size();++i)
//	{
//		if (vec2_lianjia[i]<=vec1_lianjia[0])
//		{
//			result_lianjia.push_back(1);
//		}
//		for (int j = 1; j < vec1_lianjia.size();++j)
//		{
//			if (vec2_lianjia[i]>vec1_lianjia[j-1]&&vec2_lianjia[i]<=vec1_lianjia[j])
//			{
//				result_lianjia.push_back(j + 1);
//			}
//		}
//	}
//	for (int i = 0; i < result_lianjia.size();++i)
//	{
//		cout << result_lianjia[i] << endl;
//	}
//	return 0;
//}