#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Checking if Caesar Cipher works:" ) { 
    CHECK(encrypt_caesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encrypt_caesar("Hello, World!" , 10) == "Rovvy, Gybvn!");
    CHECK(encrypt_caesar("This works!", 400) == "Drsc gybuc!");
}

TEST_CASE("Checking for solve solution: ") { 
    CHECK(solve(encrypt_caesar("I agree with those who have said that in my first statement after I testified I was not contrite enough. I don’t think there is a fancy way to say that I have sinned. It is important to me that everybody who has been hurt know that the sorrow I feel is genuine: first and most important, my family; also my friends, my staff, my Cabinet, Monica Lewinsky and her family, and the American people. I have asked all for their forgiveness… But I believe that to be forgiven, more than sorrow is required – at least two more things. First, genuine repentance – a determination to change and to repair breaches of my own making. I have repented. Second, what my bible calls a ”broken spirit”; an understanding that I must have God’s help to be the person that I want to be; a willingness to give the very forgiveness I seek; a renunciation of the pride and the anger which cloud judgment, lead people to excuse and compare and to blame and complain", 255)) == "I agree with those who have said that in my first statement after I testified I was not contrite enough. I don’t think there is a fancy way to say that I have sinned. It is important to me that everybody who has been hurt know that the sorrow I feel is genuine: first and most important, my family; also my friends, my staff, my Cabinet, Monica Lewinsky and her family, and the American people. I have asked all for their forgiveness… But I believe that to be forgiven, more than sorrow is required – at least two more things. First, genuine repentance – a determination to change and to repair breaches of my own making. I have repented. Second, what my bible calls a ”broken spirit”; an understanding that I must have God’s help to be the person that I want to be; a willingness to give the very forgiveness I seek; a renunciation of the pride and the anger which cloud judgment, lead people to excuse and compare and to blame and complain");
    CHECK(solve("HELLO HELLO HELLOOO") == "HELLO HELLO HELLOOO");
    CHECK(solve("I find your lack of faith disturbing.") == "I find your lack of faith disturbing.");
}