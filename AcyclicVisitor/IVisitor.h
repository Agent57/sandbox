#pragma once

#include <memory>

class IVisitor
{
public:
  virtual ~IVisitor() {}
};
typedef std::shared_ptr<IVisitor> IVisitorPtr;