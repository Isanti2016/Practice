/*
用最少的硬币数构建一定数额
如用1，3，5元的硬币，怎么才能用最少的数量得到11元
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main_26_1() {
	int sum;
	while (cin >> sum) {
		int a[] = { 1,3,5 };

		int *dp = new int[sum + 1];
		for (int i = 0; i < sum + 1; ++i)
		{
			dp[i] = 0x7fffffff;
		}
		dp[0] = 0;
		for (int i = 0; i <= sum; ++i)
		{
			for (int j = 0; j < 3; ++j)//通过dp[i - a[j]]体现与前i的关系
			{
				//if (i >= a[j] && dp[i - a[j]] + 1 < dp[i])//一方面限制i-a[j]的范围，一方面找到最新的值,那个1代表一个a[j]
				//{
				//	dp[i] = dp[i - a[j]] + 1;
				//}
				if (i>=a[j])
				{
					dp[i] = min(dp[i], dp[i - a[j]] + 1);
				}
			}
		}
		cout << dp[sum] << endl;
	}
	return 0;
}
/*
数塔的路径中和的值最大
输入
5   //层数
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
输出：
30    //路径中和的最大值是30
*/
int main_26_2() {
	int a[200][200];
	int n;
	while (cin>>n) {
		for (int i = 0; i < n;++i)
		{
			for (int j = 0; j <= i;++j)
			{
				int temp;
				cin >> temp;
				a[i][j] = temp;
			}
		}
		for (int i = n-1; i > 0; --i)
		{
			for (int j = 0; j <= i;++j)
			{
				a[i-1][j] = a[i-1][j] + max(a[i][j],a[i][j+1]);
			}
		}
		cout << a[0][0] << endl;
	}
	return 0;
}
/*
最长非下降子序列的长度
5 3 4 8 6 7   例如3 4 6 7长度为4
输入：
5
5 3 4 8 6 7
输出
4    //最长的非下降子序列长度为4
*/
int No_drop_Sque26(vector<int> vec) {

	vector<int> dp(vec.size());//dp为动态规划中，存储的中间过程中最长子序列长度

	for (int i = 0; i < vec.size();++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i;++j)//通过j体现与前n项关系
		{	
			if (vec[j]<=vec[i])//在此条件下,查找max(1,dp[0]+1,dp[1]+1，dp[2]+1......dp[j]+1)的最大值，并赋值给dp[i]
			{
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	return dp[vec.size() - 1];
}
int main_26_3() {
	int n;
	cin >> n;
	vector<int> vec;
	while (n>0)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
		n--;
	}
	int result = No_drop_Sque26(vec);
	cout << result << endl;
	return 0;
}

/*
走n阶台阶的问题，一次可以走1，2，走n个台阶有多少种走法？

*/

//方法一递归
//int Steps_26(int n) {
//	vector<int> vec(n);
//	if (n == 1 || n == 2)
//		return n;
//	return Steps_26(n-1)+Steps_26(n-2);
//}
//方法二动态规划
int Steps_26(int n) {
	if (n == 1 || n == 2)
		return n;
	vector<int> dp(n);//放在此处较好
	if (n > 2) {	
		dp[0] = 1, dp[1] = 2;
		for (int i = 2; i < n;++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[n - 1];
}
int main_26_4() {
	int n;
	while (cin >> n) {
		int result = Steps_26(n);
		cout << result << endl;
		
	}
	return 0;
}
/*
矩阵向下或向右走，到右下角的路径最小值
输入：
4 4
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
输出：
12
*/
int Min_Path_Sum_26(vector<vector<int>>& vec) {//如果要求路径只能对每个点的最小路径进行标记，在倒序寻找路径

	for (int i = 1; i < vec.size(); ++i)
		vec[i][0] = vec[i - 1][0] + vec[i][0];
	for (int i = 1; i < vec[0].size(); ++i)//上边和左边的求值，直接累加
		vec[0][i] = vec[0][i-1] + vec[0][i];

	for (int i = 1; i < vec.size();++i)
	{
		for (int j = 1; j < vec[1].size();++j)
		{
			vec[i][j] = min(vec[i - 1][j], vec[i][j - 1]) + vec[i][j];
		}
	}
	return vec[vec.size()-1][vec[0].size()-1];

}
int main_26_5() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n);
	for (int i = 0; i < n;++i)
	{
		for (int j = 0; j < m;++j)
		{
			int temp;
			cin >> temp;
			vec[i].push_back(temp);
		}
	}
	int result = Min_Path_Sum_26(vec);
	cout << result << endl;
	return 0;
}

/*
背包问题：背包额定重量weight，有N件物品，每件一个，每件物品价值为Vi,重量为Wi，使物品价值最大，且不能超过背包重量

*/
int BackPack_Problem_26(int weight, vector<int> vec_v, vector<int> vec_w) {
	int N = vec_v.size();
	vector<vector<int>> dp(N+1,vector<int>(weight+1,0));//使用vector申请的二维数组

	for (int i = 1; i < N + 1;++i)//i控制可用的物品(有顺序的)的数量
	{
		for (int j = 1; j < weight + 1;++j)//j控制背包额定重量的变换，用于求出每个额定状态的最优
		{
			if (j >= vec_w[i - 1])//子结构最优体现在j-vec_w[i-1]的值是简单的
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec_w[i - 1]] + vec_v[i - 1]);//一方面不使用vec_w[i-1]则价值是dp[i - 1][j]，即原有价值
			}																			//另一方面使用时的价值是dp[i - 1][j - vec_w[i - 1]] + vec_v[i - 1]
			else
				dp[i][j] = dp[i - 1][j];
		}
				
	}
	//for (int i = 0; i < N + 1;++i)
	//{
	//	for (int j = 0; j < weight + 1;++j)
	//	{
	//		cout << dp[i][j] << "\t";
	//	}
	//	cout << endl;
	//}
	return dp[N][weight];
}
/*
完全背包问题：背包额定重量weight，有N件物品，每件无限个，每件物品价值为Vi,重量为Wi，使物品价值最大，且不能超过背包重量
*/
int BackPack_Problem__Infinite_26(int weight, vector<int> vec_v, vector<int> vec_w) {

	vector<int> vec(weight + 1);
	vec[0] = 0;
	for (int i = 1; i < weight + 1; ++i)
	{
		vec[i] = 0;
		for (int j = 1; j < vec_w.size(); j++)
		{
			if (i >= vec_w[j])
			{
				vec[i] = max(vec[i], vec[i - vec_w[j]] + vec_v[j]);
			}
		}
	}

	return vec[weight];
}
int main_26_6() {
	int weight, N;
	cin >> weight>>N;
	vector<int> vec_v;
	vector<int> vec_w;
	for (int i = 0; i <N; i++)
	{
		int temp;
		cin >> temp;
		vec_v.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vec_w.push_back(temp);
	}
	int result = BackPack_Problem_26(weight, vec_v, vec_w);//背包问题
	//int result = BackPack_Problem__Infinite_26(weight, vec_v, vec_w);//完全背包问题(每个物品无限个)，即硬币问题
	cout << result << endl;
	return 0;
}

