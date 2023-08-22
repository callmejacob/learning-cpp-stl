#include <iostream>
#include "base_object.h"

using namespace std;

class TestSubClass : public DerivedBaseObject<TestSubClass> {
public:
  TestSubClass() : DerivedBaseObject<TestSubClass>(HERE) {}

  virtual ~TestSubClass() {

  }

private:
  std::string good1;
};

class TestBBase {

};

class TestSubB : public TestBBase, public DerivedBaseObject<TestSubB> {
public:
  TestSubB() : DerivedBaseObject<TestSubB>(HERE) {}

  virtual ~TestSubB() {}

private:
  std::string good1;
  std::string good2;

};

std::string GetBBB() {
  return std::string("look");
}

std::string GetBBBWrap() {
  auto r = GetBBB();
  cout << "hi bbb~~~" << endl;
  return r;
}

#define GetBBB() GetBBBWrap()

void modify(std::string *&p) {
  p = new std::string("vvv");
}

class Base {
public:
  Base() {}
  virtual ~Base() {}
};

class Sub : public Base {
public:
  Sub() {}
  ~Sub() override {}
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

  cout << GetBBB() << endl;

  const std::shared_ptr<std::string> vvv = std::make_shared<std::string>("good");
  *vvv = "ee";
  std::cout << *vvv << std::endl;


  std::string *p = new std::string("good");
  modify(p);

  Base *b = new Sub();
  delete b;

  return 0;
}