#include <iostream>
#include "base_object.h"

using namespace std;

class TestSubClass : public DerivedBaseObject<TestSubClass> {
public:
  TestSubClass() : DerivedBaseObject<TestSubClass>(HERE) {}

  virtual ~TestSubClass() {

  }

private:
  std::string  good1;
};

class TestBBase {

};

class TestSubB : public TestBBase, public DerivedBaseObject<TestSubB> {
public:
  TestSubB() : DerivedBaseObject<TestSubB>(HERE) {}

  virtual ~TestSubB() {}

private:
  std::string  good1;
  std::string  good2;

};

int main(int argc, const char **argv) {
  cout << "hello memory ref." << endl;

  {
    auto test1 = new TestSubClass();
//    delete test1;
  }
  cout << "[cut] " << BaseObject::TotalAvailableInfo() << endl;

  {
    auto test2 = std::make_shared<TestSubB>();
  }
  cout << "[cut] " << BaseObject::TotalAvailableInfo() << endl;

  return 0;
}