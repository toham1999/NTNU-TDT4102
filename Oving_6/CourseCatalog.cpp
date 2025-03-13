#include "CourseCatalog.h"

// BEGIN: 3a
void CourseCatalog::addCourse(const string& key, const string& value)
{
    courses.insert({key,value});
}
// END: 3a

// BEGIN: 3b
void CourseCatalog::removeCourse(const string& key)
{
    courses.erase(key);
}
// END: 3b

// BEGIN: 3c
string CourseCatalog::getCourse(const string& key) const
{
    
    return courses.at(key);
}
// END: 3c

// BEGIN: 3d
ostream& operator<<(ostream& os, const CourseCatalog& cc) 
{
    for (const auto& course : cc.courses) 
    {
        os << course.first << ":" << course.second << endl;
    }
    return os;
}
// END: 3d

// BEGIN: 3e
void testCourseCatalog()
{
    CourseCatalog cc;
	cc.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    cc.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    cc.addCourse("TMA4100","Matematikk 1");
    cout << cc;
    cc.saveToFile("wow.txt");
}
// END: 3e

// BEGIN: 3g
void CourseCatalog::saveToFile(const string& filename) const
{
    std::ofstream outputStream{filename};
    for (const auto& course : courses) 
    {
        outputStream << course.first << ":" << course.second << endl;
    }
}
// END: 3g

// BEGIN: 3h
void CourseCatalog::loadFromFile(const string& filename) {
    ifstream inputStream{filename};
    
    if (!inputStream) 
	{
		std::cout << "Could not open file" << std::endl;
        return;
	}

    string nextLine;
    while (getline(inputStream, nextLine)) 
    {
        size_t pos = nextLine.find(":");
        string emneKode = nextLine.substr(0, pos);  // Før kolon
        string emneBeskrivelse = nextLine.substr(pos + 1);  // Etter kolon

        addCourse(emneKode, emneBeskrivelse);
    }
}
// END: 3h