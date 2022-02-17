# When we have several different genomes at the same time, it's interesting
# to identify regions of similarity that may indicate genes shared by different
# organisms or species

import sys
import re


# A common substring of a collection of strings is a substring of every member
# of the collection. We say that a common substring is a longest common
# substring if there does not exist a longer common substring
def longest_common_substring(dnas):
    dnas = sorted(dnas, key=len)

    longest_motif = ''

    for i in range(len(dnas[0])):

        for j in range(i, len(dnas[0])):
            contains = True
            motif = dnas[0][i:j + 1]

            for dna in dnas[1:]:
                if motif not in dna:
                    contains = False
                    break

            if contains and len(longest_motif) < len(motif):
                longest_motif = motif

    return longest_motif


if __name__ == '__main__':
    dnas = re.split(
        pattern='>Rosalind_[0-9]+',
        string=''.join(sys.stdin.read().split('\n'))
    )[1:]

    longest_motif = longest_common_substring(dnas=dnas)
    print(longest_motif)
