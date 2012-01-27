#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

typedef unsigned long long ull;

const size_t sz = 30011; //  max size for vector (prime number)


template <class Key, class T>
class hash_map {
public:

	hash_map();
	hash_map(const hash_map&);
	
	hash_map& operator=(const hash_map&);
//	T& operator[](const Key&);
//	const T& operator[](const Key&);
	
	size_t size() const { return cnt_size; }
	T& insert(const pair<Key,T>&);
	void erase(const pair<Key,T>&);
	bool find(const pair<Key,T>&);
private:
	size_t cnt_size;
	vector< list<pair<Key,T> > > hashes;
};

size_t hash_value(const string& str, int m)
{	// hash range of string elements
	ull val = 0;
	const int stride1 = 13, stride2 = 17;	// primes for hash
	for (string::const_iterator i = str.begin(); i != str.end(); ++i)
		val = (val + stride1 + (stride2 * (*i - '0'))) % m;

	return (size_t)val;
}

size_t hash_value(int val, int m)
{
	// hash range of int element
	return val % m;
}

template <class Key,class T>
T& hash_insert( vector<list<pair<Key,T> > >& arr, const pair<Key,T>& val)
{
	// It is neccessary to add an exception
	size_t hs =  hash_value(val.first,arr.size());
	list<pair<Key,T> >::iterator i = find(arr[hs].begin(),arr[hs].end(),val);		
	if(i == arr[hs].end()) {
		arr[hs].push_back(val);
		i = (--arr[hs].end());
	}
	return (*i).second; 
}

template <class Key,class T>
bool hash_find(vector< list<pair<Key,T> > >& arr,const pair<Key,T>& val)
{
	size_t hs = hash_value(val.first,arr.size());
	if(find(arr[hs].begin(),arr[hs].end(),val) == arr[hs].end()) 
		return false;
	return true;
}

template <class Key, class T>
void hash_erase(vector<list<pair<Key,T> > >& arr,const pair<Key,T>& val )
{
	size_t hs = hash_value(val.first,arr.size());
	list<pair<Key,T> >::iterator i = find(arr[hs].begin(),arr[hs].end(),val);
	if (i != arr[hs].end())
		arr[hs].erase(i);
	
}

// hash_map
template <class Key, class T>
hash_map<Key,T>::hash_map()					// default constructor
	:hashes(sz)	, cnt_size(0)		
{
}

template <class Key, class T>
hash_map<Key,T>::hash_map(const hash_map& obj)
{
	hashes = obj.hashes;
}

template <class Key, class T>
hash_map<Key,T>& hash_map<Key,T>::operator=(const hash_map& obj)
{
	if (this != &obj)
		hashes = obj.hashes;
		return (*this);
}
/*
template <class Key, class T>
T& hash_map<Key,T>::operator[](const Key& key)
{
	// I don't know
} 
*/

 template <class Key, class T>
 void hash_map<Key,T>::erase(const pair<Key,T>& val)
 {
	hash_erase(hashes,val);
 }

 template <class Key, class T>
 bool hash_map<Key,T>::find(const pair<Key,T>& val)
 {
	return hash_find(hashes,val);
 }

 //--
 template <class Key, class T>
 T& hash_map<Key,T>::insert(const pair<Key,T>& val)
 {
	return hash_insert(hashes,val);
 }
 