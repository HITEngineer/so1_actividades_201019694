# Completely Fair Scheduler (CFS) en Linux

## Descripción
El **Completely Fair Scheduler (CFS)** es el planificador por defecto del kernel de Linux desde la versión 2.6.23. Está diseñado para asignar el tiempo de CPU de manera equitativa entre todos los procesos en ejecución, eliminando la dependencia de prioridades absolutas y proporcionando un enfoque basado en el tiempo virtual de cada proceso.

## Características principales

1. **Equidad**: 
   - El CFS distribuye el tiempo de CPU de manera justa entre los procesos, asignando más tiempo a aquellos que han utilizado menos recursos recientemente.
   
2. **Tiempo virtual**:
   - Cada proceso tiene un "tiempo virtual" que avanza más rápido cuanto más CPU utiliza, penalizando a los procesos con alto consumo de recursos y favoreciendo a los que han usado menos CPU.

3. **Árbol rojo-negro**:
   - Los procesos se organizan en un árbol rojo-negro (estructura de datos balanceada), lo que permite seleccionar rápidamente el proceso con el menor tiempo de CPU utilizado. Esto asegura la equidad en la asignación de CPU.

4. **"Sleeper fairness"**:
   - Los procesos que han estado durmiendo (inactivos) no son penalizados cuando vuelven a ejecutarse, mejorando la responsividad de procesos interactivos.

5. **Sin "timeslices" tradicionales**:
   - A diferencia de planificadores anteriores, el CFS no asigna "cuotas de tiempo" fijas. En su lugar, mide el tiempo de CPU usado y ajusta la asignación de forma dinámica.

6. **Prioridades de "niceness"**:
   - El CFS respeta el valor de **niceness** de los procesos (que varía de -20 a +19), lo que permite que los procesos con mayor prioridad obtengan más tiempo de CPU.

7. **Multiprocesador (SMP)**:
   - El CFS distribuye los procesos entre varios núcleos en sistemas multiprocesador, asegurando que el hardware sea utilizado eficientemente.

## Funcionamiento

1. **Asignación de tiempo virtual**:
   - El tiempo virtual de cada proceso se incrementa a medida que usa la CPU. El CFS siempre selecciona el proceso con el menor tiempo virtual para ejecutar, logrando un reparto justo del tiempo de CPU.

2. **Rotación de procesos**:
   - Cuando un proceso ha utilizado suficiente tiempo de CPU, su tiempo virtual aumenta y es reinsertado en el árbol rojo-negro, permitiendo que otros procesos se ejecuten.

3. **Eficiencia O(log n)**:
   - La inserción y eliminación de procesos en el árbol rojo-negro tiene un coste logarítmico, lo que hace que el CFS sea muy eficiente incluso con muchos procesos en ejecución.

4. **Procesos interactivos**:
   - Los procesos que interactúan con el usuario (por ejemplo, aplicaciones gráficas o terminales) reciben más rápidamente tiempo de CPU cuando despiertan, mejorando la experiencia del usuario.

## Conclusión
El **Completely Fair Scheduler (CFS)** es un planificador avanzado que garantiza una distribución justa de los recursos de CPU entre todos los procesos del sistema, mejorando la eficiencia y la experiencia del usuario, especialmente en sistemas interactivos. El CFS logra un equilibrio óptimo entre simplicidad y rendimiento.

