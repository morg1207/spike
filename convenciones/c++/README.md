# spike

1. Clases y Estructuras

    Formato: PascalCase
    Ejemplo: RobotController, MotorSettings
    Justificación: Mantiene las clases y estructuras visualmente distinguibles y facilita su identificación.

2. Variables Miembro de Clase

    Formato: camel_case_
    Ejemplo: speed_robot_, position_

3. Variables Globales

    Formato: g_variable_name
    Ejemplo: g_max_speed, g_log_level
    Justificación: Facilita la identificación de variables de ámbito global y evita confusión con variables locales o miembros.

4. Variables Constantes

    Formato: ALL_CAPS
    Ejemplo: MAX_SPEED, PI
    Justificación: Facilita la identificación de constantes y refuerza la idea de que son valores inmutables.

5. Enumeraciones (enum)


    Formato de Valores enum: ALL_CAPS 

    enum Direction { NORTH, SOUTH, EAST, WEST };


6. Funciones y Métodos

    Formato: camelCase
    Ejemplo: calculateSpeed, moveRobot
    Justificación: Sigue la convención de métodos de muchas librerías estándar de C++ y resulta familiar para la mayoría de los programadores.

7. Parámetros de Función

    Formato: camelCase o snake_case
    Ejemplo: speedLimit, distance
    Justificación: Mantiene el nombre de los parámetros simple y fácil de distinguir de los nombres de variables miembro.

8. Macros

    Formato: ALL_CAPS, con _ entre palabras.
    Ejemplo: DEBUG_MODE, VERSION_NUMBER
    Justificación: Son notoriamente visibles en el código y de fácil identificación como macros.

9. Espacios de Nombres (Namespaces)

    Formato: lowercase
    Ejemplo: robotics, utils
    Justificación: Diferencia los espacios de nombres de otros elementos y se adapta bien a la convención de C++ para namespaces.

10. Alias de Tipos (typedef o using)

    Formato: PascalCase
    Ejemplo: StringMap, Vector3D
    Justificación: Permite distinguir los tipos definidos por el usuario de las variables regulares y es similar al estilo de las clases.

Aplicando estas convenciones, se logra un código consistente y fácil de seguir, lo cual facilita su mantenimiento y colaboración en equipo.

11. Publicadores, Subscripciones

    subScan_
    pubMap_

12. Callback

    callbackScan