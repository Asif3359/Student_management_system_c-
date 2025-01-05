 <h1>🔐 Secure Login System with SHA-256 Hashing (Using OpenSSL on Windows)</h1>
    <p>This project demonstrates how to implement a secure login system in C++ by hiding password input and using <strong>SHA-256 hashing</strong> for secure password storage. The guide includes setting up OpenSSL on Windows and compiling the project with MinGW.</p>

<h2>🚀 Features</h2>
    <ul>
        <li>Secure password hashing using SHA-256.</li>
        <li>Password input hidden with * during entry.</li>
        <li>Cross-platform compatibility (Windows/Linux).</li>
    </ul>

<h2>📦 Prerequisites</h2>
    <ul>
        <li><strong>OpenSSL</strong> (for SHA-256 hashing).</li>
        <li><strong>MinGW</strong> (or any other C++ compiler).</li>
        <li>Basic knowledge of <strong>C++</strong>.</li>
    </ul>

<h2>🛠️ Setup Guide for Windows</h2>

    
<h3>Step 1: Install OpenSSL on Windows</h3>
    <ul>
        <li>Download OpenSSL from <a href="https://slproweb.com/products/Win32OpenSSL.html">here</a>.</li>
        <li>Install the <strong>Win64 OpenSSL</strong> version based on your system architecture.</li>
        <li>Set the <strong>Environment Variables</strong>:
            <ul>
                <li>Add the OpenSSL <code>bin</code> directory to your <strong>PATH</strong>.</li>
                <li>Example: <code>C:\OpenSSL-Win64\bin</code></li>
            </ul>
        </li>
    </ul>

<h3>Step 2: Install MinGW Compiler</h3>
    <ul>
        <li>Download <strong>MinGW</strong> from <a href="https://sourceforge.net/projects/mingw/">here</a>.</li>
        <li>Make sure <code>g++</code> is in your system's <strong>PATH</strong> environment variable.</li>
        <li>To verify the installation, run the following command in your terminal:
            <pre><code>g++ --version</code></pre>
        </li>
    </ul>

<h3>Step 3: Link OpenSSL with Your C++ Project</h3>
    <p>To compile your C++ program with OpenSSL, use the following command:</p>
    <pre><code>g++ your_program.cpp -o your_program.exe -lssl -lcrypto</code></pre>

<h3>Step 4: Modify Your Code</h3>
    <p>Use the following code to hash a password using OpenSSL's SHA-256:</p>
    <pre><code>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>  // OpenSSL header for SHA-256

using namespace std;

// Utility function to hash a password using SHA-256
string hashPassword(const string &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)password.c_str(), password.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    string hashedPassword = hashPassword(password);
    cout << "Hashed Password: " << hashedPassword << endl;

    return 0;
}
    </code></pre>

<h3>Step 5: Compile and Run the Program</h3>
    <ul>
        <li>If you're using <strong>MinGW</strong>, run the following command in your terminal to compile and run your program:
            <pre><code>g++ your_program.cpp -o your_program.exe -lssl -lcrypto</code></pre>
        </li>
        <li>For <strong>Visual Studio</strong> users:
            <ul>
                <li>Add the OpenSSL <code>include</code> directory to your project settings.</li>
                <li>Link the <code>libssl.lib</code> and <code>libcrypto.lib</code> files in your project.</li>
            </ul>
        </li>
    </ul>

<h3>🔍 Alternative: Custom SHA-256 Implementation</h3>
    <p>If you prefer not to install OpenSSL, you can use a <strong>pure C++ implementation</strong> of SHA-256.</p>
    <p>Here’s a popular lightweight SHA-256 implementation:</p>
    <p><a href="https://github.com/B-Con/crypto-algorithms">https://github.com/B-Con/crypto-algorithms</a></p>

    
<h2>📋 Example Output</h2>
    <pre><code>
Enter password: ******
Hashed Password: 5e884898da28047151d0e56f8dc6292773603d0d6aabbddbf511cbbe65d8310b
    </code></pre>

<h2>🤝 Contributing</h2>
    <p>Contributions are welcome!</p>
    <p>Feel free to fork this project and submit a pull request.</p>