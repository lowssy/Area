#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define UP_ARROW     72
#define DOWN_ARROW   80
#define ENTER        13

using namespace std;

float PI = 3.14159265;
int selected = 0;
int previousSelected = 0;
string options[4] = {
  "1) Circle",
  "2) Rectangle",
  "3) Triangle",
  "4) EXIT" // The last option must always be the EXIT option
};
int optionsLength = sizeof(options) / sizeof(options[0]);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void changeTextColor(int color) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void draw() {
  system("CLS");
  changeTextColor(6);
  cout << "What area do you want to get?" << endl;
  changeTextColor(7);

  for(int i = 0; i < optionsLength; i++) {
    if(selected == i) changeTextColor(96);
    cout << "\t" << options[i] << endl;
    changeTextColor(7);
  }
}

void handleAreaCalculations() {
  float result;
  float base;
  float height;
  string units = "m";
  system("CLS");

  switch(selected) { // This is to check wich operation will be done
    case 0: // Circle
      float radius;
      changeTextColor(9);
      cout << "What are the circle radius?: ";
      changeTextColor(7);
      cin >> radius;

      result = radius * radius * PI;
      break;
    case 1: // Rectangle
      changeTextColor(9);
      cout << "What are the base of the rectangle?: ";
      changeTextColor(7);
      cin >> base;
      changeTextColor(9);
      cout << "What are the height of the rectangle?: ";
      changeTextColor(7);
      cin >> height;

      result = base * height;
      break;
    case 2:
      changeTextColor(9);
      cout << "What are the base of the rectangle?: ";
      changeTextColor(7);
      cin >> base;
      changeTextColor(9);
      cout << "What are the height of the rectangle?: ";
      changeTextColor(7);
      cin >> height;

      result = base * height / 2;
      break;
  }

  changeTextColor(1);
  cout << "What are the measure units?: ";
  changeTextColor(7);
  cin >> units;

  changeTextColor(224);
  cout << "\nArea = " << result << units + "2"  << endl;
  changeTextColor(7);
}

int main() {
  char key;
  int keyCode;
  draw();

  while(true) {
    key = getch();
    keyCode = key;

    switch(keyCode) {
      case UP_ARROW:
        selected--;
        if(selected == -1) selected = optionsLength - 1;
        draw();
        break;
      case DOWN_ARROW:
        selected++;
        if(selected == optionsLength) selected = 0;
        draw();
        break;
      case ENTER:
        if(selected == optionsLength - 1) {
          exit(1);
        } else {
          handleAreaCalculations();
        }
        break;
    }
  }

  return 0;
}
