#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath> /* for floor */

using namespace std;

enum MENU_CHOICES {EXIT = 'X', PROG_DESC = 'P', EXPANSION = 'E', COMPRESSION = 'C'};

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

#endif // DEFINITIONS_H
