#include <iostream>
#include <chrono>
#include <memory>
#include <vector>

class Robot {
public:
    Robot(std::string & namerobot) : name_(namerobot){

        printf("constructor was called of robot  %s \n", name_.c_str());
    }
    ~Robot(){

        printf("Destructor was called of robot  %s \n", name_.c_str());
    }
    void print_name(){
        printf("The robot name is %s \n", name_.c_str());
    }

private:
    std::string name_; 
 
};

void anotherFunction(std::unique_ptr<Robot> &uniue){

    std::cout << "Another fucntion was execute"<< std::endl;
}


int main(){
    std::string robot_name_1 = "Mecanum";
    Robot robot_1 = Robot(robot_name_1);

    std::string robot_name_2 = "Diferencial";
    std::unique_ptr<Robot> robot_2 { new Robot(robot_name_2)};
    // Robot robot_2_copy = robot_2; // No puedo apuntar al un puntero compartido

    std::string robot_name_3 = "Qudruped";
    Robot *robot_3 = new Robot(robot_name_3);
    Robot *robot_3_copy = robot_3; //puedo crear otro puntero ue apunta a un no unique pointer

    std::vector<int> *myvec = new std::vector<int>();
    myvec->push_back(4);
    std::cout << "Vector creado" << std::endl;
    delete myvec;
    anotherFunction(robot_2);

    Robot * robot_ptr = robot_3;

}