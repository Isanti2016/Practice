#include <iostream>
#include <string>
using namespace std;
/*
ֻ��"AABB"��"BBAA"�������ֻ��һ�Բ�ͬ��ɫ������ש�飬���е�ש���ų�һ��
���룺ABAB
�����2
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
�ж��Ƿ�Ϊ�Ȳ����У��˴�������������
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
����һ�Σ���������
Ӧ��ʹ��deque�������˴Ӳ��룬ż����ǰ���룬���㿪ʼ
��
����
4
1 2 3 4
���
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