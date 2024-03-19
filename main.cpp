#include <iostream>
#include<string>
#include <fstream>
#include <filesystem>

#ifdef _WIN32
#include <direct.h> // Para Windows
    #define mkdir _mkdir
#else
#include <sys/stat.h> // Para sistemas basados en Unix
#endif

using namespace std;
namespace fs = std::filesystem;

int main() {

    // Crear una carpeta
    string folderName = "../mi_carpeta";
    if (fs::exists(folderName) && fs::is_directory(folderName)) {
        cout << "La carpeta ya existe." << endl;
    } else {
        cout << "La carpeta no existe." << endl;
        //Creamos la carpeta.
        #ifdef _WIN32
                int folderCreated = mkdir(folderName.c_str());
        #else
                int folderCreated = mkdir(folderName.c_str(), 0777); // Permisos en sistemas Unix
        #endif

        if (folderCreated == 0) {
            cout << "Carpeta creada correctamente." << endl;
        } else {
            cout << "Error al crear la carpeta. Es posible que ya exista" << endl;
            return 1;
        }
    }

    // Crear un archivo de texto dentro de la carpeta
    string filePath = folderName +"/mi_archivo.txt";
    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile << "Este es el contenido del archivo de texto." << endl;
        outputFile.close();
        cout << "Archivo de texto creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo de texto." << endl;
        return 1;
    }

    return 0;
}
