#include "test.cpp"


int32_t main()
{
    int n,m;
    string tr;
    in >> n >> m;
    student * students = new student[n];
    group* groups = new group[m];
    FOR(i,0,n)
    {
        students[i].inp();
    }
    {
        FOR(i,0,n)
        students[i].out();
    }
    FOR(i,0,m)
    {
        groups[i].change_Numb(i);
    }
    FOR(i,0,n)
    {
        groups[students[i].getGroup()].add(students[i]);
    }
    FOR(i,0,m)
    {
        if(groups[i].getSz() != 0)
            groups[i].out();
        else
            cout << "group " << i+1 << " has no students" << endl;
    }
    while(true)
    {
        cout << "to find a student type 1: ";
        string t;
        cin >> t;
        if(t != "1")
            break;
        cout << "give the type of information: name - 1, addres - 2, zalikovka - 3, group - 4, predmet - 5, semester - 6: ";
        int t1;
        cin >> t1;
        cout << "give information: ";
        string cur;
        cin >> cur;
        switch(t1){
            case 1:
                studFindName(students,cur,n);
                break;
            case 2:
                studFindAdd(students,cur,n);
                break;
            case 3:
                studFindNumbZali(students,cur,n);
                break;
            case 4:
                studFindNumbGroup(students,cur,n);
                break;
            case 5:
                studFindPredm(students,cur,n);
                break;
            case 6:
                studFindSem(students,cur,n);
                break;
        }
        cout << endl;

    }
    in.close();
}
