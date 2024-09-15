#include <string>
#include <vector>
#include "word.h"
#include "sentence.h"

using namespace std;

Word::Word(){};
Word::Word(const string &in): w(in){if(w[w.size() -1] == '\"')w.pop_back();if(w[0] == '\"')w.erase(w.begin());};
Word::Word(const char* in):w(in){if(w[w.size() -1] == '\"')w.pop_back();if(w[0] == '\"')w.erase(w.begin());};
Word::Word(const char &in):w(1,in){if(w[w.size() -1] == '\"')w.pop_back();if(w[0] == '\"')w.erase(w.begin());};
Word::Word(const  Word  &in):w(in.w){if(w[w.size() -1] == '\"')w.pop_back();if(w[0] == '\"')w.erase(w.begin());};

Word& Word::operator=(const char& rval)   {w=rval;return *this;}; 
Word& Word::operator=(const char* rval)   {w=rval;return *this;};
Word& Word::operator=(const string& rval) {w=rval;return *this;};

Word Word::operator-(const char&rval)      {                        
                                                string str(1, rval); 
                                                return Word(this->find_n_erase(str));
                                            };
Word Word::operator-(const char*rval)      {  
                                                string str(rval); 
                                                return Word(find_n_erase(str));
                                            };
Word Word::operator-(const string& rval)   { 
                                                string str(rval); 
                                                return Word(find_n_erase(str));
                                            };
Word Word::operator-(const Word &rval)        {return Word(this->find_n_erase(rval.w));}     
Word& Word::operator+=(const char& rval)      {w+=rval;return *this;}; 
Word& Word::operator+=(const char* rval)      {w+=rval;return *this;};
Word& Word::operator+=(const string& rval)    {w+=rval;return *this;};

Word Word::operator+(const char& rval)        {string str(1,rval);return Word(w+str);};
Word Word::operator+(const char* rval)        {string str(rval);return Word(w+str);};
Word Word::operator+(const Word& rval)        {return Word(string(w+rval.w));};

char Word::operator[](const int& i)           {  int idx = (i < 0) ? (w.size() + i) : i;
                                                    idx = idx < 0 ? 0 : idx % w.size();
                                                    return w[idx];};

bool Word::operator==(const Word& w)            {return this->w.compare(w.w) == 0;};
bool Word::operator>(const Word& w)             {return this->w.compare(w.w) > 0;};
bool Word::operator>=(const Word& w)            {return this->w.compare(w.w) >= 0;}
bool Word::operator<(const Word& w)             {return this->w.compare(w.w) < 0;};
bool Word::operator<=(const Word& w)            {return this->w.compare(w.w) <= 0;}

bool Word::compare(const Word& w1, const Word& w2) {return w1.w.compare(w2.w) == 0;}
bool Word::is_empty()                           {return this->w.compare("\0") == 0;}
ostream& operator<<(ostream& os, const Word& w) {return os << w.w;}
istream& operator>>(istream& is, Word& w)       {return is >> w.w;}