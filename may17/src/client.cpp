//This program creates a TCP client and connects with TCP server
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<iostream>

int main(int argc,char* argv[]){
        /*if(argc != 2){
                std::cout << "usage: ./tcp_client <PORTNO>" << std::endl;
                return -1;
        }*/
        const char* port = "8029";
        int portno = atoi(port);

        int socketid = socket(AF_INET,SOCK_STREAM,0);
        if(socketid==-1){
                std::cout<<"Socket creation failed"<<std::endl;
                return -1;
        }//creating socket
        std::cout << "Socket creation successful" << std::endl;

        struct sockaddr_in serveraddr;//creating server address
        memset(&serveraddr,0,sizeof(serveraddr));

        //set the server address
        serveraddr.sin_family=AF_INET;
        serveraddr.sin_port=htons(portno);
        serveraddr.sin_addr.s_addr= inet_addr("127.0.0.29");

        int connect_status = connect(socketid,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
        if(connect_status==-1){
                std::cout<<"Connection failed"<<std::endl;
                return -1;
        }//creating connection with server
        std::cout << "Connection successful" << std::endl;

        std::cout << "Type a message for the server : ";//sending message to server
        const char* message;
        std::string m;
        getline(std::cin,m);
        message = m.c_str();
        ssize_t send_status = send(socketid,message,strlen(message),0);
        if(send_status==-1){
                std::cout<<"Message sending failed"<<std::endl;
                return -1;
        }
        std::cout << "Message sent successfully" << std::endl;

        while(1){
        char buffer[256];//creating buffer for storing message
        memset(buffer,0,sizeof(buffer));//clearing the buffer

        int len=sizeof(serveraddr);//Receiving message from server
        ssize_t receive_status = recv(socketid,buffer,256,0);
        if(receive_status==-1){
                std::cout<<"Message receiving failed"<<std::endl;
                return -1;
        }
        else if(receive_status==0){
                std::cout<<"Server closed the connection"<<std::endl;
                break;
        }
        std::cout << "Message received successfully" << std::endl;

        std::cout<<"Message received from server: "<<buffer<<std::endl;

        if(strcmp(buffer,"bye")==0)
        break;

        std::cout << "Enter the message to be sent to the server : ";//For sending message to client
        const char* message;
        std::string m;
        getline(std::cin,m);
        message = m.c_str();
        ssize_t send_status = send(socketid,message,strlen(message),0);
        if(send_status==-1){
                std::cout<<"Message sending failed"<<std::endl;
                return -1;
        }
        std::cout << "Message sent successfully" << std::endl;
        if(strcmp(message,"bye")==0)
        break;
        }
        close(socketid);//Closure of socket after terminated
}
