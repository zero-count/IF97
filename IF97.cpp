// This compiler flag causes input/output units on the Thermodynamic Properties in IF97.h
// to take pressure units of [MPa] and Energy units of [kJ] for comparison with IAPWS
// table values.  If not set, the default behavior of IF97.h is to use straight SI units
// with pressure in [Pa] and enthalpy in [J].
#define IAPWS_UNITS

#include "IF97.h"

#include <pybind11/pybind11.h>

using namespace std;

namespace py = pybind11;


double FtoK(double F) {
    auto K = (F - 32) / 1.8 + 273.15;
    return K;
}

double KtoF(double K) {
    auto F = (K - 273.15) * 1.8 + 32;
    return F;
}

double rhomass_Tp(double T, double p) {
    auto rho = IF97::rhomass_Tp(FtoK(T), p);
    return rho;
}

double hmass_Tp(double T, double p) {
    auto h = IF97::hmass_Tp(FtoK(T), p);
    return h;
}

double T_phmass(double p, double h) {
    auto T = IF97::T_phmass(p, h);
    return KtoF(T);
}

PYBIND11_MODULE(IF97, m) {
    m.doc() = "IF97 cpp code";
    m.def("rhomass_Tp", &rhomass_Tp, py::arg("T"), py::arg("p"),
          "calculate rho using given T and p, p:Mpa, T:F, rho:kg/m^3");
    m.def("hmass_Tp", &hmass_Tp, py::arg("T"), py::arg("p"),
          "calculate H using given T and p, p:Mpa, T:F, rho:kg/m^3");
    m.def("T_phmass", &T_phmass, py::arg("p"), py::arg("h"),
          "calculate T using given p and H, p:Mpa, T:F, rho:kg/m^3");
}