import math

def ODZ(n, x, z):
    z = (2*n + 1) * x ** (2*n + 1)
    # z2 = math.log((x**2-1)**0.5/(1-x))
    if z != 0 and x!=1 and (x**2-1)**0.5/(1-x) >= 0 and abs(x) > 1:
        return x, z, n

arthx = 0
x = int(input("Введите x: "))
x, z, n = ODZ(x, z, 0) 
n=0 
while n > 0:
    arthx = z
    print(f"n = {n}, x = {x}, z = {z}")
    n += 1
print(arthx)