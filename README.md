# File System Smulator in C++

A file system is a crucial component of any operating system, enabling users to store, organize, and manage files efficiently. It provides the necessary structure for data retrieval and manipulation, ensuring that files and directories are accessible in a systematic manner. This **File System Simulator** is a diy that mimics some basic file system functionalities using C++, simulating operations such as creating directories, adding files, moving files, deleting files, and printing directory structures.

 ## Features
This project implements the following core functionalities of a file system:
- Create a New Directory: Users can create new directories dynamically.
- Add a New File: Users can create and write content to new files within a specified directory.
- Move a File: Allows moving a file from one directory to another.
- Delete a File: Enables users to remove specific files from the system.
- Delete a Directory: Supports deletion of entire directories along with their contents.
- Print Directory Structure: Recursively displays the directory structure and its files.

## C++ and Software Design Components
This project is implemented using C++17 and leverages the std::filesystem library for file and directory operations. It follows the SOLID principles of software engineering along with object-oriented design principles. The main design components include:

**FileSystemSimulator Class** \
Encapsulates all file system operations.
Uses std::filesystem to interact with the underlying OS file system.

**Main Driver Program** \
Provides a user interface to interact with the file system.
Uses a loop to repeatedly accept user commands and execute appropriate actions.

**Error Handling** \
Catches exceptions to handle errors such as invalid paths, permission issues, or missing files.

**Recursive Directory Traversal** \
Implements a recursive function to display nested directories and files.

## Output 
Sample Interaction (Including negative test scenarios)
```
File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 1
Enter directory path: C:\Users\Asus\Desktop\FileSystem\NewDir
Directory created successfully: C:\Users\Asus\Desktop\FileSystem\NewDir

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 2
Enter directory path: C:\Users\Asus\Desktop\FileSystem\NewDir
Enter file name: file1.txt
Enter content for the file: "This is a file created using file system simulator"
File added successfully: C:\Users\Asus\Desktop\FileSystem\NewDir\file1.txt

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 3
Enter source file path: C:\Userss\Asus\Desktop\FileSystem\NewDir
Enter destination file path: C:\Users\Asus\Desktop\FileSystem\OldDir
Error moving file: filesystem error: cannot rename: Input/output error [C:\Userss\Asus\Desktop\FileSystem\NewDir] [C:\Users\Asus\Desktop\FileSystem\OldDir]

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 3
Enter source file path: C:\Users\Asus\Desktop\FileSystem\NewDir\file1.txt
Enter destination file path: C:\Users\Asus\Desktop\FileSystem\OldDir\file2.txt
Error moving file: filesystem error: cannot rename: Input/output error [C:\Users\Asus\Desktop\FileSystem\NewDir\file1.txt] [C:\Users\Asus\Desktop\FileSystem\OldDir\file2.txt]

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 1
Enter directory path: C:\Users\Asus\Desktop\FileSystem\OldDir
Directory created successfully: C:\Users\Asus\Desktop\FileSystem\OldDir

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 3
Enter source file path: C:\Users\Asus\Desktop\FileSystem\NewDir\file1.txt
Enter destination file path: C:\Users\Asus\Desktop\FileSystem\OldDir\file1.txt
File moved successfully: C:\Users\Asus\Desktop\FileSystem\NewDir\file1.txt -> C:\Users\Asus\Desktop\FileSystem\OldDir\file1.txt

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 6
Enter directory path to print: C:\Users\Asus\Desktop\FileSystem
[DIR] NewDir\
[DIR] OldDir\
[FILE] OldDir\file1.txt

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 5
Enter directory path to delete: C:\Users\Asus\Desktop\FileSystem\Dir
Failed to delete directory: C:\Users\Asus\Desktop\FileSystem\Dir

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 5
Enter directory path to delete: C:\Users\Asus\Desktop\FileSystem\NewDir
Directory and its contents deleted successfully: C:\Users\Asus\Desktop\FileSystem\NewDir

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 6
Enter directory path to print: C:\Users\Asus\Desktop\FileSystem 
[DIR] OldDir\
[FILE] OldDir\file1.txt

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 4
Enter file path to delete: C:\Users\Asus\Desktop\FileSystem\OldDir\file1.txt
File deleted successfully: C:\Users\Asus\Desktop\FileSystem\OldDir\file1.txt

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 5
Enter directory path to delete: C:\Users\Asus\Desktop\FileSystem\OldDir
Directory and its contents deleted successfully: C:\Users\Asus\Desktop\FileSystem\OldDir

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 6
Enter directory path to print: C:\Users\Asus\Desktop\FileSystem

File System Simulator
1. Create Directory
2. Add File
3. Move File
4. Delete File
5. Delete Directory
6. Print Directory
7. Exit
Enter your choice: 7
Exiting the File System Simulator...
```

## Conclusion

This File System Simulator provides a practical demonstration of file and directory manipulation using C++. It reinforces concepts related to operating systems and file handling, making it a great learning tool for understanding how file systems work in real-world applications. Future enhancements could include adding user permissions, file searching, and implementing a GUI interface for better user experience.
