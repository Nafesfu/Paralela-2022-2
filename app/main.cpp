#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

/**
 * Evaluador de polinomios.
 *
 * @param argc Cantidad de argumentos
 * @param argv matriz de argumentos
 * @return El código de salida del programa.
 */
void participantes(std::string programa);

int main(int argc, char **argv) {
  
  int exitCode;

  /// Si no hay argumentos suficientes mostramos un texto por defecto.
  if (argc != 2) {
    std::cout
        << "Argumentos inválidos, ejecute el programa de la siguiente forma:"
        << std::endl;
    std::cout << argv[0] << " \"[integral polinomica]\"" << std::endl;
    exitCode = EXIT_FAILURE;
  } else {
    /// Procesamos
    const std::string polinomio(argv[1]);
    
    std::cout << std::endl << "polinomio (cmd): " << polinomio << std::endl;
    

    std::cout << "polinomio (convertido): ";
    std::vector<Monomio> monomios = Utils::convertir(polinomio);
    std::vector<Monomio>::size_type i = 0;
    for (i = 0; i < monomios.size(); i++) {
      Monomio monomio = monomios[i];
      std::cout << monomio.GetCoeficiente() << "x^" << monomio.GetGrado()
                << " ";
    }
    std::cout << std::endl;

    double resultado = Utils::newtonraphson(monomios);
    std::cout << "Resultado: " << resultado << std::endl;
    exitCode = EXIT_SUCCESS;
  }
  participantes(argv[0]);
  return exitCode;
}
void participantes(std::string programa)
{	
	std::cout << std::endl <<"=== Taller " << programa << " ===" <<std::endl;
	std::cout << std::endl <<"Nahuel Espinoza     ";
	std::cout << std::endl <<"Cristian Montecinos ";
	std::cout << std::endl <<"Roberto Castillo    "<<std::endl;
}
