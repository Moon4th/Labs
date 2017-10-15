import math
from math import atan, log

print("Formula 1: G = 4*(-4*pow(x,2)+a*x+5*pow(x,2))/-20*pow(a,2)+28*a*x+3*pow(x,2)\n");
print("Formula 2: F = math.atan(24*pow(a,2)-25*a*x+6*pow(x,2))\n");
print("Formula 3: Y = math.log(2*pow(a,2)-7*a*x+6*pow(x,2)+1)\n");
n = int(input('Select Formula:'))

if n == 1:
    a = int(input('Enter a: '))
    x = int(input('Enter x: '))
    G = 4 * (-4 * pow(x, 2) + a * x + 5 * pow(x, 2)) / -20 * pow(a, 2) + 28 * a * x + 3 * pow(x, 2)
    print ('A={},X={},G={}'. format(a,x,G))
elif n == 2:
    a = int(input('Enter a: '))
    x = int(input('Enter x: '))
    F = atan(24 * pow(a, 2) - 25 * a * x + 6 * pow(x, 2))
    print ('A={},X={},F={}'. format(a,x,F))
elif n == 3:
    a = int(input('Enter a: '))
    x = int(input('Enter x: '))
    Y = log(2 * pow(a, 2) - 7 * a * x + 6 * pow(x, 2) + 1)
    print('A={},X={},Y={}'.format(a, x, Y))
if (n<1) or (n>3):
    print('Error')