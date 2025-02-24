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
void group::out()
{
    cout << "group - " << numb  << " has " << sz << " students"<< endl;
    FOR(i,0,sz)
        students[i].out();
}
void group::change_Numb(int i){
    numb = i;
}
int group::getSz(){
    return sz;
}
