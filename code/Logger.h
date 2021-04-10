#ifndef __LOGGER__H
#define __LOGGER__H

#include <string>
#include <sstream>

class Logger
{
private:
	Logger();
	~Logger();
public:
	static void write(const std::string& text);
	template<typename T>
	static void write(const std::string& note, const T& value)
	{
		std::stringstream ss;
		ss << note << ":" << value;		
		write(ss.str());
	}
};
#endif//__LOGGER__H
