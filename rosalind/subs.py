# We define a motif as such a commonly shared interval of DNA. A common task
# in molecular biology is to search an organism's genome for a known motif.

import sys
import re


def find_motif(dna, motif):
    locations = []

    motif = f'(?=({motif}))'
    p = re.finditer(pattern=motif, string=dna)

    for match in p:
        locations.append(str(match.start() + 1))

    return locations


if __name__ == '__main__':
    dnas = sys.stdin.read().split('\n')
    s = dnas[0]
    t = dnas[1]

    locations = find_motif(dna=s, motif=t)

    print(' '.join(locations))
