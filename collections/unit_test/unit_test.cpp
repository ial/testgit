#include <hash_map.h>

#include <gtest/gtest.h>

typedef unsigned int uint;
typedef pair<string,int> pii;


int main(int argc[], char *argv[])
{
	
	hash_map<string,int> a;
	a.insert(pii("123",32));
	a.insert(pii("324",323));
	a.insert(pii("324324",4334));

  ASSERT_EQ(3, a.size());

	ASSERT_TRUE(a.find(pii("123",32)));
	ASSERT_FALSE(a.find(pii("32",3222)));
	ASSERT_TRUE(a.find(pii("324",323)));

	a.erase(pii("324",323));
	ASSERT_FALSE(a.find(pii("324",323)));

	a.insert(pii("123",123456732));             
	ASSERT_FALSE(a.find(pii("123",32)));
	ASSERT_TRUE(a.find(pii("123",123456732)));
	a.insert(pii("1234",123456732));
	ASSERT_TRUE(a.find(pii("123",123456732)));
	ASSERT_TRUE(a.find(pii("1234",123456732)));
	a.erase(pii("123",123456732));
	ASSERT_FALSE(a.find(pii("123",123456732)));
	ASSERT_TRUE(a.find(pii("1234",123456732)));

	a.erase(pii("324",323));

  string s = "";
  for (int i = 0; i < 10000; i += 10)
  {
    a.insert(pii(s, i));
    ASSERT_TRUE(a.find(pii(s, i)));
    s += "s";
  }

}