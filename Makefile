include_libs = -I/home/shubham/Desktop/COPTask2MI/Utils -I/home/shubham/Desktop/COPTask2MI/Graphics -I/home/shubham/Desktop/COPTask2MI/Shapes -I/home/shubham/Desktop/COPTask2MI/App -I/home/shubham/Desktop/COPTask2MI/Scenes -I/home/shubham/Desktop/COPTask2MI/Input -I/home/shubham/Desktop/COPTask2MI/Games -I/home/shubham/Desktop/COPTask2MI/Games/Pacman -I/home/shubham/Desktop/COPTask2MI/Scenes/Pacman

LINKER_FLAGS = -lSDL2

OBJ_NAME = exec

main_objects = Vec2D.o Utils.o Color.o ScreenBuffer.o Screen.o Line2D.o Shape.o Triangle.o AARectangle.o Circle.o App.o MainScene.o GameController.o InputController.o FileCommandLoader.o BMPImage.o SpriteSheet.o BitmapFont.o Button.o ButtonOptionsScene.o NotImplementedScene.o Animation.o AnimationPlayer.o AnimatedSprite.o PacmanStartScene.o Excluder.o Actor.o Ghost.o GhostAI.o Pacman.o PacmanGame.o PacmanGameUtils.o PacmanLevel.o GameScene.o main.o


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

MainScene.o: Scenes/MainScene.cpp
	g++ $(include_libs) -c Scenes/MainScene.cpp

GameController.o: Input/GameController.cpp
	g++ $(include_libs) -c Input/GameController.cpp

InputController.o: Input/InputController.cpp
	g++ $(include_libs) -c Input/InputController.cpp

FileCommandLoader.o: Utils/FileCommandLoader.cpp
	g++ $(include_libs) -c Utils/FileCommandLoader.cpp

BMPImage.o: Graphics/BMPImage.cpp
	g++ $(include_libs) -c Graphics/BMPImage.cpp

SpriteSheet.o: Graphics/SpriteSheet.cpp
	g++ $(include_libs) -c Graphics/SpriteSheet.cpp

BitmapFont.o: Graphics/BitmapFont.cpp
	g++ $(include_libs) -c Graphics/BitmapFont.cpp

Button.o: App/Button.cpp
	g++ $(include_libs) -c App/Button.cpp

ButtonOptionsScene.o: Scenes/ButtonOptionsScene.cpp
	g++ $(include_libs) -c Scenes/ButtonOptionsScene.cpp

NotImplementedScene.o: Scenes/NotImplementedScene.cpp
	g++ $(include_libs) -c Scenes/NotImplementedScene.cpp

Animation.o: Graphics/Animation.cpp
	g++ $(include_libs) -c Graphics/Animation.cpp

AnimationPlayer.o: Graphics/AnimationPlayer.cpp
	g++ $(include_libs) -c Graphics/AnimationPlayer.cpp

AnimatedSprite.o: Graphics/AnimatedSprite.cpp
	g++ $(include_libs) -c Graphics/AnimatedSprite.cpp

PacmanStartScene.o: Scenes/Pacman/PacmanStartScene.cpp
	g++ $(include_libs) -c Scenes/Pacman/PacmanStartScene.cpp

Excluder.o: Games/Excluder.cpp
	g++ $(include_libs) -c Games/Excluder.cpp

Actor.o: Games/Pacman/Actor.cpp
	g++ $(include_libs) -c Games/Pacman/Actor.cpp

Ghost.o: Games/Pacman/Ghost.cpp
	g++ $(include_libs) -c Games/Pacman/Ghost.cpp

GhostAI.o: Games/Pacman/GhostAI.cpp
	g++ $(include_libs) -c Games/Pacman/GhostAI.cpp

Pacman.o: Games/Pacman/Pacman.cpp
	g++ $(include_libs) -c Games/Pacman/Pacman.cpp

PacmanGame.o: Games/Pacman/PacmanGame.cpp
	g++ $(include_libs) -c Games/Pacman/PacmanGame.cpp

PacmanGameUtils.o: Games/Pacman/PacmanGameUtils.cpp
	g++ $(include_libs) -c Games/Pacman/PacmanGameUtils.cpp

PacmanLevel.o: Games/Pacman/PacmanLevel.cpp
	g++ $(include_libs) -c Games/Pacman/PacmanLevel.cpp

GameScene.o: Scenes/GameScene.cpp
	g++ $(include_libs) -c Scenes/GameScene.cpp