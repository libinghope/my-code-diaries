/*
为了避免同一个文件被include多次，C/C++中有两种方式，
一种是 #ifndef 方式，一种是 #pragma once 方式。
*/

// #pragma once
#ifndef __FUN_H__
#define __FUN_H__
#include<stdio.h>
extern int max(int a, int b);

#endif
