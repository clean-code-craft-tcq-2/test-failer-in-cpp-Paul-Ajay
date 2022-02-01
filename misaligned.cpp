#include <iostream>
#include <assert.h>
#include <vector>
#include <iomanip>

class ColorMap {
private:
    std::vector<std::string> majorColor;
    std::vector<std::string> minorColor;
public:
    ColorMap(std::vector<std::string>, std::vector<std::string>);
    std::string formatColorPairString(int index, std::string majorColor, std::string minorColor);
    std::vector<std::string> generateColorMap();
    int printColorMap(std::vector<std::string> colorMap);
};

ColorMap::ColorMap(std::vector<std::string> majorColor, std::vector<std::string> minorColor) {
    this->majorColor = majorColor;
    this->minorColor = minorColor;
}

std::string ColorMap::formatColorPairString(int index, std::string majorColor, std::string minorColor) {
    std::stringstream formattedColorPair;
    formattedColorPair << std::setw(2) << std::setfill('0') << index << " | " ;
    formattedColorPair << std::left << std::setw(6) << std::setfill(' ') << majorColor << " | ";
    return formattedColorPair.str() + minorColor;
}

std::vector<std::string> ColorMap::generateColorMap() {
    std::vector<std::string> colorMap;
    for(auto majorColorItr = majorColor.begin(); majorColorItr != majorColor.end() ; majorColorItr ++) {
        for(auto minorColorItr = minorColor.begin(); minorColorItr != minorColor.end(); minorColorItr++) {
            colorMap.push_back(formatColorPairString((majorColorItr - majorColor.begin()) * majorColor.size() + (minorColorItr - minorColor.begin()) + 1,
                                                    *majorColorItr, *minorColorItr));
        }
    }
    return colorMap;
}

int ColorMap::printColorMap(std::vector<std::string> colorMap) {
    for(auto colorMapItr : colorMap)
        std::cout << colorMapItr<<std::endl;
    return colorMap.size();
}

int main() {
    std::vector<std::string> majorColor = {"White", "Red", "Black", "Yellow", "Violet"};
    std::vector<std::string> minorColor = {"Blue", "Orange", "Green", "Brown", "Slate"};
    ColorMap colorMapObject(majorColor, minorColor);
    auto colorMapList = colorMapObject.generateColorMap();
    assert(colorMapList.at(0).at(3) == colorMapList.at(10).at(3));
    auto result = colorMapObject.printColorMap(colorMapList);
    assert(result == static_cast<int> (majorColor.size() * minorColor.size()));
    std::cout << "All is well (maybe!)\n";
    return 0;
}