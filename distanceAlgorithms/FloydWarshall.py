INF = float('inf')


def floyd_warshall(distance):
    # Adding vertices individually
    for k in range(len(distance)):
        for i in range(len(distance)):
            for j in range(len(distance)):
                distance[i][j] = min(
                    distance[i][j], distance[i][k] + distance[k][j])
    print_solution(distance)


def print_solution(distance):
    for i in range(len(distance)):
        for j in range(len(distance)):
            if (distance[i][j] == INF):
                print("INF", end=" ")
            else:
                print(distance[i][j], end="  ")
        print(" ")


G = [[0, 3, INF, 5],
     [2, 0, INF, 4],
     [INF, 1, 0, INF],
     [INF, INF, 2, 0]]

floyd_warshall(G)
