
#include <iostream>
#include <fstream>

// void	f(){
// 	system("leaks a.out");
// }


int	main(int argc, char **argv)
{
	std::string		str;
	std::string		s1;
	std::string		s2;
	std::string		line;
	std::ifstream	ifs;//입력스트림 객체 생성
	std::ofstream	ofs;
	size_t			pos;

	if (argc != 4){
		std::cout << "Argument error" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	str = argv[1];
	ifs.open(argv[1]);//argv[1]로 들어오는거 open
	str = str + ".replace";
	ofs.open(str.c_str());//이거 const char *로 변환해야함 c_str()사용
	while (std::getline(ifs, line)){
		pos = 0;
		while (line.find(s1, pos) != std::string::npos){
			pos = line.find(s1, pos);
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			// pos += s1.length();
		}
		ofs << line;
		if (!ifs.eof())
			ofs << '\n';
	}
// atexit(f);
// std::getline(ifs, line);
}