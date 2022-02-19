# For a collection of strings and a positive k, the overlap graph for the
# strings is a directed graph Ok in which each string is represented by a node,
# and string s is connected to string t with a directed edge when there is a
# length k suffix of s that matches a length k prefix of t, as long as s != t

import sys
import networkx as nx


def build_graph(keys, suffixes, prefixes):
    g = nx.DiGraph()

    for i in range(0, len(keys)):

        for j in range(0, len(keys)):
            if i != j:
                if suffixes[i] == prefixes[j]:
                    g.add_edge(keys[i], keys[j])

    return g


if __name__ == '__main__':
    FASTA = ''.join(sys.stdin.read().split('\n')).split('>')[1:]

    # Generating ids, prefixes, and suffixes
    keys = [i[:13] for i in FASTA]
    values = [i[13:] for i in FASTA]
    prefixes = [i[:3] for i in values]
    suffixes = [i[-3:] for i in values]

    # Building graph
    g = build_graph(keys=keys, suffixes=suffixes, prefixes=prefixes)

    for edge in g.edges:
        print(edge[0], edge[1])
