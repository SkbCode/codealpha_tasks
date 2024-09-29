#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

void list_directory(const fs::path& path) {
    cout << "Directory contents of: " << path << endl;
    for (const auto& entry : fs::directory_iterator(path)) {
        cout << (fs::is_directory(entry.path()) ? "[DIR]  " : "[FILE] ") << entry.path().filename() << endl;
    }
}

void view_file(const fs::path& file_path) {
    if (!fs::exists(file_path)) {
        cout << "File does not exist!" << endl;
        return;
    }

    ifstream file(file_path);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "Contents of " << file_path << ":" << endl;
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void create_directory(const fs::path& path) {
    if (fs::create_directory(path)) {
        cout << "Directory created successfully: " << path << endl;
    } else {
        cout << "Failed to create directory: " << path << endl;
    }
}

void copy_file(const fs::path& source, const fs::path& destination) {
    try {
        fs::copy(source, destination, fs::copy_options::overwrite_existing);
        cout << "File copied successfully!" << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error copying file: " << e.what() << endl;
    }
}

void move_file(const fs::path& source, const fs::path& destination) {
    try {
        fs::rename(source, destination);
        cout << "File moved successfully!" << endl;
    } catch (const fs::filesystem_error& e) {
        cout << "Error moving file: " << e.what() << endl;
    }
}

int main() {
    string command, path, source, destination;

    cout << "Welcome to the Command-Line File Manager!" << endl;

    while (true) {
        cout << "\nEnter a command (list, view, mkdir, copy, move, exit): ";
        cin >> command;

        if (command == "list") {
            cout << "Enter directory path: ";
            cin >> path;
            list_directory(fs::path(path));

        } else if (command == "view") {
            cout << "Enter file path: ";
            cin >> path;
            view_file(fs::path(path));

        } else if (command == "mkdir") {
            cout << "Enter directory path: ";
            cin >> path;
            create_directory(fs::path(path));

        } else if (command == "copy") {
            cout << "Enter source file path: ";
            cin >> source;
            cout << "Enter destination file path: ";
            cin >> destination;
            copy_file(fs::path(source), fs::path(destination));

        } else if (command == "move") {
            cout << "Enter source file path: ";
            cin >> source;
            cout << "Enter destination file path: ";
            cin >> destination;
            move_file(fs::path(source), fs::path(destination));

        } else if (command == "exit") {
            cout << "Exiting file manager..." << endl;
            break;

        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}

