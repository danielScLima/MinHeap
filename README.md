MIN HEAP
====================
Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/MinHeap.svg?branch=master)](https://www.travis-ci.com/danielScLima/MinHeap)

This repository has a project with the implementation of a MIN HEAP.

It is written in C++.

The code of the MIN HEAP is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the MIN HEAP (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the MIN HEAP, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -

The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Remove minimum number;](#markdown-header-emphasis)
	
- - -

Sample images: 
====================

![Alt text](images/sample.png)


Insertion steps: 
====================

## Initial
![Alt text](images/insert/1.png)

## Inserting 40
![Alt text](images/insert/2.png)

## Inserting 50
![Alt text](images/insert/3.png)

## Inserting 75
![Alt text](images/insert/4.png)

## Inserting 35
![Alt text](images/insert/5.png)

## Inserting 20
![Alt text](images/insert/6.png)

## Inserting 60
![Alt text](images/insert/7.png)

## Inserting 4
![Alt text](images/insert/8.png)

## Inserting 2
![Alt text](images/insert/9.png)


Remove min steps: 
====================

## Initial
![Alt text](images/removemin/1.png)

## Removing min
![Alt text](images/removemin/2.png)

## Removing min
![Alt text](images/removemin/3.png)

## Removing min
![Alt text](images/removemin/4.png)

## Removing min
![Alt text](images/removemin/5.png)

## Removing min
![Alt text](images/removemin/6.png)

## Removing min
![Alt text](images/removemin/7.png)

## Removing min
![Alt text](images/removemin/8.png)

## Removing min
![Alt text](images/removemin/9.png)



Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)



