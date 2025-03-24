# Multi-Checker

This C++ program processes a list of credentials from a file and checks for SSH, cPanel, and WebMail access. The results are stored in a `result/` directory.

## Features
- Reads credentials from `list.txt` (format: `host:username:password`).
- Simulates checking:
  - **SSH** (Port 22)
  - **cPanel** (Port 2083)
  - **WebMail** (Port 2084)
- Saves successful checks to respective result files.
- Logs failed attempts in `result/failed.txt`.

## Installation & Compilation
### Prerequisites
- A C++ compiler (`g++` recommended)
- Standard C++ libraries

### Compile the Program
```sh
g++ -o credential_checker 1.cpp
```

## Usage
1. Create a `list.txt` file with credentials in the format:
   ```
   example.com:user1:password123
   myserver.net:admin:securepass
   ```
2. Run the program:
   ```sh
   ./credential_checker
   ```
3. Results will be saved in the `result/` folder:
   - `result/ssh.txt`
   - `result/cpanel.txt`
   - `result/webmail.txt`
   - `result/failed.txt`

## Notes
- The program currently **simulates** connection checks.
- To implement actual checks, modify the functions:
  - `check_ssh_connection`
  - `check_cpanel_connection`
  - `check_webmail_connection`
- Ensure you have permission to test credentials legally.

## Disclaimer
⚠️ **Use this tool responsibly. Unauthorized access to systems is illegal.** This project is for educational purposes only.
