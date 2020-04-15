//
//  main.cpp
//  SuperPass
//
//  Created by William Phenicie on 4/14/20.
//  Copyright © 2020 Peer Group Softwrae. All rights reserved.
//

#include <iostream>
#include "Dictionary.h"
using namespace std;

struct Key keyDictionary[] = {
    {'a', "wx8P06LJ2"},
    {'b', "82jQ972Rp"},
    {'c', "jsv9Q280t"},
    {'d', "hn9ILdbh4"},
    {'e', "q11RSuZ98"},
    {'f', "kFsloDwaS"},
    {'g', "CzryA4851"},
    {'h', "pAK8yMZvb"},
    {'i', "nh3N15ZUE"},
    {'j', "vOuGE2MT7"},
    {'k', "chTBGhsL7"},
    {'l', "bwep3I6iu"},
    {'m', "Sq9KVF8Jb"},
    {'n', "Yp9CwiliF"},
    {'o', "dk182JSER"},
    {'p', "wmp69kLoL"},
    {'q', "5LK97oMwR"},
    {'r', "ZMuQarPAu"},
    {'s', "z3QuS9XbV"},
    {'t', "MJyheFF1N"},
    {'u', "abkV2MIma"},
    {'v', "N9wOeZxbU"},
    {'w', "6K7vp91Pa"},
    {'x', "dSEppfJMI"},
    {'y', "oSkKRPILx"},
    {'z', "g0enNmKdg"},
    {'A', "vo18jVcTa"},
    {'B', "Fzejo1Ak2"},
    {'C', "B7WEcVEj6"},
    {'D', "1rVHIrH3G"},
    {'E', "iQL4xoKhY"},
    {'F', "LnlVvYsuF"},
    {'G', "i7cHQ8GDz"},
    {'H', "9kmn4jmbc"},
    {'I', "J9Q2Gv1tm"},
    {'J', "jxnmYHDbx"},
    {'K', "a2qdLDDHQ"},
    {'L', "QivMkTj9o"},
    {'M', "EBgufwIIF"},
    {'N', "IidASiZX7"},
    {'O', "eG4AeMK7k"},
    {'P', "ZgVieEeYP"},
    {'Q', "jspbNZQJM"},
    {'R', "MfnZJfgTl"},
    {'S', "iTXmHpaR4"},
    {'T', "D4gl4FExe"},
    {'U', "Cot1GQqEt"},
    {'V', "myRWqSsmE"},
    {'W', "gac1BW7tm"},
    {'X', "l69uFyjbH"},
    {'Y', "NMiA1k1ab"},
    {'Z', "jakF5Uojc"},
    {'0', "s29snRXnr"},
    {'1', "U4mdKuDRw"},
    {'2', "uleOLuwva"},
    {'3', "Snqs9TTiR"},
    {'4', "tmDps7ym8"},
    {'5', "Ilr6v7VQP"},
    {'6', "rqijWh657"},
    {'7', "F5VxsJ0k4"},
    {'8', "rHkMEZ5Lw"},
    {'9', "cSlp75zPl"},
    {'!', "BF3aTEw9f"},
    {'$', "jmT8hGI1p"},
    {'&', "YbTZgu5yV"},
    {'_', "Rqhw0QJ77"},
    {'-', "cky94qHR0"},
    {'?', "iixnMcUtr"}

};

string password;
string encryptedPassword;
string decryptedPassword;

