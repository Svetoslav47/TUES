#ifndef PersonGuard
    #include "person.h"
#endif

typedef struct{
    Person students[26];
    char classLetter;
    int classNumber;
    Person classTeacher;
} SchoolClass;