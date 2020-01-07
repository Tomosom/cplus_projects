添加继承的类后，用Ubuntu10的编译器编译会告警 :
g++  -o a.out offsetof.cpp
offsetof.cpp: In function ‘int main(int, char**)’:
offsetof.cpp:24: warning: invalid access to non-static data member ‘ST::i’  of NULL object
offsetof.cpp:24: warning: (perhaps the ‘offsetof’ macro was used incorrectly)
offsetof.cpp:25: warning: invalid access to non-static data member ‘ST::j’  of NULL object
offsetof.cpp:25: warning: (perhaps the ‘offsetof’ macro was used incorrectly)
offsetof.cpp:26: warning: invalid access to non-static data member ‘ST::c’  of NULL object
offsetof.cpp:26: warning: (perhaps the ‘offsetof’ macro was used incorrectly)

