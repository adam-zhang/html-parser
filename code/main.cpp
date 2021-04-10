#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <gq/Document.h>
#include <gq/Node.h>
#include "CommandLineParser.h"


std::string content(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.bad())
		return std::string();
	std::stringstream ss;
	ss << file.rdbuf();
	return ss.str();
}

int main(int argc, char * argv[])
{
	CommandLineParser parser;
	if(!parser.parse(argc, argv))
		return -1;
	auto s = content(parser.arguments()[0]);
	std::cout << s << std::endl;
	CDocument doc;
	doc.parse(s.c_str());

	CSelection c = doc.find("h1 a");
	std::cout << c.nodeAt(0).text() << std::endl; // some link
	return 0;
}
