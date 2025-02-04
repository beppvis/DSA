from tabulate import tabulate


def implication(a, b):
    return (not (a) or b)


def biImplication(a, b):
    return implication(a, b) and implication(b, a)


header = ("A", "B", "A<=>B")
rows = []

for a in [True, False]:
    for b in [True, False]:
        c = biImplication(a, b)
        rows.append((a, b, c))

print(tabulate(rows, headers=header, tablefmt="fancy_grid"))
