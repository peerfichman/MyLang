#pragma once 
#include <string.h>
#include <vector>
#include "word.h"

using namespace std;

class Sentence
{
    private:
        vector<Word> s;

    public:
        Sentence();
        Sentence(const string& s);
        Sentence(const Word& w);
        Sentence(const vector<Word>& v);
        Sentence(const Sentence& param);

        Sentence &operator=(const Sentence &rval);

        Sentence operator-(const Word &w);
        Sentence operator-(const char &c);
        Sentence operator-(const char* c);

        Sentence &operator+=(const Word &w);
        Sentence &operator+=(const Sentence &rval);
        
        Sentence operator+(const Word &w);
        Sentence operator+(const Sentence &s2);

        Word operator[](const int &i);

        bool operator==(const Sentence &s);
        bool operator>(const Sentence &s);
        bool operator>=(const Sentence &s);
        bool operator<(const Sentence &s);
        bool operator<=(const Sentence &s);
        

        bool is_empty();
        friend class Word;
        friend ostream &operator<<(ostream& os, const Sentence& s);
        friend istream &operator>>(istream& is, Sentence& s);

};