#include <map>
#include<iostream>
using namespace std;
int main() {
	multimap<int,string> m;
	m.insert({1,"hello"});
	m.insert({1,"world"});
	m.insert({2,"goodbye"});
	m.insert({3,"spacecows"});

	cout<<"Number of elements in key 1: "<<m.count(1)<<endl;

	auto range = m.equal_range(1);
	for(auto iter = range.first; iter != range.second; iter++) cout<<iter->second<<" ";
	cout<<endl;
	return 0;
}
