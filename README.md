# proxy

Diseñe una máquina de estados pensada para censurar información que circule por un proxy.

¿Cómo se va a realizar esta censura? Al principio, y puesto que se va a utilizar en una simulación y
no en un escenario real, el programa se limitará a imprimir por pantalla cadenas de texto que
previamente se introduzcan por teclado. Sin embargo, al activar el modo censura, cada vez que se introduzca por teclado un mensaje que contenga la palabra"taco", la máquina lo cambiará por "xxxx" (manteniendo el resto del mensaje intacto) antes de
imprimirlo por pantalla. A la tercera vez que se detecte la introducción de un "taco", la máquina dejará de
imprimir mensajes, mostrando por pantalla el aviso "usted ya no esta autorizado a leer contenido".
La forma de activar la censura por filtro es mediante la introducción por teclado de la cadena "/on",
para desactivar el modo de filtrado de tacos, o el de bloqueo total de información, se utiliza la
cadena "/off". Nótese como, si se está en el modo de bloqueo total, un "/off" hace volver a la
máquina al estado de filtrado de tacos, mientras que un segundo "/off" desactivaría la censura. Para
salir de la máquina se utiliza la cadena "/fin".
