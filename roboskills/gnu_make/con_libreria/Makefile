# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -g -std=c++11

# Nombre del ejecutable final
TARGET = programa_cpp

# Archivos objeto
OBJS = main.o utils.o

# Regla principal: compila el programa final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

programa_cpp: main.o utils.o
	g++ Wall -g -std=c++11 -o programa_cpp main.o utils.o -

# Regla para compilar main.o
main.o: main.cpp utils.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar utils.o
utils.o: utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Regla para recompilar todo
rebuild: clean $(TARGET)