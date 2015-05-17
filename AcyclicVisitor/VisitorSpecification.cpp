#include "CppUnitTest.h"
#include "TestObjectReportVisitor.h"
#include "TestObjectWrapper.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Specification
{		
	TEST_CLASS(VisitorSpecification)
	{
	public:
    TEST_METHOD(Using_an_invalid_visitor_throws_a_bad_cast_exception)
    {
      TestObject testObject;
      IObjectWrapperPtr wrapper = TestObjectWrapper::Create(testObject);

      try
      {
        AcceptTestVisitor(wrapper, NULL);
      }
      catch (std::bad_cast&)
      {
        return;
      }
      catch (...) {}

      Assert::Fail(L"Bad cast expected");
    }

    TEST_METHOD(A_TestObjectNumberVisitor_validates_the_number_field)
    {
      TestObject testObject;
      testObject.number = 1234;
      IObjectWrapperPtr wrapper = TestObjectWrapper::Create(testObject);
      
      AcceptTestVisitor(wrapper, TestObjectNumberVisitor::Create());
    }

    TEST_METHOD(A_TestObjectTextVisitor_validates_the_text_field)
    {
      TestObject testObject;
      testObject.text = "Hello World";
      IObjectWrapperPtr wrapper = TestObjectWrapper::Create(testObject);

      AcceptTestVisitor(wrapper, TestObjectTextVisitor::Create());
    }

    void AcceptTestVisitor(const IObjectWrapperPtr& wrapper, const IVisitorPtr& visitor)
    {
      wrapper->Accept(visitor);
    }
  };
}
