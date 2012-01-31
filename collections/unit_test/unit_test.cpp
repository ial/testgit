#include <hash_map.h>
#include <iostream>

#include <gtest/gtest.h>

typedef unsigned int uint;
typedef pair<string,int> pii;


int main(int argc[], char *argv[])
{
	
	hash_map<string,int> a;
	a.set_value("123",32);
	a.set_value("324",323);
	a.set_value("324324",4334);

	ASSERT_EQ(3, a.size());

	ASSERT_TRUE(a.find("123"));
	ASSERT_FALSE(a.find("32"));
	ASSERT_TRUE(a.find("324"));

	a.erase("324");
	ASSERT_FALSE(a.find("324"));

	a.set_value("ccc",123456732);           
	//ASSERT_EQ(123456732 == a.get_value("ccc"));
	ASSERT_TRUE(a.find("123"));
	ASSERT_TRUE(a.find("123"));
	a.set_value("1234",123456732);
	ASSERT_TRUE(a.find("123"));
	ASSERT_TRUE(a.find("1234"));
	a.erase("123");
	ASSERT_FALSE(a.find("123"));
	ASSERT_TRUE(a.find("1234"));

	a.erase("324");

  string s = "";
  for (int i = 0; i < 10000; i += 10)
  {
    a.set_value(s, i);
    ASSERT_TRUE(a.find(s));
    s += "s";
  }
  std::cout << "Ok" << std::endl;
  
  return 0;
}