#pragma once

#include "CppUnitTest.h"
#include "ITestObjectVisitor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class TestObjectNumberVisitor : public ITestOjectVisitor
{
public:
  void Visit(const TestObject& object)
  {
    Assert::AreEqual(1234, object.number);
    Assert::IsTrue("" == object.text);
  }

  static const IVisitorPtr Create()
  {
    return std::make_shared<TestObjectNumberVisitor>();
  }
};

class TestObjectTextVisitor : public ITestOjectVisitor
{
public:
  void Visit(const TestObject& object)
  {
    Assert::AreEqual(0, object.number);
    Assert::IsTrue("Hello World" == object.text);
  }

  static const IVisitorPtr Create()
  {
    return std::make_shared<TestObjectTextVisitor>();
  }
};