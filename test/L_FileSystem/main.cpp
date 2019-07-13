//
// Created by z16cn on 2019/7/7.
//
//#include <filesystem>
#include <filesystem>
#include <iostream>

using namespace std::filesystem;
using namespace std;

int main(){
    directory_entry d;
    path path1{"D:\\workspace\\glzw"};
    cout<<path1<<endl;
    error_code errorCode;
    bool d_exit=exists(path1, errorCode);
    if(d_exit){

    }else if(errorCode){
        cout<<errorCode.message()<<endl;
    }
    return 0;
}

/*
 Classes
Defined in header <filesystem>
Defined in namespace filesystem
path
(C++17)
represents a path
(class)
filesystem_error
(C++17)
an exception thrown on file system errors
(class)
directory_entry
(C++17)
a directory entry
(class)
directory_iterator
(C++17)
an iterator to the contents of the directory
(class)
recursive_directory_iterator
(C++17)
an iterator to the contents of a directory and its subdirectories
(class)
file_status
(C++17)
represents file type and permissions
(class)
space_info
(C++17)
information about free and available space on the filesystem
(class)
file_type
(C++17)
the type of a file
(enum)
perms
(C++17)
identifies file system permissions
(enum)
perm_options
(C++17)
specifies semantics of permissions operations
(enum)
copy_options
(C++17)
specifies semantics of copy operations
(enum)
directory_options
(C++17)
options for iterating directory contents
(enum)
file_time_type
(C++17)
represents file time values
(typedef)
Non-member functions
 */