# 🎬 Proyecto Integrador - Sistema de Streaming en C++

Este proyecto implementa un **modelo de servicio de streaming** en C++ utilizando **Programación Orientada a Objetos (POO)**.  
El sistema permite organizar y mostrar películas y series, incluyendo información como nombre, duración, género y calificaciones promedio, además de manejar episodios y temporadas.

---

## 🚀 Características

- Implementación de **clases y herencia**:
  - `Video` (clase base abstracta).
  - `Pelicula` y `Serie` (clases derivadas).
  - `Episodio` (composición dentro de `Serie`).
- **Polimorfismo** para mostrar, visualizar y calificar contenido.
- **Sobrecarga de operadores** (`<`, `==`) para comparar duración de videos.
- Manejo de **archivos CSV** para almacenar y actualizar calificaciones.
- Reproducción de **videos (MP4)** y visualización de **imágenes (PNG)** usando `ShellExecute` (Windows).
- Uso de librerías estándar de C++:
  - `<fstream>` para lectura/escritura de archivos.
  - `<vector>` para listas dinámicas de calificaciones.
  - `<chrono>` y `<thread>` para control de tiempos en reproducción.
- Compatible con **Windows**.

---

## 📂 Estructura del Proyecto

- **Clases principales**: `Video`, `Pelicula`, `Serie`, `Episodio`.
- **Archivos de soporte**:
  - `calificaciones.csv` → almacenamiento de calificaciones.
  - Recursos multimedia: videos y fotos asociados al contenido.

---

## ⚙️ Requisitos

- **Compilador C++** compatible con C++11 o superior (ej. g++, MSVC).
- **Sistema operativo Windows** (uso de librería `<windows.h>`).
- Archivos multimedia (videos e imágenes) ubicados en las rutas configuradas en el código.

---

## 🖥️ Instalación y Ejecución

1. Clonar el repositorio:
   ```bash
   git clone https://github.com/usuario/proyecto-integrador.git
   cd proyecto-integrador
