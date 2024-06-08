#include <iostream>
#include <string>
#include <windows.h>

#include <config.hpp>

bool createDir(const std::string dirName);

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

    createDir("TEST");

    return 0;
}

bool createDir(const std::string dirName){
    TCHAR cwd[MAX_PATH];
    if(!GetCurrentDirectory(MAX_PATH, cwd)){
        std::cerr<<"-- Error Getting Current Directory"<<std::endl;
        return false;
    }

    const std::string path = std::string(cwd) + "\\" + dirName;

    if(!CreateDirectory(path.c_str(), NULL)){
        std::cerr<<"-- Error Creating Directory: "<<path<<std::endl;
        return false;
    }

    return true;
}