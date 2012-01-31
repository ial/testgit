#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

typedef unsigned long long ull;

const size_t N = 30011; //  max size for vector (prime number)


template <class Key, class Val>
class hash_map {
public:

	hash_map();
	hash_map(const hash_map&);
	
	hash_map& operator=(const hash_map&);
	
	size_t size() const { return sz; }
	Val get_value(const Key&);
	void set_value(const Key&, const Val&);
	void erase(const Key&);
	bool find(const Key&);
private:
	size_t sz;
	vector< list<pair<Key,Val> > > hashes;
};

size_t hash_value(const string& str, int m)
{	// hash range of string elements
	ull val = 0;
	const int stride1 = 13, stride2 = 17;	// primes for hash
	for (string::const_iterator i = str.begin(); i != str.end(); ++i)
		val = (val + stride1 + (stride2 * (*i - '0'))) % m;

	return (size_t)val;
}

template <class Key, class Val> typename
list<pair<Key,Val> >::iterator find_key(list<pair<Key,Val> >& arr, const Key& key)
{
	auto i = arr.begin();
	for (; i != arr.end(); ++i) if ((*i).first == key) break;
	return i;
}

size_t hash_value(int val, int m)
{
	// hash range of int element
	return val % m;
}


// hash_map
template <class Key, class Val>
hash_map<Key,Val>::hash_map()					// default constructor
	:hashes(N)	, sz(0)		
{
}

template <class Key, class Val>
hash_map<Key,Val>::hash_map(const hash_map& obj)
{
	hashes = obj.hashes;
}

template <class Key, class Val>
hash_map<Key,Val>& hash_map<Key,Val>::operator=(const hash_map& obj)
{
	if (this != &obj)
		hashes = obj.hashes;
		return (*this);
}


 template <class Key, class Val>
 void hash_map<Key,Val>::erase(const Key& key)
 {
	size_t hs = hash_value(key,hashes.size());
	auto i = find_key(hashes[hs],key);
	if (i != hashes[hs].end()) {
		hashes[hs].erase(i);
		--sz;
	}
 }

 template <class Key, class Val>
 bool hash_map<Key,Val>::find(const Key& key)
 {
	size_t hs = hash_value(key,hashes.size());
	auto i = find_key(hashes[hs],key);
	if (i == hashes[hs].end()) 
		return false;
	return true;
 }

 template <class Key, class Val>
 Val hash_map<Key,Val>::get_value(const Key& key)
 {
	size_t hs = hash_value(key,hashes.size());
	auto i = find_key(hashes[hs],key);
	if (i == hashes[hs].end()) return Val();
	return (*i).second;
 }
 
 template <class Key, class Val>
 void hash_map<Key,Val>::set_value(const Key& key, const Val& val)
 {
	// It is neccessary to add an exception
	size_t hs =  hash_value(key,hashes.size());
	if(find_key(hashes[hs],key) == hashes[hs].end()) 
	{
		sz++;
		hashes[hs].push_back(pair<Key,Val>(key,val));
	}
 }
 