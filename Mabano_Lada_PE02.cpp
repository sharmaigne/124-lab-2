/**
 * Legolas Tyrael B. Lada | 2022-04734
 * Sharmaigne Angelie C. Mabano | 2022-03464
 * 2-BSCS
 *
 * CMSC 124 PE02: String Expansion/Compression
 */
#include "definitions.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
  bool running = true;

  while (running) {
    switch (menu()) {
      case PROG_DESC:
        programDescription();
        break;
      case EXPANSION:
        expansionLoop();
        break;
      case COMPRESSION:
        compressionLoop();
        break;
      case EXIT:
        running = false;
        break;
      default:
        cout << "\nInvalid input, try again.\n";
    }
  }
  return 0;
}

char menu(void) {
  char ret;
  cout << "Welcome to this String Expansion/Compression program! Please choose an action to perform...\n"
          "[P] Program Description\n"
          "[E] String Expansion\n"
          "[C] String Compression\n"
          "[X] Exit\n"
          "\nChoice: ";
  cin >> ret;
  cin.ignore(1000, '\n');

  return toupper(ret); /* lowercase versions of P E C X should be valid */
}

void programDescription(void) {
  cout << "\n\n\t\t==== PROGRAM DESCRIPTION ====\n\n"
          "Legolas Tyrael B. Lada       | 2022-04734\n"
          "Sharmaigne Angelie C. Mabano | 2022-03464\n"
          "March 12, 2024 - March 13, 2024\n=====\n"
          "Menu Descriptions:\n\n"
          "- [P] Program Description: Prints out the program description to "
          "stdout.\n"
          "- [E] String Expansion: Enters loop to expand strings.\n"
          "Each iteration asks for a string and displays its expanded version if input is valid.\n"
          "- [C] String Compression: Enters loop to compress strings.\n"
          "Each iteration asks for a string and displays its compressed version if input is valid.\n"
          "- [X] Exit: Terminates the program.\n"
          "\n=====\n"
          "Work distribution:\n"
          "Tyrael: compression, testing\n"
          "Sharmaigne: boilerplate code, expansion\n\n"
          "\t\t============================\n\n";
  
}

void expansionLoop() {
  string s;
  char exit;

  cout << "\n\n\t\t==== STRING EXPANSION ====\n\n"
          "For each valid compressed string of format \n"
          /* insert grammar here */
          "\t\t==========================\n\n";
  

  while (true) {
    cout << "Enter a compressed string: ";
    getline(cin, s);

    cout << "\nExpanded form: " << expandString(s);

    cout << "\n\nDo you want to expand another string?\n\n"
            "[X] NO\n"
            "[other] YES\n"
            "\nChoice: ";

    cin >> exit;
    cin.ignore(1000, '\n');
    if (toupper(exit) == EXIT)
      return;
  }
}

void compressionLoop() {
  string s;
  char exit;

  cout << "\n\n\t\t==== STRING COMPRESSION ====\n\n"
          "For each valid expanded string of format \n"
          /* insert grammar here */
          "\t\t==========================\n\n";
  

  while (true) {
    cout << "Enter an expanded string: ";
    getline(cin, s);

    cout << "\nCompressed form: " << compressString(s);

    cout << "\n\nDo you want to compress another string?\n\n"
            "[X] NO\n"
            "[other] YES\n"
            "\nChoice: ";

    cin >> exit;
    cin.ignore(1000, '\n');
    if (toupper(exit) == EXIT)
      return;
  }
}

string expandString(string s) {

}

string compressString(string s) {

}