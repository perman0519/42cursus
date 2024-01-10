/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:05:07 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 11:44:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << std::endl
              << &stringPTR << std::endl
              << &stringREF << std::endl;

    std::cout << str << std::endl
              << stringPTR << std::endl
              << stringREF << std::endl;

    return 0;
}