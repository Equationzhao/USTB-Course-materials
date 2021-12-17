#include <cmath>
#include <iostream>

using namespace std;

int main() {
  const double xi = 11.06 * 1e-3;
  const double Ux = 0.11 * 1e-3;
  const double L = 736 * 1e-3;
  const double UL = 2 * 1e-3;
  const double H = 698 * 1e-3;
  const double UH = 2 * 1e-3;
  const double l = 35.1 * 1e-3;
  const double Ul = 0.1 * 1e-3;
  const double d = 0.640 * 1e-3;
  const double Ud = 0.005 * 1e-3;
  const double m = 0.5;
  const double Um = 0.005;
  const double g = 9.8;
  const double pi = 3.14159265358979323846;
  const double E = 8 * m * g * L * H / (pow(d, 2) * l * pi * xi);
  const double UE = sqrt(
      pow((8 * g * L * H / (pi * pow(d, 2) * l * xi)) * Um, 2) +
      pow((8 * m * g * H / (pi * pow(d, 2) * l * xi)) * UL, 2) +
      pow((8 * m * g * L / (pi * pow(d, 2) * l * xi)) * UH, 2) +
      pow((16 * m * g * L, H / (pi * pow(d, 2) * pow(l, 2) * xi)) * Ul, 2) +
      pow((8 * m * g * L * H / (pi * pow(d, 2) * l * pow(xi, 2))) * Ux, 2));
  cout << E << " " << UE << endl;
  return 0;
}
