# LibExcelFormula

LibExcelFormula is a cross platform library that parses and evaluates excel formulas. It is written in pure modern C++ and is designed to be a cross platform library that emphasizes **correctness** and **performance** without any **external dependencies**. You should be able to drop the library into your existing C++ projects and integrate it. 

The library is an implementation of the research paper - [A Grammar for Spreadsheet Formulas Evaluated on Two Large Datasets](https://drive.google.com/file/d/0B79P2Uym3JjvMjlaWWtnTWRLQmc/view)

This is a project by **Sri Madhavi Rajasekaran** (adhirai96@gmail.com).

## Goals

The main goals for this library are (in priority order)

* Correctness
* Performance
* Platform Independent

## Installation

This library is in its very early stages. It will support the full grammar of Excel formulas. The only major thing it will lack is implementation of evaluators for all the built in Excel formulas or support for User Defined formulas.

You can build this library using CMake

* Go to CMake/ directory in the root of the folder
* Generate the Makefile or Visual Studio soluion file
* Build and install the static library

## How do I hack on this library?

You will need the following things to hack on this library

* Code Editor - (I use Visual Studio Code)
* Good C++ Compiler with C++ 17 support - (I highly recommend Clang. I use Clang 9.0 with the compiler flag set to C++1z)
* CMake 3.10.2 or greater (CMake is used for building)
* Google Benchmark - (Used for running and collecting performance numbers)
* Doxygen - (Used for generating documentation from comments)

This library uses [Catch2](https://github.com/catchorg/Catch2) for unit testing and integration testing. It is a header only library and a copy of that library is checked into this code base. Every code folder will have a parallel folder in the test folder where unit tests corresponding to that folder will be checked. You can use CMake to build and run unit tests. Since this is native code, we also take security very seriously. Every unit test is run with Google Sanitizer runtime which flags potential security issues with the code. The goal is to have 100% unit test coverage and have zero sanitizer issues. FYI, Google Sanitizers are built into Clang.

The library uses two large datasets referenced in the research paper linked above for testing and validation purposes.

## Motivations

I love Excel. I have used it extensively during my time running clubs and organizations. One of the features I love about Excel are the formulas. I have always been curious about how formulas are implemented in Excel. That's why I decided to make this library.

And, Microsoft Recruiter wanted to see a C++ coding sample along with a writeup that explains the implementation. I hacked this library together to send to the recruiter. I might open source this at some point.