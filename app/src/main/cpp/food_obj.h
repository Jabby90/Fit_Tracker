//
/// @brief Класс представляет собой продукт, который содержит некоторый КБЖУ
//
#pragma once
#ifndef FIT_TRACKER_FOOD_OBJ_H
#define FIT_TRACKER_FOOD_OBJ_H

#include <string>
#include <string_view>

namespace food_dictionary
{

class food_obj
{
public:
    food_obj(const std::string& n, double k, double p, double f, double c) : name{n}, kcal{k}, proteins{p}, fats{f}, carbohydrates{c} {};

    const std::string& getName() const {return name;}
    const char* getNameCChar() const {return name.c_str();}
    double getKcal() const {return kcal;}
    double getProteins() const {return proteins;}
    double getFats() const {return fats;}
    double getCarbohydrates() const {return carbohydrates;}

private:
    std::string name{};     //наименование продукта

    double kcal{};          //калорийность в ККал на 100г. вообще, логично было бы int,
                            // но в случае каких-либо производных (или составных) продуктов, double удобнее
    double proteins{};      //белки в г. на 100г
    double fats{};          //жиры в г. на 100г
    double carbohydrates{}; //углеводы в г. на 100г

};

} // food_dictionary

#endif //FIT_TRACKER_FOOD_OBJ_H
