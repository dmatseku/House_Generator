#ifndef HOUSE_GENERATOR_HOUSE_HPP
#define HOUSE_GENERATOR_HOUSE_HPP

#define PORCHS              "Number of porches:   "
#define FLOORS              "Number of floors:    "
#define FIRST_NB            "First number:        "
#define APF             	"Apartment per floor: "

#define WORD_PORCH          "Подъезд"
#define WORD_FLOOR          "Этаж"
#define WORD_RUDE           "Грубые"
#define WORD_CATEGORICAL    "Категорические"
#define WORD_NO             "Нет"

#define FLOOR_PREFIX        "    "
#define APARTMENT_PREFIX    "    "

#include <vector>
#include <string>

class House
{
public:
    House();
    House(House const &) = default;
    House(int ac, char** av);

    ~House() = default;

    House&      operator =(House const &) = default;

    std::string			to_string();

private:

    struct  data
    {
        int floors;
        int apf;
    };

    int                 _porchs;
    int                 _s_floors;
    int                 _first_nb;
    int                 _s_apf;
    std::vector<data>   _porchs_data;

    void        		read_data();
    static std::string	create_porch(int first_nb, data const & dat);
    static std::string	create_floor(int first_nb, int apf);
};

#endif