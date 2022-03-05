// Copyright 2022 mgshim

#ifndef TABLE_H_
#define TABLE_H_

#include <string>
#include <vector>

class Table {
 private:
    std::vector<std::string> attribute;
    std::vector<std::vector<std::string>> value;

 public:
    Table();
    explicit Table(std::string initStream);
    Table(std::vector<std::string> attrVec,
          std::vector<std::vector<std::string>> valueVec);
    void PrintTable();
    Table FindEquals(std::string attr, std::string val);
    std::string GetValue(int row, std::string attr);
    int GetRowLength();
};
#endif  // TABLE_H_
