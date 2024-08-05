import re

def remove_newlines(file_path):
    try:
        # Leer el contenido del archivo
        with open(file_path, 'r') as file:
            content = file.read()

        # Eliminar todos los saltos de línea
        content = content.replace('\n', ' ')
        content = re.sub(r'\s+', ' ', content)
        content = content.replace('5a 41','5a\n41')
        # Escribir el contenido modificado de vuelta al archivo
        with open(file_path, 'w') as file:
            file.write(content)

        print(f"Se han eliminado todos los saltos de línea del archivo: {file_path}")

    except FileNotFoundError:
        print(f"El archivo {file_path} no se encuentra.")
    paquetes = 0
    paquetes_ok = 0
    
    for linea in content.splitlines():
        paquetes += 1
        if (len(linea) == 56):
            paquetes_ok += 1
    print(f"NUMERO DE PAQUETES = {paquetes}")
    print(f"NUMERO DE PAQUETES OK = {paquetes_ok}")
    print(f"% OK = {paquetes_ok / paquetes}")
        
# Ruta al archivo
file_path = 'out.txt'  # Cambia esto por la ruta a tu archivo

remove_newlines(file_path)