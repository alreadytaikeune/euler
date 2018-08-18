#include <iostream>
#include <fstream>
#include <sstream>      // std::stringstream
#include <bitset>
#include <assert.h>
using namespace std;
typedef unsigned long long ull;

int bits[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
ull ONE = 1ULL;
ull ZERO = 0ULL;

template<typename T> int hammingSum(T n){
    int out = 0, mask = (1 << 4)-1;
    while(n>0){
        out += bits[n & mask];
        n>>=4;
    }      
    return out;
}

inline unsigned short getMsbPos(short i){
    unsigned short t, s=0;
    t = (i >= (1 << 8)) << 3; i >>= t;
    s = (i >= (1 << 4)) << 2; i >>= s; t |= s;
    s = (i >= (1 << 2)) << 1; i >>= s; t |= s;
    return t | (i >> 1);
}

inline unsigned short getLsbPos(short i){
    unsigned short t, s=0;
    t = ((i & ((1 << 8)-1) << 8) == i) << 3; i = (i >> t) & ((1<<8)-1);
    s = ((i & ((1 << 4)-1) << 4) == i) << 2; i = (i >> s) & ((1<<4)-1); t |= s;
    s = ((i & ((1 << 2)-1) << 2) == i) << 1; i = (i >> s) & ((1<<2)-1); t |= s;
    return t | (1-(i&1));
}



void scoreHand(ull player, ull* score1, ull* score2){
    ull D = (ONE<<16)-1;
    ull H = (ONE<<32)-1-D;
    ull S = (ONE<<48)-1-H-D;
    ull C = -1;
    C -= (S+H+D);
    *score1 = 0;
    *score2 = 0;
    int pD = (player & D), pH = ((player & H) >> 16), pS = ((player & S) >> 32), pC = ((player & C) >> 48);
    ull A = (pD & pH) | (pD & pS) | (pD & pC) | (pH & pS) | (pH & pC) | (pS & pC);
    int hA =  hammingSum(A);
    ull O = pD | pH | pS | pC;
    int hO =  hammingSum(O);
    ull X = pD ^ pH ^ pS ^ pC;

    if(hO == 4){ // 1P
        *score1 = 1;
        *score2 = (getMsbPos(A) << 16) | X;
        return;
    }
    else if(hO == 3 && hA == 2){ // 2P
        *score1 = 2;
        int p = getMsbPos(A);
        *score2 = (p << 24) | (getMsbPos(A ^ (1 << p)) << 16) | X;
        return;
    }
    else if(hO == 3 && hA == 1){ // B
        *score1 = 3;
        *score2 = getMsbPos(A);
        return;
    }
    else if(hO == 2 && hA == 2){ // FH
        *score1 = 6;
        *score2 = getMsbPos(X);
        return;
    }
    else if(hO==2 && hA == 1){  // SQ
        *score1 = 7;
        *score2 = getMsbPos(A);
        return;
    }
    ull p = player;
    // all same color or not
    if((p & D) == p | (p & H) == p | (p & S) == p | (p & C) == p){
        if(getMsbPos(O) - getLsbPos(O) == 4){ // SF
            *score1 = 8;
            *score2 = getLsbPos(O);
            return;
        }
        // F
        *score1 = 5;
        *score2 = O;
        return;
    }

    // Now straight, or nothing
    if(getMsbPos(O) - getLsbPos(O) == 4){
        *score1 = 4;
        *score2 = getLsbPos(O);
        return;
    }
    *score2=O;
}


int main(){
    ifstream inFile ("poker.txt");
    int win1=0;
    ull player1 = ZERO;
    ull player2 = ZERO;
    ull score11, score12, score21, score22;
    string s;
    string line;
    if (inFile.is_open()){
        while(getline(inFile, line)){
            player1 = ZERO;
            player2 = ZERO;
            stringstream hand(line);
            int hand1=0, hand2=0;
            for(int i=0;i<10;i++){
                unsigned long long tmp=0;
                hand >> s;
                switch(s[0]){
                    case 'T': tmp = ONE << 8; break;
                    case 'J': tmp = ONE << 9; break;
                    case 'Q': tmp = ONE << 10; break;
                    case 'K': tmp = ONE << 11; break;
                    case 'A': tmp = ONE << 12; break;
                    default: tmp += ONE << (s[0]-50);
                }
                switch(s[1]){
                    case 'H': tmp = tmp << 16; break;
                    case 'S': tmp = tmp << 32; break;
                    case 'C': tmp = tmp << 48; break;
                }
                if(i < 5)
                    player1 += tmp;
                else
                    player2 += tmp;

            }
            scoreHand(player1, &score11, &score12);
            scoreHand(player2, &score21, &score22);
            if(score11>score21 || (score11==score21 && score12 > score22))
                win1++;

        }
        inFile.close();
    }
    else{
        cerr << "Error opening file" << endl;
    }
    cout << "Player 1 wins: " << win1 << endl;
    return 0;
}


/*

ull handFromString(string line){
    stringstream hand(line);
    string s;
    ull out=ZERO;
    for(int i=0;i<5;i++){
        hand >> s;
        ull tmp=ZERO;
        cout << s << endl;
        switch(s[0]){
            case 'T': tmp = ONE << 8; break;
            case 'J': tmp = ONE << 9; break;
            case 'Q': tmp = ONE << 10; break;
            case 'K': tmp = ONE << 11; break;
            case 'A': tmp = ONE << 12; break;
            default: tmp = ONE << (s[0]-50);
        }
        switch(s[1]){
            case 'H': tmp = tmp << 16; break;
            case 'S': tmp = tmp << 32; break;
            case 'C': tmp = tmp << 48; break;
            default: break;
        }
        out += tmp;
    }
    return out;
}

void testScoreHand(){
    cout << "testing single pair..." << endl;
    ull hand = ONE << 17 | ONE << 1 | ONE << 36 | ONE << 59 | ONE << 41;
    ull hand1 = handFromString("3H 3D 6S KC JS");
    cout << bitset<64>(hand) << endl;
    cout << bitset<64>(hand1) << endl;
    assert(hand1 == hand);
    ull score1, score2, score22, score23;
    scoreHand(hand1, &score1, &score2);
    assert(score1 == 1);
    cout << "3C 3S 6S QC JS" << endl;
    hand1 = handFromString("3H 3D 6S QC JS");
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 1);
    assert(score2 > score22);
    cout << "3C 3S 6S AC JS" << endl;
    hand1 = handFromString("3H 3D 6S AC JS");
    scoreHand(hand1, &score1, &score23);
    assert(score1 == 1);
    assert(score2 < score23);
    cout << "testing two pairs..." << endl;
    hand = handFromString("3H 3D 6S 6C JS");
    hand1 = handFromString("3H 3D 7S 7C JS");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 2);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 2);
    assert(score2 < score22);

    cout << "testing three..." << endl;
    hand = handFromString("3H 3D 3S 6C JS");
    hand1 = handFromString("4H 4D 4S 7C QS");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 3);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 3);
    assert(score2 < score22);

    cout << "testing full house..." << endl;
    hand = handFromString("3H 3D 3S 6C 6S");
    hand1 = handFromString("4H 4D 4S 2C 2S");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 6);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 6);
    assert(score2 < score22);

    cout << "testing four..." << endl;
    hand = handFromString("3H 3D 3S 3C JS");
    hand1 = handFromString("4H 4D 4S 4C QS");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 7);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 7);
    assert(score2 < score22);

    cout << "testing flush..." << endl;
    hand = handFromString("3H 4H 5H 6H 8H");
    hand1 = handFromString("3C 4C 5C 6C 9C");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 5);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 5);
    assert(score2 < score22);

    cout << "testing straight..." << endl;
    hand = handFromString("3H 4H 5H 6H 7D");
    hand1 = handFromString("7C 4C 5C 6C 8D");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 4);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 4);
    assert(score2 < score22);

    cout << "testing straight flush..." << endl;
    hand = handFromString("3H 4H 5H 6H 7H");
    hand1 = handFromString("7C 4C 5C 6C 8C");
    scoreHand(hand, &score1, &score2);
    assert(score1 == 8);
    scoreHand(hand1, &score1, &score22);
    assert(score1 == 8);
    assert(score2 < score22);
}
*/