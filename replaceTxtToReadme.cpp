#include<iostream>
#include<string>
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
string replace(string s){

    string word = "";
    string newString = "";
    int start = 0;
    int end = 0;
    for(int i = 0; i<s.size(); i++){

        if(s[i] == '<'){
            word = "";   
            start  = i;
        }
        
        else if(s[i] == '>'){
            end = i;
            
            string replacingWord = convertWords[index(word)];
            // cout << "Replacing the word : "<<word<< " with the word : "<<replacingWord << endl;
            // newString = "";
            newString +=  replacingWord;
            start = 0;
            end = 0;
            word = "";
        }
        else if(start == 0 && end == 0){
            newString += s[i];
        }
        
        word+=s[i];
        
    }
    return newString;
}

int main(){
    string s = "HI this is the file <head>: <cpp> <description> <head><cpp>";
    cout <<"******"<< s << endl;
    s = replace(s);
    cout <<"----------------"<< s << endl;
}