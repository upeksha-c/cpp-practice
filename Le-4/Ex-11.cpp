#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class FarmAnimal{
public:
  FarmAnimal(double water_consumption);
  double getWaterConsumption();
  // ...
private:
  double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) {
  this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}
//---------------------------------------------------------------
class Sheep : public FarmAnimal{
    public:
        Sheep(double weight);
};
Sheep::Sheep(double weight) : FarmAnimal((weight/10)*1.1){
    // nothing to do here
}
//---------------------------------------------------------------
class Cow : public FarmAnimal{
    public:
        Cow(double weight);
};

Cow:: Cow(double weight) : FarmAnimal((weight/100)*6.8){
    // nothing to do here
}
//---------------------------------------------------------------
class Horse : public FarmAnimal{
    public:
        Horse(double weight);
};
Horse::Horse(double weight) : FarmAnimal((weight/100)*8.6){
    // nothing to do here
}
//---------------------------------------------------------------
class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(FarmAnimal &animal);
private:
  double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
  total_consumption(0)
{
}

double ConsumptionAccumulator::getTotalConsumption()
{
  return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal &animal)
{
  total_consumption += animal.getWaterConsumption();
}

//---------------------------------------------------------------
int main()
{
  ConsumptionAccumulator accumulator;

  std::string input;
  
  while(true){
    std::cout << "Enter the type of animal and its weight (or a blank line to finish): ";
    std::getline(std::cin, input);

    if(input.empty()){
        break;
    } else {
        std::stringstream ss(input);
        std::string animal;
        double weight;

        ss >> animal >> weight;
        if(animal == "sheep"){
            Sheep sheep(weight);
            accumulator.addConsumption(sheep);
        } else if(animal == "cow"){
            Cow cow(weight);
            accumulator.addConsumption(cow);
        } else if(animal == "horse"){
            Horse horse(weight);
            accumulator.addConsumption(horse);
        } else {
            std::cout << "Invalid input" << std::endl;
        }

    }
  }
  // read user input
  // create appropriate objects and add them to the accumulator

  std::cout << accumulator.getTotalConsumption() << std::endl;

  return 0;
}