/*
将字符串str1变为str2的代价最小，插入ic=5,删除dc=3,替换rc=2，如str1="abc" str2="adc" 则代价最低为2
输入：
abc adc    //从abc变为adc
5 3 2
输出：
2
*/
int Cost_Transform_26(string str1,string str2,vector<int> cost) {//cost[0]插入，cost[1]删除，cost[2]替换的代价
	int length1 = str1.size();
	int length2 = str2.size();
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));//vector二维数组
	for (int i = 0; i < length1 + 1;++i)//初始化边缘
	{
		dp[i][0] = i*cost[1];
	}
	for (int i = 0; i < length2 + 1;++i)
	{
		dp[0][i] = i*cost[0];
	}
	for (int i = 0; i < length1;++i)
	{
		for (int j = 0; j < length2;++j)
		{
			int temp = min(dp[i][j+1] + cost[1], dp[i+1][j] + cost[0]);
			if (str1[i] == str2[j])
			{
				dp[i+1][j+1] = min(dp[i][j], temp);
			}
			else
				dp[i+1][j+1] = min(dp[i][j]+cost[2],temp);
		}
	}

	for (int i = 0; i < length1 + 1; ++i)
	{
		for (int j = 0; j < length2 + 1; ++j)
		{
			cout << dp[i][j] << "\t";
		}
		cout << endl;
	}

	return dp[length1][length2];
}
int main_26_7() {
	string str1, str2;
	cin >> str1 >> str2;
	vector<int> cost;
	int n = 3;
	while (n>0)
	{
		int temp;
		cin >> temp;
		cost.push_back(temp);
		n--;
	}
	int result = Cost_Transform_26(str1, str2, cost);
	cout << result << endl;

}

