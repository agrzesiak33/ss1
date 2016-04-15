/* 
 * File:   main.cpp
 * Author: Alex Grzesiak
 *Excersize: 1
 *Mat #: 15-717-879
 *
 * Created on September 21, 2015, 10:40 PM
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct employee {
        string lastName;
        string firstName;
        string salary;
        string age;
        string clearanceLevel;
    };    
    
//Function the std::sort uses to sort the employees
bool sortBySalary(const employee &lhs, const employee &rhs){                   
    return lhs.salary<rhs.salary;
}

int main( int argc, char* argv[] )
{
	cout<<"1";
    string line, temp, result;			
    int employeeTrait;	
    int personCounter=0;	
    vector<employee> employeeDatabase;      
    
    ifstream  readFile(argv[1]);                                                
    if(readFile.is_open()){
        while ( getline (readFile, line)){
            employeeTrait=0;
            int ll= line.length();
	    	for(int i=0; i<=ll;i++){
                    //if the character isn't a space or the end of the line
                    //the char gets appended to the end of the temp string
                    if((line[i]!=' ' )&&line[i]!=NULL){                          
                        temp.push_back(line[i]);
                    }
                    else{
                        //Switch based on if temp is last name, first name, ect.]
                        switch(++employeeTrait){                                  
                            case 1:
                                employeeDatabase.push_back(employee());
                                employeeDatabase[personCounter].lastName=temp;
                                temp="";
                                break;
                            case 2:
                                employeeDatabase[personCounter].firstName=temp;
                                temp="";
                                break;
                            case 3:
                                employeeDatabase[personCounter].salary=temp;
                                temp="";
                                break;

                            case 4:
                                employeeDatabase[personCounter].age=temp;
                                temp="";
                                break;
                            case 5:
                                employeeDatabase[personCounter].clearanceLevel=temp;
                                temp="";
                                break;
                            default:
                                break;
                        }
                    }
            }
            personCounter++;    
        }
    }
    readFile.close();
    sort(employeeDatabase.begin(),employeeDatabase.end(),sortBySalary);
    vector<employee>::iterator mEI;
    ofstream output_file;
    output_file.open("sorted_db.txt");
    int i=0;
    for(mEI=employeeDatabase.begin();mEI != employeeDatabase.end();mEI++){ 
        if(mEI->age>"10"){
            output_file << mEI->lastName << " " << mEI->firstName <<" " 
                    << mEI->salary<< " " << mEI->age << " " 
                    << mEI->clearanceLevel<<endl; 
        }
    }
    output_file.close();

}
