#include <iostream>
#include <fstream>
#include <sstream> //treat strings like streams
using namespace std;
int main(int argc, char *argv[]){

    ifstream inFile;
    string data;
    inFile.open (argv[1]);

    if(inFile.is_open())
    {
        cout << "File Opened" <<endl;
        while(getline(inFile, data))
        {
            cout << data <<endl;
            stringstream ss(data);
            string name;
            string strAge;
            int age;
            ss >> name;
            ss >> strAge;

            age=stoi(strAge);
            cout << "Name: " << name<< endl;
            cout << "Age: " <<age <<endl;
        }//while
    }//for

}//main
