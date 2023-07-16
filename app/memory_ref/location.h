#pragma once

#include <iostream>
#include <sstream>
#include <string>

struct Location {
  std::string file_;
  int line_;
  std::string func_;

  Location(const char *file, int line, const char *func) : file_(file), line_(line), func_(func) {}

  friend
  std::ostream &operator<<(std::ostream &os, const Location &loc) {
    os << "[" << loc.file_ << ":" << loc.line_ << " " << loc.func_ << "]";
    return os;
  }

  friend
  std::stringstream &operator<<(std::stringstream &os, const Location &loc) {
    os << "[" << loc.file_ << ":" << loc.line_ << " " << loc.func_ << "]";
    return os;
  }

  std::string ToString() const {
    std::stringstream os;
    os << *this;
    return std::move(os.str());
  }
};

#define HERE Location(__FILE__, __LINE__, __FUNCTION__)