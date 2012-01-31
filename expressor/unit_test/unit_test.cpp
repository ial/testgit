#include <expressor.h>

#include <gtest/gtest.h>

int main(int argc[], char *argv[])
{
  EXPECT_EQ(1, CalcVar("1=x", 'x'));
  EXPECT_EQ(1, CalcVar("x=1", 'x'));
  //EXPECT_EQ(2, CalcVar("x=1+1", 'x'));
  //EXPECT_EQ(2, CalcVar("1+1=x", 'x'));
  //EXPECT_EQ(2, CalcVar("1=x-1", 'x'));
  //EXPECT_EQ(2, CalcVar("x-1=1", 'x'));
}