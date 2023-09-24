# Offline Judge for Windows: the next generation of C++ judging
(Still developing, if you want to join us, please contact zzk2010 on [Luogu](https://www.luogu.com.cn/user/773060) or [Github](https://github.com/zzk2010))

### Introduction
This Offline Judge is designed to be used offline for OIers to check their programs. It can be a part of the Online Judge in the future.
With it, you can conveniently check your program even if you don't connect to the Internet.

### How to use
Type "Offline Judge" to enter the judging area. You need to provide:
+ your .cpp file
+ your compiler option (default: -std=c++11)
+ your input file
+ your answer file

When using the Offline Judge, you just need to simply drag these files into it.

The Judge will return three kinds of message: Compile Error, Wrong Answer and Accepted.
+ Compile Error: your program has grammatical or other mistakes so that the Offline Judge can't compile your .cpp file.
+ Wrong Answer: your program gives a different answer.
+ Accepted: your program is successfully compiled, and gives the correct answer.

### FAQ
Q: How does this Offline Judge judge my program?\
A: It uses g++.exe for compiling and fc for judging.

Q: Why can't I get Accepted, even though I gave the correct answer?
A: That's because fc strictly compares all the characters, including white spaces and new lines. You have to strictly follow the output format of the given output. We'll fix this in the near future.
