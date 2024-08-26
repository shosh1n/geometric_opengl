#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

class FileManager {
public:
    FileManager();
    ~FileManager();
    static std::string read(const std::string& filename);
};



#endif // FILE_MANAGER_H_
