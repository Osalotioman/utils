#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <cstdlib> // For system()

namespace fs = std::filesystem;

void monitorFile(const std::string& filePath, const std::string& scriptPath) {
    // Check if the file exists
    if (!fs::exists(filePath)) {
        std::cerr << "Error: File " << filePath << " does not exist.\n";
        return;
    }

    // Store the last modification time
    auto lastWriteTime = fs::last_write_time(filePath);

    std::cout << "Monitoring file: " << filePath << "\nPress Ctrl+C to exit.\n";

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Check every second

        try {
            // Get the current last modification time
            auto currentWriteTime = fs::last_write_time(filePath);

            // If the file has been modified
            if (currentWriteTime != lastWriteTime) {
                std::cout << "File " << filePath << " has been modified.\n";

                // Update the stored modification time
                lastWriteTime = currentWriteTime;

                // Execute the script
                std::cout << "Running script: " << scriptPath << "\n";
                int retCode = system(scriptPath.c_str());
                if (retCode != 0) {
                    std::cerr << "Error: Script execution failed with return code " << retCode << "\n";
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error: " << e.what() << "\n";
            break;
        }
    }
}

int main() {
    // File to monitor and script to run
    std::string fileToMonitor = "a.cxx"; //Enter the name of the file you want to monitor here
    std::string scriptToRun = "./script.sh"; //Enter the name of the script to run when the file is changed.
    //Note: You might need to run "chmod +x script.sh" to make the script executable and avoid permission issues. You can also contribute to the program a feature that lets the C++ program make sure the file is executable, possibly by running "chmod +x script.sh" within the program.

    monitorFile(fileToMonitor, scriptToRun);

    return 0;
}
