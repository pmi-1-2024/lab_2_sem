#include "functions.h"

void read(string src, Phone ** list, int &index){
	ifstream inp(src);
	while(!inp.eof()){
		Phone *p;
		string type;

		inp >> type;

		if(type == "R")
			p = new RadioPhone();

		else if(type == "M")
			p = new MobilePhone();

		p->input(inp);
		list[index] = p;
		index ++;
	}
	inp.close();
}

void write(string src, Phone ** list, int size){
	ofstream out(src);
	for(int i = 0; i < size; i ++)
			list[i]->print(out);
	out.close();
}

void quick_sort(Phone** list, int l, int r) {
    int left = l;
    int right = r;
    int mid = list[(left + right) / 2]->get_price();
    Phone * t;

    while (left <= right) {
        while (list[left]->get_price() < mid) {
            left++;
        }
        while (list[right]->get_price() > mid) {
            right--;
        }
        if (left <= right) {
            t = list[left];
            list[left]=list[right];
            list[right]=t;
            left++;
            right--;
        }
    }

    if (l < right) {
        quick_sort(list, l, right);
    }
    if (r > left) {
        quick_sort(list, left, r);
    }
}

Phone ** has_auto(Phone ** list, int size, int & res_size){


	RadioPhone ** buff = new RadioPhone*[size];
	int j = 0;
	for(int i = 0; i < size; i ++){
		if(list[i]->get_type() == "R"){
			buff[j] = dynamic_cast<RadioPhone*>(list[i]);
			cout << i;
			j ++;
		}}

	Phone ** res = new Phone*[j];
	int k = 0;
	for(int i = 0; i < j; i ++)
		if(buff[i]->has_auto()){
			res[k] = &(*buff[i]);
			k ++;
		}
	res_size = k;
	return res;
}
