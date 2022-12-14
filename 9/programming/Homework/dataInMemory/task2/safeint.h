#ifndef SAFEINT_H
#define SAFEINT_H

struct SafeResult {
    int value;
    char errorflag;
};

struct SafeResult safeadd(int x, int y);
struct SafeResult safesubtract(int x, int y);
struct SafeResult safemultiply(int x, int y);
struct SafeResult safedivide(int x, int y);
struct SafeResult safestrtoint(char* str);

#endif