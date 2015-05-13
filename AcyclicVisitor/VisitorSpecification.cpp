#include <stdexcept>

#include "CppUnitTest.h"
#include "TestObjectReportVisitor.h"
#include "TestObjectWrapper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Specification
{		
	TEST_CLASS(VisitorSpecification)
	{
	public:
		
    TEST_METHOD(TestMethod1)
    {
      TestObject testObject;
      testObject.number = 1234;
      testObject.text = "Hello World";

      auto wrapper = TestObjectWrapper::Create(testObject);

      try
      {
        wrapper->Accept(NULL);
      }
      catch (std::bad_cast& exception)
      {
        return;
      }

      Assert::Fail(L"Bad cast expected");
    }

    TEST_METHOD(TestMethod2)
    {
      TestObject testObject;
      testObject.number = 1234;
      testObject.text = "Hello World";

      auto wrapper = TestObjectWrapper::Create(testObject);
      auto visitor = TestObjectReportVisitor::Create();

      try
      {
        wrapper->Accept(visitor);
      }
      catch (std::bad_cast& exception)
      {
        Assert::Fail(L"Bad cast exception");
      }
    }

  };
}
