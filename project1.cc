// Copyright 2022 Wook-shin Han
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "project1.h"
#include "Table.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        return -1;
    }

    std::string query = std::string(argv[1]);
    std::string file1 = std::string(argv[2]);
    std::string file2 = std::string(argv[3]);

    std::ifstream ifs1(file1);
    std::ifstream ifs2(file2);

    std::string file1Content = std::string(std::istreambuf_iterator<char>(ifs1),
                                           std::istreambuf_iterator<char>());
    std::string file2Content = std::string(std::istreambuf_iterator<char>(ifs2),
                                           std::istreambuf_iterator<char>());

    Table table1 = Table(file1Content);
    Table table2 = Table(file2Content);

    // table1.PrintTable();
    // table2.PrintTable();

    if (query == "q1") {
        std::string zoneID =
            table2.FindEquals("ZONEDESC", "Toronto").GetValue(0, "ZONEID");
        Table tmpTable =
            table1.FindEquals("ZONE", zoneID).FindEquals("ACTIVE", "1");

        for (int i = 0; i < tmpTable.GetRowLength(); i++) {
            std::cout << tmpTable.GetValue(i, "LNAME") << std::endl;
        }
    } else {
        int len = table2.GetRowLength();
        std::string *arrBarcode = new std::string[len];
        std::pair<int, int> *arrPair =
            new std::pair<int, int>[len];  // row, num
        for (int i = 0; i < len; i++) {
            arrBarcode[i] = table2.GetValue(i, "BARCODE");
            std::get<0>(arrPair[i]) = i;
            std::get<1>(arrPair[i]) = 0;
        }

        for (int i = 0; i < table1.GetRowLength(); i++) {
            std::string code = table1.GetValue(i, "BARCODE");

            int index = std::distance(
                arrBarcode, std::find(arrBarcode, arrBarcode + len, code));
            std::get<1>(arrPair[index])++;
        }

        for (int i = 0; i < len; i++) {
            if (std::get<1>(arrPair[i]) >= 2) {
                std::cout << arrBarcode[i] << " "
                          << table2.GetValue(std::get<0>(arrPair[i]),
                                             "PRODDESC")
                          << std::endl;
            }
        }
    }

    return 0;
}
