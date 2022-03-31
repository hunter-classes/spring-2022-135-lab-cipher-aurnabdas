#include <iostream>
#include "funcs.h"
#include <string> 
#include <array>
#include <cctype>
#include <cmath>
#include <climits>

const std::array<char, 26> upper = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const std::array<char, 26> lower = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

const std::array<double, 26> english_freqs = 
{.084966, .020720, .045388, .033844, .111607, .018121, .024705, .030034, .075448, .001964, .011016, .054893, .030129, .066544, .071635, .031671, .001962, .075809, .057351, .069509, .036308, .010074, .012899, .002902, .017779, .002722};

char shift_char(char c, int rshift) { 
    for(int i = 0; i < 26; i++) { 
        if(c == upper[i] || c == lower[i]) { 
            return isupper(c) ? upper[(i + rshift) % 26] : lower[(i + rshift) % 26];
        }
    }

    return c;
}

std::string encrypt_caesar(std::string plaintext, int rshift) { 
    std::string sen = "";

    for(int i = 0; i < plaintext.length(); i++) { 
        sen += shift_char(plaintext.at(i), rshift); 
    }

    return sen;
}




std::string solve(std::string encrypted_string) { 
    int min;
    double l_count = 0;
    double r_total = 0;
    std::string sen = "";
    std::string test_string = "";
    double smallest = INT_MAX;

    std::array<double, 26> letter_freq = 
    {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    for(int i = 0; i < 26; i++) { 
        test_string = encrypt_caesar(encrypted_string, i);
        for(int j = 0; j < 26; j++) { 
            for(int k = 0; k < encrypted_string.length(); k++) {
                if(test_string[k] == upper[j] || test_string[k] == lower[j]) {
                    letter_freq[j]++;
                    l_count++;
                }
            }
        }

        for(int i = 0; i < 26; i++) { 
            letter_freq[i] = letter_freq[i] / l_count; 
            letter_freq[i] = std::fabs(letter_freq[i] - english_freqs[i]); 
            r_total += letter_freq[i]; 
            // std::cout << letter_freq[i] << std::endl; 

            letter_freq[i] = 0;
        }

        if(r_total < smallest) { 
            smallest = r_total; 
            min = i; 
        }

        r_total = 0; 
        l_count = 0;         
    }
    
    for(int i = 0; i < encrypted_string.length(); i++) { 
        sen += shift_char_uncipher(encrypted_string[i], min);
    }

    return sen; 
}

char shift_char_uncipher(char c, int rshift) {  
    int shift = rshift % 26; 
    shift = 26 - shift;

    
    if(shift < 0) {  
        for(int i = 0; i < 26; i++) { 
            if(c == upper[i] && i - shift > 25) {
                return upper[(i - shift) - 26];
            } else if(c == lower[i] && i - shift > 25) { 
                return lower[(i - shift) - 26];
            } else if(upper[i] == c) { 
                return upper[i - shift]; 
            } else if(lower[i] == c) { 
                return lower[i - shift];
            }
        }
    } else {
        for(int i = 0; i < 26; i++) { 
            if(c == upper[i] && i - shift < 0) {
                return upper[26 - (shift - i)];
            } else if(c == lower[i] && i - shift < 0) { 
                return lower[26 - (shift - i)];
            } else if(upper[i] == c) { 
                return upper[i - shift]; 
            } else if(lower[i] == c) { 
                return lower[i - shift];
            } 
        }
    }

    return c;
}