include_libs = -I/home/shubham/Desktop/COP_Task2_MI/Utils -I/home/shubham/Desktop/COP_Task2_MI/Graphics -I/home/shubham/Desktop/COP_Task2_MI/Shapes -I/home/shubham/Desktop/COP_Task2_MI/App

LINKER_FLAGS = -lSDL2

OBJ_NAME = exec

main_objects = Vec2D.o Utils.o Color.o ScreenBuffer.o Screen.o Line2D.o Shape.o Triangle.o AARectangle.o Circle.o App.o main.o


all : $(main_objects)
	g++ -o $(OBJ_NAME) $(main_objects) $(LINKER_FLAGS)
	./exec

clean:
	rm *.o
	rm exec



main.o: main.cpp
	g++ $(include_libs) -c main.cpp

App.o: App/App.cpp
	g++ $(include_libs) -c App/App.cpp

Vec2D.o: Utils/Vec2D.cpp
	g++ $(include_libs) -c Utils/Vec2D.cpp

Utils.o: Utils/Utils.cpp
	g++ $(include_libs) -c Utils/Utils.cpp

Color.o: Graphics/Color.cpp
	g++ $(include_libs) -c Graphics/Color.cpp

ScreenBuffer.o: Graphics/ScreenBuffer.cpp
	g++ $(include_libs) -c Graphics/ScreenBuffer.cpp

Screen.o: Graphics/Screen.cpp
	g++ $(include_libs) -c Graphics/Screen.cpp

Line2D.o: Shapes/Line2D.cpp
	g++ $(include_libs) -c Shapes/Line2D.cpp

Shape.o: Shapes/Shape.cpp
	g++ $(include_libs) -c Shapes/Shape.cpp

Triangle.o: Shapes/Triangle.cpp
	g++ $(include_libs) -c Shapes/Triangle.cpp

AARectangle.o: Shapes/AARectangle.cpp
	g++ $(include_libs) -c Shapes/AARectangle.cpp

Circle.o: Shapes/Circle.cpp
	g++ $(include_libs) -c Shapes/Circle.cpp



