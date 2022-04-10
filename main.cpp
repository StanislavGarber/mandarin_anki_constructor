#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using std::cout; using std::cerr; using std::endl; using std::string;
using std::ifstream; using std::ostringstream; using std::istringstream;
using std::cin;

string read_file_into_string(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << path << "'" << endl;
        exit(EXIT_FAILURE);
    }

    ss << input_file.rdbuf();
    return ss.str();
}

void store_csv_contents(std::map<int, std::vector<string>>& csv_contents, string path, char delimiter) {

    string filename(path);
    string file_contents;

    file_contents = read_file_into_string(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;

    int counter = 0;

    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            // record.erase(std::remove_if(record.begin(), record.end(), isspace), record.end());
            items.push_back(record);
        }

        csv_contents[counter] = items;
        items.clear();
        counter += 1;
    }
}

int main()
{

    string path;
    char delimiter;
    std::map<int, std::vector<string>> csv_contents;

    cout << "path to file: " << endl;
    cin >> path;
    cout << "delimiter: " << endl;
    cin >> delimiter;

    store_csv_contents(csv_contents, path, delimiter);


    std::vector<string> test_items = csv_contents[1];
    for (string i : test_items) cout << i;


    exit(EXIT_SUCCESS);

}
