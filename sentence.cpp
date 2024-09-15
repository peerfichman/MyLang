#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include "sentence.h"
#include "word.h"

using namespace std;
                                              
#define MISMACH(a,b)  mismatch(a.begin(), a.end(), b.begin(),b.end(),Word::compare);

Sentence:: Sentence():s(){};
Sentence:: Sentence(const Word& w):s({w}){};
Sentence:: Sentence(const string& s){vector<Word> v; int pos; stringstream ss(s);string w;
                                    while (ss >> w) {
                                        if(w[w.size() -1] == '^')w.pop_back();if(w[0] == '^')w.erase(w.begin());
                                        v.push_back(Word(w));};
                                    this->s = v; };

// Sentence:: Sentence(const Word &w):s(1,w){};
Sentence:: Sentence(const vector<Word>& v):s(v){};
Sentence:: Sentence(const Sentence& param): s(param.s){};

Sentence& Sentence::operator=(const Sentence &rval){ s.resize(rval.s.size());
                                                     s=rval.s; return *this;};

Sentence Sentence::operator-(const Word &w)     {
                                                    Sentence tmp(s);
                                                    auto r = find(tmp.s.begin(), tmp.s.end(), w);
                                                    if (r != tmp.s.end()) tmp.s.erase(r);
                                                    return tmp;
                                                }
Sentence Sentence::operator-(const char &c)     {
                                                    Sentence tmp(s);
                                                    for (auto &word : tmp.s)
                                                    if (word.char_in_word(c)){word = word - c; break;}
                                                    return tmp;
                                                }
Sentence Sentence::operator-(const char* c)     {
                                                    Sentence tmp(s);
                                                    for (auto &word : tmp.s)
                                                    if (word.char_in_word(*c)){word= word - *c; break;}
                                                    return tmp;
                                                }
Sentence Sentence::operator+(const Word& w)     {vector<Word> r(s); r.push_back(w); return Sentence(r);}
Sentence Sentence::operator+(const Sentence& s2){vector<Word> r(s); r.insert(r.end(), s2.s.begin(), s2.s.end()); return Sentence(r);}
bool Sentence::operator==(const Sentence &s)    {return equal(this->s.begin(),this->s.end(), s.s.begin(), s.s.end(), Word::compare);}
bool Sentence::operator>(const Sentence &s)     {   
                                                    auto mispair = MISMACH(this->s,s.s)
                                                    if(mispair.first == this->s.end()) return false;
                                                    else if(mispair.second == s.s.end()) return true;
                                                    else return mispair.first > mispair.second;
                                                }
bool Sentence::operator<(const Sentence &s)     {
                                                    auto mispair = MISMACH(this->s,s.s)
                                                    if(mispair.first == this->s.end()) return true;
                                                    else if(mispair.second == s.s.end()) return false;
                                                    else return mispair.first < mispair.second;
                                                }
bool Sentence::operator>=(const Sentence &s)    {return *this > s || *this == s;}
bool Sentence::operator<=(const Sentence &s)    {return *this < s || *this == s;}

Word Sentence::operator[](const int &i)         {return s[i];};
bool Sentence::is_empty()                       {return s.size() == 0;}

ostream &operator<<(ostream& os, const Sentence& s)  {
                                                        for(auto w : s.s) os << w << string(" ");
                                                        return os;
                                                    }
istream &operator >>(istream& is, Sentence& s)  {
                                                        string str;is >> str;s = Sentence(str);return is;
                                                }