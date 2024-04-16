def mymax(iterable, key=lambda x: x):
    max_x = max_key = None

    for x in iterable:
        if (max_key == None or key(x) > max_key):
            max_x = x
            max_key = key(x)
    return max_x

f=lambda x: x
maxint = mymax([1, 3, 5, 7, 4, 6, 9, 2, 0])
maxchar = mymax("Suncana strana ulice")
maxstring = mymax([
    "Gle", "malu", "vocku", "poslije", "kise",
    "Puna", "je", "kapi", "pa", "ih", "njise"],f)
D = {'burek': 8, 'buhtla': 5}
maxfood = mymax(D, lambda x: D[x])
osobe = [("Frane", "Franić"), ("Mate", "Matić"), ("Miro", "Avkov"), ("Luka", "Uvodić"), ("Boris", "Borisov")]
maxperson = mymax(osobe)
print(maxint)
print(maxchar)
print(maxstring)
print(maxfood)
print(maxperson)
