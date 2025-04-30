#include "iostream"
#include <cstdlib>
#include "algorithm"
#include "list"
#include "vector"
#include "thread"
#define HEIGHT 10
#define WIDTH 10


enum class Direction {UP, RIGHT, DOWN, LEFT};

enum class Turn {LEFT, RIGHT};

enum class State {RUNNING, PAUSED, GAME_OVER};

class Snake{
public:
    Direction direccion_;
    int vel_;
    int posicion_;
    Snake(Direction dir,int vel,int pos){
        direccion_ = dir;
        vel_ = vel;
        posicion_ = pos;

    }
};

std::vector<int> vec_window;

void init_window(int height, int width);
void print_window();
int generate_pos_rand();
int update_index_head(Direction , int velocidad, int index);

float check_colision(int index); 

int main() {
    std::cout << "Init program" << std::endl;

    Snake smake(Direction::UP, 1, 0);

    init_window(HEIGHT, WIDTH);
    int index_init = generate_pos_rand();
    std::cout << "Index init: " << index_init << std::endl;
    int index_current = index_init;

    float colision = false;

    while(true) {
        system("clear");
        index_current = update_index_head(Direction::UP, 1, index_current);
        colision = check_colision(index_current);
        if(colision != true){
            print_window();
        }
        else{
            index_current = update_index_head(Direction::RIGHT, 1, index_current);
            if(colision != true){
                print_window();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    print_window();
    return 0;
}

void init_window(int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(i == 0 || i == height - 1) {
                std::cout << "* ";
                vec_window.push_back(1);
                continue;
            }
            if(j == 0 || j == width - 1) {
                std::cout << "* ";
                vec_window.push_back(1);
                continue;
            }
            else {
                std::cout << "  ";
                vec_window.push_back(0);
            }
        }
        std::cout << std::endl;
    }
}

int generate_pos_rand(){ 
    int pos = rand() % ((HEIGHT-2)*(WIDTH-2));
    std::cout << "Posición generada: " << pos << std::endl;
    int x = pos % (HEIGHT-2) + 1;
    int y = pos / (HEIGHT-2) + 1;
    // le asigno la comida
    vec_window[x*WIDTH + y] = 2;
    return x*WIDTH + y;
}

int update_index_head(Turn dir, Snake snake, int index){
    int head = index;
    std::cout << "Head: " << head << std::endl;
    // Manejamos el giro de la dirección de la serpiente
    if (dir == Turn::LEFT) {
        snake.direccion_ = static_cast<Direction>((static_cast<int>(snake.direccion_) + 3) % 4);
    } else if (dir == Turn::RIGHT) {
        snake.direccion_ = static_cast<Direction>((static_cast<int>(snake.direccion_) + 1) % 4);
    }
    switch (snake.direccion_){
        case Direction::UP:
            head = head - WIDTH*snake.vel_;
            break;
        case Direction::DOWN:
            break;
        case Direction::LEFT:
            head = head - 1;
            break;
        case Direction::RIGHT:
            head = head + 1;
            break;
    }

    return head;
}

float check_colision(int index){
// Si el espacio esta libre

    if ( vec_window[index]==4){
        vec_window[index] = 2;
    }
    float has_colision = false;
    return has_colision;
}


void print_window(){

    for(auto i= vec_window.begin(); i != vec_window.end(); i++){
        //bloques de paredes
        if(*i == 1) {
            std::cout << "* ";
        }
        //comida
        else if (*i == 2){
            std::cout << "o ";
        }
        //cuerpo
        else if (*i == 3){
            std::cout << "x ";
        }
        //espacio vacio
        else {
            std::cout << "  ";
        }
        if( (i - vec_window.begin()+1) % WIDTH == 0) {
            std::cout << std::endl;
        }
    }
}

std::pair<int,int>  random_function(int height, int width) {
    std::cout << "Random function" << std::endl;
    int x = rand() % height;
    int y = rand() % width;
    std::cout << "x: " << x << " y: " << y << std::endl;
    return std::make_pair(x, y);
}