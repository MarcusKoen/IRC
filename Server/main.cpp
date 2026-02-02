#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

// MinGW does NOT auto-link from pragma, so this is optional but harmless
#pragma comment(lib, "Ws2_32.lib")

int main()
{
    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    std::cout << "Winsock initialized successfully!" << std::endl;

    WSACleanup();
    return 0;
}
