#include "House/House.hpp"
#include <iostream>

int main(int ac, char** av)
{
    std::string str;

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
    return (0);
}