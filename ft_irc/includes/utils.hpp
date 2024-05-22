#pragma once
#include <string>
#include <vector>
#include <sstream>

std::string trim(const std::string& str);
std::vector<std::string> split(const std::string& s, char delimiter);
std::string getCommand(int CMD);
std::string welcome();
