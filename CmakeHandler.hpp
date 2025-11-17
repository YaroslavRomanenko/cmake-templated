#include <iostream>

class CmakeHandler 
{
public:
    void AskProjectSetup();
    void GenerateCmakeFile();

private:
    std::string GetVersionFromSys();

    std::string cmakeVersion;
    std::string projectName;
    std::string executableName;
};