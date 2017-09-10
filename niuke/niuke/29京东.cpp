#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long NUM_29(long long num) {
	long long result;
	long long num1,num2;
	long long temp = sqrt(num * 2);
	num1 = (temp + 1)*temp / 2;
	num2 = (temp + 1)*(temp + 2) / 2;

	if (num<=num1)
	{
		result = temp;
	}
	else if (num <= num2)
	{
		result = temp + 1;
	}
	else
		result = temp + 2;
	return result;
}

int main_29() {

	long long num;
	cin >> num;
	long long result = NUM_29(num);
	cout << result << endl;
	return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//void fun(int num,vector<int>& vec) {
//	while (num>0)
//	{
//		int temp;
//		temp = num % 10;
//		vec.push_back(temp);
//		num = num / 10;
//	}
//	//for (int i = 0; i < vec.size();++i)
//	//{
//	//	cout << vec[i] << " ";
//	//}
//	//cout << endl;
//}
//bool Is_Magical_num(vector<int>& vec) {
//	int length = vec.size();
//	int sum1=0, sum2=0;
//	for (int i = 0; i < vec.size()-1;++i)
//	{
//		sum1 += vec[i];
//		for (int j = i + 1; j < vec.size();++j)
//		{
//			sum2 += vec[j];
//		}
//		if (sum1==sum2)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//int main() {
//	int num1, num2;
//	cin >> num1 >> num2;
//	
//	int result = 0;
//	for (int i = num1; i < num2;++i)
//	{
//		vector<int> vec;
//		fun(i, vec);
//		sort(vec.begin(), vec.end()); 
//
//		if (Is_Magical_num(vec))
//		{
//			result++;
//		}
//	}
//	
//	cout << result << endl;
//	return 0;
//}