#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
string tolower_for_str(string x){
    string y = x;
    for (int i = 0; i < x.size(); i++){
        y[i] = tolower(x[i]);
    }
    return y;
}

int main(){
    int x=0;
    vector<string>list_name;
    vector<float>list_score;
    vector<char>list_grade;
    ifstream source;
    source.open("name_score.txt");
    string textline;
    while (getline(source,textline)){
        char format[] = "%[^:]: %f %f %f";
        char name[100];
        float a,b,c;
        sscanf(textline.c_str(),format,name,&a,&b,&c);
        list_name.push_back(name);
        list_score.push_back(a);
        list_score.push_back(b);
        list_score.push_back(c);
        int sum = a+b+c;
        char grade;
        if(sum >= 80)grade = 'A';
        else if (sum >= 70 && sum <= 79)grade = 'B';
        else if (sum >= 60 && sum <= 69)grade = 'C';
        else if (sum >= 50 && sum <= 59)grade = 'D';
        else grade = 'F';
        list_grade.push_back(grade);
        x++;
    }
    while (true){
        string commandtext;
        cout << "Please input your command :";
        getline(cin,commandtext);

        if(commandtext == "exit") break;
        else if(commandtext.substr(0,6) == "grade "){
            string key = commandtext.substr(6,7);
            for (int i = 0; i < x; i++){
                if (list_grade[i] == key[0]){
                    cout << list_name[i] << "\n";
                }
            }
        }
        else if(commandtext.substr(0,5) == "name "){
            int end = commandtext.find_first_of(commandtext);
            string key = commandtext.substr(5,end);
            for (int i = 0; i > x; i++){
                if (list_name[i] == key){
                cout << list_name[i] << "'s grade = " << list_grade[i];
                }  
            }   
        }else{
            cout << "Invalid command." << "\n";
        }
        
            
        
    }
    
    return 0;
}

