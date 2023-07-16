#pragma once

#include <set>
#include <string>
#include "location.h"

class BaseObject {
public:
  BaseObject(const std::string &loc_info);

  virtual ~BaseObject();

  virtual int ObjectSize() = 0;

  const std::string GetInfo();

private:
  std::string loc_info_;

public:
  static std::string TotalAvailableInfo();
};

template<typename T>
class DerivedBaseObject : public BaseObject {
public:
  DerivedBaseObject(const Location &loc) : BaseObject(loc.ToString()) {}

  virtual ~DerivedBaseObject() {}

  virtual int ObjectSize() { return sizeof(T); }
};