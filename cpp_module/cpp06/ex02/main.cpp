/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:51:27 by junssong          #+#    #+#             */
/*   Updated: 2024/03/29 12:56:02 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	std::srand(std::time(NULL));

	Base* base = generate();
	identify(base);
	identify(*base);
	Base* base1 = generate();
	identify(base1);
	identify(*base1);
	Base* base2 = generate();
	identify(base2);
	identify(*base2);

	delete base;
	delete base1;
	delete base2;
	return (0);
}
