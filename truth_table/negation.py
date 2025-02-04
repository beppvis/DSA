from tabulate import tabulate

headers = ("p", "! p")
rows = []
for p in [True, False]:
    a = not p
    rows.append((p, a))

print(tabulate(rows, headers=headers, tablefmt="fancy_grid"))
