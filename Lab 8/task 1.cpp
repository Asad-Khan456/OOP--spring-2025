#include "iostream"
#include "string"
using namespace std;
class humidity;
class Temperature{
    protected:
    int temp;
    public:
    Temperature(int temp):temp(temp){}
    friend void calcHeatindex(Temperature t,humidity h);
};
class humidity{
    protected:
    int humid;
    public:
    humidity(int humid):humid(humid){}
    friend void calcHeatindex(Temperature t,humidity h);
};
void calcHeatindex(Temperature a,humidity b){
    float fahrenheit =  (a.temp *9/5)+32;
    float Heatindex = fahrenheit + 0.55 * (1-0.01*b.humid)*(fahrenheit - 58);
    Heatindex = (Heatindex-32)*5/9;
   cout << " Heat index:" << Heatindex << endl;

}
int main(){
    Temperature t(32);
    humidity h(76);
    calcHeatindex(t , h);
    return 0;

}
