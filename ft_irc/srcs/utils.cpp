#include "utils.hpp"

std::string trim(const std::string& str)
{
	std::string::size_type start = str.find_first_not_of(' ');
	std::string::size_type end = str.find_last_not_of(' ');
	if (start == std::string::npos)
		return str.substr(0, end);
	else if (end == std::string::npos)
		return str.substr(start);
	else
		return str.substr(start, end - start + 1);
}

std::string removeExtraDelimiters(const std::string& input, char delimiter) {
	std::string result;
	bool previousWasDelimiter = false;

	std::string::const_iterator it = input.begin();
	while (it != input.end() && *it == delimiter)
		++it;

	for (; it != input.end(); ++it) {
		char c = *it;
		if (c == delimiter)
		{
			if (!previousWasDelimiter)
			{
				result += delimiter;
				previousWasDelimiter = true;
			}
		}
		else
		{
			result += c;
			previousWasDelimiter = false;
		}
	}

	if (result.size() && result[result.size() - 1] == delimiter)
		result.erase(result.size() - 1);

	return result;
}

std::vector<std::string> split(const std::string& s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::string cleanedInput = removeExtraDelimiters(s, delimiter);
	std::istringstream tokenStream(cleanedInput);

	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

std::string getCommand(int CMD)
{
	std::string cmdarr[] = {"NICK ", "USER ", "PASS ", "JOIN ", "PRIVMSG ", "PING ", "KICK ", "TOPIC ", "MODE ", "INVITE "};
	if (CMD == 0)
		return "";
	return cmdarr[CMD - 1];
}

std::string welcome()
{
	std::string str;
	str += "   _____  __  __ ____   ______ ____\n";
	str += "  / ___/ / / / // __ \\ / ____// __ \\\n";
	str += "  \\__ \\ / / / // /_/ // __/  / /_/ /\n";
	str += " ___/ // /_/ // ____// /___ / _, _/\n";
	str += "/____/ \\____//_/ _  /_____//_/ |_|\n";
	str += "   /  |/  //  _// | / //  _/\n";
	str += "  / /|_/ / / / /  |/ / / /\n";
	str += " / /  / /_/ / / /|  /_/ /\n";
	str += "/_/ _/_//___//_/_|_//___/\n";
	str += "   /  _// __ \\ / ____/\n";
	str += "   / / / /_/ // /\n";
	str += " _/ / / _, _// /___\n";
	str += "/___//_/ |_| \\____/\n";
	str += "                                    \n";
	str += "Welcome to SUPER-MINI IRC!\n";
	return str;
}
