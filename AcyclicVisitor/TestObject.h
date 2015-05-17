#pragma once

#include <string>

class TestObject
{
public:
  int number;
  std::string text;

  TestObject()
    : number(0)
    , text("")
  {
  }
};