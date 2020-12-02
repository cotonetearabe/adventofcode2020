#include <iostream>
#include <vector>
#include <string>

using namespace std;


int solve_part_one(int min, int max, char target, string str) {
    int counter = 0;

    for(int i = 0; i < str.size(); i++)
        counter += (str[i] == target);

    return (counter >= min && counter <= max ? 1 : 0);
}


int solve_part_two(int idx1, int idx2, char target, string str) {
    return int((str[idx1] == target) ^ str[idx2] == target);
}


int main() {    
    int min, max;
    char target;
    string str;

    int part_one = 0, part_two = 0;

    while(scanf("%d-%d %c :", &min, &max, &target) != EOF) {
        cin >> str;
        part_one += solve_part_one(min, max, target, str);
        part_two += solve_part_two(min, max, target, str);
    }

    cout << "Day 2 - Part one: " << part_one << endl;
    cout << "Day 2 - Part two: " << part_two << endl;

    return 0;
}
