//Program for displaying the name of the user when entering the user id
#include <iostream>
#include <string>
using namespace std;

class User//creating a class named User
{
	string userid;
	string username;
	//char userid[20];
	//char username[80];

	private://created a constructor as private
	User(){
		userid = " ";
		username = " ";
		this->username = username;
         	this->userid = userid;
	}
	vector<User>psu;
	int  readFileInfo ()
        {

              ifstream input;
              input.open("data.txt");
              if (!input.is_open())
              {
                    cout << "Unable to open data file " <<endl;
                    return 1;
              }
              string line;
              while(getline(input,line))
              {
                     int count =0;
                     stringstream ss(line);
                     string username;
                     string userid;
                     if(getline(ss,username,':'))
                        count++;
                     if(getline(ss,userid,':'))
                        count++;
                     if(count == 2)
                     {
                             if(username != ""&& userid != "")
                             {
                                    psu.push_back(User(username,userid));
                             }

                             else
                             {
                             cout<<"missing field occurs in document"<<endl;
                             }
                     }

              } // end of while line in file
              input.close();
              return 0;
          }
          string searchName(string tofindName)
          {
             for(auto User:psu)
             {
                  if(User.userid == tofindname)

                  {
                         return User.username;
                  }
             }
             return "not found";
          }
};

int main()
{
        string a="";
        string b="";
        User F(a,b);
        F.readFileInfo();
        string id;
        cout<<"Enter User ID"<<endl;
        cin>>id;
        cout<<F.searchName(id)<<"           "<<endl;
        return 0;
}
