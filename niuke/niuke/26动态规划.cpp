/*
�����ٵ�Ӳ��������һ������
����1��3��5Ԫ��Ӳ�ң���ô���������ٵ������õ�11Ԫ
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
			for (int j = 0; j < 3; ++j)//ͨ��dp[i - a[j]]������ǰi�Ĺ�ϵ
			{
				//if (i >= a[j] && dp[i - a[j]] + 1 < dp[i])//һ��������i-a[j]�ķ�Χ��һ�����ҵ����µ�ֵ,�Ǹ�1����һ��a[j]
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
������·���к͵�ֵ���
����
5   //����
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
�����
30    //·���к͵����ֵ��30
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
����½������еĳ���
5 3 4 8 6 7   ����3 4 6 7����Ϊ4
���룺
5
5 3 4 8 6 7
���
4    //��ķ��½������г���Ϊ4
*/
int No_drop_Sque26(vector<int> vec) {

	vector<int> dp(vec.size());//dpΪ��̬�滮�У��洢���м������������г���

	for (int i = 0; i < vec.size();++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i;++j)//ͨ��j������ǰn���ϵ
		{	
			if (vec[j]<=vec[i])//�ڴ�������,����max(1,dp[0]+1,dp[1]+1��dp[2]+1......dp[j]+1)�����ֵ������ֵ��dp[i]
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
��n��̨�׵����⣬һ�ο�����1��2����n��̨���ж������߷���

*/

//����һ�ݹ�
//int Steps_26(int n) {
//	vector<int> vec(n);
//	if (n == 1 || n == 2)
//		return n;
//	return Steps_26(n-1)+Steps_26(n-2);
//}
//��������̬�滮
int Steps_26(int n) {
	if (n == 1 || n == 2)
		return n;
	vector<int> dp(n);//���ڴ˴��Ϻ�
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
�������»������ߣ������½ǵ�·����Сֵ
���룺
4 4
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
�����
12
*/
int Min_Path_Sum_26(vector<vector<int>>& vec) {//���Ҫ��·��ֻ�ܶ�ÿ�������С·�����б�ǣ��ڵ���Ѱ��·��

	for (int i = 1; i < vec.size(); ++i)
		vec[i][0] = vec[i - 1][0] + vec[i][0];
	for (int i = 1; i < vec[0].size(); ++i)//�ϱߺ���ߵ���ֵ��ֱ���ۼ�
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
�������⣺���������weight����N����Ʒ��ÿ��һ����ÿ����Ʒ��ֵΪVi,����ΪWi��ʹ��Ʒ��ֵ����Ҳ��ܳ�����������

*/
int BackPack_Problem_26(int weight, vector<int> vec_v, vector<int> vec_w) {
	int N = vec_v.size();
	vector<vector<int>> dp(N+1,vector<int>(weight+1,0));//ʹ��vector����Ķ�ά����

	for (int i = 1; i < N + 1;++i)//i���ƿ��õ���Ʒ(��˳���)������
	{
		for (int j = 1; j < weight + 1;++j)//j���Ʊ���������ı任���������ÿ���״̬������
		{
			if (j >= vec_w[i - 1])//�ӽṹ����������j-vec_w[i-1]��ֵ�Ǽ򵥵�
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec_w[i - 1]] + vec_v[i - 1]);//һ���治ʹ��vec_w[i-1]���ֵ��dp[i - 1][j]����ԭ�м�ֵ
			}																			//��һ����ʹ��ʱ�ļ�ֵ��dp[i - 1][j - vec_w[i - 1]] + vec_v[i - 1]
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
��ȫ�������⣺���������weight����N����Ʒ��ÿ�����޸���ÿ����Ʒ��ֵΪVi,����ΪWi��ʹ��Ʒ��ֵ����Ҳ��ܳ�����������
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
	int result = BackPack_Problem_26(weight, vec_v, vec_w);//��������
	//int result = BackPack_Problem__Infinite_26(weight, vec_v, vec_w);//��ȫ��������(ÿ����Ʒ���޸�)����Ӳ������
	cout << result << endl;
	return 0;
}

/*
���ַ���str1��Ϊstr2�Ĵ�����С������ic=5,ɾ��dc=3,�滻rc=2����str1="abc" str2="adc" ��������Ϊ2
���룺
abc adc    //��abc��Ϊadc
5 3 2
�����
2
*/
int Cost_Transform_26(string str1,string str2,vector<int> cost) {//cost[0]���룬cost[1]ɾ����cost[2]�滻�Ĵ���
	int length1 = str1.size();
	int length2 = str2.size();
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));//vector��ά����
	for (int i = 0; i < length1 + 1;++i)//��ʼ����Ե
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

