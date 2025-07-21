#include "FileHandler.h"
#include <fstream>
#include <sstream>

std::string FileHandler::ReadFile(const std::string &filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile)
        return "";

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

bool FileHandler::WriteFile(const std::string &filePath, const std::string &content)
{
    std::ofstream outFile(filePath);
    return outFile ? static_cast<bool>(outFile << content) : false;
}

bool FileHandler::AppendFile(const std::string &filePath, const std::string &content)
{
    std::ofstream outFile(filePath, std::ios::app);
    return outFile ? static_cast<bool>(outFile << content) : false;
}

bool FileHandler::FileExists(const std::string &filePath)
{
    std::ifstream inFile(filePath);
    return inFile.good();
}