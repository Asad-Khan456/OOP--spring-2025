#include "iostream"
#include "string"
using namespace std;
class Activity{
public:
    virtual double calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};
class Running : public Activity{
    double distance;
    double time;
    double weight;
public:
    Running(double distance, double time, double weight)
        : distance(distance), time(time), weight(weight) {}
    double calculateCaloriesBurned() override{
        return 0.063 * weight * distance;
    }
};
class Cycling : public Activity{
    double speed;
    double time;
    double weight;
public:
    Cycling(double speed, double time, double weight)
        : speed(speed), time(time), weight(weight) {}
    double calculateCaloriesBurned() override{
        return 0.049 * weight * speed * time;
    }
};
void simulateActivity(Activity *activity){
    double calories = activity->calculateCaloriesBurned();
    cout << "Calories burned: " << calories << " kcal" << endl;
}
int main(){
    Running myRunning(5.0, 30.0, 70.0);
    Cycling myCycling(20.0, 1.0, 70.0);
    cout << "Simulating Running Activity..." << endl;
    simulateActivity(&myRunning);
    cout << "\nSimulating Cycling Activity..." << endl;
    simulateActivity(&myCycling);
    return 0;
}
