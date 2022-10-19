"""
Created on Fri Oct 14 17:06:15 2022
@author: edwintmz
funciona en colab
"""

# ejercicio 5
from multiprocessing import Pool

def mensaje(pala):
    #pala = pala.lower()  # cambia a minusculas la palabra
    if str(pala) == str(pala)[::-1] :
        return "Verdad"
    else:
        return "Falso"

print(Pool().map(mensaje, ['ana','edwin','oruro','Oruro']))
