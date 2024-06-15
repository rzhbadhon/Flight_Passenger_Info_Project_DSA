#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    string destinationCountry;
    int seatNumber; 
    node* next;

    node(string name, string destinationCountry, int seatNumber) {
        this->name = name;
        this->destinationCountry = destinationCountry;
        this->seatNumber = seatNumber;
        this->next = NULL;
    }
};

void insertatHead(node*& head, string name, string destinationCountry, int seatNumber) {
    node* newN = new node(name, destinationCountry, seatNumber);
    newN->next = head;
    head = newN;
}

void insertatEND(node*& head, string name, string destinationCountry, int seatNumber) {
    node* newN = new node(name, destinationCountry, seatNumber);
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newN;
}

void display(node* head) {
    node* temp = head;
    int x = 1;
    while (temp != NULL) {
        cout << x << ". Seat Number: " << temp->seatNumber << ", Name: " << temp->name << ", Destination: " << temp->destinationCountry << endl;
        temp = temp->next;
        x++;
    }
    cout << endl;
}


void searchN(string& pat, node* head) {
    int M = pat.size();

    node* t = head;
    int p = 1;
    while (t != NULL) {
        string x = t->name;
        int N = x.size();

        for (int i = 0; i <= N - M; i++) {
            int j;
            for (j = 0; j < M; j++) {
                if (x[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M) {
                cout<<"Passenger Name: "<<t->name<<endl;
                cout<<"Destination Country: " <<t->destinationCountry<<endl;
                cout<<"Seat Number: " << t->seatNumber<<endl;
                break; 
            }
        }
        t = t->next;
        p++;
    }
}

void searchS(int seatN, node* head) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->seatNumber==seatN)
        {
           cout<<"Passenger Name: "<<temp->name<<endl;
           cout<<"Destination Country: " <<temp->destinationCountry<<endl;
           cout<<"Seat Number: " << temp->seatNumber<<endl;
        }
        
        temp = temp->next;
    }
}

void edit(node* &head, int seat){
    cout<<"1. Name Edit"<<endl;
    cout<<"2. Destination Country Edit"<<endl;
    cout<<"3. Seat Number Edit"<<endl;
    cout<<"Enter Choice: ";
    cin.ignore();
    int c;
    cin>>c;
    if(c==1){
        cout<<"Enter new name: ";
        cin.ignore();
        string newName;
        getline(cin,newName);
        node* temp=head;
        int cp= 1;
        while(cp != seat){
            temp=temp->next;
            cp++;
        }
        temp->name=newName;
    }
    else if(c==2){
        cout<<"Enter new destination country: ";
        cin.ignore();
        string newc;
        getline(cin,newc);
        node* temp=head;
        int cp= 1;
        while(cp != seat){
            temp=temp->next;
            cp++;
        }
        temp->destinationCountry=newc;
    }
    if(c==3){
        cout<<"Enter new seat number: ";
        cin.ignore();
        int x;
        cin>>x;
        node* temp=head;
        int cp= 1;
        while(cp != seat){
            temp=temp->next;
            cp++;
        }
        temp->seatNumber=x;
    }
}
void passremove(node* &head, int sn) {
    node* temp = head;

    if (sn == 1) {
        head = head->next;
        delete temp;
        cout <<"Passenger Removed From The Flight"<< endl;
        return;
    }

    int x = 1;
    while (temp != NULL && x < sn - 1) {
        temp = temp->next;
        x++;
    }

    node* del = temp->next;
    temp->next = del->next;
    delete del;
    cout <<"Passenger Removed From The Flight"<< endl;
}

int main() {
    node* head = NULL;
    int snc = 1; 

    while (true) {
        cout << "Flight Passenger Information" << endl;
        cout << "1. Add passenger information" << endl;
        cout << "2. Display passenger list" << endl;
        cout << "3. Search for passenger by name" << endl;
        cout << "4. Edit or Change Passenger Information by Seat Number"<<endl;
        cout << "5. Remove a Passenger From Flight"<<endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string name, destinationCountry;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter destination country: ";
            getline(cin, destinationCountry);
            
            int seatNumber = snc++;
            
            if (head == NULL) {
                insertatHead(head, name, destinationCountry, seatNumber);
            }
            else {
                insertatEND(head, name, destinationCountry, seatNumber);
            }
        }
        else if (choice == 2) {
            if (head == NULL) {
                cout << "No passengers to display." << endl;
            }
            else {
                display(head);
            }
        }
        else if(choice==3){
            string s;
            int c;
            cout<<"1. Search by Name"<<endl;
            cout<<"2. Search by Seat Number"<<endl;
            cout<<"Enter Choice: ";
            cin.ignore();
            cin>>c;
            if(c==1){
                cout<<"Enter Name: ";
                cin.ignore();
                getline(cin,s);
                searchN(s,head);
            }
            else if(c==2){
                cout<<"Enter Seat Number: ";
                cin>>c;
                searchS(c,head);
            }
        }
        else if(choice==4){
            cout<<"Enter Seat Number: ";
            int c;
            cin>>c;
            edit(head,c);
        }
        else if(choice==5){
            cout<<"Enter Seat Number: ";
            cin.ignore();
            int c;
            cin>>c;
            passremove(head,c);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
