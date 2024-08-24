#include<iostream>
#include<string>
#include <fcntl.h> //for open() of a file 
#include <unistd.h> // for read , close() and other function
#include<stdlib.h>  //for exiting a file ;
#include <bits/stdc++.h>

//in readme file link is like : [appeartext](link);
using namespace std;

//for me the <> work as the replacing bracket so like
//<head> : ## 

//first is empty so if no word matches or error then it will return the empty word;
string reservedWords[]={"","head","description","cpp","bash","python","link"};
string convertWords[] = {"","##","###","```cpp","```bash","```python","[]()"};

int index(string word){

    string newWord;
    cout << "The function index is called for the word : "<<word << endl;
    
    for(int i = 1 ; i<word.size(); i++){
        newWord+=word[i];
    }
    
    for(int i = 0;i<7; i++){
        if(newWord == reservedWords[i]){
            
            return i;
        }
    }
    return 0;
}

//This will replace the word 
#include<iostream>
#include<string>
#include <fcntl.h> //for open() of a file 
#include <unistd.h> // for read , close() and other function
#include<stdlib.h>  //for exiting a file ;
#include <bits/stdc++.h>
#include <sys/stat.h> // For fstat()
#include <fstream>
//in readme file link is like : [appeartext](link);
using namespace std;

//for me the <> work as the replacing bracket so like
//<head> : ## 

//first is empty so if no word matches or error then it will return the empty word;
string reservedWords[]={"","head","description","cpp","bash","python","link"};
string convertWords[] = {"","##","###","```cpp","```bash","```python","[]()"};

int index(string word){

    string newWord;
    cout << "The function index is called for the word : "<<word << endl;
    
    for(int i = 1 ; i<word.size(); i++){
        newWord+=word[i];
    }
    
    for(int i = 0;i<7; i++){
        if(newWord == reservedWords[i]){
            return i;
        }
    }
    return 0;
}

//This will replace the word 
string replace(string s){

    string word = "";
    string newString = "";
    int start = 0;
    int end = 0;
    bool isZero = false;
    for(int i = 0; i<s.size(); i++){
        // cout << i<< " ........... " << start <<"..."<<end << "........."<< ".......... "<<word<< "........... "<<endl;
        if(s[i] == '<'){
            word = "";
            if(i == 0){
                start = 0;
                isZero = true;
            }   
            else{
                start  = i;
            }
            
        }
        
        else if(s[i] == '>'){
            end = i;
            
            string replacingWord = convertWords[index(word)];
            // cout << "Replacing the word : "<<word<< " with the word : "<<replacingWord << endl;
         
            newString +=  replacingWord;
            start = 0;
            end = 0;
            isZero = false;
            word = "";
        }
        else if(start == 0 && end == 0 && isZero != true){
            newString += s[i];
            // cout << "###############################"<<newString<<endl;
        }
        
        word+=s[i];
        
    }
    return newString;
}

int main(){
    int fd = open("./a.txt",O_RDONLY);
    if(fd < 0){
        cerr << "Error opening the file "<<endl;
    }

    fstream file("./a.txt",ios::in|ios::out);

    fstream newFile("readme.md",ios::out);
    string line;
    while(getline(file,line)){
        cout << "....................."<<line << endl;
        line = replace(line);
        cout << "#############"<<line << endl;
        newFile << line << endl;
    }

    close;
    file.close();
    newFile.close();

    fstream b("./b.txt",ios::in);
    string l;
    while(getline(b,l)){
        cout << l << endl;
    }
}

int main(){
    string s = " <head> include <iostea,> <cpp> <description>";
    cout <<"******"<< s << endl;
    s = replace(s);
    cout <<"----------------"<< s << endl;
}