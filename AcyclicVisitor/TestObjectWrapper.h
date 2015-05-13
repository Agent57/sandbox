#pragma once

#include <stdexcept>

#include "IObjectWrapper.h"
#include "ITestObjectVisitor.h"

class TestObjectWrapper : public IObjectWrapper
{
  TestObject m_object;

public:
  typedef std::shared_ptr<TestObjectWrapper> TestObjectWrapperPtr;

  TestObjectWrapper(const TestObject& object) : m_object(object) {}

  virtual void Accept(const IVisitorPtr& visitor) const
  {
    auto accepted = std::dynamic_pointer_cast<ITestOjectVisitor>(visitor);
    if (!accepted)
      throw std::bad_cast();

    accepted->Visit(m_object);
  }

  static const IObjectWrapperPtr Create(const TestObject& object)
  {
    return std::make_shared<TestObjectWrapper>(object);
  }
};
