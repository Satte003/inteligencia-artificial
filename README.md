# inteligencia-artificial

## Empezar

-Primero se descarga Git desde la pagina oficial https://git-scm.com/ Una vez instalado se ejecuta, no hay que cambiar ninguna condicion de su descarga.

-Tras eso se va a Vscode. Se crea una carpeta en la que deseas tener el codigo. (Este paso es importante porque aunque luego la borremos, si no lo haces se pondran en cola todos tus archivos en dicha carpeta.)

-Se abre la terminal en la nueva carpeta.

-Creamos la cuenta de Github y usamos el comando:

    git config --global user.email "correo"
    
    git config --global user.name "Nombre"

-Usamos los siguientes comando:

    git init

    git remote add origin https://github.com/Satte003/inteligencia-artificial.git

    git clone https://github.com/Satte003/inteligencia-artificial.git

    git push --set-upstream origin main

Com esto iniciamos git, nos conectamos al repositorio, lo clonamos y determinamos como rama principal "master". Esto creara una carpeta dentro de la propia carpeta. La mas interio, la llamada "inteligencia-artificial" podemos borrarla. Pero recordad antes sacar sus archivos a la otra carpeta.

-Tras esto ya podemos crear y editar archivos.


## Como subir la modificacion de un archivo

-Antes de comenzar a editar o modificar un archivo ya subido usamos 'git pull' para bajar los cambios que han hecho otras personas.

-Realiza los cambios en el archivo.

-Una vez lo tengas, en la terminal de la carpeta usamos 'git status' (por precaucion) para ver si realmente el archivo que hemos editado esta àra subir. En caso de que no puede que no lo hayamos guardad.

-Usamos 'git add .' para poner en cola de subida todos los cambios que nos han salido en el status.

-Usamos 'git commit -m "TEXTO"' sustituyendo TEXTO por una breve explicacion de los cambios hechos. Con esto explicamos que cambios hemos hecho de forma que podremos movernos entre versiones. 
(RECOMENDACION: ir subiendo poco a poco y archivo a archivo para explicar que cambios se han hecho en cada archivo)

-Una vez hemos hecho el commit usamos 'git push' Si da error puede ser que no se ha definido la rama principal'


## COMANDOS UTILES

-Iniciar git:

    git init

-Añadir un archivo: 

    git add README.md

-Añadir todos los archivos: 

    git add .

-Registrar cambio:  

    git commit -m "TEXTO"

-Subir los cambios: 

    git push

-Bajar los cambios que otros han hecho: 

    git pull

-Añadir una conexion al repositorio: 

    git remote add origin https://github.com/Satte003/inteligencia-artificial

-Asentar una rama en la que subir los cambios:  

    git push -u origin main

-Cambiar a otra rama (en caso de que estes en master):

    git checkout main

a