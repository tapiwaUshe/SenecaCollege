// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 4
#ifndef HEADERNAME_H
#define HEADERNAME_H
namespace sict{
	class Enrollment{
	private:
		char name_[31];
		char code_[11];
		int year_;
		int semester_;
		int slot_;
		bool enrolled_;
	public:
		Enrollment();
		Enrollment(const char* name, const char* code, int year, int semester, int time);
		void display(bool nameOnly = false)const;
		bool isValid()const;
		void setEmpty();
		void withdraw();
		bool isEnrolled() const;
		void set(const char* name, const char* code, int year, int semester, int time, bool enrolled = false);
		bool hasConflict(const Enrollment &other) const;
		int enrol(const Enrollment* enrollments, int size);
	};
}
#endif
