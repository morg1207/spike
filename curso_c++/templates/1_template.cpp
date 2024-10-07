#include <memory>
#include <vector>
#include <iostream>


struct Transform {
  
 	int x_{10};
    int y_{20};
  
};
struct Render {
 	char sprite{'A'} ;
};

struct Entity{
  	Entity(std::string name) noexcept
 		: name_{name}
	{}
  	
   void print_info(Entity* entity){
    std::cout << "El name es " << name_ << std::endl; 
     if(entity->render_){
       std::cout << "Hay render " << std::endl; 
     }
     if(entity->transform_){
       std::cout << "Hay trasform " << std::endl; 
     } 
   }
	
  	std::string name_;
  	Transform* transform_{};
 	Render* render_{};
};

Transform* create_component(int) noexcept
{
 	return new Transform{}; 
}

Render* create_component(float) noexcept
{
 	return new Render{}; 
}


int main (){
  
  Entity player{"Player"};
  player.transform_ = create_component(1);
  player.render_ = create_component(2.5f);
  player.print_info(&player);
  Entity grillo{"Grillo"};
  Entity spawner{"Spawner"};
  
 
 return 0; 
}