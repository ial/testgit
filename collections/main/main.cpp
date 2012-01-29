// hash_map.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>

#include <hash_map.h>

using namespace std;

typedef unsigned int uint;
typedef pair<string,int> pii;


int main(int argc[], char *argv[])
{
	
	hash_map<string,int> a;
	a.insert(pii("123",32));
	a.insert(pii("324",323));
	a.insert(pii("324324",4334));
	if (a.find(pii("123",32))) cout << "1" << endl;
	if (a.find(pii("32",3222))) cout << "2" << endl;
	if (a.find(pii("324",323))) cout << "3" << endl;
	a.erase(pii("324",323));
	if (a.find(pii("324",323))) cout << "3" << endl;
	
	cout << "Well" << a.size() << endl;
	return 0;
}
	