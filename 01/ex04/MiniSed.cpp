#include "MiniSed.h"
#include <sys/stat.h>

MiniSed::MiniSed(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {
}

MiniSed::~MiniSed() {
}

std::string MiniSed::readFile(const std::string& filename) {
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return "";
    }

    std::string content;
    char c;
    while (infile.get(c)) {
        content += c;
    }

    infile.close();
    return content;
}

bool MiniSed::writeFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot create file '" << filename << "'" << std::endl;
        return false;
    }

    outfile << content;
    outfile.close();
    return true;
}

std::string MiniSed::replaceOccurrences(const std::string& content) {
    if (_s1.empty()) {
        return content;
    }

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(_s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result += _s2;
        pos = found + _s1.length();
    }

    result.append(content, pos, content.length() - pos);
    return result;
}

bool MiniSed::isRegularFile(const std::string& filename) {
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) {
        return false;
    }
    return S_ISREG(st.st_mode);
}

bool MiniSed::process() {
    if (_s1.empty()) {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return false;
    }

    if (!isRegularFile(_filename)) {
        std::cerr << "Error: '" << _filename << "' is not a regular file" << std::endl;
        return false;
    }

    std::string content = readFile(_filename);

    std::string replaced = replaceOccurrences(content);
    std::string outFilename = _filename + ".replace";

    if (!writeFile(outFilename, replaced)) {
        return false;
    }

    std::cout << "File '" << outFilename << "' created successfully." << std::endl;
    return true;
}