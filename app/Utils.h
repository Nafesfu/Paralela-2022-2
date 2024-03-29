#ifndef UTILS_H
#define UTILS_H

#include "Monomio.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

/**
 * Espacio de nombres para utilidades de manejo de monomios/polinomios
 */
namespace Utils {

/**
 *
 * @param texto cadena de texto
 * @return String sin espacios
 */
std::string acomodar(std::string texto);

/**
 *
 * @param polinomioStr representación de texto del polinomio
 * @return Un arreglo con los terminos separados.
 */
std::vector<std::string> obtener_terminos(std::string polinomioStr);

/**
 *
 * @param texto cadena de texto
 * @return Objeto monomio
 */
Monomio str2Monomio(std::string texto);

/**
 *
 * @param polinomioStr Representación de string del polinomio
 * @return arreglo del polinomio.
 */
std::vector<Monomio> convertir(std::string polinomioStr);

/**
 *
 * @param polinomio Arreglo de polinomios
 * @param value Elemento a evaluar
 * @return el valor resultante
 */
double evaluar(std::vector<Monomio> polinomio, double value); 
/**
*corregir las variables negativas ya que el programa las toma como 0x
*/
std::vector<Monomio> derivada(std::vector<Monomio> polinomio);
/**
*parametro Arreglo de polinomios
*ciclo para derivar
*retorna el plonomio derviado
*/

double newtonraphson(std::vector<Monomio> polinomio);
/**
*Constante x(n) inicial 
*Parametro polinomio auxiliar
*ciclo de iteraciones (50) a mas iteraciones, mes preciso el resultado
*
*/

} // namespace Utils

#endif /* UTILS_H */
