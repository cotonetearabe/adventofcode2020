#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define LINE_MAX 31


int solve(vector<string> input, int step_x, int step_y) {
    int ret = 0;

    int x = 0, y;

    for(y = 0; y < input.size();) {
        
        cout << "x: " << x << " y: " << y << endl;

        if(input[y][x] == '#')
            ret++;
        
        x = (x + step_x) % LINE_MAX;
        y += step_y;
    }

    return ret;
}


int main() {
    string temp;
    vector<string> input;
    int part_one_result, part_two_result;

    while(cin >> temp)
        input.push_back(temp);

    part_one_result = solve(input, 3, 1);
    part_two_result = solve(input, 1, 1);
    part_two_result *= part_one_result;
    part_two_result *= solve(input, 5, 1);
    part_two_result *= solve(input, 7, 1);
    part_two_result *= solve(input, 1, 2);

    cout << "Day 3 - Part one: " << part_one_result << endl;
    cout << "Day 3 - Part two: " << part_two_result << endl;

    return 0;
}
