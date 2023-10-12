//
// Created by michael.brunner on 12/10/2023.
//

#ifndef CPP_PLAYGROUND_CWRITEREADLAZY_H
#define CPP_PLAYGROUND_CWRITEREADLAZY_H

#include <string>
#include <utility>
#include <functional>
#include <fstream>
#include <iostream>
#include <sstream>
#include <bitset>

class CWriteReadLazy
{
public:
	explicit CWriteReadLazy(std::string aFileName)
			: mFileName{std::move(aFileName)}
	{
		mReadFunction = [this]// () -> std::stringstream
		{
			std::ifstream lFile{mFileName};
			lFile.open(mFileName, std::ios::in, std::ios::out);
			std::stringstream lStream;
			lStream << lFile.rdbuf();
			lFile.close();
			return lStream;
		};
	}

	~CWriteReadLazy() = default;

	std::stringstream read()
	{
		return mReadFunction();
	}

private:
	std::string mFileName;
	std::function<std::stringstream(void)> mReadFunction;
};

void writeFile()
{
	using namespace std::string_literals;
	std::ofstream lFile{R"(C:\Users\michael.brunner\CLionProjects\CPP-Playground\ProxyObjects\fstream.dat)", std::ios::out, std::ios::binary};
	if (lFile.is_open()) {
//		lFile << "Hello World" << std::endl;
//		lFile << "Salut C++" << std::endl;
		auto lText = "Binarys are just numbers"s;
		for (char c : lText) {
			std::bitset<8> binary(c); // Convert each character to an 8-bit binary representation
			lFile << binary << " ";
		}
		lFile.flush();
		lFile.close();
	} else {
		std::cerr << "Failed to open the file for writing." << std::endl;
	}
}

#endif //CPP_PLAYGROUND_CWRITEREADLAZY_H
