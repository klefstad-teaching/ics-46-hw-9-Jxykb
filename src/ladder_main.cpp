#include "ladder.h"
#include "dijkstras.h"
#include <ostream>

int main(){
    /*
    cout << edit_distance_within("cat", "bat", 1) << endl;   
    cout << edit_distance_within("cat", "cats", 1) << endl; 
    cout << edit_distance_within("cat", "at", 1) << endl;   
    cout << edit_distance_within("cat", "dog", 2) << endl;   
    cout << edit_distance_within("cat", "catch", 1) << endl; 
    cout << edit_distance_within("charge", "chargersy", 2) << endl;
    */
    //1 is true 0 is false

    //expecting 1
    cout << is_adjacent("cog", "log") << endl; 
    cout << is_adjacent("cog", "cjg") << endl;
    cout << is_adjacent("cog", "cow") << endl;

    cout << is_adjacent("cog", "scog") << endl;
    cout << is_adjacent("cog", "csog") << endl;
    cout << is_adjacent("cog", "cosg") << endl;
    cout << is_adjacent("cog", "cogs") << endl;

    cout << is_adjacent("cog", "og") << endl;
    cout << is_adjacent("cog", "cg") << endl;
    cout << is_adjacent("cog", "cog") << endl;

    //expecting 0
    cout << is_adjacent("cog", "cty") << endl;
    cout << is_adjacent("cog", "zot") << endl;
    cout << is_adjacent("cog", "mtg") << endl;

    cout << is_adjacent("cog", "coggy") << endl;
    cout << is_adjacent("cog", "shcog") << endl;
    cout << is_adjacent("cog", "scsog") << endl;
    cout << is_adjacent("cog", "cgohg") << endl;
    cout << is_adjacent("cog", "cohgj") << endl;
    cout << is_adjacent("cog", "cogyu") << endl;

    cout << is_adjacent("cog", "c") << endl;
    cout << is_adjacent("cog", "o") << endl;
    cout << is_adjacent("cog", "g") << endl;

    return 0;
}