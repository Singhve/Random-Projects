#include <bits/stdc++.h>

using namespace std;

struct node{
	int student_no;
	int class_no;
	int grade;
	node *right;
	node *down;
};

class multilist{
	node *head;

public:
	multilist(){
		head = NULL;
		addDummyNodes();
	}
	void addDummyNodes();
	void insert(int s, int c);
	void printClass();
	void printStudent();
};

void multilist::addDummyNodes(){
	node *newNode = new node;
	newNode->right = NULL;
	newNode->down = NULL;
	newNode->student_no = 0;
	newNode->class_no = 0;
	head = newNode;
	node *ptr;
	ptr = head;
	for(int i=1; i<=10000; ++i){
		node *temp = new node;
		temp->student_no = i;
		temp->class_no = 0;
		ptr->right = temp;
		ptr = temp;
	}
	ptr = head;

	for(int i=1; i<=3000; ++i){
		node *temp = new node;
		temp->class_no = i;
		temp->student_no = 0;
		ptr->down = temp;
		ptr = temp;
	}
	return;
}

void multilist::insert(int s, int c){
	node *newNode = new node;
	newNode->student_no = s;
	newNode->class_no = c;
	node *ptr;
	node *prev;
	ptr = head;
	for(int i=1; i<=s; ++i){
		ptr = ptr->right;
	}
	prev = NULL;
	while(ptr!=NULL && ptr->class_no < c){
		prev = ptr;
		ptr = ptr->down;
	}

	if(ptr == NULL){
		prev->down = newNode;
		newNode->down = NULL;
	}else if(ptr->class_no == c){
		cout<<"Student-Class combination already present in multilist"<<endl;
		return;
	}else{
		prev->down = newNode;
		newNode->down = ptr;
	}

	ptr = head;
	prev = NULL;
	for(int i=1; i<=c; ++i){
		ptr = ptr->down;
	}

	while(ptr != NULL && ptr->student_no < s){
		prev = ptr;
		ptr = ptr->right;
	}

	if(ptr == NULL){
		prev->right = newNode;
		newNode->right = NULL;
	}else if(ptr->student_no == s){
		cout<<"Student-Class combination already present in multilist"<<endl;
		return;
	}else{
		prev->right = newNode;
		newNode->right = ptr;
	}

	return;

}

void multilist::printClass(){
	node *ptr;
	node *temp;
	ptr = head;
	for(int i=1; i<=3000; ++i){
		ptr = ptr->down;
		if(ptr->right != NULL){
			cout<<"Class "<<ptr->class_no<<": students ";
			temp = ptr->right;
			while(temp->right != NULL){
				cout<<temp->student_no<<", ";
				temp = temp->right;
			}
			cout<<temp->student_no<<";"<<endl;
		}
	}
	return;
}

void multilist::printStudent(){
	node *ptr;
	node *temp;
	ptr = head;
	for(int i=1; i<=10000; ++i){
		ptr = ptr->right;
		if(ptr->down != NULL){
			cout<<"Student "<<ptr->student_no<<": classes ";
			temp = ptr->down;
			while(temp->down != NULL){
				cout<<temp->class_no<<", ";
				temp = temp->down;
			}
			cout<<temp->class_no<<";"<<endl;
		}
	}
	return;
}

int main(){
	multilist m;
	while(1){
		cout<<"Choose:\n1. Input student and class.\n2. Print class lists.\n3. Print student lists.\n4. Exit"<<endl;
		int choice,s,c;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter student number and class number separated by space."<<endl;
				cin>>s>>c;
				m.insert(s,c);
				break;
			case 2:
				m.printClass();
				break;
			case 3:
				m.printStudent();
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"Please enter a valid choice"<<endl;
		}
	}
}