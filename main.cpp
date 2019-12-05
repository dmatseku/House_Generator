#include "House/House.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>

static bool find_filename(int ac, char** av, std::string& filename)
{
	std::string	expression = "(-file=)(\\w+)(.)?(\\w*)";
	std::regex flag(expression);
	std::cmatch info;

	for (int i = 1; i < ac; i++)
		if (std::regex_match(av[i], info, flag))
		{
			filename = info.str(2) + info.str(3) + info.str(4);
			return (true);
		}
	return (false);
}

int main(int ac, char** av)
{
    std::string str;
    std::string filename;

    if (ac > 1)
    {
        House house(ac, av);
        str = house.to_string();
    }
    else
    {
        House house;
        str = house.to_string();
    }
    std::cout << str << std::endl;

    if (find_filename(ac, av, filename))
	{
		std::cout << std::endl << "Writing in file " << filename << "... ";
    	std::ofstream file(filename);
    	file << str << std::endl;
    	file.close();
    	std::cout << "success" << std::endl;
	}
    return (0);
}