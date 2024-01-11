/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:41:27 by junssong          #+#    #+#             */
/*   Updated: 2024/01/11 13:43:06 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv) {
    if (argc != 2)
        return 1;
    std::string str(argv[1]);
    if (str.size() == 0)
        return 1;
    Harl harl;
    harl.complain(std::string(argv[1]));
}