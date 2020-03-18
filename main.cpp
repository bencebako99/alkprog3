#include <iostream>
#include <math.h>
#include <array>
#include <vector>
#include <numeric>
using namespace std;

auto illeszt(vector<double> const& x, vector<double> const& y){
    array<double, 2> m;
    double average_x=accumulate(x.begin(), x.end(), 0.0)/x.size();
    double average_y=accumulate(y.begin(), y.end(), 0.0)/y.size();
    auto f = [average_x](double a, double b) {return a+(b-average_x)*(b-average_x);};
    m[0]=0;
    for (int i = 0; i < x.size(); i++)
    {
        m[0]+=(x[i]-average_x)*(y[i]-average_y);
    }
    m[0]=m[0]/accumulate(x.begin(), x.end(), 0.0, f);
    m[1]=average_y-m[0]*average_x;
    return m;
}

int main(){
    vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<double> y = {2, 1.5, 4, 15, 9.6, 11.3, 0.4, 21.87, 7.36, 10};
    array<double, 2> m= illeszt(x, y);
    cout << "Az illesztett egyenes meredeksege " << m[0] << ", a tengelymetszet " << m[1] << endl;
    return 0;
}