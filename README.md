# Doodle Jump
Bachelor in Computer Science

## Project overview

This project is made for the Advanced Programming course at the University of Antwerp. We have to implement the logic for our own version of Doodle Jump which will be visualized with the SMFL library.

## Design Patterns

An important part of this project was implementing a variety of design patterns.

### Model-View-Controller (MVC)
This pattern is used to seperate the game logic and its graphical representation. This is realised by the corresponding namespaces models, views and controllers. Interactions with the controller are being passed to the model and the view provides the graphical representation for the sprite.

### Observer
In order to properly manage all the events during the gameplay, the EventManager will notify all the EventHandlers whenever a new event is invoked.

### Abstract Factory
The abstract EntityFactory provides an interface to easily create entities.

### Singleton
Both the Stopwatch and Random classes are singletons. They have 1 particular job and only have to be instantiated once.

### State
Since the game can be in multiple states, I've decided to use the state pattern to manage the game states. This facilitates switching between the menu, game world, game over and error screen.

### Adapter
The SFML implementation is being seperated from the any source code related to doodlejump through the GUI adapters or wrappers. This way, the game logic can be compiled without the SMFL library.

## SFML Library

SFML can be downloaded from https://www.sfml-dev.org/download.php.
> Simple and Fast Multimedia Library (SFML) is a cross-platform software development library designed to provide a simple application programming interface (API) to various multimedia components in computers. - Wikipedia

## Install and run

 1. Download or clone the repository
 2. Make sure you have the SFML library installed
 3. Set it up as a CMake project
 4. Build the sourcecode
 5. Run the generated executable from the project root directory

## Warning

*Plagiarism is illegal and will have consequences. Do NOT copy parts of this repository claiming it's your own work.*

