#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <gq/Document.h>
#include <gq/Node.h>
#include "CommandLineParser.h"
#include "Logger.h"

int gbk2utf8(char *utfstr,const char *srcstr,int maxutfstrlen)
{
	if(NULL==srcstr)
	{
		printf("bad parameter\n");
		return -1;
	}
	//首先先将gbk编码转换为unicode编码
	if(NULL==setlocale(LC_ALL,"zh_cn.gbk"))//设置转换为unicode前的码,当前为gbk编码
	{
		printf("bad parameter\n");
		return -1;
	}
	int unicodelen=mbstowcs(NULL,srcstr,0);//计算转换后的长度
	if(unicodelen<=0)
	{
		printf("can not transfer!!!\n");
		return -1;
	}
	wchar_t *unicodestr=(wchar_t *)calloc(sizeof(wchar_t),unicodelen+1);
	mbstowcs(unicodestr,srcstr,strlen(srcstr));//将gbk转换为unicode

	//将unicode编码转换为utf8编码
	if(NULL==setlocale(LC_ALL,"zh_cn.utf8"))//设置unicode转换后的码,当前为utf8
	{
		printf("bad parameter\n");
		return -1;
	}
	int utflen=wcstombs(NULL,unicodestr,0);//计算转换后的长度
	if(utflen<=0)
	{
		printf("can not transfer!!!\n");
		return -1;
	}
	else if(utflen>=maxutfstrlen)//判断空间是否足够
	{
		printf("dst str memory not enough\n");
		return -1;
	}
	wcstombs(utfstr,unicodestr,utflen);
	utfstr[utflen]=0;//添加结束符
	free(unicodestr);
	return utflen;
}

std::string content(const std::string& fileName)
{
	std::ifstream file(fileName);
	assert(file.good());
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
	std::cout << "Hello" << std::endl;
	//CDocument doc;
	//doc.parse(s.c_str());

	//CSelection c = doc.find("h1 a");
	//std::cout << c.nodeAt(0).text() << std::endl; // some link
	return 0;
}
