#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "State.h"
#include "ClassType.h"
#include "Element.h"
#include "ElementsOutput.h"
#include "ElementsInput.h"

std::string previousInput;
std::vector<Element> elements;
bool leave = false;
//it's an ignore case compare
bool compare(std::string str1, std::string str2){
	if(str1.length() != str2.length())return false;
	for(unsigned int i = 0; i < str1.length(); i++) if(tolower(str1.at(i)) != tolower(str2.at(i))) return false;
	return true;
}
int findIndex(std::string input){
	unsigned int index = 69420;
	try{
		return std::stoi(input) -1;
	} catch (std::exception& e){
		unsigned short int size = elements.size();
		//check name
		for(int i = 0; i < size; i++) if(compare(input, elements[i].name)) return i;
		//check symbol
		for(int i = 0; i < size; i++) if(compare(input, elements[i].symbol)) return i;
	}
	if (index == 69420) throw std::invalid_argument("Element not found in findIndex()");
	return index;
}

/**
 * Edits the element
 * 
 * @param index index of element to modify
 * @param subParam sub parameter of element to modify
 * @param text text input
 */
void editElement(unsigned short int index, unsigned short subParam, std::string text){
  if (index >= elements.size()) {
    std::cout << "Element does not exist." << std::endl;
    return;
  }
  try {
    elements[index].edit(subParam,text);
    std::cout << "Element modified!" << std::endl;
    elements[index].readElement();
    ElementsOutput::addRevision(ElementsOutput::LATEST_REVISION_NAME, elements);
  } catch (std::exception & e) {
    std::cout << "Unable to edit element: " << e.what() << std::endl;
  }
}
void editFile(){
	std::cout << "Please enter an element: ";
	std::string input;
	std::cin >> input;
	int index = 69420;
	try{
		index = findIndex(input);
    if (index < 0 || index > 117) throw new std::invalid_argument("Invalid atomic number.");
	} catch (std::exception& e){
    std::cout << "Well that's not a valid element name/symbol/number." << std::endl;
    return;
	}
	std::cout << "What do you want to modify? ";
	input = "";
	std::cin >> input;
	unsigned int mod = 69420;
  if (compare(input,"name")) mod = 0;
  else if (compare(input,"symbol")) mod = 1;
  else if (compare(input, "period")) mod = 2;
  else if (compare(input, "radioactive") || compare(input, "isradioactive")) mod = 3;
  else if (compare(input, "group")) mod = 4;
  else if (compare(input,"block")) mod = 5;
  else if (compare(input,"atomic number")) mod = 6;
  else if (compare(input,"neutrons") || compare(input,"neutron number") || compare(input, "number of neutrons")) mod = 7;
  else if (compare(input,"actual mass") || compare(input,"mass")) mod = 8;
  else if (compare(input,"econfig") || compare(input,"electron configuration") || compare(input,"electronic configuration") || compare(input,"electronconfig") || compare(input, "electron config")) mod = 9;
  else {
    std::cout << "Well that's not a valid thing to modify." << std::endl;
    return;
  }
  // there's only 10 things to modify
  if (mod > 9) {
    std::cout << "Well that's not a valid thing to modify." << std::endl;
    return;
  }
	std::cout << "Replace it with...? ";
	input = "";
	while (input.length() == 0) getline(std::cin, input);
	editElement(index,mod+1,input);
}


void printHelpMenu() {
  std::cout << "This program is not case sensitive." << std::endl;
  std::cout << "The neutron number is for the most common isotope of the element." << std::endl;
  std::cout << "If the mass number is a round number, that is the mass of the most stable isotope."  << std::endl;
  std::cout << "Some electron configurations (period = 7) may be predictions."  << std::endl;
  std::cout << "Quit/Leave quits the program."  << std::endl;
  std::cout << "\"all\" lists all elements in the program."  << std::endl;
  std::cout << "Entering a number brings up the element of the same atomic number."  << std::endl;
  std::cout << "Entering a name or symbol brings up the element of the same name/symbol (if it exists)."  << std::endl;
  std::cout << "Entering \"clear\" clears the screen."  << std::endl;
  std::cout << "Entering \"m: number\" brings up the element with the closest atomic mass."  << std::endl;
  std::cout << "Entering \"p: number (or Lanthanide/Actinide)\" brings up all elements in that period/row."  << std::endl;
  std::cout << "Entering \"g: number\" brings up the elements in that group."  << std::endl;
}

