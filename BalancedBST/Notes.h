#pragma once
class Notes
{
};

/*

Saturday To Do list:
1. update height after removal
2. double check height and bf after rotation
3. work on getting rotation changes to actually stick



Main:
	~Still need to work on parsing, allow spaces in name and allow for leading zeros.

Insert function:
	~I got the left and right rotations working! This->root problem has been fixed :) now i need to work on leftright and rightleft
	rotations. Rememver to call the first on the child then the second on the parent! ie right left is right on child and then
	left on parent
	~Still need to have the option for leading zeros
	~create a function to test if my main root is chanignig without reference var

Remove function:
	~Readjust height: create a update height function that will accept the val of the parent, and it will basically do a binary
	search for the parent node! Then update the heights and return, which will traverse all the way back up to the root.


Rotations:
	~See Insert
	~readjust height and BF
	~keep work of rl and lr bc i am too tired rn

Parsing:
	~Allow for names with spaces
	~Allow for leading zeros

Print:
	~I need to remember to fix the print to ONLY print the names, so far they print everything!
	
removeInOrderN:
	~This is still not working, and when the main root is removed, it takes all its right stuff with it!











*/
