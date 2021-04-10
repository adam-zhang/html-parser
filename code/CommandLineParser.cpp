#include "CommandLineParser.h"

CommandLineParser::CommandLineParser()
{
}

CommandLineParser::~CommandLineParser()
{
}

bool CommandLineParser::parse(int argc, char** argv)
{
	if (argc == 1)
		return false;
	for(int i = 1; i != argc; ++i)
		arguments_.emplace_back(argv[0]);
	return true;
}
