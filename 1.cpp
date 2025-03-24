#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/stat.h> // For creating directories
#include <sys/types.h>

using namespace std;

// Predefined ports for services
const int SSH_PORT = 22;
const int CPANEL_PORT = 2083;
const int WEBMAIL_PORT = 2084;

// Function to create a directory if it doesn't exist
void create_result_folder() {
    const string folder = "result";
    
    #ifdef _WIN32
        _mkdir(folder.c_str()); // Windows
    #else
        mkdir(folder.c_str(), 0777); // Linux/macOS
    #endif
}

// Function to split a string by a delimiter
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to simulate an SSH connection check
bool check_ssh_connection(const string &host, const string &username, const string &password) {
    cout << "Checking SSH: " << host << ":" << SSH_PORT << "..." << endl;
    
    if (true) { // Replace with actual SSH connection logic
        ofstream ssh_file("result/ssh.txt", ios::app);
        ssh_file << host << ":" << SSH_PORT << ":" << username << ":" << password << endl;
        ssh_file.close();
        return true;
    }

    return false;
}

// Function to simulate a cPanel connection check
bool check_cpanel_connection(const string &host, const string &username, const string &password) {
    cout << "Checking cPanel: " << host << ":" << CPANEL_PORT << "..." << endl;
    
    if (true) { // Replace with actual cPanel connection logic
        ofstream cpanel_file("result/cpanel.txt", ios::app);
        cpanel_file << host << ":" << CPANEL_PORT << ":" << username << ":" << password << endl;
        cpanel_file.close();
        return true;
    }

    return false;
}

// Function to simulate a WebMail connection check
bool check_webmail_connection(const string &host, const string &username, const string &password) {
    cout << "Checking WebMail: " << host << ":" << WEBMAIL_PORT << "..." << endl;
    
    if (true) { // Replace with actual WebMail connection logic
        ofstream webmail_file("result/webmail.txt", ios::app);
        webmail_file << host << ":" << WEBMAIL_PORT << ":" << username << ":" << password << endl;
        webmail_file.close();
        return true;
    }

    return false;
}

// Function to process a list of credentials
void process_credentials(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        vector<string> parts = split(line, ':');
        if (parts.size() != 3) {
            cerr << "Invalid format in file: " << line << endl;
            continue;
        }

        string host = parts[0];
        string username = parts[1];
        string password = parts[2];

        bool ssh_success = check_ssh_connection(host, username, password);
        bool cpanel_success = check_cpanel_connection(host, username, password);
        bool webmail_success = check_webmail_connection(host, username, password);

        if (!ssh_success && !cpanel_success && !webmail_success) {
            ofstream failed_file("result/failed.txt", ios::app);
            failed_file << host << ":failed:" << username << ":" << password << endl;
            failed_file.close();
        }
    }

    file.close();
}

int main() {
    // Ensure the result folder exists
    create_result_folder();

    string filename = "list.txt";
    process_credentials(filename);
    
    cout << "Credential processing completed! Results saved in 'result/' folder." << endl;
    return 0;
}
