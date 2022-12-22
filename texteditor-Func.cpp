#include "texteditor-header.h"


//__________________________________________________________
int displaymenu()
{
    int i;
    cout << "\n Please choose one of these option :\n" << endl;
    cout<< "1- Add new text to the end of the file" << endl;
    cout<< "2- Display the content of the file" << endl;
    cout<< "3- Empty the file" << endl;
    cout<< "4- Encrypt the file content" << endl;
    cout<< "5- Decrypt the file content" << endl;
    cout<< "6- Merge another file" << endl;
    cout<< "7- Count the number of words in the file" << endl;
    cout<< "8- Count the number of characters in the file" << endl;
    cout<< "9- Count the number of lines in the file" << endl;
    cout<< "10- Search for a word in the file" << endl;
    cout<< "11- Count the number of times a word exists in the file" << endl;
    cout<< "12- Turn the file content to upper case" << endl;
    cout<< "13- Turn the file content to lower case" << endl;
    cout<< "14- Turn file content to 1st caps (1st char of each word is capital)" << endl;
    cout<< "15- Save" << endl;
    cout<< "16- Exit" << endl;
    cin >> i;
    return i;
}
//__________________________________________________________
void loadfile2(ofstream& file)
{
    y1:
    char filename[100];
    cout << "Please enter your target file name: " << endl;
    cin >> filename;

    file.open(filename, ios::app);
    if (file.fail())
    {
        cout << "Sorry.  I couldn't open this file " << endl;
        goto y1;
    }
    else
    {
        cout << "File open successfully " << endl;
    }
}
//__________________________________________________________
void loadfile(ifstream& file,string filename)
{
    y1:
    file.open(filename);
    if (file.fail())
    {
        cout << "Sorry.  I couldn't open this file " << endl;
        goto y1;
    }
    else
    {
        cout << "File open successfully " << endl;
    }
}
//__________________________________________________________
int no_of_words(ifstream& file, string x)
{
    int y =0;
    while (!file.eof())
    {
        file >> x;
        y += 1;
    }
    return (y-1);
    file.close();
}
//__________________________________________________________
void display_file(ifstream& file)
{
        vector<string>text;
        char line[100];
        while (!file.eof())
        {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
        for (string line:text)
          cout<<line<<endl;
        file.close();
}
//__________________________________________________________
void empty_file(string file_name)
{
    ofstream file;
    file.open(file_name, ofstream::out | ofstream::trunc);
}
//__________________________________________________________
void enc_file(ifstream& file,string file_name)
{
    ofstream target;
    vector<string>text;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    for(int i=0 ;i<text.size();i++){
            for (int j=0;j<text[i].size();j++){
                 if (int (text[i][j])<=90){
                    text[i][j]=char(int((text)[i][j]-65+1)%26+65) ;
                 }
                 else{
                    text[i][j]=char(int((text)[i][j]-97+1)%26+97);
                 }
            }
    }
    target.open(file_name);
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    file.close();
    target.close();
}
//__________________________________________________________
void dec_file(ifstream& file , string file_name)
{
    vector<string>text;
    ofstream target;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    for(int i=0 ;i<text.size();i++){
            for (int j=0;j<text[i].size();j++){
                 if (int (text[i][j])<=90){
                    text[i][j]=char(int((text)[i][j]-65+(26-1))%26+65) ;
                        if(text[i][j]=='T'){
                        text [i][j]=' ';
                        }
                 }
                 else{
                    text[i][j]=char(int((text)[i][j]-97+(26-1))%26+97);
                    if(text[i][j]=='T'){
                        text [i][j]=' ';
                        }
                 }
            }
    }
         target.open(file_name);
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    file.close();
    target.close();
}
//__________________________________________________________
int no_of_characters(ifstream& file, char y)
{
    int z = 0;
    while (!file.eof())
    {
        file >> y;
        z += 1;
    }
    return (z-1);
    file.close();
}
//__________________________________________________________
void no_of_line(vector<string>& vec, ifstream& file)
{
    char line[100];
    while(!file.eof())
    {
        file.getline(line, 100, '\n');
        vec.push_back(line);
    }
    file.close();
}
//__________________________________________________________
void search_word (ifstream& file, string word)
{
    string search;
    cout << "Enter the word you want to search for " << endl;
    cin >> search;
    for(int i =0 ; i < search.size() ; i++ )
    {
        search[i] = tolower(search[i]);
    }

    while (!file.eof())
    {
        file >> word;
        for(int i =0 ; i < word.size() ; i++ )
        {
            word[i] = tolower(word[i]);
        }
        if (search == word)
        {
            cout << "Word was found in the file " << endl;
            break;
        }
        else if (file.eof())
        {
            cout <<  "Word was not found in the file " << endl;
        }
    }
    file.close();

}
//__________________________________________________________
void merge_files(ifstream& file, ofstream& target)
{
    char t[100];
    while (!file.eof())
    {
        file.getline(t, 100, '\n');
        target<< " " << t;
    }
    file.close();
    target.close();
}
//__________________________________________________________
void add_text(ofstream& file,string& add_text)
{
    cout << "Enter the text that you want to add "<< endl;
    cin.ignore();
    cin >> add_text;
    file << add_text << endl;
    file.close();
}
//__________________________________________________________
void to_lower(ifstream& file, string file_name)
{
    ofstream target;
    vector<string>text;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    for(int i=0 ;i<text.size();i++){
            for (int j=0;j<text[i].size();j++){
                text[i][j]=tolower(text[i][j]);
            }
    }
    target.open(file_name);
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    file.close();
    target.close();
}


//__________________________________________________________
void to_upper(ifstream& file, string file_name)
{
    ofstream target;
    vector<string>text;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    for(int i=0 ;i<text.size();i++){
            for (int j=0;j<text[i].size();j++){
                text[i][j]=toupper(text[i][j]);
            }
    }
    target.open(file_name);
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    file.close();
    target.close();
}
//__________________________________________________________
void to_upper_first(ifstream& file, string file_name)
{
    ofstream target;
    vector<string>text;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
     for(int i=0 ; i<text.size();i++){
        for(int j=0 ; j<text[i].size();j++){
            text [i][j] =tolower(text[i][j]);
            text [i][0] =toupper(text[i][0]);
        }
       }
        for(int i=0 ; i<text.size();i++){
        for(int j=0 ; j<text[i].size();j++){
            if (text [i][j] == ' '){
            text [i][j+1] =toupper(text[i][j+1]);
            }
       }
}
    target.open(file_name);
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    file.close();
    target.close();
}
//__________________________________________________________
void search_word_rep(ifstream& file)
{
    vector<string>text;
    char line[100];
    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
     char word[100];
       int re=0 , size_word;
       cout<<"Enter the word you want to search \n";
       cin>>word;
       size_word=string(word).size();
       for(int i=0 ; i<text.size() ;i++){
        for(int j=0 ; j<text[i].size();j++){
            if (tolower(text [i][j]) == tolower(word[0])&&tolower(text [i][(j+size_word)-1]) == tolower(word[size_word-1])){
                if(tolower(text [i][j+size_word-2]) == tolower(word[size_word-2])&&tolower(text [(i)][j+size_word-3]) == tolower(word[size_word-3])){
            re++;

            }
            }
        }
       }
       cout<<"The word "<<word<<" has repeated "<<re<<" times\n";
    file.close();

}
//__________________________________________________________
void save (vector <string>& text, string filename)
{
        ofstream target;
        char name [100];
        int choice;
        cout<<"Enter :\n 1. f you want to save to the existing file \n ";
        cout<<"2. if you want to save into new file\n";
        cin >> choice;
        if(choice==1){
            target.open(filename);
            for(int i=0 ;i< text.size();i++ ){
            target<<text[i];
            target<<'\n';
            }
        }
        else if(choice==2){
            cout<<"Enter the file name";
            cin>>name;
                ofstream target(name);
                for(int i=0 ;i< text.size();i++ ){
                    target<<text[i];
                    target<<'\n';
            }
        }
}
