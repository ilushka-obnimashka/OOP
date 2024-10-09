#include <iostream>
#include <map>
#include <set>
#include <string>


int main() {
    std:: cout << "HELLO";
    std:: map <char,int> letterFreq;

    std:: string tempString;
    int countWords = 0;
    while(std:: cin >> tempString) {

        ++countWords;
        std:: set <char> tempSet {tempString.begin(), tempString.end()};

        for (auto iter = tempSet.begin(); iter != tempSet.end(); iter++) {
            ++letterFreq[*iter];
        }

    }

    for (const auto& [letter, freq] : letterFreq) {
        if (freq == countWords) std:: cout << letter;
    }

}