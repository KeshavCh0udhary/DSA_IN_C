#include<iostream>
#include<string.h>
typedef struct Student{
    
    int data;
    void setData(int age, char* name,char data[]){
        this->age = age;
        this->name = name;
        strcpy(courseDetail,data);
    }
    void printData(){
   
        std::cout<<this->name<<std::endl;
        std::cout<<this->age<<std::endl;
        std::cout<<this->courseDetail<<std::endl;
    }
    private:
    char courseDetail[50];
    int age;
    char* name;

    
}s;

int main(){
    s *s = new Student;
    s->data = 10;
    s->setData(23,"Krishna Keshav","B.Tech in computer science and engineering");
    std::cout<<s->data<<std::endl;
    s->printData();
    delete s;
} 