#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Pants{
	private:
		string color, name;
		int size;
		double price;
		bool arrow = false;
	public:
		void setColor( string c ){color = c;}
		void setName (string n ) { name = n;}
		void setSize (int s ) { size = s;}
		void setPrice (double p) { price = p;}
		void setArrow (bool b) {arrow = b;}
		void showPants(){
			if(arrow == true){
				cout << right <<  "\x1b[35;1m" << setw(10) << ">" << "\x1b[0m";
			}
			else{
				cout << setw(10) << " ";
			}
			cout << left << setw(2) <<  size << " " << setw(14) << name << "\t$" << price << endl; 
		}

		void showExit(){
			if(arrow == true){
				cout << right <<  "\x1b[35;1m" << setw(10) << ">" << "\x1b[0m";
			}
			else{
			cout << setw(10) << " ";
			}
			cout << left << setw(16) << name << endl; 
		}
};

void choice1();
int main(){

	Pants a, b, c, d;
    a.setName("Slim Dungarees");
    a.setSize(32);
    a.setPrice(198.00);


	b.setName("Futureworks");
	b.setSize(31);
	b.setPrice(148.00);

	
	c.setName("Workdarts");
	c.setSize(31);
	c.setPrice(198.00);

	d.setName("EXIT");
	int value = 0;

	vector<Pants> vPants;
	vPants.push_back(a);
	vPants.push_back(c);
	vPants.push_back(b);
	vPants.push_back(d);
	vPants[0].setArrow(true);
	
	do{
	system("clear");
			ifstream f("outlierart.txt");
			string g;
			while(getline(f, g)){
				cout << "\t" << g << endl;
			}
			cout << "\n\n";

	cout << fixed << setprecision(2);


	vPants[0].showPants();
	vPants[1].showPants();    
	vPants[2].showPants(); 
	vPants[3].showExit();
	cout << endl;

	cout << "\tWASD to navigate, ENTER to select:";

	string line;
	string again;
	getline(cin, line);


	if( line.empty() && value == 0){

		do{
			system("clear");
			ifstream f("outlierart.txt");
			string g;
			while(getline(f, g)){
				cout << "\t" << g << endl;
			}
			cout << "\n\n";

			vPants[0].showPants();
			vPants[1].showPants();    
			vPants[2].showPants(); 
			vPants[3].showExit();
			cout << endl;

			ifstream a("slimdungarees.txt");
			string x;
			while(getline(a, x)){
				cout << "\t" << x << endl;
			}
			cout << endl;
			cout <<  "\tENTER to return:";
			getline(cin, again);
		}while(again.empty() == false);
	
	}

	else if( line.empty() && value == 2){
		do{
			system("clear");
			ifstream f("outlierart.txt");
			string g;
			while(getline(f, g)){
				cout << "\t" << g << endl;
			}
			cout << "\n\n";


			vPants[0].showPants();
			vPants[1].showPants();    
			vPants[2].showPants(); 
			vPants[3].showExit();
			cout << endl;
			ifstream a("futureworks.txt");
			string x;
			while(getline(a, x)){
				cout << "\t" << x << endl;
			}
			cout << endl;
			cout <<  "\tENTER to return:";
			getline(cin, again);
		}while(again.empty() == false);
	}

	else if( line.empty() && value == 1){
		do{
			system("clear");
			ifstream f("outlierart.txt");
			string g;
			while(getline(f, g)){
				cout << "\t" << g << endl;
			}
			cout << "\n\n";


	vPants[0].showPants();
	vPants[1].showPants();    
	vPants[2].showPants(); 
	vPants[3].showExit();
			cout << endl;
			ifstream a("workdarts.txt");
			string x;
			while(getline(a, x)){
				cout << "\t" << x << endl;
			}
			cout << endl;
			cout <<  "\tENTER to return:";
			getline(cin, again);
		}while(again.empty() == false);
	}
	else if( line.empty() && value == 3){
		return 0;
	}

	else if(line == "s" || line == "d"){
		if(value == 3){
			vPants[value].setArrow(false);
			value = 0;
			vPants[value].setArrow(true);}
		else{
			vPants[value].setArrow(false);
			value ++;
			vPants[value].setArrow(true);

		}
	}

	else if(line == "w" || line == "a"){
		if(value == 0){
			vPants[value].setArrow(false);
			value = 3;
			vPants[value].setArrow(true);
		}
		else{
			vPants[value].setArrow(false);
			value --;
			vPants[value].setArrow(true);
		}
	}


	cout << endl;
	cout << endl;
	system("clear");
	} while (value != 4);
}

void choice1(){
	system("clear");
	ifstream f("outlierart.txt");
	if (f.is_open() )
		cout << f.rdbuf();
	cout << endl << endl;
}

