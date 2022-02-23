#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>
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





//Reads the cars.txt file, extracts the required data and inputs it into the struct.
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
  file >> car.mpg;
  file.get();
  file >> car.cylinders;
  file.get();
  file >> car.displacement;
  file.get();
  file >> car.horsepower;
  file.get();
  file >> car.weight;
  file.get();
  file >> car.acceleration;
  file.get();
  file >> car.model;
  file.get();
  file >> car.origin;
  file.get();

  car.validEntry = true;

  return car;

}

//Function that opens the cars.txt file, then calls readCarFile to extract the data
int readCarData(Car cars[]){
  ifstream carFile("cars.txt");
  int count = 0;
  while (carFile.peek() != EOF){
    cars[count] = readCarFile(carFile);
    count++;
  }
  return count;
}

//Function for actually printing the cars
void carPrint(Car c, int i){
        cout << "CAR NUMBER " << i + 1 << endl;
        cout << "Car name: " << c.carName << endl;
        cout << "MPG: " << c.mpg << endl;
        cout << "Cylinders: " << c.cylinders << endl;
        cout << "Displacement: " << c.displacement << endl;
        cout << "Horsepower: " << c.horsepower << endl;
        cout << "Weight: " << c.weight << endl;
        cout << "Acceleration: " << c.acceleration << endl;
        cout << "Model: " << c.model << endl;
        cout << "Origin: " << c.origin << endl;
        cout << endl;
}

//Function for determining if user would like to print one or all cars
void printCar(Car cars[]){
  
  int select = 0;
  while (select != 3){
    cout << "Would you like to display all cars, or just a specific singlular car?" << endl;
    cout << "1) All Cars" << endl;
    cout << "2) Singular Car" << endl;
    cout << "3) Go Back" << endl;
    cin >> select;

    //All cars!
    if (select == 1) {
      for (int i = 0; i < MAX_CARS; i++){
        if (cars[i].validEntry == true){
            carPrint(cars[i], i);
          }
      }
    }

    //One :(
    if (select == 2) {
     int selection;
     cout << "Please enter the number of the car you would like to view:" << endl;
     cin >> selection;
      if (cars[selection].validEntry == true){
         selection = selection - 1; 
         cout << "Viewing car number " << selection + 1 << "..."<< endl;
        cout << endl;
         carPrint(cars[selection], selection);
        } else {
        cout << "That car does not exist!" << endl;
        }
    }

    if (select == 3) {
      cout << "Returning to main menu..." << endl;
    }

    if (select > 3 || select < 1){
      cout << "Please enter a valid entry" << endl;
    }
  }
  }

//Data validation for ints
int readInt(const char prompt[]){
  cout << endl;
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Entry!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

//Data validation for doubles
double readDouble(const char prompt[]){
  cout << endl;
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Entry!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

//Function that adds a car
  void addCar(Car &c, int start){
    double doubIn = 0;
    int intIn = 0;
    char nameIn[100];
    char originIn[100];

    cin.ignore(100,'\n');
    bool check = false;
    while (check == false){
      cout << "Please enter a name (max characters 100): " << endl;
      
      int length = 0;
      cin.getline(nameIn, start);      
      
          while(nameIn[length] != '\0') {
            length++;
          }
      

      if (length < Car::MAX_CHAR_LEN){  
        for (int i = 0; i < length; i++){
          c.carName[i] = toupper(nameIn[i]);
        }
        
        
        check = true;
      } else {
        cout << "Length of entry is too long" << endl;
      }
    }
    

    doubIn = readDouble("Please enter a MPG (Miles Per Gallon):\n");
    c.mpg = doubIn;
    doubIn = 0;
    
    intIn = readInt("Enter a number of cylinders (whole number):\n");
    c.cylinders = intIn;
    intIn = 0;

    doubIn = readDouble("Please enter a isplacement ammount:\n");
    c.displacement = doubIn;
    doubIn = 0;

    doubIn = readDouble("Please enter a horespower:\n");
    c.horsepower = doubIn;
    doubIn = 0;

    doubIn = readDouble("Please enter a weight:\n");
    c.weight = doubIn;
    doubIn = 0;

    doubIn = readDouble("Please enter an acceleration:\n");
    c.acceleration = doubIn;
    doubIn = 0;

    intIn = readInt("Please enter a model year (last two digits of the year):\n");
    c.model = intIn;
    intIn = 0;

    cout << endl;
    check = false;
    cin.ignore(100,'\n');
    while (check == false){
      cout << "Please enter an origin (max characters 100): " << endl;
      cin.getline(originIn, start); 
      int length = 0;
          while(originIn[length] != '\0') {
            length++;
            }
      if (length < Car::MAX_CHAR_LEN){  
        for (int i = 0; i < length; i++){
          c.origin[i] = originIn[i];
        }
        
        
        check = true;
      } else {
        cout << "Length of entry is too long" << endl;
      }
    }
    check = false;

    c.validEntry = true;
    

  } 

//Menu code, returns selection
int menu(int select){

    cout << "You are now accessing the Car Database" << endl;
    
    cout << "1) Display Car(s)" << endl;
    cout << "2) Enter a new Car" << endl;
    cout << "3) Remove a Car" << endl;
    cout << "4) Search for Cars by Origin" << endl;
    cout << "5) Quit" << endl;
    select = readInt("Please select an option by inputing 1 - 5: \n");
    
    return select;

}


int main (){
  Car cars[MAX_CARS];
  int carAmmount = readCarData(cars);
  int select = 0; 
  while (select != 5){
  select = menu(select);
      
    //Print Car
    if (select == 1){
      printCar(cars);
    }

    //Enter New Car
    if (select == 2){
      if (carAmmount < MAX_CARS) {
        int i = 0;
        while(i < MAX_CARS){
          if (cars[i].validEntry == false){
              addCar(cars[carAmmount], i);
              break;
            }
            i++;
          }
        cout << "Your new entry:" << endl;
        carPrint(cars[carAmmount], i);
      } else {
        cout << "Cars Database is full!" << endl;
      }
    }

    //Remove a Car
    if (select == 3){
      int remove = 0;
      remove = readInt("Please enter the number of the car you would like to remove:\n");
      
      cars[remove].validEntry = false;
      cout << "Car " << remove << " was removed!" << endl;
    }

    //Search for Cars by Origin
    if (select == 4){
      char search[100];
    cin.ignore(100,'\n');
    
    bool check = false;
    while (check == false){
      cout << "Enter the origin you would like to search by (i.e. Japan, US, Europe)"       << endl;
      cin >> search;
      int length = 0;
          while(search[length] != '\0') {
            length++;
          }
      if (length < Car::MAX_CHAR_LEN){   
        check = true;
      } else {
        cout << "Length of entry is too long" << endl;
      }
    }

      cout << "Searching for cars made in: " << search << endl;

    

    for (int i = 0; i < MAX_CARS; i++){
      if (strcmp(cars[i].origin, search) == 0){
        carPrint(cars[i], i);
      }
    }
      
    }

    //Quit
    if (select > 5 || select < 1){
      cout << "Please enter a valid selection." << endl;
    }
  }
  cout << "Exiting the Database..." << endl;
  return 0;
}

