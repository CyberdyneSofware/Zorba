#ifndef DIALOG_H_INCLUDED
#define DIALOG_H_INCLUDED

#include <iostream>

using namespace std;
/* *************************
Alexi Zelaya
5-23-18

Dialog for ZORBA.

Users will be
able to read a small story
which is what makes this a text
adventure game.
************************** */
extern void dialog_intro(); //void functions containing dialog that will be summoned by a call.
extern void dialog_miniboss();
extern void dialog_mainboss();
extern void dialog_ending();


#endif
