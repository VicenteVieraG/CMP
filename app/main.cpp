#include <iostream>
#include <string>
#include <windows.h>

#include <config.hpp>

bool createDir(const std::string dirName);
bool createFile(const std::string fileName);

int main(int argc, char** argv){
    std::cout<<project_name<<std::endl;
    std::cout<<project_version<<std::endl;

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

bool createFile(const std::string filePath){
    HANDLE file = CreateFile(
        filePath.c_str(),
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if(file == INVALID_HANDLE_VALUE){
        std::cerr<<"-- Error Creating File: "<<filePath<<std::endl<<GetLastError()<<std::endl;
        return false;
    }

    CloseHandle(file);
    return true;
}