#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>


using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int> result;
	result.clear();
	int length = input.size();
	if (k <= 0 || length == 0 || length < k)
		return result;
	multiset<int, greater<int> > res_set;//��������С��k�����������ظ���,������multiset��greater��<functional>�У�����������ͷ��������ɾ��������
	for (int i = 0; i < length; i++)
	{
		if (i < k)
		{
			res_set.insert(input[i]);
		}
		else
		{
			if (input[i] < (*res_set.begin()))
			{
				res_set.erase(res_set.begin());//���ܲ����������֣�ֻ�ܲ���������ָ�������
				res_set.insert(input[i]);
			}
		}
	}
	result.assign(res_set.begin(), res_set.end());//�������ֵ
	return result;
}
