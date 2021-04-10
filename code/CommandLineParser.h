#ifndef __COMMANDLINEPARSER__H
#define __COMMANDLINEPARSER__H

#include <vector>
#include <string>

class CommandLineParser
{
public:
	CommandLineParser();
	~CommandLineParser();

public:
	bool parse(int argc, char** argv);
	std::vector<std::string> arguments()
	{ return arguments_; }
private:
	std::vector<std::string> arguments_;
};
#endif//__COMMANDLINEPARSER__H
