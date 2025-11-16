#include "CmakeHandler.hpp"
#include <fstream>

void CmakeHandler::GenerateCmakeFile()
{
    if (cmakeVersion.empty())
        GetVersionFromSys();

    if (projectName.empty())
        projectName = "MyProject";

    if (executableName.empty())
        executableName = "myExe";

    std::ofstream CmakeFile("CMakeLists.txt");

    CmakeFile << "cmake_minimum_required(VERSION " << cmakeVersion << ")\n";
    CmakeFile << "project(" << projectName << ")\n";
    CmakeFile << "add_executable(" << executableName << " main.cpp)";
}

void CmakeHandler::GetVersionFromSys()
{
    const int versionSize = 50;
    int versionStart, versionEnd;
    bool isStartFound = false;

    FILE* result = popen("cmake --version", "r");
    int status;

    if (!result)
    {
        std::cout << "" << std::endl;
        throw std::runtime_error("Error while getting cmake version");
    }

    char data[versionSize];
    int bytesRead = fread(data, 1, versionSize, result);
    
    for (int i = 0; i < bytesRead; i++)
    {
        if (!isStartFound && isdigit(data[i]))
        {
            versionStart = i;
            isStartFound = true;
            continue;
        }

        if (isStartFound && !isdigit(data[i]) && data[i] != '.')
        {
            versionEnd = i;
            break;
        }
    }
    cmakeVersion.assign(data + versionStart, data + versionEnd);

    status = pclose(result);
    if (status < 0) {
        std::cout << "status: " << status << std::endl;
        throw std::runtime_error("Error while closing pipe with the shell");
    }
}