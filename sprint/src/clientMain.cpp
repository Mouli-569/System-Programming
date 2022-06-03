//program to execute client 
#include <client.h>
using namespace std;
int main(){
    while(1){
        string uname,passwd;
        Client client("127.0.0.1", 8088);//request connection with server using IP address and port number
        cout<<"Please enter your username: ";
        cin>>uname;//reading username
        cout<<"Please enter your password: ";
        cin>>passwd;//reading password
        //send username and password to server
        client.sendMessage((uname+" "+passwd).c_str());
        
        //receive message from server
        char* buffer = client.receiveMessage();
        if(buffer[0] == '1'){
            cout<<"Authentication successful!"<<endl;
            client.sync();
            break;
        }
        else{
            cout<<"Authentication failed!"<<endl;
        }
    }    
    return 0;
}
