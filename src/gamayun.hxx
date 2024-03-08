#ifndef gamayun_hxx
#define gamayun_hxx

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <stdexcept>
#include <sys/socket.h>
#include <netinet/in.h>
#include "response_http.hxx"

class Gamayun {

    public:
        
        int buffer;
        int PortForConnection;
        int ServerSocket, ClientSocket;
        struct sockaddr_in ServerAddress, ClientAddress;
        socklen_t ClientAddress_len = sizeof(ClientAddress);

        void handle_client() {

            char buffer[buffer];

            send(ClientSocket, ResponseHttp::callback().c_str(), ResponseHttp::callback().size(), 0);

            close(ClientSocket);
        }

        Gamayun( int PortForConnection ){

            this->PortForConnection = PortForConnection;

            this->buffer = ResponseHttp::callback().size() +1;

            ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

            if ( ServerSocket < 0 )
            {
                std::cout << "Error to inicialize socket\n";
            }

            ServerAddress.sin_family = AF_INET;
            ServerAddress.sin_addr.s_addr = INADDR_ANY;
            ServerAddress.sin_port = htons(PortForConnection);

            if ( bind(ServerSocket, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress)) < 0)
            {
                std::cerr << "Invalid Port\n";
            }

            if (listen(ServerSocket, 5) < 0)
            {
                std::cout << "Error to list connection\n";
            }
        }

        void Run()
        {
            while (true) {

                this->ClientSocket = accept(this->ServerSocket, (struct sockaddr *)&ClientAddress, &ClientAddress_len);

                if (this->ClientSocket < 0) 
                {
                    std::cout << "Error to accept connection\n";
                    continue;
                }

                std::cout << "New Connection Receive\n";

                handle_client();    
            }
            
            close(this->ServerSocket);
        }
};

#endif