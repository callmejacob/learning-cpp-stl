#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class MemoryRecord {
public:
  MemoryRecord() {}

  virtual ~MemoryRecord() {}

  MemoryRecord(MemoryRecord &&other) {
    id = move(other.id);
    date = move(other.date);
  }

  MemoryRecord &operator=(const MemoryRecord &&other) {
    id = move(other.id);
    date = move(other.date);
    return *this;
  }

  MemoryRecord(const MemoryRecord &other) = delete;

  MemoryRecord &operator=(const MemoryRecord &other) = delete;

public:
  int id;
  string date;
};

ostream &operator<<(ostream &os, const MemoryRecord &item) {
  os << item.id << " " << item.date;
  return os;
}

void ParseFromFile(string input_file_name, map<int, MemoryRecord> &m) {
  ifstream ifs(input_file_name);
  if (!ifs.is_open()) {
    return;
  }

  string line;
  while (getline(ifs, line)) {
    stringstream ss(line);

    MemoryRecord record;
    ss >> record.id;
    ss >> record.date;

//    cout << record << endl;
    m[record.id] = std::move(record);
  }
}

long ConvertTimeStamp(string str) {
  // 22:28:07.393919
  int h = 0;
  int m = 0;
  int s = 0;
  int us = 0;
  sscanf(str.c_str(), "%d:%d:%d.%d", &h, &m, &s, &us);

  auto result = (h * 3600L + m * 60L + s) * 1000000 + us;
//  cout << "convert [" << str << "] to result [" << result << "], h:" << h << ",m:" << m << ",s:" << s << ",us:" << us << endl;

  return result / 1000;
}

int main(int argc, const char **argv) {
  cout << "welcome to memory_count app." << " argc:" << argc << endl;
  if (argc < 3) {
    cout << "you should input some file which has the content like: \n"
            "2108 22:28:15.423103\n"
            "2109 22:28:15.491549\n"
            "2110 22:28:15.554667\n"
            "2111 22:28:15.624868\n"
            "2112 22:28:15.678452\n";
    return 0;
  }

  auto cv_create_file = string(argv[1]);
  auto cv_destroy_file = string(argv[2]);
  cout << "you input a create file:" << cv_create_file << " and a destroy file:" << cv_destroy_file << endl;

  map<int, MemoryRecord> create_map;
  ParseFromFile(cv_create_file, create_map);

  map<int, MemoryRecord> destroy_map;
  ParseFromFile(cv_destroy_file, destroy_map);

  // time diff
  for (auto &item: create_map) {
    auto id = item.first;
    auto create_time = item.second.date;

    auto &destroy_item = destroy_map[id];
    if (destroy_item.id == id) {
      auto destroy_time = destroy_item.date;

      auto diff = ConvertTimeStamp(destroy_time) - ConvertTimeStamp(create_time);
      if (diff > 500) {
        cout << "id:" << id << ", diff time:" << diff << "ms" << endl;
      }
    }
  }


  return 0;
}