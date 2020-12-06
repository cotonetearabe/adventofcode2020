#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;


int part_one(string input) {
    return regex_match(input, regex("((byr|iyr|eyr|hgt|hcl|ecl|pid|cid).*){8}|((byr|iyr|eyr|hgt|hcl|ecl|pid).*){7}"));
}

int part_two(string input) {
    bool byr = regex_match(input, regex(".*byr:((19[2-9]\\d)|(200[0-2])) .*"));
    bool iyr = regex_match(input, regex(".*iyr:((201\\d)|(2020)) .*"));
    bool eyr = regex_match(input, regex(".*eyr:((202\\d)|(2030)) .*"));
    bool hgt = regex_match(input, regex(".*hgt:((((1[5-8]\\d)|(19[0-3]))cm)|((59)|(6\\d)|(7[0-6]))in) .*"));
    bool hcl = regex_match(input, regex(".*hcl:#(\\d|[a-f]){6} .*"));
    bool ecl = regex_match(input, regex(".*ecl:(amb|blu|brn|gry|grn|hzl|oth) .*"));
    bool pid = regex_match(input, regex(".*pid:(\\d){9} .*"));
    return byr && iyr && eyr && hgt && hcl && ecl && pid;
}


int main() {
    string line;
    string input = "";

    int part_one_result = 0, part_two_result = 0;

    while(getline(cin, line, '\n')) {
        if(line[0] == '\0') {
            if(part_one(input)) {
                part_one_result++;
                part_two_result += part_two(input);
            }
            input = "";
        }

        else
            input += line + " ";
    }

    part_one_result += part_one(input);
    part_two_result += part_two(input);

    cout << "Day 4 - Part one: " << part_one_result << endl;
    cout << "Day 4 - Part two: " << part_two_result << endl;

    return 0;
}
