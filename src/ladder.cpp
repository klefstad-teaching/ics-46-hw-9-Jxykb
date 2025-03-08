#include "ladder.h"
#include <fstream>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void error(string word1, string word2, string msg){
    cerr << "Error: " << word1 << " + " << word2 << " " << msg;
}



bool edit_distance_within(const string &str1, const string &str2, int d){
    int len1 = str1.length();
    int len2 = str2.length();
    
    if(abs(len1 - len2) > d){
        return false;
    }

    int numVariations  = 0;
    
    if (len1 == len2) {  
        // Case 1: Same length -> Check for d differences
        for (int i = 0; i < len1; i++) {
            //found a difference
            if (str1[i] != str2[i]) {
                ++numVariations;   
                if (numVariations > d){
                    return false;  // More than d differences
                }
            }
        }
        return true;  // True if exactly d or less differences
    }
    //atp we know the length between the two string is greater than 1 and less than d
    int i = 0;
    int j = 0;

    while(i < len1 && j < len2){
        if(str1[i] != str2[j]){
            ++numVariations;
            if(numVariations > d){
                return false;
            }
            if (len1 > len2) {
                i++; 
            } else {
                j++; 
            }
        }else{
            ++i;
            ++j;
        }
    }
    //accounts for any remaining charatcers
    numVariations += abs((len1 - i) - (len2 - j));
    return numVariations <= d;
}

bool is_adjacent(const string &word1, const string &word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();
        for(const string & word : word_list){
            if(is_adjacent(last_word, word)){
                if(visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }        
            }
        } 
    }
    return {};
}

void load_words(set<string> & word_list, const string & filename){
    string tmp;
    fstream in(filename);
    if(!in){
        error("", "", "Cannot open file");
    }
    while(in >> tmp){
        word_list.insert(tmp);
    }
}

void print_word_ladder(const vector<string> &ladder){
    if (ladder.empty()) {
        cout << "No word ladder found.\n";
    }else{
        cout << "Word ladder found: ";
        for(size_t i = 0; i < ladder.size(); ++i){
            cout << ladder[i] << " ";
        }
        cout << "\n";
    }
}


#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder(){

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}