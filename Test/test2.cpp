#include <algorithm>
#include <string>
#include  <iostream>
using namespace std;
int  main(){
	string str ="aBc";
	string b="";
	transform(str.begin(),str.end(),b,::tolower);
	cout<<b;
}
