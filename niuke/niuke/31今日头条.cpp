/*
输入：
5 3 2
3 1 2 3
0
2 1 2
1 2
1 3
输出：

*/
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int Fun_31(vector<vector<int>> vec,int m) {

	set<int> result;
	int length = vec.size();

	for (int i = 0; i < m;i++)//形成循环
	{
		vec.push_back(vec[i]);
	}

	for (int i = 0; i <length; ++i)
	{
		for (int j = 0; j < vec[i].size(); ++j)
		{
			bool flag = true;
			for (int k = 1; k <= m && flag;++k)
			{
				for (int y = 0; y < vec[i+k].size() && flag;++y)
				{
					if (vec[i][j]==vec[i+k][y])
					{
						result.insert(vec[i][j]);
						flag = false;
					}
				}
			}

		}
		
	}
	
	return result.size();
}
int main_31_1() {

	int n, m, c;
	cin >> n>>m>>c;
	vector<vector<int>> vec;
	while (n>0)
	{
		int num1;
		cin >> num1;
		vector<int> vec_c;
		while (num1 > 0)
		{
			int temp;
			cin >> temp;
			vec_c.push_back(temp);
			num1--;
		}
		vec.push_back(vec_c);
		n--;

	}
	int result = Fun_31(vec,m);
	cout << result << endl;
	return 0;
}


void main_31_2()
{
	int a, b;
	cin >> a;

	char ch;


	vector <int>user;
	for (int i = 0; i < a; i++)
	{
		ch= getchar();
		//	if(ch!='\n'&&ch!=' ')//把这句判断条件改动  
		//	{  
		int tem;
		//ungetc(ch,stdin);  
		cin >> tem;
		user.push_back(tem);
	}
	//}  */
	cin >> b;
	vector<int>sur;
	vector<vector<int>>svs;
	for (int j = 0; j < b; j++)
	{
		for (int k = 0; k < 3; k++)
		{       //if(c=getchar()!='\n'){
			int temp;
			cin >> temp;
			sur.push_back(temp);
		}
		svs.push_back(sur);
		sur.clear();
	}
	//for(int iter=0;iter!=svs.size();iter++)
	//{  
	//	for(int k=0;k<3;k++){
	//        //cout<<"遍历"<<svs[iter][k]<<endl;
	//	}
	//}
	vector<int>numb;
	for (int iter = 0; iter != svs.size(); iter++)
	{
		int times = 0;

		for (int m = (svs[iter][0] - 1); m < (svs[iter][1] - 1); m++)
		{

			if (user[m] == svs[iter][2])times++;
		}
		numb.push_back(times);
	}
	for (int n = 0; n < b; n++)
		cout << numb[n] << endl;
}
#include <string>
#include <iostream>

using namespace std;

int mian_31_3() {
	string str;
	cin >> str;
	int hashs[256];
	memset(hashs, 0, 256 * sizeof(int));
	int count1 = 0;
	for (int i = 0; i < str.size();++i)
	{
		if (hashs[str[i]]==0)
		{
			hashs[str[i]] = i;
		}
		else
		{
			count1 += hashs[str[i]] - i;
		}
	}
	return 0;
}

