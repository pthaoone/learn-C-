#include<iostream>
#include<string>
#include<list>
using namespace std;
class Student{
    private:
    int ID;
    string Name;
    int Date, Month, Year;
    float Score;
    
    public:
    //input student details
    void input(){
        cout << "Ma so sinh vien: ";
        cin >> ID;
        cout << "Ho ten sinh vien: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Ngay sinh: "; cin >> Date;
        cout << "Thang sinh: "; cin >> Month;
        cout << "Nam sinh: "; cin >> Year;
        cout << "Diem trung binh: "; cin >> Score;
    }
    void display()const{
        cout << "Ma so sinh vien: " << ID << endl;
        cout << "Ho ten sinh vien: " << Name << endl;
        cout << "Ngay sinh: " << Date << "/" << Month << "/" << Year << endl;
        cout << "Diem trung binh: " << Score << endl;
    }
    float getscore()const{
        return Score;
    }
    int getID()const{
        return ID;
    }
};
//displays student imformation
void display_Student(const list<Student>& classroom){
    cout << "\n Student Data: \n";
    for(const Student& student:classroom){
        student.display();
        cout << endl;
    }
}
//find ID
Student* findIDStudent(const list<Student>& classroom, int ID){
    for(const Student& student:classroom){
        if(student.getID() == ID){
            return new Student(student);
        }
    }
    return nullptr;
}
//find the student with the highest score
void findMaxScore(const list<Student>& classroom){
    if(classroom.empty()){
        cout << "No student in the list.\n";
        return;
    }
    float maxScore = classroom.front().getscore(); 
    for(const Student& student:classroom){
        if(student.getscore() > maxScore){
            maxScore = student.getscore();
        }
    }
    cout << "\nSinh vien co so diem trung binh cao nhat la:\n";
    for(const Student& student:classroom){
        if(student.getscore() == maxScore){
            student.display();
        }
    }
}
//find the student with the lowest score
void findMinScore(const list<Student>& classroom){
    if(classroom.empty()){
        cout << "No student in the list.\n";
        return;
    }
    float minScore = classroom.front().getscore();
    /*phương thức front() của lớp list trả về tham chiếu tới phần tử đầu tiên trong danh sách classroom
    Khi dùng classroom.front().getscore() là gọi phương thức getscore() trên đối tượng Student đầu tiên trong danh sách classroom*/
    for(const Student& student:classroom){
        if(student.getscore() < minScore){
            minScore = student.getscore();
        }
    }
    cout << "\nSinh vien co so diem trung binh thap nhat la:\n";
    for(const Student& student:classroom){
        if(student.getscore() == minScore){
            student.display();
        }
    }
}

int main(){
    list<Student> classroom;
    int numStudent;
    cout << "Enter so luong sinh vien: ";
    cin >> numStudent;
    for(int i = 0; i < numStudent; i++){
        Student student;
        cout << "Thong tin sinh vien [" << i + 1 << "]: " << endl;
        student.input();
        classroom.push_back(student);
    }
    int choice;
    do{
        cout << "\nMenu: \n";
        cout << "1. Nhap lieu: Them sinh vien moi vao danh sach.\n";
        cout << "2. Hien thi tat ca: Hien thi danh sach sinh vien.\n";
        cout << "3. Tim kiem: Tim kiem sinh vien theo ma so sinh vien.\n";
        cout << "4. Hien thi sinh vien co diem trung binh cao nhat.\n";
        cout << "5. Hien thi sinh vien co diem trung binh thap nhat.\n";
        cout << "6. Thoat chuong trinh.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                Student student;
                student.input();
                classroom.push_back(student);
                break;
            }
            case 2:
            display_Student(classroom);
            break;
            case 3:
            {
            int searchID;
            cout << "Enter ma so sinh vien can tim: ";
            cin >> searchID;
            Student* foundStudent = findIDStudent(classroom, searchID);
            if (foundStudent != nullptr) {
                cout << "Student found:\n";
                foundStudent->display();
                delete foundStudent;
                } 
            else {
                cout << "Student with ID " << searchID << " not found.\n";
                }
            break;
            }
            case 4:
            findMaxScore(classroom);
            break;
            case 5:
            findMinScore(classroom);
            break;
            case 6:
            cout << "Thoat chuong trinh.\n";
            break;
            default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
        while(choice != 6);
        return 0;
}
