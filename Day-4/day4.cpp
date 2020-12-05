#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;


int part_one(string input) {
    return regex_match(input, regex("((byr|iyr|eyr|hgt|hcl|ecl|pid|cid).*){8}|((byr|iyr|eyr|hgt|hcl|ecl|pid).*){7}"));
}


int main() {
    string line;
    string input = "";

    int part_one_result = 0, part_two_result = 0;


    while(getline(cin, line, '\n')) {
        if(line[0] == '\0') {
            part_one_result += part_one(input);
            input = "";
        }

        else
            input += line + " ";
    }

    part_one_result += part_one(input);

    cout << "Day 4 - Part one: " << part_one_result << endl;
    cout << "Day 4 - Part two: " << part_two_result << endl;

    return 0;
}
