#include "Utils.h"

std::string Utils::acomodar(std::string texto) {
    /*
     * Pasamos el texto a minusculas (en caso de que se use una variable en mayúscula)
     */
    std::transform(texto.begin(), texto.end(), texto.begin(), [](unsigned char c) {
        return std::tolower(c); });

    /*
     * Truco para tokenizar negativos.
     * 
     * Reemplazar el menos por un más y un menos.
     */
    std::string polinomio = std::regex_replace(texto, std::regex("-"), "+-");

    /*
     * Se eliminan los espacios al polinomio
     */
    std::string::iterator it = std::remove(polinomio.begin(), polinomio.end(), ' ');
    polinomio.erase(it, polinomio.end());

    return polinomio;
}

std::vector<std::string> Utils::obtener_terminos(std::string polinomioStr) {
    std::vector<std::string> elementos;
    if (!polinomioStr.empty()) {

        char* str = new char[polinomioStr.size() + 1];
        strncpy(str, polinomioStr.c_str(), polinomioStr.size());

        char* token = strtok(str, "+");
        while (token != NULL) {
            std::string elemento = token;
            elementos.push_back(elemento);
            token = strtok(NULL, "+");
        }
        delete[] str;
    }
    return elementos;
}

Monomio Utils::str2Monomio(std::string texto) {
    Monomio mono;

    if (!texto.empty()) {
        std::string str = texto;
        std::size_t pos = str.find("x");

        //        std::cout << "Texto: " << texto << " Pos: " << pos << std::endl;
        if (pos != std::string::npos) {
            /// Coeficiente
            std::string coefStr = str.substr(0, pos);
            if (coefStr.empty()) {
                mono.SetCoeficiente(1);
            } else {
                mono.SetCoeficiente(atof(coefStr.c_str()));
            }

            /// Grado
            unsigned int resto = pos + 3;
            if (str.size() >= resto) {
                std::string gradoStr = str.substr(resto, str.size() - 1);
                mono.SetGrado(atof(gradoStr.c_str()));
            } else if (str.size() > pos) {
                mono.SetGrado(1);
            } else {
                mono.SetGrado(0);
            }
        } else {
            mono.SetCoeficiente(atof(str.c_str()));
            mono.SetGrado(0);
        }
    }

    return mono;
}

std::vector<Monomio> Utils::convertir(std::string polinomioStr) {
    std::vector<Monomio> listado;
    if (!polinomioStr.empty()) {
        std::string resultado = acomodar(polinomioStr);
        std::vector<std::string> terminos = obtener_terminos(resultado);

        std::vector<int>::size_type i = 0;
        std::vector<Monomio> polinomio;

        for (i = 0; i < terminos.size(); i++) {
            std::string valor = terminos[i];
            Monomio monomio = str2Monomio(valor);
            polinomio.push_back(monomio);
        }

        listado = polinomio;


    }
    return listado;
}

double Utils::evaluar(std::vector<Monomio> polinomio, double valor) {
    double resultado;
    std::vector<Monomio>::size_type i;
    double suma = (double) 0;
    for (i = 0; i < polinomio.size(); i++) {
        Monomio monomio = polinomio[i];
        suma += (monomio.GetCoeficiente() * pow(valor, monomio.GetGrado()));
    }
    resultado = suma;
    return resultado;
}

std::vector<Monomio> Utils::derivada(std::vector<Monomio> polinomio){
    std::vector<Monomio>::size_type i;//esto no sabemos para que sirve  
    std::vector<Monomio> resultado;//Polinomio resultante
    for (i = 0; i < polinomio.size(); i++) { //para sacar los datos del polinomio
    	Monomio monomioaux;//creamos un monomio auxiliar para guardar los datos
        Monomio monomio = polinomio[i];//de aqui sacamos los datos
        monomioaux.SetCoeficiente(monomio.GetGrado()*monomio.GetCoeficiente());//formula de la derivada para el coeficiente
        monomioaux.SetGrado(monomio.GetGrado()-1);//formula de la derivada para el grado  
        resultado.push_back(monomioaux);//llevar los resultados del monomio al polinomio
    }
    return resultado;//retorna el resultado obviamente
}
	
double Utils::newtonraphson(std::vector<Monomio> polinomio){ //funcion newton raphson
     double constante=8; //x(n) valor aleatorio para iterar
     int i=0; 
     double n=constante;
     std::vector<Monomio> polinomioaux;//Creamos un polinomio auxiliar
     polinomioaux = derivada(polinomio); 
     double polinomioevaluado = evaluar(polinomio,n);
     double polinomioderivado = evaluar(polinomioaux,n);
     double aproximacion=polinomioevaluado/polinomioderivado;//operacion f(x)/f'(x)
     while (i<=50){//iteramos 50 veces (mas veces=mas precision)
     	polinomioevaluado = evaluar(polinomio,n);
     	polinomioderivado = evaluar(polinomioaux,n);
     	aproximacion=polinomioevaluado/polinomioderivado;
     	n = n-aproximacion;
     	i++;
     	}
     return n;	
}
