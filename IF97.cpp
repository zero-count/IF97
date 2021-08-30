// This compiler flag causes input/output units on the Thermodynamic Properties in IF97.h
// to take pressure units of [MPa] and Energy units of [kJ] for comparison with IAPWS
// table values.  If not set, the default behavior of IF97.h is to use straight SI units
// with pressure in [Pa] and enthalpy in [J].
#define IAPWS_UNITS

#include "IF97.h"

#include <pybind11/pybind11.h>

using namespace std;

namespace py = pybind11;


PYBIND11_MODULE(IF97, m) {
    m.doc() = "IF97 cpp code";
    m.def("rhomass_Tp", &IF97::rhomass_Tp, py::arg("T"), py::arg("p"), "calculate rho using given T and p");
    m.def("hmass_Tp", &IF97::hmass_Tp, py::arg("T"), py::arg("p"), "calculate H using given T and p");
}