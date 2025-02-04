from tabulate import tabulate


def implication(a, b):
    return (not (a) or b)


headers = ("A", "B", "A->B")
rows = []
for a in [True, False]:
    for b in [True, False]:
        c = implication(a, b)
        rows.append((a,  b, c))

print(tabulate(rows, headers=headers, tablefmt="fancy_grid"))
