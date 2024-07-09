# File Encryptor

File Encryptor is a C++ application that allows users to encrypt and decrypt files in a specified directory.

## Features

- Recursive directory traversal
- File encryption and decryption
- Command-line interface for user input
- Process management for handling multiple files

## Prerequisites

- C++17 compatible compiler (e.g., GCC, Clang, MSVC)
- Make (for building the project)

## Building the Project

To build the project, navigate to the project directory and run:

This will create two executables:
- `encrypt_decrypt`: The main application
- `cryption`: A standalone encryption/decryption tool

## Usage

### Main Application

Run the `encrypt_decrypt` executable:

You will be prompted to enter:
1. The directory path containing files to encrypt/decrypt
2. The action to perform (encrypt or decrypt)

### Standalone Cryption Tool

Run the `cryption` executable:

(Note: Additional usage instructions for the standalone tool may be needed)

## Project Structure

- `main.cpp`: Entry point for the main application
- `src/app/processes/`: Contains process management code
- `src/app/fileHandling/`: Handles file I/O operations
- `src/app/encryptDecrypt/`: Contains encryption and decryption logic

## Configuration

The encryption key is stored as an environment variable. Make sure to set this variable before running the application.

## Cleaning the Project

To remove all built files: make clean
