#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

// MinGW does NOT auto-link from pragma, so this is optional but harmless
#pragma comment(lib, "Ws2_32.lib")

//Note : Need to manually link ws2_32 in Project -> Build Options -> Linked Options -> Add -> ws2_32
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
    std::cout << "Winsock status: " << wsaData.szSystemStatus << std::endl;

    WSACleanup();
    return 0;
}
