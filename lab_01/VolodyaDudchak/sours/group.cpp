#include <bits/stdc++.h>
#include "../head/group.h"
using namespace std;
#define FOR(i, st_, n) for(int i = st_; i < n; ++i)


group::group(){
    numb = 0, sz = 0, students = new student[0];
}
group::group(int nu, int s, student* st)
{
    numb = nu, sz = s, students = st;
}
void group::add(student st)
{
    student* cur = new student[sz+1];
    FOR(i,0,sz)
        cur[i] = students[i];
    cur[sz] = st;
    students = cur;
    sz++;
}
void group::change_Numb(int i){
    numb = i;
}
int group::getSz(){
    return sz;
}
istream& operator >> (istream& in, group& a){
    in >> a.numb >> a.sz;
    for(int i = 0; i < a.sz; i++)
        in >> a.students[i];
    return in;
}
ostream& operator << (ostream& out, group& a){
    out << "group - " << a.numb  << " has " << a.sz << " students"<< endl;
    FOR(i,0,a.sz)
        out << a.students[i];
    return out;
}