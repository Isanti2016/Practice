#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


double MAX_DIS_27(vector<double> vec) {
	double result = 0.0;
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		for (int j = i + 1; j < vec.size(); j++)
		{
			double temp = vec[j] - vec[i];
			if (temp <= 180.00)
			{
				result = max(result, temp);
			}
			else
			{
				temp = 180.00 - (temp - 180.00);
				result = max(result, temp);
			}
		}
	}
	return result;
}

int main_27() {

	int n;
	cin >> n;
	vector<double> vec;
	while (n>0)
	{
		double temp;
		cin >> temp;
		vec.push_back(temp);
		n--;
	}
	double result = MAX_DIS_27(vec);
	cout <<fixed<< setprecision(8) << result << endl;

	return 0;
}