void printElementsOfPeriod(std::string input) {
  std::string kill;
		unsigned short int f = 0;
		if (compare(input, "p: lanthanide")){
      for(int i = 56; i < 71; i++){
        elements[i].readElement();
        std::cout << "\n";
      }
      previousInput = input; return;
    } else if (compare(input, "p: actinide")){
      for(int i = 88; i < 103; i++){
        elements[i].readElement();
        std::cout << "\n";
      }
      previousInput = input; return;
    }
		std::istringstream stream(input);
		stream >> kill >> f;
		if (f >= 8 || f == 0){
      std::cout << "Those elements have not yet been discovered, dingus.\n";
      previousInput = input; return;
    }
		switch (f){
      case 1:{
        elements[0].readElement();
        std::cout << "\n";
        elements[1].readElement();
        std::cout << "\n";
        break;
      }
      case 2:{
        for(int i = 2; i < 10;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      case 3:{
        for(int i = 10; i < 18;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      case 4:{
        for(int i = 18; i < 36;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      case 5:{
        for(int i = 36; i < 54;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      case 6:{
        for(int i = 54; i < 86;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      case 7:{
        for(int i = 86; i < 118;i++){
          elements[i].readElement();
          std::cout << "\n";
        }
        break;
      }
      default:{
        std::cout << "Invalid input, or the element does not exist.\n";
        break;
      }
    }
}

void printAllElements() {
  for(int i = 0; i < elements.size(); i++){
    elements[i].readElement();
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void clearScreen() {
  system("clear");
		std::cout << "Please enter input: " << "\n";
		std::cout << "Type \"help\" for help." << "\n";
}

void findElementByAtomicMass(std::string input) {
  std::string kill;
		double f = -1;
		std::istringstream stream(input);
		stream >> kill >> f;
		//attempt to binary search the input
		unsigned int boundLeft = 0;
		unsigned int boundRight = elements.size()-1;
		unsigned int index =  floor(boundRight/2);
		//295 = approximate mass of oganesson, last known element
		if(f > 296){
      std::cout << "Atomic mass > mass of heaviest known element.";
      return;
    }
		if (f <= 0){
      std::cout << "Atomic mass input < 0.";
      return;
    }
		if(f > (elements[boundRight].atomicMass) + 5) throw std::range_error("Some glitch in the atomic mass binary searcher.");
    else if (f > (elements[boundRight].atomicMass)){
      std::cout << "Our closest guess:" << std::endl;
      elements[boundRight].readElement();
      return;
    } else if (f < 1.008){
      std::cout << "Our closest guess:" << std::endl;
      elements[0].readElement();
      return;
    }
		while((boundRight - boundLeft) != 1){
      if(f > elements[index].atomicMass){
        boundLeft = index;
        index = round((boundLeft + boundRight)/2);
      } else {
        boundRight = index;
        index = round((boundLeft + boundRight)/2);
      }
    }
		if (std::abs(elements[boundRight].atomicMass-f) > std::abs(f-elements[boundLeft].atomicMass)){
      std::cout << "Our closest guess:" << std::endl;
      elements[boundLeft].readElement();
    } else{
      std::cout << "Our closest guess:" << std::endl;
      elements[boundRight].readElement();
    }
}

void printElementsOfGroup(std::string input) {
  std::string kill;
		unsigned short int f = 0;
		std::istringstream stream(input);
		stream >> kill >> f;
		if (f > 18 || f == 0){
      std::cout << "Invalid group number " << f << std::endl;
      previousInput = input; return;
    }
		for(unsigned int i = 0; i < elements.size(); i++){
      if (elements[i].groupNum.number == f){
        elements[i].readElement();
        std::cout << std::endl;
      }
    }
}

bool findElementByAtomicNumber(std::string input) {
  int index = -1;
		bool success = false;
		try{
      index = findIndex(input);
      success = true;
    } catch (std::exception& e){}
		if (success) {
      if (index > 117) std::cout << "Input atomic number greater than last discovered element's atomic number: " << index << std::endl;
      else if (index < 0) std::cout << "Input has negative atomic number " << index << std::endl;
      else elements[index].readElement();
    }
  return success;
}

void parseInput(std::string input){
	if(input.length() == 0){
		previousInput = input;
		return;
	}
	if(compare(input,"quit") || compare(input,"leave") || compare(input,"exit")){
		leave = true;
		return;
	} else if(compare(input, "prev") || compare(input, "previous")){
		parseInput(previousInput);
		return;
	} else if(compare(input,"all")){
    printAllElements();
		return;
	} else if (compare (input, "edit")) {
		editFile();
		return;
	} else if (compare(input,"help")){
    printHelpMenu();
		return;
	} else if (compare(input,"clear")){
    clearScreen();
	} else{
    bool result = findElementByAtomicNumber(input);
    if (result) {
      previousInput = input;
      return;
    }
	}
	if (compare(input.substr(0,3),"m: ")){
    findElementByAtomicMass(input);
	} else if (compare(input.substr(0,3),"p: ")){
    printElementsOfPeriod(input);
		return;
	} else if (compare(input.substr(0,3),"g: ")){
    printElementsOfGroup(input);
	} else{
    std::cout << "Invalid input, or the element does not exist." << std::endl;
	}
  previousInput = input;
}

int main(){
  try {
    elements = ElementsInput::getElements();
  } catch (std::exception & e) {
    std::cout << "Could not access any copies of period table files. Exiting." << std::endl;
    return 255;
  }
  clearScreen();
	while(!leave){
		std::string input;
		getline(std::cin, input);
		parseInput(input);
	}
  if (ElementsOutput::hasRevision()){
		ElementsOutput::saveRevision(elements);
		ElementsOutput::deleteRevisions();
	}
}