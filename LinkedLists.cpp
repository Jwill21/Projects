#include <iostream>
#include<ios>     // for <streamsize>
#include<limits>  // for numeric_limits

using namespace std;

struct Node
{
	string name;
	int age;
	Node* next;
};

int menu();
void append_node(Node* &); // *& this mean pass the pointer by reference // so I can change the data of the pointer directly
void print_list(Node*);
Node* find_node(Node*, string);
void find_node(Node*);
void remove_node(Node* &);
void update_data(Node* &);
void free_data(Node* &);
void sort_data(Node* &);
void insert_node(Node* &);

int main()
{
	
	int sel;
	Node* temp;

	Node *students = nullptr;
	
	do
	{
		sel = menu();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		
		switch (sel)
		{
			case 1:
				append_node(students);
				break;
			case 2:
				remove_node(students);
				break;
			case 3:
				find_node(students);
				break;
			case 4:
				cout << endl << "-------------" << endl;
				print_list(students);
				cout << "-------------" << endl;
				break;
			case 5:
			  update_data(students);
				break;
			case 6:
				sort_data(students);
				print_list(students);
				break;
			case 7:
				insert_node(students);
				break;
			case 8:
			  free_data(students);
			  break;
			default:
				cout << "Selection Error" << endl << endl;
				break;
		}
		
		
	} while (sel != 8);
	  
	  if (sel == 8) {
	  cout << endl;
	  cout << "Goodbye.";
	}
	
	return 0;
}


void remove_node(Node* &list)
{
	Node *current, *previous;
	current = list;
	previous = nullptr;
	string name;
	cout << "Enter Name of student to remove: ";
	getline(cin,name);
	
	if (current) // if list exist
	{
		
		//if the first node is the match
		
		if (current->name == name)
		{
			list = current->next;
			delete current;
			
		}
		else
		{
		
			// skip all nodes whose value member is not equal to search
			while(current != nullptr && current->name != name)
			{
				previous = current;
				current = current->next;
			}

			if(current) // if not at end of list
			{
				previous->next = current->next;
				delete current;

			}
		}
	}
}

int menu()
{
	int temp;
	cout << endl;
	cout << "----------------" << endl;
	cout << "(1) Add" << endl;
	cout << "(2) Remove " << endl;
	cout << "(3) Find" << endl;
	cout << "(4) Show" << endl;
	cout << "(5) Update" << endl;
	cout << "(6) Sort" << endl;
	cout << "(7) Insert" << endl;
	cout << "(8) Quit" << endl;
	cout << "----------------" << endl;
	cout << "Selection: ";
	cin >> temp;
	return temp;
	
}

void find_node(Node *s)
	{
		Node* temp;
		string name;
		cout << "Enter Name of Student to find: ";
		getline(cin,name);
		temp = find_node(s,name);
		cout << endl << "-------------" << endl;
		if (temp)
				cout << "Name: " << temp->name << " Age: " << temp->age << endl;
		else
			 	cout << "Student does not exist" << endl;
		cout << "-------------" << endl;
	}

Node* find_node(Node* list, string name)
{
	
	if (list)
	{
		
		if(list->name == name)
			return list;
		else
			return find_node(list->next, name);
		
	}
	else
		return nullptr;
	
}

void print_list(Node* list)
{
	if (list)
	{
		cout << "Name: " << list->name << " Age: " << list->age << endl;
		print_list(list->next);
	}
}


void append_node(Node* &list)
{
	// *& pass pointer by reference
	
	int age;
	string name;
	
	cout << "Enter Student Name: ";
	getline(cin,name);
	cout << "Enter Age: ";
	cin >> age;
	
	Node* current = list;
	Node* temp = new Node;
	temp->name = name;
	temp->age = age;
	temp->next = nullptr;
	
	if (!list) // nothing in the list
	{
		list = temp;
	}
	else // list is not empty
	{
		// Find the last node in the list.
		while(current->next) 
		{
			current = current->next;
		}
		
		// Insert newNode as the last node
		current->next = temp;
		
	}
}

void update_data(Node* &list)
{
  string temp_name;
  int temp_age;
  
  if (list == nullptr){ //if list is empty
    cout << "There is nothing in this list." << endl;
  }
 
  if (list != nullptr){ //if list contains data
    string search_name;
    cout << "Enter the name of the student to update: " << endl;
    getline(cin, search_name);
    
    if (list){
      if (list->name == search_name){
        cout << "Enter updated student name: ";
        getline(cin, temp_name);
        cout << "Enter updated student age: ";
        cin >> temp_age;
        
        list->name = temp_name;
        list->age = temp_age;
        
      } else {
        cout << "Student not found.";
      }
    }
  }
}

void free_data (Node* &list)
{
   if (list){ 
   
   Node* temp = new Node;
   temp = list;
   list = list->next;
   delete temp;
   free_data(list->next);
  }
}

void sort_data (Node* &list) //bubble sort technique
{
  Node* i, *j;
  i = list;
  int temp;
  string temp_name;
  
  for (i = list; i->next != nullptr; i = i->next){ // passes
    for (j = i->next; j !=nullptr; j = j->next){ //checks
      if (i->age > j->age){
        
		temp = i->age;
        i->age = j->age;
        j->age = temp;
        
        temp_name = i->name;
        i->name = j->name;
        j->name = temp_name;
      }
    }
  }
}

void insert_node (Node* &list){

	int age;
	string name;

	cout << "Enter students name: " << endl;
	getline(cin, name);
	cout << "Enter students age: " << endl;
	cin >> age;

	Node* current = list;
	Node* temp = new Node;
	temp->name = name;
	temp->age = age;
	temp->next = nullptr;

	if (!list){
		list = temp;
	} else {
		while (current->next){
			current = current->next;
		}   
			current->next = temp; 
	}		cout << endl << endl;
	    sort_data(list);
	    print_list(list);
}
