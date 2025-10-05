#include <iostream>

int main() {

   std:: cout << "--- Sistema de Despacho Logístico MegaEnvío (Modo Punteros) ---\n"; 
std:: cout << "Inicializando sistema con capacidad para 50 paquetes...\n";
std:: cout << "Capacidad actual: 50. Paquetes en cola: 0.\n"; 
int cantidadPaquetes = 0;
int capacidad_Paquetes = 50;
int Index_inicio_Cola = 0;

  int *id_Paquete = new int[50];
    float *peso_Paquete = new float[50];
    std::string *destino_Paquete = new std::string[50];
     int *nivel_Prioridad_Paquete = new int[50];
      char *estado_Paquete = new char[50];

do
{
   std:: cout << "Seleccione una operación:\n";
std:: cout << "1. Agregar Paquete (Encolar)\n";
std:: cout << "2. Despachar Paquete (Desencolar)\n";
std:: cout << "3. Inspeccionar Frente de Cola\n";
std:: cout << "4. Reporte por Destino\n";
std:: cout << "5. Salir (Liberar Memoria)\n";
int select = 0;
std::cin >> select;

switch (select)
{

case 1:{ //Agregar Paquetes seleccionado

  

    std::cout << "Ingrese el ID: \n" ; std::cin >> id_Paquete[cantidadPaquetes] ;
    std::cout << "Ahora el Peso: \n"; std::cin >> peso_Paquete[cantidadPaquetes];
     std::cout << "Destino: \n"; std::cin >> destino_Paquete[cantidadPaquetes];
     std::cout << "Y por ultimo el nivel de prioridad: \n"; std::cin >> nivel_Prioridad_Paquete[cantidadPaquetes];
     estado_Paquete[cantidadPaquetes] = 'E';

     if (cantidadPaquetes == 50 )
     {
        /* code */
     }
     
    //-------------------------------
    std::cout << "Paquete agregado: "
         << "ID: " << id_Paquete[cantidadPaquetes] << ", "
        << "Peso: "  << peso_Paquete[cantidadPaquetes] << " kg, "
        << "Destino: "  << destino_Paquete[cantidadPaquetes] << ", "
          << "Nivel de Prioridad: " << nivel_Prioridad_Paquete[cantidadPaquetes]  << ", "
          << "Estado: " << estado_Paquete[cantidadPaquetes] << "\n";

    cantidadPaquetes++;
    break;
    }
    case 2:{ //Aplicar FIFO
    std::cout << "Despachando paquete...\n";

        if (estado_Paquete[Index_inicio_Cola] == 'E')
        {
            estado_Paquete[Index_inicio_Cola] = 'D';
        
        }
        
std::cout << "Paquete " << id_Paquete[Index_inicio_Cola] << " despachado con éxito. Estado: 'D'.";
Index_inicio_Cola++; //Avanza en uno cuando despachamos
    break;
}

    case 3:{
    std::cout << "Frente de la cola:\n";
    
        std::cout  << "ID: " << id_Paquete[Index_inicio_Cola] << ", "
        << "Peso: "  << peso_Paquete[Index_inicio_Cola] << " kg, "
        << "Destino: "  << destino_Paquete[Index_inicio_Cola] << ", "
          << "Nivel de Prioridad: " << nivel_Prioridad_Paquete[Index_inicio_Cola]  << ", "
          << "Estado: " << estado_Paquete[Index_inicio_Cola] << "\n";
    break;
}
    case 4: {
        std::string Ingresar_Destino = "";
        int totalPaquetesConE = 0;
        float pesoPromedio = 0.0f;



    std::cout << "Ingrese el destino para el reporte: \n";
    std::cin >> Ingresar_Destino;

    for (int i = 0; i < cantidadPaquetes; i++) //Correr mis paquetes y verificar que tengan un estado en E
    {
       if (estado_Paquete[i] == 'E' && destino_Paquete[i] == Ingresar_Destino)
       {
        std::cout << "\n";
        std::cout  << "ID: " << id_Paquete[i] << ", "
        << "Peso: "  << peso_Paquete[i] << " kg, "
        << "Destino: "  << destino_Paquete[i] << ", "
          << "Nivel de Prioridad: " << nivel_Prioridad_Paquete[i]  << ", "
          << "Estado: " << estado_Paquete[i] << "\n";
          pesoPromedio = pesoPromedio + peso_Paquete[i];
          totalPaquetesConE++;
       }
        std::cout << "\n";
        std::cout << "Peso promedio de los paquetes: " << pesoPromedio / totalPaquetesConE;
    }
    
    break;
}
    case 5: {
    std::cout << "Liberando 50 bloques de memoria asignada...\n";

delete[] id_Paquete;
delete[] peso_Paquete;
delete[] destino_Paquete;
delete[] nivel_Prioridad_Paquete;

std::cout << "Sistema cerrado. ¡Memoria libre!\n";

    break;
    }
default:{
std::cout << "ERROR: Opcion invalida\n";
    break;
    break;
    }
}


} while (true);

    return 0;
}