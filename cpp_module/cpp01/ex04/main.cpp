/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:46 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 16:45:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

int main(int argc, char **argv) {
    std::string fileName(argv[1]);
    std::string str1(argv[2]);
    std::string str2(argv[3]);
    std::fstream og(argv[1], std::ios_base::in);
    if (argc != 4 || str1.size() == 0)
        return 1;
    if (og.is_open()) {
        std::ofstream ogReplace((fileName + std::string(".replace")).c_str(), std::ios_base::out);
        if (!ogReplace.is_open())
            return 1;
        og.seekg (0, og.end);
        int length = og.tellg();
        og.seekg (0, og.beg);
        char * buff = new char [length];
        og.read (buff,length);
        std::string buffer(buff);
        delete [] buff;
        int find_index = 0;
        int before_index = 0;
        while (1) {
            find_index = buffer.find(str1, find_index);
            if (find_index == -1)
                break;
            ogReplace.write(buffer.substr(before_index, find_index).c_str(), find_index - before_index);
            ogReplace.write(argv[3], str2.size());
            int subSize = str1.size();
            find_index += subSize;
            before_index = find_index;
        }
        ogReplace.write(buffer.substr(before_index, buffer.size() - find_index).c_str(), buffer.size() - before_index);
        ogReplace.close();
    }
    else
        return 1;
    og.close();
    return 0;
}