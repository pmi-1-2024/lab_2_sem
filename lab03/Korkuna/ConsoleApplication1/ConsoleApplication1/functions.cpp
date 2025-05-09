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

		else 
					p = new ComboPhone();

		inp >> *p;
		list[index] = p;
		index ++;
	}
	inp.close();
}

void write(string src, Phone ** list, int size){
	ofstream out(src);
	for(int i = 0; i < size; i ++)
			out << *list[i];
	out.close();
}


Phone ** find(string field, string request, Phone ** list, int size, int & res_size){
	Phone ** res = new Phone *[size];
	int j = 0;
	string var;
	res_size = 0;
	for(int i =  0; i<size; i++){
		if(field == "Type")
			var = list[i]->get_type();
		else if(field == "Firm")
			var = list[i]->get_firm();
		else if(field == "Name")
			var = list[i]->get_name();
		else{
			break;
		}
		if(var == request){
			res[j] = list[i];
			j ++;
		}
	}
	res_size = j;
	return res;
}

void search(Phone ** list, int size){
	string f, r, name;
	Phone ** responce;
	int r_size;
	cout << "Possible requests - Type, Firm, Name, All"<<endl<<"Stop working - End"<<endl<<endl;

	while(true){
		cout << "Request: ";
		cin >>f;

		if(f == "End") break;
		if(f == "All"){
			responce = list;
			r_size = size;
		}
		else{
			cout << "Value: ";
			cin >> r;
			responce = find(f,r,list,size,r_size);
		}

		if(r_size != 0){
		cout << "Name of file: ";
		cin >> name;

		write("responces/"+name+".txt", responce, r_size);

		cout << "Answer saved"<<endl;
		}
		else cout << "Something went wrong"<<endl;

		cout<<endl;

	}
}
