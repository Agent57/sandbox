#pragma once

#include <memory>

class IObjectWrapper
{
public:
  virtual ~IObjectWrapper() {}
  virtual void Accept(const IVisitorPtr& visitor) const = 0;
};
typedef std::shared_ptr<IObjectWrapper> IObjectWrapperPtr;