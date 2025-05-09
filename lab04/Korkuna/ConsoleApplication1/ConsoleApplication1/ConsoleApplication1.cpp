#include "s_manager.h"
using namespace std;

int main() {
	srand(time(0));
	StudentManager m;
	int n;
	cout << "Number: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		Student s;
		cin >> s;
		m.add(s);
	}

	m.printAll();
}