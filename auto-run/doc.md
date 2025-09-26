# File Monitor and Script Runner

This C++ program continuously monitors a specified file for changes.  
Whenever the file is modified, a given script is executed automatically.  
It is useful for automating tasks like recompilation, testing, or code generation.  

---

## Features
- Monitors a file for modifications in real time.
- Executes a shell script when changes are detected.
- Prints logs to the console for file changes and script execution.
- Handles file system errors gracefully.

---

## How It Works
1. The program checks if the target file exists.  
2. It records the file’s last modification time.  
3. Every second, it checks whether the file’s last modification time has changed.  
4. If a change is detected:
   - Logs the event to the console.
   - Runs the configured script using `system()`.  
   - Reports success or failure of the script execution.

---

## Example Usage
1. Place your C++ file (e.g., `a.cxx`) in the same directory.
2. Create a shell script (e.g., `script.sh`) with the commands you want to run.
   ```bash
   #!/bin/bash
   echo "File changed, running tasks..."
   g++ a.cxx -o a.out && ./a.out
   ```

3. Make the script executable:

   ```bash
   chmod +x script.sh
   ```
4. Update `main()` with the file and script paths:

   ```cpp
   std::string fileToMonitor = "a.cxx";
   std::string scriptToRun   = "./script.sh";
   ```
5. Compile and run the program:

   ```bash
   g++ -std=c++17 monitor.cpp -o monitor
   ./monitor
   ```

---

## Notes

* Requires **C++17** (for `<filesystem>`).
* On Linux/Mac, ensure the script has execute permission (`chmod +x`).
* On Windows, replace `script.sh` with a `.bat` or `.ps1` script.
* You can extend the program to:

  * Monitor multiple files.
  * Auto-apply `chmod +x` to the script.
  * Add debounce logic to avoid multiple rapid triggers.

---