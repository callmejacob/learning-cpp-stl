#include <iostream>

#include <time.h>
#include <ctime>
#include <future>
#include <unistd.h>

int TestWait() {
  std::shared_ptr<std::promise<int>> promise = std::make_shared<std::promise<int>>();
  std::future<int> future = promise->get_future();
  auto t = new std::thread([promise]() {
    std::cout << "begin thread." << std::endl;
    usleep(600 * 1000);
    std::cout << "end thread." << std::endl;
    promise->set_value(1);
  });
  t->detach();

  bool ret = false;
  std::chrono::milliseconds time(500);
  try {
    if (future.wait_for(time) == std::future_status::ready) {
      ret = true;
    }
  } catch (...) {
  }

  std::cout << "end test." << std::endl;

  return 1;
}

#include <sstream>
#include <bitset>

#include <thread>

class SharedGood {
public:
  SharedGood() {
    vv = std::make_shared<int>();
    *vv = 3;
  }
  virtual ~SharedGood() {
    vv.reset();
  }

public:
  std::shared_ptr<int> vv;
};

void good() {
  for (int i = 0; i < 100; i++) {
    std::shared_ptr<SharedGood> v = std::make_shared<SharedGood>();

    std::thread([v](){
      for (int j = 0; j < 10; j++) {
        std::cout << *(v->vv) << std::endl;
      }
      sleep(1);
    }).detach();

    v.reset();
    sleep(2);
  }
}

class AutoFreeCls {
public:
  AutoFreeCls() {
    std::cout << "AutoFree construct." << std::endl;
  }

  virtual ~AutoFreeCls() {
    std::cout << "AutoFree destruct." << std::endl;
  }
};

void TestAutoFree() {
  auto *p = new AutoFreeCls();
  std::shared_ptr<AutoFreeCls> good(p);
}

int main(int argc, const char **argv) {
//  TestWait();

//  usleep(5000 * 1000);

  int a = 0;
//  std::cout << "good=0x" << std::hex << long(&a) << std::endl;

//  good();

  TestAutoFree();

  return 0;
}