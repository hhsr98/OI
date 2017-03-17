#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;
int main()
{
	int n;
	string s1;
	freopen("in.text","r",stdin);
	while(cin>>n) cout<<n;
	cout<<clock()/CLOCKS_PER_SEC;
	fclose(stdin);
	freopen("in.text","r",stdin);
	cin>>s1;
	stringstream ss(s1);
	while(ss>>n);
	cout<<clock()/CLOCKS_PER_SEC;
	system("pause");
	return 0;
}
	
