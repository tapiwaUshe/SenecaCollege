// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132

#pragma once
#include <string>
class Person{
	public:
		int ID;
        std::string name;
        Person() {}
        Person(int id, std::string nm): ID(id), name(nm){}
        void setID(int id){
            ID = id;
            
        }
    
        void setName(std::string nm){
			name = nm;
		}
    
        int getID(void){
            return ID;
            
        }
    
        std::string getName(void){
            return name;
        }
};
