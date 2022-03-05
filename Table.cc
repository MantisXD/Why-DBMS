// Copyright 2022 mgshim

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Table.h"
#include "stringUtil.h"

Table::Table(std::string initStream) {
    std::vector<std::string> rows = split(trim(initStream), std::string("\n"));
    std::vector<std::string> dashes = split(rows.at(1), std::string(" "));
    std::vector<int> attrLength;

    for (std::string str : dashes) {
        attrLength.push_back(str.length());
        // cout << str.length() << endl;
    }

    int aux = 0;
    for (int x : attrLength) {
        std::string row = rows.at(0).substr(aux, x);
        std::string attr = trim(row);
        this->attribute.push_back(attr);
        // cout << attr << " ";
        aux += x + 1;
    }
    // cout << endl;

    for (int i = 2; i < rows.size(); i++) {
        int aux = 0;
        std::vector<std::string> valueVec;
        for (int x : attrLength) {
            std::string row = rows.at(i).substr(aux, x);
            std::string value = trim(row);
            valueVec.push_back(value);
            aux += x + 1;
            // cout << value << " ";
        }
        this->value.push_back(valueVec);
        // cout << "  " << aux << endl;
    }
}

Table::Table(std::vector<std::string> attrVec,
             std::vector<std::vector<std::string>> valueVec) {
    for (std::string str : attrVec) {
        this->attribute.push_back(str);
    }

    for (std::vector<std::string> row : valueVec) {
        std::vector<std::string> tmpVec;
        for (std::string str : row) {
            tmpVec.push_back(str);
        }
        this->value.push_back(tmpVec);
    }
}

void Table::PrintTable() {
    for (std::string str : this->attribute) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    for (std::vector<std::string> row : this->value) {
        for (std::string str : row) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}

Table Table::FindEquals(std::string attr, std::string val) {
    std::vector<std::vector<std::string>> newValue;

    int attrIndex =
        std::find(this->attribute.begin(), this->attribute.end(), attr) -
        this->attribute.begin();

    for (std::vector<std::string> row : this->value) {
        if (row.at(attrIndex) == val) {
            std::vector<std::string> tmp;
            for (std::string str : row) {
                tmp.push_back(str);
            }
            newValue.push_back(tmp);
        }
    }
    Table newTable(this->attribute, newValue);
    return newTable;
}

std::string Table::GetValue(int row, std::string attr) {
    if (row < 0 || row > this->value.size()) {
        return "";
    }

    int attrIndex =
        std::find(this->attribute.begin(), this->attribute.end(), attr) -
        this->attribute.begin();

    if (attrIndex < this->attribute.size()) {
        return value.at(row).at(attrIndex);
    } else {
        return "";
    }
}

int Table::GetRowLength() { return static_cast<int>(this->value.size()); }
