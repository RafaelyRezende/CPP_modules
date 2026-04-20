#include <iostream>
#include <fstream>
#include <string>

void	copy_and_replace(const char *source_path, const char *pattern, const char *subs) {
	if (!source_path) {
		std::cerr << "Error: NULL filename" << std::endl;
		exit(1);
	}
	std::ifstream	infile(source_path);
	if (!infile) {
		std::cerr << "Error: cannot open file.\n";
		exit(2);
	}
	std::string		dest_path = std::string(source_path) + ".replace";
	std::ofstream	outfile(dest_path.c_str());
	if (!outfile) {
		std::cerr << "Error: cannot write to file\n";
		exit(3);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	copy_and_replace(argv[1], argv[2], argv[3]);
}
