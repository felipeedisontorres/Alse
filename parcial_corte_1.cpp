#include <iostream>
#include <cmath>


// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
double calcularDistancia(Point p1, Point p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return std::sqrt(dx*dx + dy*dy);
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    // Verificar si la respuesta es 's' o 'n'
    if (respuesta == 's' || respuesta == 'n')
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        std::cout << "Usando puntos predeterminados...\n";
        if (n >= 1) puntos[0] = {0, 0};
        if (n >= 2) puntos[1] = {3, 4};
        if (n >= 3) puntos[2] = {6, 8};
        if (n >= 4) puntos[3] = {9, 12};
        for (int i = 4; i < n; i++)
        {
            puntos[i] = { (double)(i*2), (double)(i*2) };
        }
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano)
{
    indiceMasCercano = 0;
    double distanciaMinima = calcularDistancia(puntos[0], pUsuario);

    for (int i = 1; i < n; i++)
    {
        double d = calcularDistancia(puntos[i], pUsuario);
        if (d < distanciaMinima)
        {
            distanciaMinima = d;
            indiceMasCercano = i;
        }
    }

    return distanciaMinima;

    std::cout << "El punto más cercano es el #" << (indiceMasCercano + 1)
              << " con una distancia de " << distanciaMinima << std::endl;

}

int main() {
    int n;

    std::cout << "¿Cuantos puntos desea trabajar? (minimo 2): ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "Valor menor a 2; se usaran 4 puntos por defecto.\n";
        n = 4;
    }

    // Reservar arreglo de puntos
    Point* puntos = new Point[n];

    // Leer puntos (manual o predeterminados)
    leerPuntos(puntos, n);

    // Leer el punto del usuario
    Point pUsuario;
    std::cout << "\nIngrese las coordenadas del punto de referencia (x y): ";
    std::cin >> pUsuario.x >> pUsuario.y;

    // Calcular el más cercano
    int indiceMasCercano = -1;
    double distanciaMinima = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar resultado (redondeo simple a 5 decimales sin iomanip)
    double d5 = std::round(distanciaMinima * 100000.0) / 100000.0;

    std::cout << "\nEl punto mas cercano es: ("
              << puntos[indiceMasCercano].x << ", "
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto mas cercano es: " << d5 << "\n";

    delete[] puntos;
    return 0;
}

