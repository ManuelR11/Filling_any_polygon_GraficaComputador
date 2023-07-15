#include <iostream>
#include "Color.h"
#include "Framebuffer.h"
#include "Point.h"
#include "Line.h"
#include "Poligono.h"
#include "Relleno.h"

void render() {
    Framebuffer framebuffer(800, 600, Color(0, 0, 0)); // Crear instancia de Framebuffer con ancho, alto y color de borrado
    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color actual para los puntos y líneas


    // Polígono 5
    Point::Vertex2 vertices5[] = {
            {682, 175},
            {708, 120},
            {735, 148},
            {739, 170}
    };

    framebuffer.setCurrentColor(Color(255, 255, 255)); // Establecer color blanco para la orilla
    Poligono::drawPoligono(vertices5, sizeof(vertices5) / sizeof(vertices5[0]), framebuffer);

    framebuffer.setCurrentColor(Color(0, 0, 0)); // Establecer color negro para el relleno del polígono
    Relleno::fillPolygon(vertices5, sizeof(vertices5) / sizeof(vertices5[0]), framebuffer);
    
    framebuffer.renderBuffer(); // Generar el archivo BMP
}

int main() {
    render();

    return 0;
}