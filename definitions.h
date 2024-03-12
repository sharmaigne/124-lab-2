#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

enum MENU_CHOICES {EXIT = 'X', PROG_DESC = 'P', EXPANSION = 'E', COMPRESSION = 'C'};
#define INVALID "Invalid Input" 

/**
 * Menu interface, returns a choice value based on what user inputs.
 *
 * @return menu choice
 */
char menu(void);

/**
 * Prints out the program description to `stdout`.
 */
void programDescription(void);

/**
 * Enter the loop for expansion choice.
 * Exit back to `main` on `X` or invalid expression.
 */
void expansionLoop(void);

/**
 * Enter the loop for compression choice.
 * Exit back to `main` on `X` or invalid expression.
 */
void compressionLoop(void);

/**
 * Expand a valid compressed string eg. "2aA4b" -> "aaAbbbb" 
 * 
 * @param s compressed string to be expanded.
 * @return expanded version of the string, "Invalid Input" if s does not follow the correct format.
 */
string expandString(string s);

/**
 * Expand a valid expanded string eg. "aaAbbbb" -> "2aA4b"
 * 
 * @param s expanded string to be compressed.
 * @return compressed version of the string, "Invalid Input" if s does not follow the correct format.
 */
string compressString(string s);

#endif // DEFINITIONS_H
