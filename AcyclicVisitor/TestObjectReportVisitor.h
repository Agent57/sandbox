#pragma once

#include "CppUnitTest.h"
#include "ITestObjectVisitor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class TestObjectReportVisitor : public ITestOjectVisitor
{
public:
  void Visit(const TestObject& object)
  {
    Assert::AreEqual(1234, object.number);
    Assert::IsTrue("Hello World" == object.text);
  }

  static const IVisitorPtr Create()
  {
    return std::make_shared<TestObjectReportVisitor>();
  }
};