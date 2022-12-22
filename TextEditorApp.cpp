// FCI – Programming 1 – 2022 - Assignment 4
// Program Name: text editor application
// Last Modification Date: 20/5/2022
// Yousef ahmed : 20210461 and Group A 
// Mohamed ahmed : 20211075 and Group A 
// Yara salah : 20210448 and Group A 

#include "texteditor-header.h"
#include "texteditor-Func.cpp"

int main()
{

    ifstream datafile;
    ofstream targetfile;
    string token;
    char character;
    int choice;
    vector<string> text;
    char filename[100];
    cout << "Please enter your data file name: " << endl;
    cin >> filename;



    while(choice != 16)
    {
        choice = displaymenu();
        if (choice == 1)
        {
            loadfile(datafile,string(filename));
            loadfile2(targetfile);
            add_text(targetfile, token);
            datafile.close();
        }
         if (choice == 2)
        {
            loadfile(datafile,string(filename));
            display_file(datafile);
        }
         if (choice == 3)
        {
            loadfile(datafile,string(filename));
            empty_file(string(filename));
            datafile.close();
        }
         if (choice == 4)
        {
            loadfile(datafile,string(filename));
            enc_file(datafile,string (filename));
        }
         if (choice == 5)
        {
            loadfile(datafile,string(filename));
            dec_file(datafile,string (filename));
        }

        else if (choice == 6)
        {
            loadfile(datafile,string(filename));
            loadfile2(targetfile);
            merge_files(datafile, targetfile);
        }
        else if (choice == 7)
        {
            loadfile(datafile,string(filename));
            cout << "The number of word in the file is "<<  no_of_words(datafile, token) <<endl;
            datafile.close();
        }
        else if (choice == 8)
        {
            loadfile(datafile,string(filename));
            cout << "The number of characters in the file is "<<  no_of_characters(datafile, character) <<endl;
            datafile.close();
        }
        else if (choice == 9)
        {
            loadfile(datafile,string(filename));
            no_of_line(text, datafile);
            cout << "the number of lines in this file is " << (text.size()-1) << endl;
        }
        else if (choice == 10)
        {
            loadfile(datafile,string(filename));
            search_word(datafile,token);
        }
         else if (choice == 11)
        {
            loadfile(datafile,string(filename));
            search_word_rep(datafile);
        }
         else if (choice == 12)
        {
            loadfile(datafile,string(filename));
            to_upper(datafile,string (filename));
        }
           else if (choice == 13)
        {
            loadfile(datafile,string(filename));
            to_lower(datafile, string(filename));
        }
         else if (choice == 14)
        {
            loadfile(datafile,string(filename));
            to_upper_first(datafile,string (filename));
        }
         else if (choice == 15)
        {
            loadfile(datafile,string(filename));
            char line[100];
            while (!datafile.eof())
            {
                datafile.getline(line, 100, '\n');
                text.push_back(string(line));
            }
            save (text,string(filename));
            datafile.close();
        }

        else if (choice == 16)
        {
            cout << " " << endl;
        }
        else
        {
            cout << "Please choose number from 1 to 16 "<< endl;
        }
    }
}