int main(int argc, char * argv[]) {
    // insert code here...
    
    
    size_t keySize = sizeof(keyDictionary)/sizeof(keyDictionary[0]);
    
    for (int i = 0; i < keySize; i++) {
        Key tempVal = keyDictionary[i];
        for (int j = 0; j < keySize; j++) {
            if (i != j) {
            if (keyDictionary[i].key == keyDictionary[j].key) {
                cout << "Duplicate Found at " + to_string(i) + " and " + to_string(j) + "\n";
            }
            }
        }
    }

    for (int i = 0; i < keySize; i++) {
        if (keyDictionary[i].key.length() > 9) {
            cout << "Too many characters at " + to_string(i) + "\n";
        }
    }
    

    
    if (argc < 2) {
        cout << "Welcome to the SuperPass password creator and decyptor\n";
        cout << "Would you like to [C]reate a Password or [R]ead a Password\n";
        
        char response[1];
        cin >> response;
        
        cout << "Enter your password here: \n";
        cin >> password;
        
        
        
        if (tolower(response[0]) == 'c') {
        
        for (int i = 0; i < password.length(); i++) {
            char pass = password[i];
            
            if (pass != 0) {
                
                size_t keySize = sizeof(keyDictionary)/sizeof(keyDictionary[0]);
                
                for (int j = 0; j < keySize; j++) {
                    
                    if (pass == keyDictionary[j].letter) {
                        
                        encryptedPassword += keyDictionary[j].key;
    //                    strncat(encryptedPassword, &keyDictionary[j].key, 9);
                    }
                    
                }
                
            }
            
        }
        cout << "New Password: \n";
        cout << encryptedPassword + "\n";
            
        } else if (tolower(response[0]) == 'r') {
            encryptedPassword = password;
                    
                    for (int i = 0; i < encryptedPassword.length(); i+=9) {
                        string tempKey = encryptedPassword.substr((i),(9));
            //            cout << "Key Substring: ";
            //            cout << tempKey + "\n";
                        
                        for (int j = 0; j < keySize; j++) {
                            if (keyDictionary[j].key == tempKey) {
                                decryptedPassword += keyDictionary[j].letter;

                            }
                        }
                        
                    }
                    cout << "Decrypted Password: \n";
                    cout << decryptedPassword + "\n";
        }
    }
    
    else if ((argc == 2 && strcmp(argv[1], "-h") == 0)||(argc == 2 && strcmp(argv[1], "help") == 0)) {
        
        cout << "Welcome to SuperPass\n";
        cout << "This is a password creator that takes user readable Password and puts them through a cryptic letter dictionary.\n";
        cout << "To Open SuperPass simply enter: \"SuperPass\" into your terminal\n";
        cout << "To quickly create a password use \'-c\' then input your password like such: \n";
        cout << "superpass -c [PASSWORD]\n";
        cout << "To quickly create a password use the Argument \'-r\' then input your password like such: \n";
        cout << "superpass -r [PASSWORD]\n";
        cout << "To view the Help Menu use the Argument \'-h\' or \'help\' and the Help Menu will appear \n";
        
    }
    
    else if (argc == 3 && strcmp(argv[1], "-c") == 0) {
        
        password = argv[2];
        
        for (int i = 0; i < password.length(); i++) {
                char pass = password[i];
                
                if (pass != 0) {
                    
                    size_t keySize = sizeof(keyDictionary)/sizeof(keyDictionary[0]);
                    
                    for (int j = 0; j < keySize; j++) {
                        
                        if (pass == keyDictionary[j].letter) {
                            
                            encryptedPassword += keyDictionary[j].key;
        //                    strncat(encryptedPassword, &keyDictionary[j].key, 9);
                        }
                        
                    }
                    
                }
                
            }
        cout << "New Password: \n";
        cout << encryptedPassword + "\n";
    } else if (argc == 3 && strcmp(argv[1], "-r") == 0) {
        
        encryptedPassword = argv[2];
        
        for (int i = 0; i < encryptedPassword.length(); i+=9) {
            string tempKey = encryptedPassword.substr((i),(9));
//            cout << "Key Substring: ";
//            cout << tempKey + "\n";
            
            for (int j = 0; j < keySize; j++) {
                if (keyDictionary[j].key == tempKey) {
                    decryptedPassword += keyDictionary[j].letter;

                }
            }
            
        }
        cout << "Decrypted Password: \n";
        cout << decryptedPassword + "\n";
        
    } else if (argc > 3) {
        cout << "Too Many Arguments";
    }
    
    
    return 0;
}
