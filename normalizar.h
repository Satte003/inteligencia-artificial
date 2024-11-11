typedef struct {
    int mes_lanzamiento; 
    float mes_radianes;  
} Cancion;

void normalizarFecha(Cancion tabla_datos[], int);
float compararMeses(Cancion, Cancion);
void normalizarBPM(int bpm[], int bpmNormalizado[], int);