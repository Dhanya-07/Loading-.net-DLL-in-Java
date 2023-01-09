// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

// On unix make sure to compile using -ldl and -pthread flags.

// Set this value accordingly to your workspace settings

#if defined(_WIN32)
#define PathToLibrary "NativeLibrary.dll"
#elif defined(__APPLE__)
#define PathToLibrary "./bin/Debug/net6.0/osx-x64/native/NativeLibrary.dylib"
#else
#define PathToLibrary "./bin/Debug/net6.0/linux-x64/native/NativeLibrary.so"
#endif

#ifdef _WIN32
#include "windows.h"
#include "io.h"
#define symLoad GetProcAddress
#else
#include "dlfcn.h"
#include <unistd.h>
#define symLoad dlsym
#endif

#include "HelloJNI.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef F_OK
#define F_OK 0
#endif

int callSumFunc(char *path, char *funcName, int a, int b);
int callDiff(char *path, char *funcName, int a, int b);
int callProdFunc(char *path, char *funcName, int a, int b);
int callDivFunc(char *path, char *funcName, int a, int b);

// Native Functions

// Add
JNIEXPORT jint JNICALL Java_HelloJNI_JNI_1callSumFunc(JNIEnv *env, jobject thisObj, jint n1, jint n2)
{
    if (access(PathToLibrary, F_OK) == -1)
    {
        puts("Couldn't find library at the specified path");
        return 0;
    }
    int res;
    res = callSumFunc(PathToLibrary, "add", n1, n2);
    return res;
}
// Sub
JNIEXPORT jint JNICALL Java_HelloJNI_JNI_1callDiff(JNIEnv *env, jobject thisObj, jint n1, jint n2)
{
    if (access(PathToLibrary, F_OK) == -1)
    {
        puts("Couldn't find library at the specified path*********");
        return 0;
    }
    int res;
    res = callDiff(PathToLibrary, "sub", n1, n2);
    return res;
}
// Mul
JNIEXPORT jint JNICALL Java_HelloJNI_JNI_1callProdFunc(JNIEnv *env, jobject thisObj, jint n1, jint n2)
{
    if (access(PathToLibrary, F_OK) == -1)
    {
        puts("Couldn't find library at the specified path*********");
        return 0;
    }
    int res;
    res = callProdFunc(PathToLibrary, "mul", n1, n2);
    return res;
}
// Div
JNIEXPORT jint JNICALL Java_HelloJNI_JNI_1callDivFunc(JNIEnv *env, jobject thisObj, jint n1, jint n2)
{
    if (access(PathToLibrary, F_OK) == -1)
    {
        puts("Couldn't find library at the specified path*********");
        return 0;
    }
    int res;
    res = callDivFunc(PathToLibrary, "div", n1, n2);
   
    return res;
}
int main()
{

   //Can also run this c++ code to check c# functions before passing it to the Java
    printf("Calling c# DLL in C++");
    printf("\n Simple integer Manipulation!");
    printf("str %s ", PathToLibrary);
    // Check if the library file exists
    if (access(PathToLibrary, F_OK) == -1)
    {
        puts("Couldn't find library at the specified path");
        return 0;
    }
    int sum = callSumFunc(PathToLibrary, "add", 2, 18);
    printf("\nThe Added Value : %d", sum);
    int diff = callDiff(PathToLibrary, "sub", 50, 8);
    printf("\nThe Subtracted Value : %d", diff);
    int prod = callProdFunc(PathToLibrary, "mul", 10, 10);
    printf("\nThe Multiplied Value : %d", prod);
    int div = callDivFunc(PathToLibrary, "div", 40, 8);
    printf("\nThe Divided Value : %d", div);
}

int callSumFunc(char *path, char *funcName, int firstInt, int secondInt)

{
#ifdef _WIN32
    HINSTANCE handle = LoadLibraryA(path);
#else
    void *handle = dlopen(path, RTLD_LAZY);
#endif
    typedef int (*myFunc)(int, int);
    myFunc MyImport = (myFunc)symLoad(handle, funcName);

    int result = MyImport(firstInt, secondInt);
    int callSumFunc();
    return result;
}

int callDiff(char *path, char *funcName, int firstInt, int secondInt)

{

#ifdef _WIN32
    HINSTANCE handle = LoadLibraryA(path);
#else
    void *handle = dlopen(path, RTLD_LAZY);
#endif

    typedef int (*myFunc)(int, int);
    myFunc MyImport = (myFunc)symLoad(handle, funcName);
    int result = MyImport(firstInt, secondInt);
    return result;
}
int callProdFunc(char *path, char *funcName, int firstInt, int secondInt)

{
#ifdef _WIN32
    HINSTANCE handle = LoadLibraryA(path);
#else
    void *handle = dlopen(path, RTLD_LAZY);
#endif

    typedef int (*myFunc)(int, int);
    myFunc MyImport = (myFunc)symLoad(handle, funcName);
    int result = MyImport(firstInt, secondInt);
    return result;
}
int callDivFunc(char *path, char *funcName, int firstInt, int secondInt)

{

#ifdef _WIN32
    HINSTANCE handle = LoadLibraryA(path);
#else
    void *handle = dlopen(path, RTLD_LAZY);
#endif

    typedef int (*myFunc)(int, int);
    myFunc MyImport = (myFunc)symLoad(handle, funcName);
    int result = MyImport(firstInt, secondInt);
    return result;
}
