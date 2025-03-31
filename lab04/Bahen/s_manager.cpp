#include "s_manager.h"


SLink* StudentManager::find(int id){
	SLink * curr = static_cast<SLink *>(list.head);

	while(curr->val.id != id)
		if(curr->next == nullptr) return curr;
		else curr = static_cast<SLink *>(curr->next);
	return curr;
}

void StudentManager::add(Student s){list.push(s);}
void StudentManager::del(int id_to_del){list.pop(find(id_to_del));}

void StudentManager::rewrite(int id_to_change){cin >> find(id_to_change)->val;}

void StudentManager::printAll(){
	SLink * curr = static_cast<SLink *>(list.head);
	cout << curr -> val;
	while(curr->next != nullptr){
		curr = static_cast<SLink *>(curr->next);
		cout << curr -> val;
	}
}
