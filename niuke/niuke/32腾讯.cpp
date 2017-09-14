#include <iostream>
#include <cmath>


using namespace std;
int process(int i, int k, int aim);
int solve(int aim)
{
	if (aim <= 1)
		return 1;
	int k = log2(aim);

	return process(0, k, aim);
}

int process(int i, int k, int aim)
{
	if (aim < 0) return -65535;
	if (aim == 0)
		return 1;

	if (i == k)
	{
		if (aim == pow(2, k) || aim == pow(2, k) * 2)
		{
			return 1;
		}
		else return -65535;
	}

	int res1 = process(i + 1, k, aim - pow(2, i));
	res1 = res1 < 0 ? 0 : res1;
	int res2 = process(i + 1, k, aim - pow(2, i) * 2);
	res2 = res2 < 0 ? 0 : res2;
	int res3 = process(i + 1, k, aim);
	res3 = res3 < 0 ? 0 : res3;

	return  res1 + res2+ res3;

}

int main_32() {
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}