#include "base_object.h"

#include <mutex>
#include <set>
#include <sstream>
#include <vector>

static std::set<BaseObject *> s_memory_record;
static std::mutex s_mtx;

BaseObject::BaseObject(const std::string &loc_info) : loc_info_(loc_info) {
  std::unique_lock<std::mutex> lk(s_mtx);
  s_memory_record.insert(this);
}

BaseObject::~BaseObject() {
  std::unique_lock<std::mutex> lk(s_mtx);
  s_memory_record.erase(this);
}

int BaseObject::ObjectSize() {
  return sizeof(BaseObject);
}

const std::string BaseObject::GetInfo() {
  std::stringstream os;
  os << loc_info_ << " size:" << ObjectSize();
  return os.str();
}

std::string BaseObject::TotalAvailableInfo() {
  std::vector<std::string> vec;

  // copy locations
  {
    std::unique_lock<std::mutex> lk(s_mtx);
    for (auto &item: s_memory_record) {
      vec.push_back(item->GetInfo());
    }
  }

  std::stringstream buffer;
  for (auto &info: vec) {
    buffer << info << "\n";
  }
  return buffer.str();
}