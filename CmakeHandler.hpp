#include <iostream>

class CmakeHandler 
{
public:
    void GenerateCmakeFile();

private:
    void GetVersionFromSys();

    std::string cmakeVersion;
    std::string projectName;
    std::string executableName;
};