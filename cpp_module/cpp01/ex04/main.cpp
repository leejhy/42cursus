
#include <iostream>
#include <fstream>

bool	errors(int argc, char **argv)
{
	if (argc != 4){
		std::cout << "Argument error" << std::endl;
		return (true);
	}
	if (*argv[1] == '\0' || *argv[2] == '\0'){
		std::cout << "Argument error" << std::endl;
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::ifstream	ifs;
	std::ofstream	ofs;
	size_t			pos;

	if (errors(argc, argv))
		return (1);
	s1 = argv[2];
	s2 = argv[3];
	filename = argv[1];
	ifs.open(argv[1]);
	if (ifs.is_open() == 0){
		std::cout << "ifs open error" << std::endl;
		return (1);
	}
	filename = filename + ".replace";
	ofs.open(filename.c_str());
	if (ofs.is_open() == 0){
		std::cout << "ofs open error" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line)){
		pos = 0;
		while (line.find(s1, pos) != std::string::npos){
			pos = line.find(s1, pos);
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		ofs << line;
		if (!ifs.eof())
			ofs << '\n';
	}
	ifs.close();
	ofs.close();
}