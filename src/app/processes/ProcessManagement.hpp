#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP

#pragma once
#include <queue>
#include <memory>
#include "Task.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/wait.h>
#endif

class ProcessManagement
{
public:
    ProcessManagement();
    bool submitToQueue(std::unique_ptr<Task> task);
    void executeTasks();

#ifdef _WIN32
    bool executeProcess(const std::string &command);
#endif

private:
    std::queue<std::unique_ptr<Task>> taskQueue;
};

#endif