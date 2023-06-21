
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Meeting {
  Meeting(char **argv) : title_(argv[0]), date_(argv[1]), start_(::atoi(argv[2])), end_(::atoi(argv[3])) {}
  Meeting(string title, string date, string start, string end) {
    title_ = title;
    date_ = date;
    start_ = ::atoi(start.c_str());
    end_= ::atoi(end.c_str());
  }

  string title_;
  string date_;
  int start_;
  int end_;

  Meeting &operator=(const Meeting &other) {
    this->title_ = other.title_;
    this->date_ = other.date_;
    this->start_ = other.start_;
    this->end_ = other.end_;
    return *this;
  }

  bool operator==(const Meeting &other) const {
    return title_ == other.title_ &&
           date_ == other.date_;
  }

  bool operator<(const Meeting &other) const {
    return start_ <= other.start_;
  }
};

ostream &operator<<(ostream &os, const Meeting &m) {
  os << m.title_ << "," << m.date_ << "," << m.start_ << "," << m.end_;
  return os;
}

template<typename T>
class ArgvIterator : public iterator<forward_iterator_tag, T> {
public:
  ArgvIterator() {}

  ArgvIterator(int argc, char **argv, int inc) : argc_(argc), argv_(argv), base_argv_(argv), inc_(inc) {}

  T begin() { return *this; }

  T end() { return *this; }

  T operator*() { return T(argv_); }

  bool operator!=(const ArgvIterator &) { return argv_ != base_argv_ + argc_; }

  void operator++() { argv_ += inc_; }

private:
  int argc_;
  char **argv_;
  char **base_argv_;
  int inc_;
};

struct Conflict {
  Conflict(ostream &os) : os_(os) {}

  const Meeting &operator()(const Meeting &left, const Meeting &right) {
    if (left == right) {
      os_ << "conflict:" << "[" << left << ", " << right << "]" << endl;
    }
    return left;
  }

  ostream &os_;
};

static constexpr const char *const SRC_PARAMS = "CS101 W 1730 2030 CS242 T 1000 1130 CS242 T 1230 1430 CS242 R 1000 1130 CS281 T 1300 1430 CS281 R 1300 1430 CS282 M 1300 1430 CS282 W 1300 1430 CS201 T 1600 1730 CS201 R 1600 1730";

int main(int argc, char **argv) {
  cout << "[meeting] main begin." << endl;

  stringstream ss(SRC_PARAMS);
  vector<string> argv_vec;
  copy(istream_iterator<string>(ss),
       istream_iterator<string>(),
       back_inserter(argv_vec));

//  copy(&argv[1], &argv[argc], ostream_iterator<char *>(cout, ","));
//  cout << endl;

  vector<Meeting> v;
  for (auto i = 0; i < argv_vec.size(); i += 4) {
    v.push_back(Meeting(argv_vec[i+0],argv_vec[i+1],argv_vec[i+2],argv_vec[i+3]));
  }

//  copy(ArgvIterator<Meeting>(argc - 1, argv + 1, 4),
//       ArgvIterator<Meeting>(),
//       back_inserter(v));

  sort(v.begin(), v.end(), less<Meeting>());

  transform(v.begin(), v.end() - 1, v.begin() + 1, v.begin(), Conflict(cout));

  copy(v.begin(), v.end(), ostream_iterator<Meeting>(cout, "\n"));

  cout << "[meeting] main end." << endl;
  return 0;
}