from tabulate import tabulate


def disjunction(a, b):
    return a or b


headers = ("A", "B", "AUB")
rows = []
for a in [True, False]:
    for b in [True, False]:
        c = disjunction(a, b)
        rows.append((a, b, c))

print(tabulate(rows, headers=headers, tablefmt="fancy_grid"))
