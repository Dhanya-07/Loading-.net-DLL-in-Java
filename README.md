# Loading-.net-DLL-in-Java

This repository includes CSharp(.cs), C, Java files.Here the C# DLL is loaded into Java using NativeAOT feature of .net 7.
The C# DLL is first loaded into C code ,and the DLL from  C code is used in Java using JNI concept.
Native AOT(Ahead Of Time)compilation can be used with both Windows and Linux platforms.

**Steps:**

1) Create a C# class library either in Visual Studio or Visual Studio Code    

2) Annote the functions to be exported with UnmanagedCallersOnlyAttribute.
     
3) Publish the C# code,

       Static Library:  dotnet publish /p:NativeLib=Static -r win-x64 -c release //For Linux -: linux-64
       Dynamic Library: dotnet publish -r win-x64 -c Releaserelease //For Linux -: linux-64
       
4) Construct a C code calling the exported functions from C#.

5) Construct a Java code with call to native functions(C functions).

6) Compile the Java Code.

       javac -h . filename.java

8) Include the generated headers in the C code .

7) Compile C code to create DLL.

8) Run the Java Program.
    

