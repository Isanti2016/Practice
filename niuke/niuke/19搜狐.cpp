/*�Ѻ���̵�һ��   Kolakoski�㷨
����:����16����Ҫ���������4�����������ָ�����2 1 3 1Ϊ��������
16 4
2 1 3 1
�����
2 2 1 1 3 1 2 2 2 1 3 3 1 1 2 2 

���룺
10 2
1 2
1 2 2 1 1 2 1 2 2 1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
///*
//����ѭ�����vector��ֵ��
//*/
//int Loop(vector<int> vec,int index) {
//	int result;
//	int length = vec.size();
//	result = index%length;
//
//	return vec[result];
//}
///*
//Kolakoski�㷨
//*/
//void Kolakoski(int n,vector<int> vec)
//{
//	int index = 0;
//	int count = 0;
//	vector<int> result;
//	result.push_back(vec[0]);
//
//	while (result.size() < n) {
//		if (index == 0) {//��Ϊһ����������ѹ����ֵ����������Ҫ����һ��
//			for (int i = 0; i < result[index] - 1;++i)
//			{
//				int temp = Loop(vec, index);
//				result.push_back(temp);
//			}
//		}
//		else {
//			if (result.size()-1<index)//��ǰ���в���ʱ��Ҫ��ʱ����
//			{
//				int temp = Loop(vec, index);
//				result.push_back(temp);
//				count++;
//				
//			}
//			for (int i = 0; i < result[index]-count; ++i)
//			{
//				int temp = Loop(vec, index);
//				result.push_back(temp);
//			}
//		}
//		count = 0;
//		++index;//��һ��Ҫ���������������������loopѭ��������
//	}
//	for (int i = 0; i < result.size();++i)
//	{
//		cout << result[i] << " ";
//	}
//	cout << endl;
//}
//int main()
//{
//	int n,m;
//	cin >> n;
//	cin >> m;
//  if(m<2)
//     return 0;
//	vector<int> vec;
//	while (m>0)
//	{
//		int temp;
//		cin >> temp;
//		vec.push_back(temp);
//		m--;
//	}
//
//	Kolakoski(n,vec);
//	return 0;
//}

