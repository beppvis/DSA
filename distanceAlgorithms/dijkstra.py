# Dijkstra's Algorithm in Python

import sys

# Providing the graph

vertices = [
    [0, 1, 1, 0, 0, 0, 0, 0, 0,],
    [1, 0, 1, 0, 0, 1, 0, 0, 0,],
    [1, 1, 0, 1, 1, 0, 0, 0, 0,],
    [0, 0, 1, 0, 1, 0, 0, 1, 0,],
    [0, 0, 1, 1, 0, 1, 0, 1, 0,],
    [0, 1, 0, 0, 1, 0, 1, 0, 0,],
    [0, 0, 0, 0, 0, 1, 0, 1, 1,],
    [0, 0, 0, 1, 1, 0, 1, 0, 1,],
    [0, 0, 0, 0, 0, 0, 1, 1, 0,],
]

edges = [
    [0, 11, 5, 0, 0, 0, 0, 0, 0,],
    [11, 0, 11, 0, 0, 8, 0, 0, 0,],
    [5, 11, 0, 1, 7, 0, 0, 0, 0,],
    [0, 0, 1, 0, 6, 0, 0, 2, 0,],
    [0, 0, 7, 6, 0, 2, 0, 4, 0,],
    [0, 8, 0, 0, 2, 0, 7, 0, 0,],
    [0, 0, 0, 0, 0, 7, 0, 14, 9,],
    [0, 0, 0, 2, 4, 0, 14, 0, 10,],
    [0, 0, 0, 0, 0, 0, 9, 10, 0,],
]


def getToVisit(visited_distance):
    v = -1
    for vertex in range(len(visited_distance)):
        # checking if the given vertex is already visited,and the the distance towards it is less
        if visited_distance[vertex][0] == 0 and (v < 0 or visited_distance[vertex][1] <= visited_distance[v][1]):
            v = vertex
    return v


def dijkstra(edges, vertices):
    visited_distance = []
    n = int(input("enter source node : "))
    for index in range(len(vertices)):
        if index+1 == n:
            # [0,0] is appened when if it is the source node
            visited_distance.append([0, 0])
        else:
            visited_distance.append([0, sys.maxsize])

    for v_i in range(len(vertices)):
        to_visit = getToVisit(visited_distance)
        for neighbour in range(len(vertices)):
            if (vertices[to_visit][neighbour]):
                new_distance = edges[to_visit][neighbour] + \
                    visited_distance[to_visit][1]
                if (new_distance < visited_distance[neighbour][1]):
                    visited_distance[neighbour][1] = new_distance
        visited_distance[to_visit][0] = 1
    return visited_distance


visited_distance = dijkstra(edges, vertices)
for i in range(len(vertices)):
    print(chr(ord("a")+i), visited_distance[i][1])
