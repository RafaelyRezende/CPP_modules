#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs;

    ifs.open("random_words.txt", std::ifstream::in);
    std::string line;
    while(ifs.good())
    {
        getline(ifs, line);
        std::cout << line << std::endl;
    }
    ifs.close();
}
