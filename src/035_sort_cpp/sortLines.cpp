#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

void process(vector<string>& input){
    sort(input.begin(), input.end());
    for (const auto & i: input){
        cout << i << "\n";
    }
}


int main(int argc, char** argv){
    vector<string> input = {};
    string line;
    if (argc == 1){
        while (getline(cin, line)) {
            input.push_back(line);
            process(input);
        }
    }
    else{
        for (int i = 1; i < argc; ++i) {
            string filename = argv[i];
            ifstream file(filename);
            
            if (!file.is_open()) {
                cerr << "Error: Could not open the file: " << filename << endl;
                return EXIT_FAILURE;
            }

            while (getline(file, line)) {
                input.push_back(line);
                process(input);
            }
        }
    }
    return 0;
}