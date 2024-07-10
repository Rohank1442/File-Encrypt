#include "ProcessManagement.hpp"
#include <iostream>
#include <cstring>
#include "../encryptDecrypt/Cryption.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/wait.h>
#endif


ProcessManagement::ProcessManagement(){}

bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task){
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks() {
    while(!taskQueue.empty()) {
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        std::cout << "Executing task: " << taskToExecute->toString() << std::endl;
        
        #ifdef _WIN32
        executeProcess(taskToExecute->toString());
        #else
        executeCryption(taskToExecute->toString());
        #endif
    }
}

#ifdef _WIN32
bool ProcessManagement::executeProcess(const std::string& command) {
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    std::wstring wideCommand = std::wstring(command.begin(), command.end());

    bool success = CreateProcessW(
        NULL,                   // No module name (use command line)
        &wideCommand[0],        // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        0,                      // No creation flags
        NULL,                   // Use parent's environment block
        NULL,                   // Use parent's starting directory 
        &si,                    // Pointer to STARTUPINFO structure
        &pi                     // Pointer to PROCESS_INFORMATION structure
    );

    if (!success) {
        std::cerr << "CreateProcess failed. Error: " << GetLastError() << std::endl;
        return false;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return true;
}
#endif