#include <windows.h> // Para reproducir video e imagenes ShellExecute
#include <sstream> // Para el excel stringstream
#include <vector> // Para el excel push_back / vector
#include <string> // Para el excel .find(), .substr() .empty()
#include <fstream> // Para el excel ofstream / ifstream
#include <chrono> // Tiempo
#include <thread> // Necesario para sleep_for
#include <iostream>
using namespace std;


// Clase Episodio
class Episodio{
    private:
        string titulo_episodio;
        int temporada_serie;
        int numero_de_episodio;
        double calificacion_episodio = 0;
        string tipo;
        int ID;
    public:
        // Constructor
        Episodio(string title_ep,int temp_ser, int n_ep, string tipe, int id){
            titulo_episodio = title_ep;
            temporada_serie = temp_ser;
            numero_de_episodio = n_ep;
            tipo = tipe;
            ID = id;
        };

        // Destructor Virtual
        virtual ~ Episodio(){};

        // -------------------------------------------------------------Metodos Get-------------------------------------------------------------


        string gettitulo_episodio(){
            return titulo_episodio;
        };

        int gettemporada_serie(){
            return temporada_serie;
        };
        int getnumero_de_episodio(){
            return numero_de_episodio;
        };

        string gettipo(){
            return tipo;
        };

        int getID(){
            return ID;
        };

};

// Clase madre esta va a ser abstracta
class Video{
    protected:
        int ID;
        string nombre;
        double duracion;
        string genero;
        double calificacion = 0;
        string tipo;
    public:
        // Constructor
        Video(string name,int time,string gen,string tipe,int ine){
        ID = ine;
        nombre = name;
        duracion = time;
        genero = gen;
        tipo = tipe;
        };
        // Destructor Virtual
        virtual ~ Video(){};

        // -------------------------------------------------------------Funciones virtuales puras-------------------------------------------------------------
        virtual void mostrarvideo() = 0;

        virtual void visualizar() = 0;

        virtual void calificar() = 0;

        // -------------------------------------------------------------Metodos Get-------------------------------------------------------------

        // Funcion Virtual Pura Mostrar
        string getnombre(){
            return nombre;
        };

        //Funcion obtener el genero
        string getgenero(){
            return genero;
        }

        //Funcion obtener la duracion
        int getduracion(){
            return duracion;
        }

        // -------------------------------------------------------------Sobrecarga de operadores-------------------------------------------------------------

        // Sobrecarga del operador <
        bool operator<(const Video& otro){
            return this->duracion < otro.duracion;
        }

        // Sobrecarga del operador ==
        bool operator ==(const Video& otro){
            return this->duracion == otro.duracion;
        }

        // -------------------------------------------------------------EXCEL-------------------------------------------------------------
        
        vector<double> calificaciones; //almacena muchas calificaciones.
        
        void cargarCalificacionesDesdeCSV(const string& linea) { // Se define una función que carga calificaciones desde una línea de texto CSV
            calificaciones.clear(); // Limpia el vector calificaciones para borrar cualquier dato anterior antes de cargar los nuevos.
            stringstream ss(linea); // <sstream> // Esto permite leer palabra por palabra (o celda por celda) separadas por comas
            string celda;
            getline(ss, celda, ',');  // Ignorar primera celda (nombre)
            while (getline(ss, celda, ',')) { // Bucle que sigue leyendo las celdas
                if (!celda.empty()) { // Se verifica que la celda no esté vacía
                    calificaciones.push_back(stod(celda));  // (stod)Convierte la celda de texto en un double
                }
            }
        }

        void agregarCalificacion() {
            calificaciones.push_back(calificacion); //<vector>
        }

        double promedio() {
            if (calificaciones.empty()) { // <string> /Se verifica que la calificaciones <vector> no esté vacía
                return 0.0;
            }
            double suma = 0;
            for (double c : calificaciones) suma += c; // Bucle que recorre cada calificación, basicamenete se hace la formula
            double prom = suma / calificaciones.size(); // Calcular el promedio 
            return prom;
        }
};

// Clase Heredada
class Pelicula:public Video{
    public:
        // Constructor
        Pelicula(string name,int time,string gen,string tipe,int ine):Video(name, time, gen, tipe, ine){
        };

