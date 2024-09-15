#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Sentence;

class Word
{
private:
    string w;
    inline bool char_in_word(const char& c)     {
                                                    return w.find(c) != -1;
                                                }
    string find_n_erase(const string& sub)     {   
                                                    string tmp(this->w);
                                                    size_t pos = tmp.find(sub);
                                                    if(pos != -1)tmp.erase(pos, sub.size());
                                                    return tmp; 
                                                }
public:
    Word();
    Word(const string &in);
    Word(const char *in);
    Word(const char &in);
    Word(const  Word& in);

    Word &operator=(const char &rval);
    Word &operator=(const char *rval);
    Word &operator=(const string &rval);

    Word operator-(const char &rval);
    Word operator-(const char *rval);
    Word operator-(const string &rval);
    Word operator-(const Word &rval);

    Word &operator+=(const char &rval);
    Word &operator+=(const char *rval);
    Word &operator+=(const string &rval);

    Word operator+(const char &rval);
    Word operator+(const char *rval);
    Word operator+(const Word &rval);

    char operator[](const int &i);

    bool operator==(const Word& w);
    bool operator>(const Word& w);
    bool operator>=(const Word& w);
    bool operator<(const Word& w);
    bool operator<=(const Word& w);

    bool is_empty();
    static bool compare(const Word &w1, const Word &w2);
    friend ostream& operator<<(ostream& os, const Word& w);
    friend istream& operator>>(istream& is, Word& w);
    friend class Sentence;
};