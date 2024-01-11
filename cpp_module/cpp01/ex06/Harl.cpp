/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:04 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 19:46:52 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//typedef void (*function)(void);

Harl::Harl() {

}

Harl::~Harl() {

}

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming foryears whereas you started working here since last month.\n" << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level ) {
    void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int level_i = -1;
    for (int i = 0; i < 4; ++i) {
        if (str[i] == level) {
            level_i = i;
            break;
        }
    }
    switch (level_i) {
        case -1: {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
        case 0: {
            (this->*f[0])();
        }
        case 1: {
            (this->*f[1])();
        }
        case 2: {
            (this->*f[2])();
        }
        case 3: {
            (this->*f[3])();
        }

        default:
            break;
    }
}