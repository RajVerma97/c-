#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> splitString(const string& str, char delimiter) {

    vector<string> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}


int main() {
    string input = "Hello,World,This,Is,C++";
    char delimiter = ',';

    vector<string> result = splitString(input, delimiter);

    cout << "\nSplit result: \n";
    for (const string& s : result) {
        cout << s << endl;
    }
    cout << endl;

    return 0;
}
