#include <iostream>
#include <assert.h>
#include <vector>

int printColorMap(std::vector<std::string> & colorMap) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
            colorMap.push_back(std::to_string(i * 5 + j) +  " | " + majorColor[i] +  " | " + minorColor[i]);
        }
    }
    return i * j;
}

int main() {
    std::vector<std::string> colorMap;
    int result = printColorMap(colorMap);
    assert(colorMap.at(0).at(2) == colorMap.at(10).at(2));
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}