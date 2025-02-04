from tabulate import tabulate


def disjunction(a, b):
    return a or b


def implication(a, b):
    return (not (a) or b)


def conjunction(a, b):
    return a and b


rows = []

header = ("P", "Q",  "R", "[p||q]^(p->q)^(q->r)]->r")
for p in [True, False]:
    for q in [True, False]:
        for r in [True, False]:
            s = disjunction(p, q)
            t = implication(p, r)
            u = implication(q, r)
            w = conjunction(conjunction(s, t), u)
            out = implication(w, r)
            rows.append((p, q, r, out))

print(tabulate(rows, headers=header, tablefmt="fancy_grid"))
