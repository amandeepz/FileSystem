#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class FileSystemSimulator {
public:
    void createDirectory(const std::string& path) {
        if (fs::create_directory(path)) {
            std::cout << "Directory created successfully: " << path << std::endl;
        } else {
            std::cout << "Failed to create directory: " << path << std::endl;
        }
    }

    void addFile(const std::string& directory, const std::string& filename, const std::string& content) {
        std::string filePath = directory + "\\" + filename;
        std::ofstream file(filePath);
        if (file.is_open()) {
            file << content;
            file.close();
            std::cout << "File added successfully: " << filePath << std::endl;
        } else {
            std::cout << "Failed to create file: " << filePath << std::endl;
        }
    }

    void moveFile(const std::string& sourcePath, const std::string& destinationPath) {
        try {
            fs::rename(sourcePath, destinationPath);
            std::cout << "File moved successfully: " << sourcePath << " -> " << destinationPath << std::endl;
        } catch (const fs::filesystem_error& e) {
            std::cout << "Error moving file: " << e.what() << std::endl;
        }
    }

    void deleteFile(const std::string& filePath) {
        try {
            if (fs::remove(filePath)) {
                std::cout << "File deleted successfully: " << filePath << std::endl;
            } else {
                std::cout << "Failed to delete file: " << filePath << std::endl;
            }
        } catch (const fs::filesystem_error& e) {
            std::cout << "Error deleting file: " << e.what() << std::endl;
        }
    }

    void deleteDirectory(const std::string& dirPath) {
        try {
            if (fs::remove_all(dirPath)) {
                std::cout << "Directory and its contents deleted successfully: " << dirPath << std::endl;
            } else {
                std::cout << "Failed to delete directory: " << dirPath << std::endl;
            }
        } catch (const fs::filesystem_error& e) {
            std::cout << "Error deleting directory: " << e.what() << std::endl;
        }
    }

    void printDirectory(const std::string& dirPath) {
        try {
            if (fs::exists(dirPath) && fs::is_directory(dirPath)) {
                printDirectoryRecursive(dirPath, "");
            } else {
                std::cout << "Invalid directory: " << dirPath << std::endl;
            }
        } catch (const fs::filesystem_error& e) {
            std::cout << "Error reading directory: " << e.what() << std::endl;
        }
    }

private:
    void printDirectoryRecursive(const std::string& dirPath, const std::string& relativePath) {
        for (const auto& entry : fs::directory_iterator(dirPath)) {
            std::string entryPath = entry.path().string();
            std::string relativeEntryPath = relativePath + entry.path().filename().string();

            if (fs::is_directory(entry)) {
                std::cout << "[DIR] " << relativeEntryPath << "\\" << std::endl;
                printDirectoryRecursive(entryPath, relativeEntryPath + "\\");
            } else if (fs::is_regular_file(entry)) {
                std::cout << "[FILE] " << relativeEntryPath << std::endl;
            }
        }
    }
};

int main() {
    FileSystemSimulator fsSim;

    int choice;
    std::string dir, filename, content, src, dest;

    while (true) {
        std::cout << "\nFile System Simulator\n";
        std::cout << "1. Create Directory\n";
        std::cout << "2. Add File\n";
        std::cout << "3. Move File\n";
        std::cout << "4. Delete File\n";
        std::cout << "5. Delete Directory\n";
        std::cout << "6. Print Directory\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Enter directory path: ";
                std::getline(std::cin, dir);
                fsSim.createDirectory(dir);
                break;

            case 2:
                std::cout << "Enter directory path: ";
                std::getline(std::cin, dir);
                std::cout << "Enter file name: ";
                std::getline(std::cin, filename);
                std::cout << "Enter content for the file: ";
                std::getline(std::cin, content);
                fsSim.addFile(dir, filename, content);
                break;

            case 3:
                std::cout << "Enter source file path: ";
                std::getline(std::cin, src);
                std::cout << "Enter destination file path: ";
                std::getline(std::cin, dest);
                fsSim.moveFile(src, dest);
                break;

            case 4:
                std::cout << "Enter file path to delete: ";
                std::getline(std::cin, src);
                fsSim.deleteFile(src);
                break;

            case 5:
                std::cout << "Enter directory path to delete: ";
                std::getline(std::cin, dir);
                fsSim.deleteDirectory(dir);
                break;

            case 6:
                std::cout << "Enter directory path to print: ";
                std::getline(std::cin, dir);
                fsSim.printDirectory(dir);
                break;

            case 7:
                std::cout << "Exiting the File System Simulator...\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
