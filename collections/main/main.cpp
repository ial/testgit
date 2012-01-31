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
	hash_map<string,int> m;
	m.set_value("23",152);
	cout << m.get_value("23") << endl;
	cout << m.get_value("2") << endl;
	cout << m.find("23") << endl;
	m.erase("23");
	cout << m.find("23") << endl;
	cout << m.find("2") << endl;
	cout << m.find("3") << endl;
	
	hash_map<int,string> k;
	k.set_value(12,"Hello");
	k.set_value(24,"World");
	cout << k.get_value(12) << " " << k.get_value(24) << endl;
	cout << k.find(12) << endl;
	cout << k.get_value(2) << endl;
	k.erase(12);
	cout << k.get_value(12) << " " << k.get_value(24) << endl;
	

	return 0;
}
	