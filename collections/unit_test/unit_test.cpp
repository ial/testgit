#include <hash_map.h>
#include <iostream>

#include <gtest/gtest.h>

typedef unsigned int uint;
typedef pair<string,int> pii;


int main(int argc[], char *argv[])
{	
  hash_map<string,int> a;
  a.set_value("xxx", 123);
  EXPECT_EQ(123, a.get_value("xxx"));
  a.set_value("xxx", 124);
  EXPECT_EQ(124, a.get_value("xxx"));
  a.erase("xxx");
  EXPECT_FALSE(a.find("xxx"));
  a.set_value("xxx", 125);
  EXPECT_EQ(125, a.get_value("xxx"));
  EXPECT_EQ(1, a.size());
  
	hash_map<string,int> b;
  b = a;
  EXPECT_EQ(1, b.size());
  a.erase("xxx");
  EXPECT_EQ(1, b.size());
  EXPECT_NO_FATAL_FAILURE(a.erase("xxx"));

	hash_map<string,int> c(b);
  EXPECT_EQ(1, c.size());
  b.erase("xxx");
  EXPECT_EQ(1, c.size());

	hash_map<int,int> ih;
  for (int i=0;i<100000;i++)
  {
    ih.set_value(i, i);
  }
  for (int i=100000-1;i>=0;i--)
  {
    EXPECT_TRUE(ih.find(i));
    ih.erase(i);
    EXPECT_FALSE(ih.find(i));
  }
  EXPECT_EQ(0, ih.size());
  std::cout << "Ok" << std::endl;
  return 0;
}