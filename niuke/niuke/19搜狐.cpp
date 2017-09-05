/*搜狐编程第一题   Kolakoski算法
输入:其中16代表要输出个数，4代表输入数字个数，2 1 3 1为输入数字
16 4
2 1 3 1
输出：
2 2 1 1 3 1 2 2 2 1 3 3 1 1 2 2 

输入：
10 2
1 2
1 2 2 1 1 2 1 2 2 1
*/
//#include <iostream>
//#include <vector>
//using namespace std;
///*
//用于循环输出vector的值；
//*/
//int Loop(vector<int> vec,int index) {
//	int result;
//	int length = vec.size();
//	result = index%length;
//
//	return vec[result];
//}
///*
//Kolakoski算法
//*/
//void Kolakoski(int n,vector<int> vec)
//{
//	int index = 0;
//	int count = 0;
//	vector<int> result;
//	result.push_back(vec[0]);
//
//	while (result.size() < n) {
//		if (index == 0) {//因为一个数字首先压入有值，所以输入要减少一个
//			for (int i = 0; i < result[index] - 1;++i)
//			{
//				int temp = Loop(vec, index);
//				result.push_back(temp);
//			}
//		}
//		else {
//			if (result.size()-1<index)//当前序列不够时，要及时补充
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
//		++index;//下一个要输入个数的数组索引，和loop循环的索引
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

