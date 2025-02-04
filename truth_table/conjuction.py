from tabulate import tabulate


def conjunction(a, b):
    return a and b


header = ("A", "B", "A^B")
rows = []
for a in [True, False]:
    for b in [True, False]:
        c = conjunction(a, b)
        rows.append((a, b,  c))

print(tabulate(rows, headers=header, tablefmt="fancy_grid"))
