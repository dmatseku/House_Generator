#include "House.hpp"
#include <iostream>
#include <regex>
#include <Winu

namespace
{
    int find_apf(int ac, char** av, int porch)
    {
    	std::string	expression = "(apf" + std::to_string(porch) + "=)(\\d+)";
        std::regex flag(expression);
        std::cmatch info;

        for (int i = 1; i < ac; i++)
            if (std::regex_match(av[i], info, flag))
                return (std::stoi(info.str(2)));
        return (0);
    }

    int find_floors(int ac, char** av, int porch)
    {
		std::string	expression = "(floors" + std::to_string(porch) + "=)(\\d+)";
		std::regex flag(expression);
        std::cmatch info;

        for (int i = 1; i < ac; i++)
            if (std::regex_match(av[i], info, flag))
                return (std::stoi(info.str(2)));
        return (0);
    }
}

House::House(int ac, char** av):
_porchs(1),
_s_floors(1),
_first_nb(1),
_s_apf(1),
_porchs_data(0)
{
    read_data();

    int porch = 0;
    std::vector<data> p_data(_porchs);
    for(data& d : p_data)
    {
        int apf = find_apf(ac, av, porch + 1);
        int floors = find_floors(ac, av, porch + 1);

        d.apf = (apf ? apf : _s_apf);
        d.floors  = (floors ? floors : _s_floors);

        porch++;
    }
	_porchs_data = std::move(p_data);
}

House::House():
_porchs(1),
_s_floors(1),
_first_nb(1),
_s_apf(1),
_porchs_data(0)
{
    read_data();

    std::vector<data> p_data(_porchs);
    for(data& d : p_data)
    {
        d.apf = _s_apf;
        d.floors  = _s_floors;
    }
    _porchs_data = std::move(p_data);
}

void
House::read_data()
{
    std::cout << PORCHS;
    std::cin >> _porchs;

    std::cout << FLOORS;
    std::cin >> _s_floors;

    std::cout << APF;
    std::cin >> _s_apf;

    std::cout << FIRST_NB;
    std::cin >> _first_nb;

    std::cout << std::endl;
}

std::string
House::to_string()
{
    std::stringstream   res;
    int                 actual_nb = _first_nb;

    for (int porch = 0; porch < _porchs; porch++)
    {
        res << WORD_PORCH << ": " << porch + 1 << "\n";
        res << create_porch(actual_nb, _porchs_data[porch]);
        if (porch < _porchs - 1)
			res << "\n\n";
        actual_nb += (_porchs_data[porch].floors * _porchs_data[porch].apf);
    }

    return (res.str());
}

std::string
House::create_porch(int first_nb, data const & dat)
{
    std::stringstream   res;
    int                 actual_nb = first_nb;

    for (int floor = 0; floor < dat.floors; floor++)
    {
        res << FLOOR_PREFIX << WORD_FLOOR << ": " << floor + 1 << "\n";
        res << FLOOR_PREFIX << create_floor(actual_nb, dat.apf) << "\n\n";
        actual_nb += dat.apf;
    }

    res << FLOOR_PREFIX << WORD_RUDE << ": " << WORD_NO << "\n";
    res << FLOOR_PREFIX << WORD_CATEGORICAL << ": " << WORD_NO;
    
    return (res.str());
}

std::string
House::create_floor(int first_nb, int apf)
{
    std::stringstream   res;
    int                 end_nb = first_nb + apf;

    res << APARTMENT_PREFIX << first_nb;
    for (int nb = first_nb + 1; nb < end_nb; nb++)
    {
       res << " " << nb;
    }

    return (res.str());
}