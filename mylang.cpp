#include "word.h"
#include "sentence.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main(void){
Word w1;
Sentence s1, adverb;
for(int i = 3; i > 0; i--){adverb = adverb + Word("very") ;
};
w1 = Word("interesting") ;
s1 = Sentence(string("^Compilers are a^"))  + adverb + w1;
cout <<s1 + Word("topic") ;
}