#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <ncurses.h>
using namespace std;

vector<string> splitByChar(string str, char ch) {
	string substr = "";
	vector<string> vec;
	for(int x = 0; x < str.size(); x++) {
		if(str[x] == ch) {
			vec.push_back(substr);
			substr = "";
		} else {
			substr.push_back(str[x]);	
		}
	}
	vec.push_back(substr);
	return vec;
}

int main() {
	string input = "";
	string line1 = "";
	char* value1 = new char[50];
	char* value2 = new char[50];

	while(input.compare("exit") && input.compare("quit")) {
		cin >> input;
		if(!input.compare("remove")) {
			cin >> value2;
			remove(value2);
		} else if(!input.compare("rename")) {
			cin >> value1;
			cin >> value2;
			rename(value1, value2);
		} else if(!input.compare("rmdir")) {
			cin >> value1;
			rmdir(value1);
		} else if(!input.compare("echo")) {
			cin.ignore();
			getline(cin, line1);
			if(line1[0] == '"') {
				int i = 1;
				string line2 = "";
				for(; line1[i] != '"' && i < line1.length(); i++) {
					line2.push_back(line1[i]);
				}
				i+=2;
				if(i < line1.length()) {
					string filename = "";
					filename = line1.substr(i, line1.length() - i);
					ofstream file(filename);
					if(file.is_open()) {
						file << line2;
						file.close();
					} else {
						cout << "Unable to open file!" << endl;
					}
				} else {
					cout << line2 << endl;
				}
			}		
		} else if(!input.compare("out")) {
			cin.ignore();
			getline(cin, line1);
			vector<string> inputs = splitByChar(line1, ' ');
			bool lineByLine = false;
			int index = 0;
			if(!inputs[0].compare("-l")) {
				lineByLine = true;
				index = 1;
			}
			while(index < inputs.size()) {
				ifstream file(inputs[index]);
				string str2 = "";
				while(!file.eof()) {
					getline(file, str2);
					cout << str2 << endl;
					if(lineByLine) {
						getch();						
					}
				}
				index++;
				if(index < inputs.size()) {
					cout << "Press a key to continue viewing next file.\n" << endl;
					getch();
				}
				file.close();
			}
			cout << "All files displayed." << endl;
		} else if(!input.compare("zip")) {
			cin >> value1;
			cin >> value2;
			string cmd = "tar cvf ";
		    cmd	+= value1;
			cmd += " ";
		    cmd	+= value2;
			system(cmd.c_str());			
		} else if(!input.compare("unzip")) {
			cin >> value1;
			string cmd = "tar xvf ";
			cmd += value1;
			system(cmd.c_str());			
		}
	}	
	delete[] value1;
	delete[] value2;
	return 0;
}
