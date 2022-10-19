# -*- coding: utf-8 -*-
"""
@author: edwintmz
"""
"""
7.	En Python realice el cálculo de Pi, mediante sumas sucesivas.
Rta.
usando la fórmula de Leibniz
La fórmula es

X = 4 - 4/3 + 4/5 - 4/7 + 4/9 - ....
Esta serie es interminable, cuanto más términos contiene esta serie, más cerca converge el valor de X al valor de Pi.
"""
k = 1
pi = 0
  
for i in range(1000000): 
    if i % 2 == 0: 
        pi = pi + 4/k 
    else: 
        pi = pi - 4/k 
    k = k + 2
print("pi=", pi) 
