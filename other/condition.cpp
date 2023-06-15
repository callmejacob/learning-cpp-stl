#include "condition.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

static std::mutex mtx;
static std::condition_variable cv;
static bool ready = false;

static void ThreadPrint(int i) {
  std::unique_lock<std::mutex> locker(mtx);
  while (!ready) {
    std::cout << "[condition] thread wait " << i << std::endl;
    cv.wait(locker);
  }
  std::cout << "[condition] thread print " << i << std::endl;
}

static void Run() {
  std::unique_lock<std::mutex> locker(mtx);
  ready = true;
  cv.notify_all();
}

void TestCondition() {
  static const int THREAD_NUM = 10;
  std::thread threads[THREAD_NUM];
  for (auto i = 0; i < THREAD_NUM; i++) {
    threads[i] = std::thread(ThreadPrint, i);
  }

  Run();

  for (auto i = 0; i < THREAD_NUM; i++) {
    threads[i].join();
  }

  return;
}
