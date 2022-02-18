#include <iostream>
#include <fstream>
using namespace std;



struct Car{
  enum {MAX_CHAR_LEN = 100};
  char carName[MAX_CHAR_LEN];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[MAX_CHAR_LEN];
  bool validEntry;
  Car();
};

Car::Car() {
  for (int i = 0; i < MAX_CHAR_LEN; i++){
    carName[i] = '\0';
  }
  mpg = 0;
  cylinders = 0;
  displacement = 0;
  horsepower = 0;
  weight = 0;
  acceleration = 0;
  model = 0;
  for (int i = 0; i < MAX_CHAR_LEN; i++){
    carName[i] = '\0';
  }
  validEntry = false;
}

const int MAX_CARS = 500;






Car readCarFile(ifstream &file){
  Car car;
  char c = file.get();
  int index = 0;
  while (c != ';' &&  !file.eof() && index < Car::MAX_CHAR_LEN){
    car.carName[index] = c;
    c = file.get();
    index++;
  }
  car.carName[index] = '\0';
  /*file >> car.mpg;
  file.get();
  file >> car.cylinders;
  file.get();*/

  return car;

}

int readCarData(Car cars[]){
  ifstream carFile("cars.txt");
  int count = 0;
  while (carFile.peek() != EOF){
    cars[count] = readCarFile(carFile);
    count++;
  }
  return count;
}

void printCar(Car c){
    cout << "Car name: " << c.carName;
} 

int main (){
  Car cars[MAX_CARS];
  int carAmmount = readCarData(cars);
  for (int i = 0; i < carAmmount; i++){
    printCar(cars[i]);
    cout << endl;
  }
  return 0;
}