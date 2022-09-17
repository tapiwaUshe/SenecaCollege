// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 4
#include <iostream>
#include "Enrollment.h"
#include <cstring>
using namespace std;
namespace sict{

	bool Enrollment::isValid()const{
		return name_ && name_[0];
	}

	void Enrollment::setEmpty(){
		name_[0] = 0;
		code_[0] = 0;
		year_ = 0;
		semester_ = 0;
		slot_ = 0;
		enrolled_ = false;
	}

	bool Enrollment::isEnrolled() const{
		return enrolled_;
	}

	void Enrollment::display(bool nameOnly)const{
		if (isValid()){
			cout << name_;
			if (!nameOnly){
				cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "InValid enrollment!" << endl;
		}
	}

	void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){
		if (name && code && name[0] != '\0' && code[0] != '\0' && year >= 2015 && (semester > 0 && semester < 4) && (time > 0 && time < 6)){
			strcpy(name_, name);
			strcpy(code_, code);
			year_ = year;
			semester_ = semester;
			slot_ = time;
			enrolled_ = enrolled;
		}
		else{
			setEmpty();
		}
	}
	Enrollment::Enrollment(){
		setEmpty();
	}
	Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){
		set(name, code, year, semester, time);
	}

	void Enrollment::withdraw(){
		enrolled_ = false;
	}

	int Enrollment::enrol(const Enrollment* enrollments, int size){
		int i;
		for (i = 0; i < size; i++){
			if (year_ == enrollments[i].year_ && semester_ == enrollments[i].semester_ && slot_ == enrollments[i].slot_){
				return i+1;
			}
		}
		enrolled_ = true;
		return 0;
	}

	bool Enrollment::hasConflict(const Enrollment &other) const{
		if (isValid() == false){
			return false;
		}
		else if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_){
			return true;
		}
		else{
			return false;
		}

		//year
		//term
		//time	
	}
}
