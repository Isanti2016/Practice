#include <iostream>
#include <string>
using namespace std;
/*
只有"AABB"和"BBAA"满足最多只有一对不同颜色的相邻砖块，所有的砖块排成一行
输入：ABAB
输出：2
*/
//int main() {
//	string str;
//	cin >> str;
//	int a[26];
//	for (int i = 0; i < 26; ++i)
//		a[i] = 0;
//	int length = str.size();
//	for (int i = 0; i < length; ++i) {
//		a[str[i] - 'A']++;
//	}
//	int count = 0;
//	for (int i = 0; i < 26; ++i) {
//		if (a[i] > 0)
//			++count;
//	}
//
//	int result = (count > 2) ? 0 : count;
//	cout << result << endl;
//	return 0;
//}

/*
判断是否为等差数列，此处仅仅排完序了
*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	int length;
//	vector<int> array;
//	cin >> length;
//	while (length > 0) {
//		int count;
//		cin >> count;
//		array.push_back(count);
//		length--;
//	}
//	sort(array.begin(),array.end());
//	for (int i = 0; i < array.size();++i)
//	{
//		cout << array[i] << " ";
//	}
//	cout << endl;;
//	return 0;
//}

/*
输入一次，逆序依次
应给使用deque，奇数此从插入，偶数从前插入，从零开始
如
输入
4
1 2 3 4
输出
4 2 1 3
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main_9() {
	int length;
	cin >> length;
	vector<int> Array;
	while (length > 0) {
		int temp;
		cin >> temp;
		Array.push_back(temp);
		--length;
	}
	deque<int> dq;
	for (int i = 0; i < Array.size(); ++i) {
		if ((i & 1) == 0) {
			dq.push_back(Array[i]);
		}
		else {
			dq.push_front(Array[i]);
		}
	}
	for (int i = 0; i < dq.size() - 1; ++i)
		cout << dq[i] << " ";
	cout << dq[dq.size() - 1] << endl;




	return 0;
}