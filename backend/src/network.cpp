#include "network.hpp"

#define PORT 8080

int main() 
{
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    std::cout << "Waiting for connection...\n";
    client_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (client_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Send data (example: sending object positions)
    const char* data = "10.5 20.3 30.7"; // Example 3D position
    send(client_socket, data, strlen(data), 0);
    
    std::cout << "Data sent: " << data << std::endl;
    
    // Cleanup
    close(client_socket);
    close(server_fd);
    return 0;
}
