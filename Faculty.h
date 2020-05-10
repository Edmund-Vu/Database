#include "NaiveList.h"

using namespace std;

class Faculty{
  public:
    int id;
    string name;
    string level;
    string dept;
    NaiveList<int>* adv;

    Faculty();
    Faculty(string name, string level, string dept);
    Faculty(string name, string level, string dept, int id);
    Faculty(int id);
    ~Faculty();
    void addAdv(int id);
    void delAdv(int id);

    friend ostream& operator<<(ostream& os, const Faculty& f);
    friend bool operator> (const Faculty &s1, const Faculty &s2);
    friend bool operator< (const Faculty &s1, const Faculty &s2);
    friend bool operator== (const Faculty &s1, const Faculty &s2);
    friend bool operator!= (const Faculty &s1, const Faculty &s2);
};
