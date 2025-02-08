#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Task{
    string description;
    bool completed;
};

void displaymenu(){
    cout<<"1. Enter new Task"<<endl;
    cout<<"2. Display tasks"<<endl;
    cout<<"3. Mark Task as completed"<<endl;
    cout<<"4. Delete Task"<<endl;
    cout<<"5. Exit"<<endl;
}

void addtask(vector<Task>& Tasks){
    Task newtask;
    cout<<"Enter task description"<<endl;
    cin.ignore();
    getline(cin,newtask.description);
    newtask.completed=false;
    Tasks.push_back(newtask);

}

void displaytask(const vector<Task>& Tasks){
    if(Tasks.empty()){
        cout<<"Task list is empty, kindly enter a new task. "<<endl;
    }
    for(size_t i=0;i<Tasks.size();++i){
        cout<<(i+1)<<"."<<Tasks[i].description;
        if(Tasks[i].completed){
            cout<<" (Completed)";
        }
        cout<<endl;
    }
}

void completetask(vector<Task>& Tasks){
    displaytask(Tasks);
    int tasknumber;
    cout<<"Enter task number to be completed:- "<<endl;
    cin>>tasknumber;
    if(tasknumber>0&&tasknumber<=Tasks.size()){
        Tasks[tasknumber-1].completed=true;
        cout<<"Task marked as completed"<<endl;
    }
    else{
        cout<<"Invalid task number!!"<<endl;
    }
    
}

void deletetask(vector<Task>& Tasks){
    displaytask(Tasks);
    int tasknum;
    cout<<"Enter the task number of the task which you want to delete"<<endl;
    cin>>tasknum;
    if(tasknum>0 && tasknum<=Tasks.size()){
        Tasks.erase(Tasks.begin()+(tasknum-1));
        cout<<"Given task deleted successfully"<<endl;
    }
    else{
        cout<<"Invalid task number entered!!"<<endl;
    }
    cout<<endl;

}

int main(){
    vector<Task> Tasks;
    int choice;
    do{
        displaymenu();
        cout<<"Enter your choice:- ";
        cin>>choice;
        if(choice < 1 || choice > 5) {
            cout << "Invalid choice. Please choose again." << endl;
        } else {
            switch (choice){
                case 1:
                    addtask(Tasks);
                    break;
                case 2:
                    displaytask(Tasks);
                    break;
                case 3:
                    completetask(Tasks);
                    break;
                case 4:
                    deletetask(Tasks);
                    break;
                case 5:
                    cout<<"Exiting the program..."<<endl;
                    break;
            }
        }
    }while(choice!=5);
    return 0;
}