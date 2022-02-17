import sys
import re


# A subsequence of a string is a collection of symbols contained in order
# (though not necessarily contiguosly) in the string
def find_subsequence(s, t):
    positions = []
    base = 0

    for i in range(len(s)):
        if base < len(t) and s[i] == t[base]:
            positions.append(str(i + 1))
            base = base + 1

    return positions


if __name__ == '__main__':
    FASTA = re.split(
        pattern='>Rosalind_[0-9]+',
        string=''.join(sys.stdin.read().split('\n'))
    )[1:]

    positions = find_subsequence(s=FASTA[0], t=FASTA[1])
    print(' '.join(positions))
