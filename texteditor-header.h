#ifndef TEXTEDIROR_H
#define TEXTEDIROR_H


#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cctype>

using namespace std;

int displaymenu();
void display_file(ifstream& file);
void empty_file(string file_name);
void loadfile(ifstream& file, string filename);
void loadfile2(ofstream& file);
int no_of_words(ifstream& file, string x);
int no_of_characters(ifstream& file, char y);
void search_word (ifstream& file, string word);
void merge_files(ifstream& file, ofstream& target);
void no_of_line(vector<string>& vec, ifstream& file);
void add_text(ofstream& file,string& add_text);
void to_lower(ifstream& file , string file_name);
void to_upper(ifstream& file , string file_name);
void to_upper_first(ifstream& file , string file_name);
void search_word_rep(ifstream& file);
void enc_file(ifstream& file , string file_name);
void dec_file(ifstream& file , string file_name);
void save (vector <string>& text, string filename);



#endif