/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:50:01 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 16:50:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class  Harl {

public:
    Harl();
    ~Harl();
    void    complain( std::string level );

private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );
};