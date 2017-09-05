/*
第K大的数，要注意从后向前数才是第K大的数
*/
//#include<iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int Partition_di(vector<int>&a, int low, int high) {
//	int key = a[low];
//	while (low < high) {
//		while (low < high&&a[high] >= key)
//			--high;
//		a[low] = a[high];
//		while (low < high&&a[low] <= key)
//			++low;
//		a[high] = a[low];
//	}
//	a[low] = key;
//	return low;
//}
//int Num_K_didi(vector<int>& a, int low, int high, int index) {
//	int result;
//	int key = Partition_di(a, low, high);
//	while (index != key)
//	{
//		if (index > key)
//		{
//			low = key + 1;
//			key = Partition_di(a, low, high);
//		}
//		else {
//			high = key - 1;
//			key = Partition_di(a, low, high);
//		}
//	}
//
//	return a[key];
//}
//
//int main() {
//	vector<int> vec;
//	char ch;
//	do
//	{
//		int temp;
//		scanf("%d", &temp);
//		vec.push_back(temp);
//	} while ((ch = getchar()) != '\n');
//
//	int length = vec.size();
//
//	int index;
//	cin >> index;
//
//	int result;
//
//	result = Num_K_didi(vec, 0, length - 1, length - index);
//	cout << result << endl;
//	return 0;
//}



