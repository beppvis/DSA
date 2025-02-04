from tabulate import tabulate


def xor(a, b):
    return (a or b) and not (a and b)


header = ("A",  "B",  "A^B")
rows = []
for a in [True, False]:
    for b in [True, False]:
        c = xor(a, b)
        rows.append((a,  b,  c))

print(tabulate(rows, headers=header, tablefmt="fancy_grid"))
