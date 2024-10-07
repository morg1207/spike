#include <iostream>
#include <string>
#include <functional>
#include <map>

struct Character {
    std::string name_{"None" };

    void print_character() noexcept
    {
        std::cout << "Character name is "<< this->name_ << "\n";
    }

};

class Robot{
    public:

        std::string name_{"None"};
        void name_robot() noexcept
        {
            std::cout << "Robot name is "<< name_ << "\n";
        }
};


class EventSystem_test {
public:
    void bind_action(Character* character) noexcept
    {
        actions_.push_back(character);
    }
    void dispatch() noexcept
    {
        for(auto& character : actions_){
            character->print_character();
        }

    }
private:
    std::vector<Character*> actions_;

};




class EventSystem {
public:
    void bind_action(Character* character , std::function<void(Character*)> action) noexcept
    {
        actions_.insert(std::pair(character, action));
    }
    void dispatch() noexcept
    {
        for(auto& [character,action] : actions_){
            action(character);
        }

    }
private:
    std::map<Character*,std::function<void(Character*)>> actions_{};

};


class EventSystemClass {
public:
    void bind_action(Robot* character , std::function<void(Robot*)> action) noexcept
    {
        actions_.insert(std::pair(character, action));
    }
    void dispatch() noexcept
    {
        for(auto& [character,action] : actions_){
            action(character);
        }

    }
private:
    std::map<Robot*,std::function<void(Robot*)>> actions_{};

};



int main(){
    Character player{"iwo"};
    Character enemy{"Smash"};
    Robot npg{"Jovan"};
    EventSystem event_system{};
    EventSystemClass event_system_class{};

    EventSystem_test event_system_clas_tests{};


    event_system.bind_action(&player, &Character::print_character);
    event_system.bind_action(&enemy, [](Character* character) {
        std::cout << "Character enemy is "<< character->name_ << "\n";
    });

    event_system_class.bind_action(&npg, &Robot::name_robot);

    event_system_clas_tests.bind_action(&player);



    event_system.dispatch();
    event_system_class.dispatch();
    event_system_clas_tests.dispatch();
    return 0;
}