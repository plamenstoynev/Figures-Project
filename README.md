# Figures Project

This project provides a flexible and extensible C++ library for creating and managing various geometric shapes (Circle, Rectangle, Triangle) using the Factory, Abstract Factory, and Prototype design patterns. Each shape is defined by separate classes and header files. The project uses factories to instantiate these shapes dynamically and employs the Prototype pattern to allow cloning of existing shapes, providing a flexible way to create shape copies without directly instantiating new objects.
## Project Structure

The project is structured as follows:

### Shape Classes

- **Circle**
    - `Circle.cpp`: Implementation of the Circle class.
    - `Circle.h`: Header file for the Circle class.
- **Rectangle**
    - `Rectangle.cpp`: Implementation of the Rectangle class.
    - `Rectangle.h`: Header file for the Rectangle class.
- **Triangle**
    - `Triangle.cpp`: Implementation of the Triangle class.
    - `Triangle.h`: Header file for the Triangle class.

### Base Class

- **Figure**
    - `Figure.h`: Defines the base class for all shapes (Circle, Rectangle, Triangle).

### Factories

- **AbstractFactory**
    - `AbstractFactory.h`: Abstract factory interface to define the methods for creating shapes.

- **FigureFactory**
    - `FigureFactory.cpp`: Implementation of the main factory class for creating shapes.
    - `FigureFactory.h`: Header file for FigureFactory.

- **RandomFactory**
    - `RandomFactory.cpp`: Implementation of a factory that creates random shapes.
    - `RandomFactory.h`: Header file for RandomFactory.

- **StreamFactory**
    - `StreamFactory.cpp`: Implementation of a factory that creates shapes based on input streams.
    - `StreamFactory.h`: Header file for StreamFactory.


## Usage

You can create various shapes using the factory classes provided. The FigureFactory class is the main factory, and you can extend it or use other specialized factories (RandomFactory, StreamFactory) depending on the source of shape creation (e.g., random shapes, stream input).

## Getting Started

To compile and run the project, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/plamenstoynev/Figures-Project.git

2. **Compile the code:**
   Use g++ or another C++ compiler to compile the files. Here’s an example command:
    ```bash
    g++ -std=c++11 main.cpp Circle.cpp Rectangle.cpp Triangle.cpp FigureFactory.cpp RandomFactory.cpp StreamFactory.cpp -o main
   
3. **Run the executable:** 
    ```bash
    ./main
    ```