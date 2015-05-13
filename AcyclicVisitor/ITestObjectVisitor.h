#pragma once

#include "IVisitor.h"
#include "TestObject.h"

class ITestOjectVisitor : public IVisitor
{
public:
  virtual void Visit(const TestObject& object) = 0;
};