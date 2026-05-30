#ifndef MINISED_H
#define MINISED_H

#include <string>
#include <fstream>
#include <iostream>

class MiniSed{
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    std::string readFile(const std::string& filename);
    bool writeFile(const std::string& filename, const std::string& content);
    std::string replaceOccurrences(const std::string& content);
    bool isRegularFile(const std::string& filename);

public:
    MiniSed(const std::string& filename, const std::string& s1, const std::string& s2);
    ~MiniSed();

    bool process();
};

#endif