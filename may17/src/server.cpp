//Program to create a server to connect with client
#include <iostream>
#include "../include/func.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
using namespace std;
int main(int argc, char* argv[]){
        createShm();
        int sock = createSocket("0.0.0.0",8029);
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
         //accept all clients and create new process for each client

        while(1){
        int client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if(client_sock < 0){
            perror("accept error");
	    exit(EXIT_FAILURE);
            //return -1;
        }
        std::cout << "client successfully accepted" << std::endl;
        int clientsNO = writetoShm();
        cout << "No. of clients connected : " << clientsNO << endl;

        //fork a new process
        pid_t pid = fork();
        if(pid < 0){
            perror("fork error");
	    exit(EXIT_FAILURE);
           // return -1;
        }
	//initiation of child process
        else if(pid == 0){
            close(sock);
            char buf[1024];
            while(1){
                memset(buf, 0, sizeof(buf));
                int len = recv(client_sock, buf, sizeof(buf), 0);
                if(len < 0){
                    perror("recv error");
		    exit(EXIT_FAILURE);
                    //return -1;
                }
                else if(len == 0){
                    std::cout << "client closed" << std::endl;
                    break;
                }
                else{
                    std::cout << "Message received from client: " << buf << std::endl;
                    memset(buf,0,sizeof(buf));
                    std::cout << "Type message for client: ";
                    std::cin.getline(buf,sizeof(buf));
                    send(client_sock, buf, strlen(buf), 0);
                }
            }
            close(client_sock);
            exit(0);
        }
        else{
            close(client_sock);
        }//This is parent process
    }
    destroyShm();
    close(sock);
}