        // Destructor Virtual
        virtual ~Pelicula(){};
        // -------------------------------------------------------------Funciones virtuales puras (Override)-------------------------------------------------------------
        void mostrarvideo() override{
            calificacion = promedio();
            cout<<endl;
            cout<<"------------------------PELICULA------------------------"<<endl;
            if(ID == 1){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\lo_que_el_viento_se_llevo.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 2){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\avatar.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 3){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\endgame.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 4){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\avatar2.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 5){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\titanic.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 6){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\star_wars.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 7){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\infinity_war.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 8){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\avengers.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else if(ID == 9){
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\jurassic.png", NULL, NULL,SW_SHOWNORMAL);
            }
            else{
                ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Imagenes_C\\el_rey_leon.png", NULL, NULL,SW_SHOWNORMAL);
            }
            cout<<nombre<<"\n"
            <<"ID: " <<ID<<"\n"
            <<"Duración: " <<duracion<<" minutos"<<"\n"
            <<"Género: " <<genero<<"\n"
            <<"Calificación: " <<calificacion<<"\n"
            <<"Tipo: " <<tipo<<"\n"
            <<endl;
        };
        void visualizar() override{
            int otra = 0;
            int swicth = 1;
            string visualiza;
            while(swicth){
                if (otra){
                    cout<<"Selecciona una opción válida ¿Quieres visualizar este contenido?(Y/N) "<<endl;
                }
                else{
                    cout<<"¿Quieres visualizar este contenido?(Y/N) "<<endl;  
                }
                cin>>visualiza;
                if (visualiza == "Y"){
                    if(ID == 1){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\lo_que_el_viento_se_llevo.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 2){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\avatar.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 3){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\endgame.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 4){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\avatar2.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 5){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\titanic.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 6){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\star_wars.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 7){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\infinity_war.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 8){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\avengers.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 9){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\jurassic_world.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else{
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\el_rey_leon.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    otra = 0;
                    swicth = 0;
                }
                else if(visualiza == "N"){
                    swicth = 0;
                }
                else{
                    otra = 1;
                }
            }
        };
        void calificar() override{
            int otra = 0;
            int swicth = 1;
            string califica;
            while(swicth){
                if (otra){
                    cout<<"Selecciona una opción válida ¿Quieres calificar esta pelicula?(Y/N) "<<endl;
                }
                else{
                    cout<<"¿Quieres calificar esta pelicula?(Y/N) "<<endl;  
                }
                cin>>califica;
                if (califica == "Y"){
                    otra = 0;
                    while(swicth){
                        if (otra){
                        cout<<"Selecciona una opción válida ¿Qué calificación le pones a esta pelicula?(0-5) "<<endl;
                        }
                        else{
                            cout<<"¿Qué calificación le pones a esta pelicula?(0-5) "<<endl;  
                        }
                        double cal_usu;
                        cin>>cal_usu;
                        if (cal_usu >= 0.0 && cal_usu <= 5.0) {
                            calificacion = cal_usu;
                            agregarCalificacion();
                            swicth = 0;
                        } else {
                            otra = 1;
                        }
                    }
                }
                else if(califica == "N"){
                    swicth = 0;
                }
                else{
                    otra = 1;
                }
            }
        };
        
};

// Clase Heredada 
class Serie:public Video{
    private:
        Episodio* episodios[2]; // Este arreglo no crea los objetos Episodio, solo crea espacio para dos punteros
        int temporadas;
        int n_episodios;
    public:
        // Constructor
        Serie(string name,int time,string gen,string tipe,int ine,int temp, int epi, string ep1, int tmp1, int n1,string tipe_1, int id_1, string ep2,int tmp2, int n2,string tipe_2, int id_2):Video(name, time, gen, tipe, ine){
        temporadas = temp;
        n_episodios = epi;
        episodios[0] = new Episodio(ep1,tmp1,n1,tipe_1,id_1);
        episodios[1] = new Episodio(ep2,tmp2,n1,tipe_2,id_2);
        };
        // Destructor Virtual
        virtual ~Serie(){};
        void mostrarvideo() override{
            calificacion = promedio();
            cout<<"------------------------SERIE------------------------"<<endl;
            cout<<nombre<<"\n"
            <<"ID: " <<ID<<"\n"
            <<"Duración: " <<duracion<<" minutos"<<"\n"
            <<"Género: " <<genero<<"\n"
            <<"Número de temporadas: " <<temporadas<<"\n"
            <<"Número de episodios: " <<n_episodios<<"\n"
            <<"Calificación: " <<calificacion<<"\n"
            <<"Tipo: " <<tipo<<"\n"
            <<endl;
        };
        
        // Episodio Especifico 
        void mostrarepisodio(int numero){
            cout<<"------------------------EPISODIO "<<numero<<"------------------------"<<endl;
            string titulo_episodio = episodios[numero] -> gettitulo_episodio();
            int temporada_serie = episodios[numero] -> gettemporada_serie();
            int numero_de_episodio = episodios[numero] -> getnumero_de_episodio();

            cout<<nombre<<": \n"
            <<"Temporada: " <<temporada_serie<<"\n"
            <<"Capitulo: " <<titulo_episodio<<"\n"
            <<"Episodio número: "<<numero_de_episodio<<"\n"
            <<endl;
            visualizar(episodios[numero] -> getID());
        };

        void mostrarepisodio(){
            for (int i = 0; i <2;i++){
                cout<<"------------------------EPISODIO "<<i+1<<"------------------------"<<endl;
                string titulo_episodio = episodios[i] -> gettitulo_episodio();
                int temporada_serie = episodios[i] -> gettemporada_serie();
                int numero_de_episodio = episodios[i] -> getnumero_de_episodio();

                cout<<nombre<<": \n"
                <<"Temporada: " <<temporada_serie<<"\n"
                <<"Capitulo: " <<titulo_episodio<<"\n"
                <<"Episodio número: "<<numero_de_episodio<<"\n"
                <<endl;
                visualizar(episodios[i] -> getID());
            }
        };
        
        string gettitulo_epi(int i){
            return episodios[i] -> gettitulo_episodio();
        };


        void visualizar() override{
            int otra = 0;
            int swicth = 1;
            string visualiza;
            while(swicth){
                if (otra){
                    cout<<"Selecciona una opción válida ¿Quieres visualizar este contenido?(Y/N) "<<endl;
                }
                else{
                    cout<<"¿Quieres visualizar este contenido?(Y/N) "<<endl;  
                }
                cin>>visualiza;
                if (visualiza == "Y"){
                    if(ID == 1){ 
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\arcane_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        this_thread::sleep_for(chrono::duration<double>(132.6));
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\arcane_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 2){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\got_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        this_thread::sleep_for(chrono::duration<double>(196.8));
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\got_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 3){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\st_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        this_thread::sleep_for(chrono::duration<double>(126.6));
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\st_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else if(ID == 4){
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\gf_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        this_thread::sleep_for(chrono::duration<double>(78.0));
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\gf_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    else{
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\newa_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        this_thread::sleep_for(chrono::duration<double>(154.2));
                        ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\newa_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                    }
                    otra = 0;
                    swicth = 0;
                }
                else if(visualiza == "N"){
                    swicth = 0;
                }
                else{
                    otra = 1;
                }
            }
        };

        // Sobrecarga con parámetro extra (no override)
        void visualizar(int id_episodio){
            int otra = 0;
            int swicth = 1;
            string visualiza;
            while(swicth){
                if (otra){
                    cout<<"Selecciona una opción válida ¿Quieres visualizar este contenido?(Y/N) "<<endl;
                }
                else{
                    cout<<"¿Quieres visualizar este contenido?(Y/N) "<<endl;  
                }
                cin>>visualiza;
                if (visualiza == "Y"){
                    if(ID == 1){ 
                        if (id_episodio == 1){
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\arcane_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                        else{
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\arcane_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                    }
                    else if(ID == 2){
                        if (id_episodio == 1){
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\got_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                        else{
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\got_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                    }
                    else if(ID == 3){
                        if (id_episodio == 1){
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\st_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                        else{
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\st_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                    }
                    else if(ID == 4){
                        if (id_episodio == 1){
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\gf_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                        else{
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\gf_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                    }
                    else{
                        if (id_episodio == 1){
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\newa_trailer.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                        else{
                            ShellExecute(NULL, "open", "C:\\Users\\hugoa\\OneDrive\\Escritorio\\Videos_C\\newa_escena.mp4", NULL, NULL,SW_SHOWNORMAL);
                        }
                    }
                    otra = 0;
                    swicth = 0;
                }
                else if(visualiza == "N"){
                    swicth = 0;
                }
                else{
                    otra = 1;
                }
            }
        };

        void calificar() override{
            int otra = 0;
            int swicth = 1;
            string califica;
            while(swicth){
                if (otra){
                    cout<<"Selecciona una opción válida ¿Quieres calificar esta serie?(Y/N) "<<endl;
                }
                else{
                    cout<<"¿Quieres calificar esta serie?(Y/N) "<<endl;  
                }
                cin>>califica;
                if (califica == "Y"){
                    otra = 0;
                    while(swicth){
                        if (otra){
                        cout<<"Selecciona una opción válida ¿Qué calificación le pones a esta serie?(0-5) "<<endl;
                        }
                        else{
                            cout<<"¿Qué calificación le pones a esta serie?(0-5) "<<endl;  
                        }
                        double cal_usu;
                        cin>>cal_usu;
                        if (cal_usu >= 0.0 && cal_usu <= 5.0) {
                            calificacion = cal_usu;
                            agregarCalificacion();
                            swicth = 0;
                        } else {
                            otra = 1;
                        }
                    }
                }
                else if(califica == "N"){
                    swicth = 0;
                }
                else{
                    otra = 1;
                }
            }
        };

        // Aquí usas delete para liberar la memoria
        void eliminar_episodios(){
            for (int i = 0; i < 2; i++) {
                delete episodios[i];
            }
        }
};


// -------------------------------------------------------------PELICULAS-------------------------------------------------------------
void llenarPeliculas(Video* Peliculas[]){
    Peliculas[0] = new Pelicula("Lo que el viento se llevo", 238, "Drama","Pelicula",1);
    Peliculas[1] = new Pelicula("Avatar", 162, "Acción","Pelicula",2);
    Peliculas[2] = new Pelicula("Avengers: Endgame", 181, "Acción","Pelicula",3);
    Peliculas[3] = new Pelicula("Avatar: El camino del agua", 192, "Acción","Pelicula",4);
    Peliculas[4] = new Pelicula("Titanic", 194, "Drama","Pelicula",5);
    Peliculas[5] = new Pelicula("Star Wars: El despertar de la fuerza", 138, "Acción","Pelicula",6);
    Peliculas[6] = new Pelicula("Avengers: Infinity War", 149, "Acción","Pelicula",7);
    Peliculas[7] = new Pelicula("Los Vengadores", 143, "Acción","Pelicula",8);
    Peliculas[8] = new Pelicula("Jurassic World", 124, "Acción","Pelicula",9);
    Peliculas[9] = new Pelicula("El Rey Leon", 88, "Drama","Pelicula",10);
}

void porgeneropeliculas(Video* Peliculas[], string genero){
    int contador_peliculas = 0;
    for (int i = 0;i<10;i++){
        if ((Peliculas[i]->getgenero()) == genero){
            Peliculas[i]->mostrarvideo();
            Peliculas[i]->visualizar();
            Peliculas[i]->calificar();
            contador_peliculas++;
        }
    }
    if (contador_peliculas == 0){
        cout<<"------------------------PELICULA------------------------"<<endl;
        cout<<"No se encontro ninguna pelicula de "<<genero<<endl;
    }
}
void porcalificacionpeliculas(Video* Peliculas[],double baja, double alta){
        int contador_peliculas = 0;
        for (int i = 0;i<10;i++){
            if (Peliculas[i]->promedio() >= baja && Peliculas[i]->promedio() <= alta){
                Peliculas[i]->mostrarvideo();
                Peliculas[i]->visualizar();
                Peliculas[i]->calificar();
                contador_peliculas++;
            }
        }
        if (contador_peliculas == 0){
            cout<<"------------------------PELICULA------------------------"<<endl;
            cout<<"No se encontro ninguna pelicula de "<<baja<<" - "<<alta<<" estrellas "<<endl;
        }
}
// -------------------------------------------------------------SERIES-------------------------------------------------------------
void llenarSeries(Video* Series[]){
    Series[0] = new Serie("Arcane",735,"Acción","Serie",1,2,18,"El monstruo que creaste",1,9,"Episodio",1,"La mugre bajo tus uñas",2,9,"Episodio",2);
    Series[1] = new Serie("Game of Thrones",4170,"Acción","Serie",2,8,73,"Winter Is Coming",1,1,"Episodio",1,"The North Remembers",2,1,"Episodio",2);
    Series[2] = new Serie("Stranger Things",2100,"Drama","Serie",3,5,42,"Capítulo uno: La desaparición de Will Byers",1,1,"Episodio",1,"Capítulo nueve: El huésped",4,9,"Episodio",2);
    Series[3] = new Serie("Gravity Falls",947,"Misterio","Serie",4,2,40,"Doble Dipper",1,7,"Episodio",1,"Anormalgedón 3",2,20,"Episodio",2);
    Series[4] = new Serie("New Amsterdam",3956,"Drama","Serie",5,5,89,"Cavitation",1,5,"Episodio",1,"¿Cómo Puedo Ayudar?",2,13,"Episodio",2);
}

// -------------------------------------------------------------EPISODIOS-------------------------------------------------------------

void cicloepisodios(Video* Series[], int i){
    int otra = 0;
    int swicth_2 = 1;
    while (swicth_2){
        if (otra){
            cout<<"Selecciona una opción válida (Y/N): ";
        }
        else{
            cout<<"¿Quieres ver los episodios disponibles de la serie?(Y/N) "<<endl;
        }
        string epi;
        cin>>epi;
        if (epi == "Y"){
            ((Serie*)Series[i])->mostrarepisodio();
            swicth_2 = 0;
            otra = 0;
        }
        else if(epi == "N"){
            swicth_2 = 0;
            otra = 0;
        }
        else{ 
            otra = 1;
        }
    }
}

// -------------------------------------------------------------SERIES-------------------------------------------------------------

void porgeneroseries(Video* Series[], string genero){
    int contador_series = 0;
    for (int i = 0;i<5;i++){
        if ((Series[i]->getgenero()) == genero){
            Series[i]->mostrarvideo();
            Series[i]->visualizar();
            Series[i]->calificar();
            cicloepisodios(Series,i);
            contador_series++;
        }
    }
    if (contador_series == 0){
        cout<<"------------------------SERIE------------------------"<<endl;
        cout<<"No se encontro ninguna serie de "<<genero<<endl;
    }
}
// Una sola serie por calificacion (DEPENDE DE LA INTERPRETACION DE A)
void porcalificacionseries(Video* Series[],double baja, double alta,int seri){
    int contador_series = 0;
        if (Series[seri-1]->promedio() >= baja && Series[seri-1]->promedio() < alta){
            Series[seri-1]->mostrarvideo();
            Series[seri-1]->visualizar();
            Series[seri-1]->calificar();
            int swicth_2 = 1;
            cicloepisodios(Series,seri-1);
            contador_series++;
        }
    if (contador_series == 0){
        cout<<"------------------------SERIE------------------------"<<endl;
        cout<<"No se encontro ninguna serie de "<<baja<<" - "<<alta<<" estrellas "<<endl;
    }
}
// Todas las series por calificacion
void porcalificacionseries(Video* Series[],double baja, double alta){
    int contador_series = 0;
    for (int i = 0;i<5;i++){
        if (Series[i]->promedio() >= baja && Series[i]->promedio() <= alta){
            Series[i]->mostrarvideo();
            Series[i]->visualizar();
            Series[i]->calificar();
            int swicth_2 = 1;
            cicloepisodios(Series,i);
            contador_series++;
        }
    }
    if (contador_series == 0){
        cout<<"------------------------SERIE------------------------"<<endl;
        cout<<"No se encontro ninguna serie de "<<baja<<" - "<<alta<<" estrellas "<<endl;
    }
}

// -------------------------------------------------------------MENUS-------------------------------------------------------------
void menucalifacion(){
    cout<<"-------------------------------MENU CALIFICACIÓN-------------------------------"<<endl;
    cout<<"Elige un calificación: \n"
    <<"1. 0 - 1 estrellas\n"
    <<"2. 1 - 2 estrellas\n"
    <<"3. 2 - 3 estrellas\n"
    <<"4. 3 - 4 estrellas\n"
    <<"5. 4 - 5 estrellas\n"
    <<"6. Atras"<<endl;
}

// -------------------------------------------------------------CATÁLOGOS-------------------------------------------------------------
void catalogo_series(Video* Series[], int otra){
    cout<<"------------------------CATÁLOGO DE SERIES------------------------"<<endl;
    for (int i = 0;i<5;i++){
        cout<<i+1<<". "<<Series[i]->getnombre()<<endl;
    }   
    cout<<"6. Atrás"<<endl;
    if (otra){
        cout<<"Selecciona una opción válida, Introduce el número de la serie que quieres calificar: ";
    }
    else{
        cout<<"Introduce el número de la serie que quieres calificar: ";  
    }
}

void catalogopeliculas(Video* Peliculas[]){
    cout<<"------------------------CATÁLOGO DE PELÍCULAS------------------------"<<endl;
    for (int i = 0;i<10;i++){
        cout<<i+1<<". "<<Peliculas[i]->getnombre()<<endl;
    } 
    cout<<"11. Atrás"<<endl;
}

int punto_dos(Video* Series[]){
    int swicth_2 = 1; // Swicth CATALOGO
    int otra_2 = 0; // MENU CATALOGO
    int seri;
    while(swicth_2){
        catalogo_series(Series,otra_2);
        cin>>seri;
        if (seri == 1 ||seri == 2 ||seri == 3 ||seri == 4 ||seri == 5){
            Series[seri-1]->mostrarvideo();
            Series[seri-1]->calificar();
            Series[seri-1]->visualizar();
            // Aqui se deben de validar las estrellas
        }
        else if(seri == 6){
            swicth_2 = 0;
        }
        else{
            otra_2 = 1;
        }
    }
    return seri;
}

// -------------------------------------------------------------EXCEL-------------------------------------------------------------
// Función para leer el archivo CSV y cargar las calificaciones a los objetos correspondientes
void cargarCalificacionesDesdeCSV(Video* Peliculas[], Video* Series[]) {
    ifstream fin("calificaciones.csv"); // Se abre el archivo (Leer)
    if (!fin.is_open()) { // Si el archivo se abrió correctamente.
        cout << "Error al abrir calificaciones.csv\n";
        return;
    }
    string linea;
    while (getline(fin, linea)) { //Lee línea por línea el archivo hasta que termine.
        if (linea.empty()) continue; //Si la línea está vacía, la salta y continúa con la siguiente.

        size_t coma = linea.find(','); // Busca la primera coma en la línea.
        if (coma == string::npos) continue;

        string nombre = linea.substr(0, coma); // Extrae el texto antes de la primera coma

        if (nombre.find("Pelicula") != string::npos) {  // Para peliculas
            int id = stoi(nombre.substr(9)) - 1;  // Extrae la parte numérica
            if (id >= 0 && id < 10 && Peliculas[id] != nullptr) {
                Peliculas[id]->cargarCalificacionesDesdeCSV(linea); // Linea es toda la fila del csv
            }
        }
        else if (nombre.find("Serie") != string::npos) { // Para series
            int id = stoi(nombre.substr(6)) - 1;  // Extrae la parte numérica
            if (id >= 0 && id < 5 && Series[id] != nullptr) {
                Series[id]->cargarCalificacionesDesdeCSV(linea); // Linea es toda la fila del csv
            }
        }
    }
    fin.close();
}

// Guardar todas las calificaciones en CSV sin borrar lo anterior (agregando calificaciones)
void guardarCalificacionesCSV(Video* Peliculas[], Video* Series[]) {
    ofstream fout("calificaciones.csv"); // Se abre el archivo (Escribir)
    if (!fout.is_open()) {
        cout << "Error al abrir calificaciones.csv para guardar\n";
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (Peliculas[i] != nullptr) {
            fout << "Pelicula " << (i + 1);
            for (double c : Peliculas[i]->calificaciones) {
                fout << "," << c;
            }
            fout << "\n";
        }
    }
    for (int i = 0; i < 5; i++) {
        if (Series[i] != nullptr) {
            fout << "Serie " << (i + 1);
            for (double c : Series[i]->calificaciones) {
                fout << "," << c;
            }
            fout << "\n";
        }
    }
    fout.close();
}

// -------------------------------------------------------------MAIN-------------------------------------------------------------

int main(){
        int swicth = 1;
        int otra = 0;
        int eleccion;
        Video* Peliculas[10];
        llenarPeliculas(Peliculas);
        Video* Series[5];
        llenarSeries(Series);
        // Cargar calificaciones desde CSV (si existe)
        cargarCalificacionesDesdeCSV(Peliculas, Series);

        
        while (swicth){
            cout<<"-------------------------------MENU-------------------------------"<<endl;
            cout<<"1. Mostrar los videos en general con una cierta calificación o de un cierto género\n"
                <<"2. Mostrar los episodios de una determinada serie con una calificacion determinada\n"
                <<"3. Mostrar las películas con cierta calificacion\n"
                <<"4. Calificar un video\n"
                <<"5. Comparar la duración de las películas.\n"
                <<"0. Salir"<<endl;
            if (otra){
                cout<<"Selecciona una opción válida: ";
            }
            else{
                cout<<"Selecciona una opción del menú: ";  
            }
            cin>>eleccion;
            if(eleccion == 1){
                otra = 0; //  Es la del menu principal 
                int swicth_1 = 1; // Swicth FILTROS
                int otra_1 = 0; // MENU FILTROS
                while(swicth_1){
                    cout<<"-------------------------------MENU FILTROS-------------------------------"<<endl;
                    if (otra_1){
                        cout<<"1. Género\n"
                        <<"2. Calificación\n"
                        <<"3. Atras\n"
                        <<"Selecciona una opción valida: "; 
                    }
                    else{
                        cout<<"1. Género\n"
                        <<"2. Calificación\n"
                        <<"3. Atrás\n"
                        <<"Selecciona una opción: "; 
                    }
                    int filtro;
                    cin>>filtro;
                    if (filtro == 1){
                        int otra_1_1 = 0; // MENU GENEROS
                        int swicth_1_1 = 1; // Swicth GENEROS
                        while(swicth_1_1){
                            cout<<"-------------------------------MENU GÉNEROS-------------------------------"<<endl;
                            cout<<"1. Drama \n"
                            <<"2. Acción\n"
                            <<"3. Misterio\n"
                            <<"4. Atrás"<<endl;
                            if (otra_1_1){
                                cout<<"Selecciona una opción valida: ";
                            }
                            else{
                                cout<<"Selecciona un opción: ";  
                            }
                            int gen;
                            cin>>gen;
                            if(gen == 1){
                                cout<<"------------------------DRAMA------------------------"<<endl;
                                porgeneropeliculas(Peliculas, "Drama");
                                guardarCalificacionesCSV(Peliculas, Series);
                                porgeneroseries(Series, "Drama");
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_1 = 0;
                            }
                            else if (gen == 2){
                                cout<<"------------------------ACCIÓN------------------------"<<endl;
                                porgeneropeliculas(Peliculas, "Acción");
                                guardarCalificacionesCSV(Peliculas, Series);
                                porgeneroseries(Series, "Acción");
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_1 = 0;
                            }
                            else if(gen == 3){
                                cout<<"------------------------MISTERIO------------------------"<<endl;
                                porgeneropeliculas(Peliculas, "Misterio");
                                guardarCalificacionesCSV(Peliculas, Series);
                                porgeneroseries(Series, "Misterio");
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_1 = 0;
                            }
                            else if(gen == 4){
                                swicth_1_1 = 0;
                            }
                            else{
                                otra_1_1 = 1;
                            }
                        }
                    }
                    else if(filtro == 2){
                        int otra_1_2 = 0;
                        int swicth_2_1 = 1;
                        while(swicth_2_1){
                            menucalifacion();
                            if (otra_1_2){
                                cout<<"Selecciona una opción valida: ";
                            }
                            else{
                                cout<<"Selecciona un opción: ";  
                            }
                            int estre;
                            cin>>estre;
                            if(estre == 1){
                                cout<<"------------------------0 - 1 ESTRELLAS------------------------"<<endl;
                                porcalificacionpeliculas(Peliculas, 0.0, 1.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                porcalificacionseries(Series, 0, 1.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_2 = 0;
                            }
                            else if (estre == 2){
                                cout<<"------------------------1 - 2 ESTRELLAS------------------------"<<endl;
                                porcalificacionpeliculas(Peliculas, 1.0, 2.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                porcalificacionseries(Series, 1.0, 2.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_2 = 0;

                            }
                            else if(estre == 3){
                                cout<<"------------------------2 - 3 ESTRELLAS------------------------"<<endl;
                                porcalificacionpeliculas(Peliculas, 2.0, 3.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                porcalificacionseries(Series, 2.0, 3.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_2 = 0;
                            }
                            else if(estre == 4){
                                cout<<"------------------------3 - 4 ESTRELLAS------------------------"<<endl;
                                porcalificacionpeliculas(Peliculas, 3.0, 4.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                porcalificacionseries(Series, 3.0, 4.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_2 = 0;
                            }
                            else if(estre == 5){
                                cout<<"------------------------4 - 5 ESTRELLAS------------------------"<<endl;
                                porcalificacionpeliculas(Peliculas, 4.0, 5.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                porcalificacionseries(Series, 4.0, 5.0);
                                guardarCalificacionesCSV(Peliculas, Series);
                                otra_1_2 = 0;
                                
                            }
                            else if(estre == 6){
                                swicth_2_1 = 0;
                            }
                            else{
                                otra_1_2 = 1;
                            }
                        }
                    }
                    else if(filtro == 3){
                        swicth_1 = 0;
                    }
                    else{
                        otra_1 = 1;
                    }
                }
            }
            else if(eleccion == 2){ 
                otra = 0; //  Es la del menu principal 

                int otra_2_1 = 0; // MENU CALIFICACION
                int swicth_2_1 = 1; // Swicth CALIFICACION
                while(swicth_2_1){
                    menucalifacion();
                    if (otra_2_1){
                            cout<<"Selecciona una opción valida: ";
                        }
                    else{
                        cout<<"Selecciona un opción: ";  
                    }
                    int estre;
                    cin>>estre;
                    if(estre == 1){
                        cout<<"------------------------0 - 1 ESTRELLAS------------------------"<<endl;
                        porcalificacionseries(Series, 0, 1.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        otra_2_1 = 0;
                    }
                    else if (estre == 2){
                        cout<<"------------------------1 - 2 ESTRELLAS------------------------"<<endl;
                        porcalificacionseries(Series, 1.0, 2.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        otra_2_1 = 0;
                    }
                    else if(estre == 3){
                        cout<<"------------------------2 - 3 ESTRELLAS------------------------"<<endl;
                        porcalificacionseries(Series, 2.0, 3.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        otra_2_1 = 0;
                    }
                    else if(estre == 4){
                        cout<<"------------------------3 - 4 ESTRELLAS------------------------"<<endl;
                        porcalificacionseries(Series, 3.0, 4.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        otra_2_1 = 0;
                    }
                    else if(estre == 5){
                        cout<<"------------------------4 - 5 ESTRELLAS------------------------"<<endl;
                        porcalificacionseries(Series, 4.0, 5.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        otra_2_1 = 0;
                    }
                    else if(estre == 6){
                        swicth_2_1 = 0;
                    }
                    else{
                        otra_2_1 = 1;
                    }
                }
            }
            else if(eleccion == 3){
                otra = 0; //  Es la del menu principal 
                int swicth_3 = 1; // Swicth ESTRELLAS
                int otra_3 = 0; // MENU ESTRELLAS
                while(swicth_3){
                    menucalifacion();
                    if (otra_3){
                        cout<<"Selecciona una opción valida: ";
                    }
                    else{
                        cout<<"Selecciona un opción: ";  
                    }
                    int estre;
                    cin>>estre;
                    if(estre == 1){
                        cout<<"------------------------0 - 1 ESTRELLAS------------------------"<<endl;
                        porcalificacionpeliculas(Peliculas, 0.0, 1.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                    }
                    else if (estre == 2){
                        cout<<"------------------------1 - 2 ESTRELLAS------------------------"<<endl;
                        porcalificacionpeliculas(Peliculas, 1.0, 2.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                    }
                    else if(estre == 3){
                        cout<<"------------------------2 - 3 ESTRELLAS------------------------"<<endl;
                        porcalificacionpeliculas(Peliculas, 2.0, 3.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                    }
                    else if(estre == 4){
                        cout<<"------------------------3 - 4 ESTRELLAS------------------------"<<endl;
                        porcalificacionpeliculas(Peliculas, 3.0, 4.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                    }
                    else if(estre == 5){
                        cout<<"------------------------4 - 5 ESTRELLAS------------------------"<<endl;
                        porcalificacionpeliculas(Peliculas, 4.0, 5.0);
                        guardarCalificacionesCSV(Peliculas, Series);
                        
                    }
                    else if(estre == 6){
                        swicth_3 = 0;
                    }
                    else{
                        otra_3 = 1;
                    }
                }
            }
            else if(eleccion == 4){
                otra = 0; //  Es la del menu principal
                int swicth_4 = 1; // Swicth VIDEOS
                int otra_4 = 0; // MENU VIDEOS
                cout<<"Calificar un video"<<endl;
                    int califica;
                    while(swicth_4){
                        cout<<"------------------------VIDEOS------------------------"<<endl;
                        if (otra_4){
                            cout<<"1. Película \n"
                            <<"2. Serie \n" 
                            <<"3. Atras \n"
                            <<"Selecciona una opción válida ¿Quieres calificar? " <<endl;  
                        }
                        else{
                            cout<<"1. Película \n"
                            <<"2. Serie \n" 
                            <<"3. Atras \n"
                            <<"¿Quieres calificar? " <<endl;  
                        }
                        cin>>califica;
                        if (califica == 1){
                            int swicth_4_1 = 1; // Swicth CALIFICA
                            int otra_4_1 = 0; // MENU CALIFICA
                            while(swicth_4_1){
                                catalogopeliculas(Peliculas);
                                if (otra_4_1){
                                    cout<<"Selecciona una opción válida Introduce el número de la película que quieres calificar: ";
                                }
                                else{
                                    cout<<"Introduce el número de la película que quieres calificar: ";  
                                }
                                int peli;
                                cin>>peli;
                                if (peli == 1 ||peli == 2 ||peli == 3 ||peli == 4 ||peli == 5 ||peli == 6 ||peli == 7 ||peli == 8 ||peli == 9 ||peli == 10){
                                        Peliculas[peli-1]->mostrarvideo();
                                        Peliculas[peli-1]->visualizar();
                                        Peliculas[peli-1]->calificar();
                                        guardarCalificacionesCSV(Peliculas, Series);
                                        otra_4_1 = 0;
                                }
                                else if(peli == 11){
                                    swicth_4_1 = 0;
                                }
                                else{
                                    otra_4_1 = 1;
                                }
                            }   
                        }
                        else if(califica == 2){
                            int swicth_4_2 = 1; // Swicth CATALOGO
                            int otra_4_2 = 0; // MENU CATALOGO
                            while(swicth_4_2){
                                catalogo_series(Series,otra_4_2);
                                int seri;
                                cin>>seri;
                                if (seri == 1 ||seri == 2 ||seri == 3 ||seri == 4 ||seri == 5){
                                        Series[seri-1]->mostrarvideo();
                                        Series[seri-1]->visualizar();
                                        Series[seri-1]->calificar();
                                        int swicth_4_2_1 = 1; // Swicth CATALOGO
                                        int otra_4_2_1 = 0; // MENU CATALOGO
                                        while(swicth_4_2_1){
                                            cout<<"------------------------CATÁLOGO DE EPISODIOS "<< Series[seri-1]->getnombre()<<"------------------------"<<endl;
                                            for (int i = 0;i<2;i++){
                                                cout<<i+1<<". "<<((Serie*)Series[seri-1])->gettitulo_epi(i)<<endl;
                                            }  
                                            cout<<"3. Atras"<<endl;
                                            if (otra_4_2_1){
                                                cout<<"Selecciona una opción válida Introduce un número de un episodio: ";
                                            }
                                            else{
                                                cout<<"Introduce un número de un episodio: ";  
                                            }
                                            int epi;
                                            cin>>epi;
                                            if (epi == 1 ||epi == 2){
                                                    ((Serie*)Series[seri-1])->mostrarepisodio(epi-1);
                                                    guardarCalificacionesCSV(Peliculas, Series);
                                                    otra_4_2_1 = 0;
                                            }  
                                            else if (epi == 3){
                                                swicth_4_2_1 = 0;
                                            }
                                            else{
                                                otra_4_2_1 = 1;
                                            }
                                        }  
                                }    
                                else if(seri == 6){
                                    swicth_4_2 = 0;
                                }  
                                else{
                                    otra_4_2 = 1;
                                }
                            }
                        }
                        else if(califica == 3){
                            swicth_4 = 0;
                        }
                        else{
                            otra_4 = 1;
                        }
                    }
            }
            else if(eleccion == 5){
                otra = 0; //  Es la del menu principal
                int swicth_5 = 1; // Swicth PELICULA
                int otra_5 = 0; // MENU PELICULA
                while(swicth_5){
                    catalogopeliculas(Peliculas);
                    if (otra_5){
                        cout<<"Selecciona una opción valida, Elige una película: ";
                    }
                    else{
                        cout<<"Elige una película: ";  
                    }
                    int peli1;
                    cin>>peli1;
                    if (peli1 < 11){
                        otra_5 = 0;
                        int otra_5_1 = 0; // MENU COMPARAR
                        int swicth_5_1 = 1; // Swicth COMPARAR
                        while(swicth_5_1){
                            if (otra_5_1){
                                cout<<"Selecciona una opción valida, Elige la película para comparar: ";
                            }
                            else{
                                cout<<"Elige la película para comparar: ";  
                            }
                            int peli2;
                            cin>>peli2;
                            if (peli2 < 11){
                                swicth_5_1 = 0;
                                otra_5_1 = 0;
                                if (*Peliculas[peli1-1]<*Peliculas[peli2-1]){
                                    cout<<endl;
                                    cout<<"Pelicula "<<Peliculas[peli1-1]->getnombre()<<" con una duración de "<<Peliculas[peli1-1]->getduracion()<<" minutos, tiene menos duración que "<<Peliculas[peli2-1]->getnombre()<<" con una duración de "<<Peliculas[peli2-1]->getduracion()<<" minutos"<<endl;
                                    cout<<endl;
                                }
                                else if(Peliculas[peli1-1] == Peliculas[peli2-1]){
                                    cout<<endl;
                                    cout<<"Pelicula "<<Peliculas[peli1-1]->getnombre()<<" con una duración de "<<Peliculas[peli1-1]->getduracion()<<" minutos, tiene la misma duración que "<<Peliculas[peli2-1]->getnombre()<<" con una duración de "<<Peliculas[peli2-1]->getduracion()<<" minutos"<<endl;
                                    cout<<endl;
                                }
                                else{
                                    cout<<endl;
                                    cout<<"Pelicula "<<Peliculas[peli1-1]->getnombre()<<" con una duración de "<<Peliculas[peli1-1]->getduracion()<<" minutos, tiene mas duración que "<<Peliculas[peli2-1]->getnombre()<<" con una duración de "<<Peliculas[peli2-1]->getduracion()<<" minutos"<<endl;
                                    cout<<endl;
                                }
                            }
                            else if(peli2 == 11){
                                swicth_5 = 0;
                                swicth_5_1 = 0;
                            }
                            else{
                                otra_5_1 = 1;
                            }
                        }   
                    }
                    else if(peli1 == 11){
                        swicth_5 = 0;
                    }
                    else{
                            otra_5 = 1;
                        }
                }
            }
            else if(eleccion == 0){
                cout<<"Adiós, vuelva pronto"<<endl;
                swicth = 0;
            }
            else{
                otra = 0; //  Es la del menu principal
            }

        }
            
        for (int i = 0; i < 5; i++) {
            ((Serie*)Series[i])->eliminar_episodios();
        }
        

        // Eliminar objetos
        for (int i = 0; i < 10; ++i) delete Peliculas[i];
        for (int i = 0; i < 5; ++i) delete Series[i];

    return 0;
}