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
	
	size_t size() const { return size; }
	T& insert(const pair<Key,T>&);
	void erase(const pair<Key,T>&);
	bool find(const pair<Key,T>&);
private:
	size_t cnt_size;
	vector< list<pair<Key,T> > > hashes;
};
